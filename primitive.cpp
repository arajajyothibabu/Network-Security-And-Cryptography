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
	return n==0? m:gcd(n,m%n);
}

int Q_(int n) //Euler's Totient Function
{
	int i,c = 0;
	for(i=1;i<n;i++)
		if(gcd(n,i) == 1)
			c++;
	return c;
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

int primitive_Roots(int n,int *out)
{
	int i,flag,j,c,k=0,a,r = Q_(n);
	for(i=1;i<n;i++)
	{
		a = i;
		c = 1;
		flag = fmea(a,r,n);
		j=r-1;
		while(j>0 && flag == 1)
		{
			if(fmea(a,j,n) == flag)
				break;
			c++;
			j--;
		}
		if(c == r)
			out[k++] = i;
	}
	return k;
}

void main()
{
	int i,n,l,*a=(int *)malloc(sizeof(int));
	printf("Enter n: ");
		scanf("%d",&n);
		l = primitive_Roots(n,a);
	if(l!=0)
		for(i=0;i<l;i++)
			printf("%d ",a[i]);
	else
		printf("No Primitive Roots..!");
	getche();
}