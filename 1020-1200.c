/*************************************************************************
    > File Name: 102-120.c
    > Author: Mr.qiao
    > Mail: qiao_fw@163.com
    > Created Time: 2015年07月19日 星期日 23时16分14秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char arr[] = "0102030405060";
	int i,j;

	printf("%s\n", arr);

	for(i = 0, j = 0; i < strlen(arr); i++){
		if('0' != arr[i])
			arr[j++] = arr[i];
		arr[i] = '0';
	}

	printf("%s\n", arr);

	return 0;
}
