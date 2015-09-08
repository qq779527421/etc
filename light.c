/*************************************************************************
    > File Name: light.c
    > Author: Mr.qiao
    > Mail: qiao_fw@163.com
    > Created Time: 2015年07月16日 星期四 21时31分02秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int process(int total)
{
	int ret, i, j;
	int arr[total + 1];

	for(i = 0; i <= total; i++)
		arr[i] = 0;
	
	for(i = 1; i <= total; i++){
		for(j = 1; j <= i; j++){
			if(!(i % j)){
				arr[i] = !arr[i];
			}
		}
	}
	
	ret = 0;
	for(i = 1; i<= total; i++)
		ret += arr[i];

	return ret;
}


int main(int argc, char **argv)
{
	int total, remain;
	
	if(argc != 2){
		fprintf(stderr, "Usage: a.out 10\n");
		return -1;
	}

	total = atoi(argv[1]);
	remain = process(total);

	printf("total: %d\nremain: %d\n", total, remain);

	return 0;
}
