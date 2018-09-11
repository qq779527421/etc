#include <stdio.h>

int numJewelsInStones(char* J, char* S) 
{
    int num = 0;
    int count[50] = {0};

    while(*S != '\0')
    {
        count[*S - 'A']++;
        S++;
    }

    while(*J != '\0')
    {
        num += count[*J - 'A']++;
        J++;
    }

	return num;
}

int main()
{
    char *J = "aA";
    char *S = "aAbbbbbb";

    printf("%d\n", numJewelsInStones(J, S));

    return 0;
}