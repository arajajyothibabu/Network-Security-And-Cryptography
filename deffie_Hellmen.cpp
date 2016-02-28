#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#pragma warning (disable:4996)

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

void deffie_Hellmen(int Xa,int Xb,int a,int q)
{
	int Ya,Yb,k1,k2;
	Ya = fmea(a,Xa,q);
	Yb = fmea(a,Xb,q);
	k1 = fmea(Yb,Xa,q);
	k2 = fmea(Ya,Xb,q);
	if (k1 == k2)
		printf("Successful. And key is %d",k1);
	else printf("Keys not matched..!");
}

void main()
{
	int Xa,Xb,q,a;
	printf("Enter Xa,Xb,a,q in order: ");
		scanf("%d%d%d%d",&Xa,&Xb,&a,&q);
	deffie_Hellmen(Xa,Xb,a,q);
	getche();
}