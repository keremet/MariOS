#include <gtk/gtk.h>
#include <gdk/gdkkeysyms.h>

gboolean wEscPressed (GtkWidget   *widget, GdkEventKey *event){
	if(event->keyval==GDK_Escape)
		gtk_main_quit();

	return 0;
}

int main(int argc, char** argv) {
	gtk_init(&argc, &argv);
	GtkWidget* win    = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	g_signal_connect( G_OBJECT(win),  "delete_event", G_CALLBACK(gtk_main_quit), 0);
	g_signal_connect( G_OBJECT(win), "key-press-event",  G_CALLBACK (wEscPressed), 0);

	gtk_window_set_default_size(GTK_WINDOW(win), 180, 180);
	gtk_container_set_border_width(GTK_CONTAINER(win), 5);
	gtk_window_set_position(GTK_WINDOW(win), GTK_WIN_POS_MOUSE);
	gtk_window_stick(GTK_WINDOW(win));
	  
	GtkWidget* calendar = gtk_calendar_new();
	gtk_calendar_display_options(
		GTK_CALENDAR(calendar),
		GTK_CALENDAR_SHOW_WEEK_NUMBERS | GTK_CALENDAR_SHOW_DAY_NAMES
		| GTK_CALENDAR_SHOW_HEADING);
	gtk_container_add(GTK_CONTAINER(win), GTK_WIDGET(calendar));

	gtk_widget_show_all(win);
	gtk_main();
	return 0;
}

