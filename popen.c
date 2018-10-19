#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/***********************************************
 *
 *exec shell, return result and info if needed
 *
 *cmd: shell string, less than 128
 *buf: save shell print
 *len: buf len ptr, 
************************************************/

int exec_shell(char *cmd, char *buf, int *len_ptr)
{
    int ret = 0;
    FILE *fp = NULL;
    char cmd_tmp[160] = "";
    char buf_tmp[64] = "";
    int buf_tmp_len = 0;
    int buf_remain_len = *len_ptr - 1;
    int buf_write_len = 0;

    if(cmd == NULL)
    {
        return -1;
    }
    snprintf(cmd_tmp, sizeof(cmd_tmp), "%s 2>/dev/null; echo $?", cmd);

    fp = popen(cmd_tmp, "r");
    if(fp == NULL)
    {
        return -1;
    }

    while(fgets(buf_tmp, sizeof(buf_tmp), fp))
    {
        if(buf_remain_len > 0)
        {
            buf_tmp_len = strlen(buf_tmp);
            buf_write_len = (buf_remain_len < buf_tmp_len) ? buf_remain_len : buf_tmp_len ;
            strncat(buf, buf_tmp, buf_write_len);
            buf_remain_len -= buf_write_len;
        }
    }

    ret = atoi(buf_tmp);
    *len_ptr -= buf_remain_len;
    buf[*len_ptr] = '\0';

    pclose(fp);

    return ret;
    
}

int main()
{
    int ret = 0;
    char buf[1024] = {0};
    int len = sizeof(buf);

    ret = exec_shell("ping 12.13.13.13 -c 2", buf, &len);

    printf("ret = %d, len = %d\n", ret, len);
    printf("%s\n", buf);

    return 0;
}

