/*************************************************************************
    > File Name: abc.c
    > Author: Mr.qiao
    > Mail: qiao_fw@163.com
    > Created Time: 2015年07月16日 星期四 22时25分34秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
	int cnt['z' - 'a' + 1];
	int i;

	if(argc != 2){
		fprintf(stderr, "Usage: a.out abcdse\n");
		return -1;
	}

	printf("sizeof(argv[1]) = %d\n", sizeof(argv[1]));
	printf("strlen(argv[1]) = %d\n", strlen(argv[1]));

	for(i = 'a'; i <= 'z'; i++)
		cnt[i - 'a'] = 0;

	for(i = 0; i < strlen(argv[1]); i++)
		cnt[argv[1][i] - 'a']++;
	

	for(i = 'a'; i <= 'z'; i++)
		printf("%c: %d\n", i, cnt[i - 'a']);

	return 0;
}
