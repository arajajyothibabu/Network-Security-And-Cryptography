#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#pragma warning(disable:4996)
int inverse(int a)
{
	int i;
	for(i=0;i<26;i++)
	{
		if((a*i)%26==1)
			return i;
	}
	return 0;
}

int len(char *s)
{
	int i=0;
	for(i=0;s[i]!='\0';i++){}
	return i;
}

char *encrypt(int k[2][2],char *s)
{
	int i,j,l=len(s);
	char *t = (char *)malloc(sizeof(char));
	if(l % 2 != 0)
	{
		s[l] = 'X';
		s[l+1] = '\0';
		t[l+1] = '\0';
	}
	else
		t[l] = '\0';
	for(i = 0;s[i]!='\0';i=i+2)
	{
		t[i] = (k[0][0] * (s[i]-'A') + k[0][1] * (s[i+1]-'A'))%26+'A';
		t[i+1] = (k[1][0] * (s[i]-'A') + k[1][1] * (s[i+1]-'A'))%26+'A';
	}
	return t;
}

char *decrypt(int k[2][2],char *s)
{
	int i,j,d = inverse(k[0][0] * k[1][1] - k[0][1] * k[1][0]);
	char *t = (char *)malloc(sizeof(char));
	if(d == 0)
		return "Invalid Key Matrix..!";
	for(i = 0;s[i]!='\0';i=i+2)
	{
		t[i] = (d * (k[1][1] * (s[i]-'A') + -k[0][1] * (s[i+1]-'A'))%26+26)%26+'A';
		t[i+1] = (d * (-k[1][0] * (s[i]-'A') + k[0][0] * (s[i+1]-'A'))%26+26)%26+'A';
	}
	t[i] = '\0';
	return t;
}

void main()
{
	int i,j,k[2][2];
	char *input;
	input=(char*)malloc(sizeof(char));
	printf("Enter key matrix with 2*2\n");
	for(i=0;i<2;i++)
		for(j=0;j<2;j++)
			scanf("%d",&k[i][j]);
	printf("Enter plain text");
	scanf("%s",input);
	printf("Encrypted Text: %s\n",encrypt(k,input));
	printf("Decrypted Text: %s",decrypt(k,encrypt(k,input)));
	getche();
}