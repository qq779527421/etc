#include <stdio.h>


/*******************************
 *2018.9.4
 *******************************/
void print_char_buf(char *buf, int len)
{
    int i;

    printf("\r\n***len=%d***", len);
    for(i = 0; i < len; i++)
    {
        if((i%16) == 0)
            printf("\r\n");
        printf("0x%x ",buf[i] );
    }

    printf("\r\n");
}

/*******************************
 *2018.9.4
 *******************************/
void print_int_buf(int *buf, int len)
{
    int i;

    printf("\r\n***len=%d***", len);
    for(i = 0; i < len; i++)
    {
        if((i%16) == 0)
            printf("\r\n");
        printf("%d ",buf[i] );
    }
    
    printf("\r\n");
}



/*******************************
 *2018.9.4
 *******************************/
void bubble_sort(int buf[], int n)
{
    int i, j, tmp;

    for(i = 0; i< n-1; i++)
    {
        for(j = 0; j < n-1-i; j++)
        {
            if(buf[j] > buf[j + 1])
            {
                tmp = buf[j];
                buf[j] = buf[j+1];
                buf[j+1] = tmp;
            }
        }
    }
}


/*******************************
 *2018.9.4
 *******************************/
void select_sort(int buf[], int len)
{
    int i, j, mini, tmp;

    for(i = 0; i< len-1; i++)
    {
        mini = i;
        for(j = i+1; j < len; j++)
        {
            if(buf[j] < buf[mini])
            {
                mini = j;
            }
        }

        tmp = buf[i];
        buf[i] = buf[mini];
        buf[mini] = tmp;
    }
}


/*******************************
 *2018.9.4
 *******************************/
 


int main(int argc, char** argv) 
{
    int buf[] = {9,6,8,2,6,4,7,3,1,0};
    int len = sizeof(buf)/sizeof(*buf);

    //bubble_sort(buf, len);
    select_sort(buf, len);

    print_int_buf(buf, len);
    
    return 0;
}
