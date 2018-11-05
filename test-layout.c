#include <stdio.h>


char *g_ptr = "char *g_ptr";
const char *g_c_ptr = "const char *g_c_ptr";
const char g_c_buf[] = "const char g_c_buf[]";
char g_buf[] = "char g_buf[]";



int main()
{

    char l_buf[] = "static char l_buf[]";
    static char l_s_buf[] = "static char l_buf[]";
    const char l_c_buf[] = "const char l_c_buf[]";
    const char *l_c_ptr = "const char *l_c_ptr";

    printf("%p : %s\n", &main, "main()");

    printf("\n");

    printf("%p : %s \n", g_ptr, g_ptr);    
    printf("%p : %s \n", g_c_ptr, g_c_ptr);    
    printf("%p : %s \n", g_c_buf, g_c_buf);
    printf("%p : %s \n", g_buf, g_buf);    

    printf("\n");

    printf("%p : %s \n", l_buf, l_buf);
    printf("%p : %s \n", l_s_buf, l_s_buf);
    printf("%p : %s \n", l_c_buf, l_c_buf);
    printf("%p : %s \n", l_c_ptr, l_c_ptr);

    return 0;
}
