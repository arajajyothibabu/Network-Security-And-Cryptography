#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#pragma warning (disable:4996)
int abs(int x)
{
	return x>=0? x:-x;
}

int gcd(int a, int b)
{
	int x=abs(a),y=abs(b),m,n;
	m = x>y?x:y;
	n = x>y?y:x;
	if(n==0) return m;
	else return gcd(n,m%n);
}

void main()
{
	int i,x, *input = (int *)malloc(10*sizeof(int));
	printf("Enter Array: ");
	for(i=0;i<10;i++)
		scanf("%d",&input[i]);
	x = input[0];
	for(i=1;i<10;i++)
		x = gcd(x,input[i]);
	printf("GCD: %d",x);
	getche();
}