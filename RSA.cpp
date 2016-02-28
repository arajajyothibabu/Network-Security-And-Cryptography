#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

int abs(int x)
{
	return x>=0? x:-x;
}
int gcd(int a, int b)
{
	int x=abs(a),y=abs(b),m = x>y?x:y,n = x>y?y:x;
	return n==0?m:gcd(n,m%n);
}
/*int extended_Euclid(int m,int b)
{
	int A[3] = {1,0,m},B[3] = {0,1,b},gcd,e_inv,T[3];
	while(B[2]!=0 && B[2]!=1)
	{
		if(B[2] == 0)
			gcd = A[2];
		if(B[2] == 1)
			{
				gcd = B[2];
				e_inv = B[1];
			}
		q = A[2]%B[3];
		for(int i=0;i<3;i++)
		{
			T[i] = A[i]-q*B[i];
			A[i] = B[i];
			B[i] = T[i];
		}
	}
	return 0;
}*/
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
int generate_e(int Q_n)
{
	for(int i = 2;i<Q_n;i++)
		if(gcd(Q_n,i) == 1)
			return i;
	return 0;
}
int eval_d(int e,int Q_n)
{
	for(int i=1;i<Q_n;i++)
		if(fmea(i*e,1,Q_n)==1)
			return i;
	return 0;
}
int rsa_ENC(int p,int q,int M)
{
	int n = p * q,Q_n = (p-1)*(q-1),e = generate_e(Q_n);
	return fmea(M,e,n);
}
int rsa_DEC(int p,int q,int C)
{
	int n = p * q,Q_n = (p-1)*(q-1),e = generate_e(Q_n),d = eval_d(e,Q_n);
	return fmea(C,d,n);
}
void main()
{
	int p,q,M,C;
	printf("Enter p & q and Plain_Text: ");
	scanf("%d%d%d",&p,&q,&M);
	int a[3]={1,2,3};
	C = rsa_ENC(p,q,M);
	printf("Cipher Text: %d",C);
	if(M == rsa_DEC(p,q,C))
		printf("\nSuccessful..!");
	getche();
}