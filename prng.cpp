#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#pragma warning (disable:4996)
void main()
{
	int m,a,c,x,key,flag = 0,count=0,x0;
	printf("Enter m a c x in order: ");
	scanf("%d%d%d%d",&m,&a,&c,&x0);
	x = (a * x0 + c) % m;
	printf("%d ",x);
	key = x;
	while(x<m)
	{
		x = (a * x + c) % m;
		if(key == x)
				break;
		printf("%d ",x);
		count++;
	}
	printf("\nPeriod: %d",count+1);
	getche();
}