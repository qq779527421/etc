#include <stdio.h>

int main(int argc, char **argv)
{
    char buf[8];
    FILE *fp = NULL;
    
    if(argc != 2 )
    {
        printf("Usage: %s file\n", argv[0]);
        return 0;
    }

    fp = fopen(argv[1], "r");

    printf("%s\n", fgets(buf, sizeof(buf), fp));

    fclose(fp);

    return 0;
}
