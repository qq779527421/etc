#include <unistd.h>
#include <stdio.h>

int main()
{
    pid_t my_pid = fork();
    if(my_pid > 0)
        sleep(1);
    else
        setsid();

    pid_t pid = getpid();
    pid_t pgid = getpgid(pid);
    pid_t sid = getsid(pid);

    printf("pid is %d, pgid is %d, sid is %d\n", pid, pgid, sid);

    return 0;
}
