#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#pragma warning(disable:4996)
int pow(int a,int b)
{
	int i,k=1;
	for(i=0;i<b;i++)
		k *= a;
	return k;
}
int fmea(int a, int b, int n)
{
	int f=1,t=a;
	while(b>0)
	{
		if(b%2 == 1) f = (f*t)%n;
		t = (t * t)%n;
		b = b/2;		//b = b >> 1; 
	}
	return f;
}
char *test(int n,int a)
{
	int k=0,j,q = n-1;
	while(q%2 == 0)
	{
		k++; 
		q = q/2;
	}
	printf("%d-%d\n",k,q);
	if(fmea(a,q,n) == 1) return "Inconclusive";
	for(j=0;j<k;j++)
		if(fmea(a,pow(2,j)*q,n) == n-1) return "Inconclusive";
	return "Composite";
}
void main()
{
	int n,a;
	printf("Enter n & a: ");
	scanf("%d%d",&n,&a);
	printf("%s",test(n,a));
	getche();
}