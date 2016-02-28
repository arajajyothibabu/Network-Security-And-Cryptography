#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#pragma warning(disable:4996)
int *left_Circular_Shift(int *a,int start,int end,int n)
{
	int i,j,k;
	int *intarr=(int *)malloc(n*sizeof(int));
	for(i=0,k=start;i<n;i++,k++)
		intarr[i]=a[k];
	for(i=start;i<end-n;i++)
		a[i] = a[i+n];
	for(k=0;k<n;k++)
		a[i++] = intarr[k];
	return a;
}

void main()
{
	
	int p10[10] = {3,5,2,7,4,10,1,9,8,6};
	int p8[8] = {6,3,7,4,8,5,10,9};
	int i,*input = (int *)malloc(10*sizeof(int));
	int *intr10 = (int *)malloc(10*sizeof(int));
	int *intr8 = (int *)malloc(8*sizeof(int));
	printf("Enter 10bit key: ");
	for(i=0;i<10;i++)
		scanf("%d",&input[i]);
	for(i=0;i<10;i++)
		intr10[i] = input[p10[i]-1];
	intr10 = left_Circular_Shift(intr10,0,5,1);
	intr10 = left_Circular_Shift(intr10,5,10,1);
	for(i=0;i<8;i++)
		intr8[i] = intr10[p8[i]-1];
	printf("Key_1 is: ");
	for(i=0;i<8;i++)
		printf("%d",intr8[i]);
	intr10 = left_Circular_Shift(intr10,0,5,2);
	intr10 = left_Circular_Shift(intr10,5,10,2);
	for(i=0;i<8;i++)
		intr8[i] = intr10[p8[i]-1];
	printf("\n\nKey_2 is: ");
	for(i=0;i<8;i++)
		printf("%d",intr8[i]);
	getche();
}