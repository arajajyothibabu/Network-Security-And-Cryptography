#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#pragma warning(disable:4996)
int *left_Circular_Shift(int *a,int start,int end,int n)
{
	int i,j,k;
	for(i=0;i<n;i++)
	{
		k = a[start];
		for(j=start;j<end-1;j++)
			a[j] = a[j+1];
		a[j] = k;
	}
	return a;
}
int *F(int *xorEP)
{
	int i, j=0, x, *intrP4 = (int *)malloc(4*sizeof(int)), s0[4][4] = {{1,0,3,2},{3,2,1,0},{0,2,1,3},{3,1,3,2}}, s1[4][4] = {{0,1,2,3},{2,0,1,3},{3,0,1,0},{2,1,0,3}};	//fixed values
	for(i=0;i<5;i=i+4)
	{
		x = i==0?s0[2*xorEP[i]+xorEP[i+3]][2*xorEP[i+1]+xorEP[i+2]]:s1[2*xorEP[i]+xorEP[i+3]][2*xorEP[i+1]+xorEP[i+2]];
		intrP4[j++]=x/2;
		intrP4[j++]=x%2;
	}
	return intrP4;
}
int *fk(int *input, int *key)
{
	int i, *intrP4 = (int *)malloc(4*sizeof(int)), *EP = (int *)malloc(8*sizeof(int)), ep[8] = {4,1,2,3,2,3,4,1}, p4[4] = {2,4,3,1};
	for(i=0;i<8;i++)
		EP[i]=input[ep[i]+3] ^ key[i];   //Expansion Permutation and XOR with Key
	intrP4 = F(EP);        // Call for Matrix Values(s0, s1)
	for(i=0;i<4;i++)
		input[i] = input[i] ^ intrP4[p4[i]-1];     //XOR with Matrix Values(s0, s1)
	return input;
}
void main()
{
	int i, p10[10] = {3,5,2,7,4,10,1,9,8,6}, p8[8] = {6,3,7,4,8,5,10,9},ip[8] = {2,6,3,1,4,8,5,7}, ip1[8] = {4,1,3,5,7,2,8,6};			//fixed values
	int *IP = (int *)malloc(8*sizeof(int)), *IP1 = (int *)malloc(8*sizeof(int)), *key1 = (int *)malloc(8*sizeof(int)), *key2 = (int *)malloc(8*sizeof(int)), *plain = (int *)malloc(8*sizeof(int)), *input = (int *)malloc(10*sizeof(int)), *intr10 = (int *)malloc(10*sizeof(int));
	//S_DES key generation***********************************************************//key generation input: {1,0,1,0,0,0,0,0,1,0};			
	printf("Enter Key Generation Input(10 bit): ");
	for(i=0;i<10;i++)
		scanf("%d",&input[i]);
	for(i=0;i<10;i++)
		intr10[i] = input[p10[i]-1];
	intr10 = left_Circular_Shift(intr10,0,5,1);		//left_Circular_Shift by one bit
	intr10 = left_Circular_Shift(intr10,5,10,1);	//left_Circular_Shift by one bit
	for(i=0;i<8;i++)							
		key1[i] = intr10[p8[i]-1];				//key1
	intr10 = left_Circular_Shift(intr10,0,5,2);			//left_Circular_Shift by two bits
	intr10 = left_Circular_Shift(intr10,5,10,2);		//left_Circular_Shift by two bits
	for(i=0;i<8;i++)							
		key2[i] = intr10[p8[i]-1];				//key2
	// S_DES Encryption**************************************************************
	printf("Enter Plain Text(8 bit): ");
	for(i=0;i<8;i++)
		scanf("%d",&plain[i]);		//read plain text {1,0,1,1,1,1,0,1}
	for(i=0;i<8;i++)
		IP[i] = plain[ip[i]-1];			//Initial Permutaion
	IP = fk(IP,key1);					// first call to fk function;
	for(int i=0;i<4;i++)
	{
		int x = IP[i];				//*********//
		IP[i] = IP[i+4];			//SWAPING	//
		IP[i+4] = x;				//**********//
	}
	IP = fk(IP,key2);			//second call to fk function
	printf("Encrypted Text: ");
	for(i=0;i<8;i++)
		printf("%d ",IP[ip1[i]-1]);		//Inverse Initial Permutation
	getche();
}