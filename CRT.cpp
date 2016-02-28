#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#pragma warning(disable:4996)
int fmea(int a, int b, int n)
{
	int f=1,t=a;
	while(b>0)
	{
		f = b%2 == 1?(f*t)%n:f;
		t = (t * t)%n;
		b = b/2;		//b = b >> 1; 
	}
	return f;
}
int factorsOf(int M,int *a)
{
	int i=2,j=0,x=M,k=0,flagin = 0;
	/*while(x%2==0) {x /= 2;}
	if(x!=0 && x!=M) a[j++]=M/x;*/
	while(x!=0 && x != 1)
		for(i=2;i<=x;i++)
			if(x%i==0)
			{
				for(k=0;k<j;k++)
					if(a[k]==i || a[k]%i == 0)
					{
						flagin = 1;
						break;
					}
				if(flagin) a[j-1] = i * a[k];
				else a[j++] = i;
				x /= i;
				flagin = 0;
				break;
			}
	return j;
}
int inverseOf(int M,int m)
{
	for(int i=1;i<m;i++)
		if(fmea(i*M,1,m)==1)
			return i;
	return 0;
}
int CRT(int x,int y, int M)
{
	int i,j,sum=0,*m=(int *)malloc(sizeof(int));
	for(i=0;i<factorsOf(M,m);i++)
		sum += (M/m[i] * (inverseOf(M/m[i],m[i]))) * fmea(x,y,m[i]);
	return sum % M;
}
void main()
{
	int x,y,M;
	printf("Enter x & y and Modulus: ");
	scanf("%d%d%d",&x,&y,&M);
	printf("Mod Value: %d",CRT(x,y,M));
	getche();
}