#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define write_static_str(FILDES, STR) { write(FILDES, STR, sizeof(STR) - 1); }
#define write_static_str_to_stdout(STR) write_static_str(1, STR)

#define DIRNAME "/etc/sysconfig"
#define FILENAME DIRNAME"/language"

void _start(){
        mkdir(DIRNAME, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
        int f = open(FILENAME, O_WRONLY|O_CREAT, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
        if (f < 0) {
                write_static_str_to_stdout("Can not create file "FILENAME"\n");
                exit(1);
        }
        write_static_str(f, "RC_LANG="LOCALE"\n");
        close(f);
        exit(0);
}

