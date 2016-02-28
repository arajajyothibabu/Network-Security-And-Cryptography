#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#pragma warning(disable:4996)
int fmea(int a, int b, int n)
{
	int f=1,t=a;
	while(b>0)
	{
		if(b%2 == 1)
			f = (f*t)%n;
		t = (t * t)%n;
		b = b/2;		//b = b >> 1; 
	}
	return f;
}

void main()
{
	int a,b,n;
	printf("Enter a b n in order: ");
	scanf("%d%d%d",&a,&b,&n);
	printf("%d^%d mod %d = %d",a,b,n,fmea(a,b,n));
	getche();
}