#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

int Edge[5001][5001];
int b,n,m,length,mi=9999999,ans[25001],s[25001],v[5001];

void dfs(int x)
{
	for(int k=1;k<=n;k++)
	{
		if(Edge[x][k]&&!v[k])
		{
			v[k]=1;
			ans[length++]=k;
			dfs(k);
			if(b!=0) ans[length++]=x;
			else
			{
				if(length<mi)
				{
					for(int j=0;j<mi;j++) s[j]=ans[j];
					mi=length;
				}
			}
		}
	}
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	int u,v,i,j;
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&u,&v);
		Edge[u][v]=1;
	}
	for(i=1;i<=n;i++)
	{
		b=n; length=0;
		dfs(i);
	}
	for(i=mi;i>=0;i--) cout<<ans[i]<<" ";
	
	return 0;
}
