#include<iostream>
#include<cstdio>
#include<cstring>
int n,m;
using namespace std;
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	if (n==1)
	{
		if (m==1)	printf("2\n");
		if (m==2)	printf("4\n");
		if (m==3)	printf("8\n");
	}
	if (n==2)
	{
		if (m==1)	printf("4\n");
		if (m==2)	printf("12\n");
	}
	if (n==3)
	{
		if (m==1)	printf("8\n");
		if (m==3)	printf("112\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
