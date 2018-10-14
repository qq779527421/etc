//#include <syslog.h>
//
//int main(int argc, char **argv)
//{
//    syslog(LOG_ALERT, "Hello %s", argv[0]);
//
//    return 0;
//}
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>



int main()
{
    char buf[128] = {0};
    int fd = -1;

    uid_t uid = getuid(); 
    uid_t euid = geteuid(); 
   
    fd = open("abc", O_RDONLY);
    if(fd < 0)
    {
        perror("open");
        return -1;
    }

    read(fd, buf, sizeof(buf));

    printf("buf is %s\n", buf);

    printf("uid is %d, euid is %d\n", uid, euid);

    return 0;
}
