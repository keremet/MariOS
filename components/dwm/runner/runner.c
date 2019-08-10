#include <gtk/gtk.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#ifdef LANG_MARIJ
	#define LABEL_POWEROFF "Пашам мучашлымаш"
	#define LABEL_REBOOT "Уэш колташ"
#endif

#ifdef LANG_RUS
	#define LABEL_POWEROFF "Выключение"
	#define LABEL_REBOOT "Перезагрузка"
#endif

static int dlg(const char *msg)
{
	GtkWidget *dialog = gtk_message_dialog_new (0,
		                         GTK_DIALOG_MODAL,
		                         GTK_MESSAGE_QUESTION,
		                         GTK_BUTTONS_YES_NO,
		                         msg);
	gtk_window_set_position(GTK_WINDOW(dialog), GTK_WIN_POS_CENTER_ALWAYS);
	int r = (gtk_dialog_run (GTK_DIALOG (dialog)) == GTK_RESPONSE_YES);
	gtk_widget_destroy (dialog);
	return r;
}

static void poweroff_comp()
{
	if (dlg("Выключить компьютер?")) {
#ifdef __OpenBSD__
		execlp("/usr/bin/doas", "doas", "/sbin/halt", "-p", 0);
#else
		execlp("/usr/bin/sudo", "sudo", "poweroff", 0);
#endif
	}
}

static void reboot_comp()
{
	if (dlg("Перезагрузить компьютер?")) {
#ifdef __OpenBSD__
		execlp("/usr/bin/doas", "doas", "/sbin/reboot", 0);
#else
		execlp("/usr/bin/sudo", "sudo", "reboot", 0);
#endif
	}
}

static void run_command(GtkMenuItem *item, char** command)
{
	if (fork() == 0) {
		setsid();
		execvp(command[0], command);
		fprintf(stderr, "runner: execvp %s", command[0]);
		perror(" failed");
		exit(0);
	}
}

static void trayIconActivated(GObject *trayIcon, gpointer popUpMenu)
{
	gtk_menu_popup(GTK_MENU(popUpMenu), NULL, NULL, NULL, NULL, 0, gtk_get_current_event_time());
}

struct MENU_MODEL{
	const char* name;
	const char* command[4];
	struct MENU_MODEL* mm;
};

static struct MENU_MODEL MM_PROGRAMMING[] = {
	{"Geany", {"geany", 0}},
	{0},
};

static struct MENU_MODEL MM_MAIN_LEFT[] = {
	{"Firefox", {"firefox", 0}},
	{"GEdit", {"gedit", 0}},
	{"GIMP", {"gimp", 0}},
	{"Gnome commander", {"gnome-commander", 0}},
	{"Gnome terminal (Win+Enter)", {"gnome-terminal", 0}},
	{"Dia", {"dia", 0}},
	{"Krusader", {"krusader", 0}},
	{"XCFE4 terminal (Win+Enter)", {"xfce4-terminal", 0}},
	{"Pidgin", {"pidgin", 0}},
	{"LibreOffice6.1", {"/usr/local/bin/libreoffice6.1", 0}},
	{"xterm", {"xterm", 0}},
	{"Программирование", {0}, MM_PROGRAMMING},
	{"Регулятор громкости", {
#ifdef __OpenBSD__
		"xfce4-mixer"
#else
		"gnome-volume-control"
#endif
			, 0}},
	{"Звукозапись", {"gnome-sound-recorder", 0}},
	{"Разрешить доступ к рабочему столу", {"xterm", "-e", "/usr/lib/vino-server", 0}},
	{"Параметры доступа к рабочему столу", {"vino-preferences", 0}},
	{"Подключиться к рабочему столу", {"vncviewer", "-NoJPEG", 0}},
	{"Заблокировать экран (Win+L)", { "xscreensaver-command", "-lock", 0 }},
	{"Снимок экрана", { "gnome-screenshot", "--interactive", 0 }},
	{"Калькулятор", { "xcalc", 0 }},
	{0},
};

static GtkWidget *createMenu(struct MENU_MODEL *MM)
{
	GtkWidget *menu = gtk_menu_new();
	for(struct MENU_MODEL *i = MM; i->name; i++){
		GtkWidget *mi = gtk_menu_item_new_with_label (i->name);
		if(i->mm){
			gtk_menu_item_set_submenu (GTK_MENU_ITEM (mi), createMenu (i->mm));
		}else{
			g_signal_connect (G_OBJECT (mi), "activate", G_CALLBACK (run_command), i->command);
		}
		gtk_menu_shell_append (GTK_MENU_SHELL (menu), mi);
	}

	if (MM == MM_MAIN_LEFT) {
		gtk_menu_shell_append (GTK_MENU_SHELL (menu), gtk_separator_menu_item_new ());

		GtkWidget *mi;
		mi = gtk_menu_item_new_with_label (LABEL_POWEROFF);
		g_signal_connect (G_OBJECT (mi), "activate", G_CALLBACK (poweroff_comp), 0);
		gtk_menu_shell_append (GTK_MENU_SHELL (menu), mi);

		mi = gtk_menu_item_new_with_label (LABEL_REBOOT);
		g_signal_connect (G_OBJECT (mi), "activate", G_CALLBACK (reboot_comp), 0);
		gtk_menu_shell_append (GTK_MENU_SHELL (menu), mi);
	}

	gtk_widget_show_all (menu);
	return menu;
}

static void sigchld(int unused) // можно сделать через sigaction SA_NOCLDWAIT
{
	if (signal(SIGCHLD, sigchld) == SIG_ERR)
		fprintf(stderr, "can't install SIGCHLD handler");
	while (0 < waitpid(-1, NULL, WNOHANG));
}

int main(int argc, char *argv[])
{
	gtk_init (&argc, &argv);
	extern const char* logo_xpm[];
	GtkStatusIcon *trayIcon = gtk_status_icon_new_from_pixbuf (gdk_pixbuf_new_from_xpm_data (logo_xpm));
	gtk_status_icon_set_tooltip (trayIcon, "Запуск программ");
	g_signal_connect(GTK_STATUS_ICON (trayIcon), "activate", GTK_SIGNAL_FUNC (trayIconActivated), (gpointer)createMenu(MM_MAIN_LEFT));
	gtk_status_icon_set_visible(trayIcon, TRUE);

	sigchld(0);

	gtk_main ();
	return 0;
}

/*
при щелчке правой кнопкой можно сделать еще одно меню - более подробное или наоборот
    g_signal_connect(GTK_STATUS_ICON (trayIcon), "popup-menu", GTK_SIGNAL_FUNC (trayIconPopup), menu);
static void trayIconPopup(GtkStatusIcon *status_icon, guint button, guint32 activate_time, gpointer popUpMenu)
{
    gtk_menu_popup(GTK_MENU(popUpMenu), NULL, NULL, gtk_status_icon_position_menu, status_icon, button, activate_time);
}
*/
