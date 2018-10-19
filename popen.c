#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/***********************************************
 * @ 2018.10.19
 * @ exec shell string and return result
 * @ param1: shell string, less than 128
 * @ param2: process every line
************************************************/
int exec_shell(char *cmd, void (*func)(char *buf))
{
    int ret = 0;
    FILE *fp = NULL;
    #define _BUF_TMP_LEN_  256
    char buf_tmp[_BUF_TMP_LEN_] = {0};
    int buf_tmp_index = 0;

    int char_tmp = 0 ;

    if(cmd == NULL)
    {
        return -1;
    }
    
    snprintf(buf_tmp, sizeof(buf_tmp), "%s 2>/dev/null; echo $?", cmd);
    fp = popen(buf_tmp, "r");
    if(fp == NULL)
    {
        return -1;
    }

    while(1)
    {
        char_tmp = fgetc(fp);
        if(EOF == char_tmp)
        {
            ret = atoi(buf_tmp);
            break;
        }

        if(buf_tmp_index < sizeof(buf_tmp) - 1)
        {
            buf_tmp[buf_tmp_index++] = char_tmp;
        }
        
        if(char_tmp == '\n')
        {
            if(func) func(buf_tmp);
            buf_tmp_index = 0;
            memset(buf_tmp, 0, sizeof(buf_tmp));
            continue;
        }
    }
    
    pclose(fp);

    return ret;
    
}

static void print_buf(char *buf)
{
    printf("SHELL-INFO: %s", buf);
}

int main()
{
    int ret = 0;

    ret = exec_shell("ping www.baidu.com -c 2", &print_buf);

    printf("ret = %d\n", ret);

    return 0;
}

