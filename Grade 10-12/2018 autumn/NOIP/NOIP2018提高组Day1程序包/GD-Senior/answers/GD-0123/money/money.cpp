#include<bits/stdc++.h>
#define LL long long
using namespace std;

int cnt=0,b[2501],a[2501];

LL read()
{
	LL num=0;
	int f=1;
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

bool cmp(int a,int b)
{
	return a<b;
}

bool check(int x,int y)
{
	if(x%b[y]==0) return 0;
	if(y==cnt) return 1;
	for(int i=0;i<=x/b[y];i++)
	{
		int q=check(x-b[y]*i,y+1);
		if(!q) return 0;
	}
	return 1;
}

int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int t=read();
	for(;t>0;t--)
	{
		int n=read();
		for(int i=1;i<=n;i++) a[i]=read();
		sort(a+1,a+n+1,cmp);
		cnt=1; b[1]=a[1];
		for(int i=2;i<=n;i++)
		if(check(a[i],1)) b[++cnt]=a[i];
		printf("%d\n",cnt);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
