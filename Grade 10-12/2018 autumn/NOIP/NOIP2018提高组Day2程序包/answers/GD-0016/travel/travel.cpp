#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cctype>
#include<queue>
#include<string>
using namespace std;
int n,m;
int read();
bool bod[5005][5005];
int vis[5005]={0};
int a[5005],ans[5005];
int dfs1(int x);
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    n=read();m=read();
    for(int i=0;i<m;i++)
    {
    	int x=read(),y=read();
    	bod[x][y]=1;
    	bod[y][x]=1;
    }
    vis[1]=1;
    a[0]=1;
    ans[0]=9;
    if(m==n-1)
    {
    	cout<<"1 ";
    	dfs1(1);
    }
	fclose(stdin);fclose(stdout);
}
int read()
{
	char ch=getchar();int x=0,f=1;
	while(!isdigit(ch))
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch))
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int dfs1(int x)
{
	for(int i=1;i<=n;i++)
	{
		if(bod[x][i]==1&&vis[i]==0)
		{
			cout<<i<<" ";
			vis[i]=1;
			dfs1(i);
		}
	}
	return 0;
}
