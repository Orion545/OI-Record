#include<bits/stdc++.h>
#define LL long long
using namespace std;

LL p[100001],f[100001][2];

LL read()
{
	LL num=0; int f=1;
	char ch=getchar();
	while(!isdigit(ch))
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch))
	{
		num=num*10+ch-'0';
		ch=getchar();
	}
	return num*f;
}

int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	int n=read(),m=read();
	int t=read();
	for(int i=1;i<=n;i++) p[i]=read();
	for(int i=1;i<n;i++) int x=read(),y=read();
	for(int i=1;i<=m;i++)
	{
		int a=read(),x=read(),b=read(),y=read();
		if((a==b-1 || b==a-1) && !(x^y))
		{
			printf("-1\n"); continue;
		}
		f[0][0]=0; f[0][1]=0;
		for(int j=1;j<=n;j++)
		{
			f[j][0]=f[j-1][1];
			f[j][1]=min(f[j-1][0],f[j-1][1])+p[j];
			if(j==a && !x) f[j][1]=0X3f3f3f3f;
			if(j==a && x) f[j][0]=0X3f3f3f3f;
			if(j==b && !y) f[j][1]=0X3f3f3f3f;
			if(j==b && y) f[j][0]=0X3f3f3f3f;
		}
		printf("%lld\n",min(f[n][0],f[n][1]));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
