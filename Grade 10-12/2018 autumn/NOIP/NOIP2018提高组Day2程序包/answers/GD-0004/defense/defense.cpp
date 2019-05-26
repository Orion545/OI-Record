#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

int n,m,i,j,p[11],Edge[11][11],so[12],ans[12];
string c;

int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	
	cin>>n>>m;
	cin>>c;
	int u,v,a,x,b,y;
	for(i=1;i<=n;i++) scanf("%d",&p[i]);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&u,&v);
		Edge[u][v]=1;
	}
	for(i=1;i<=m;i++)
	{
		scanf("%d%d%d%d",&a,&x,&b,&y);
		memset(so,0,sizeof(so));
		memset(ans,0,sizeof(ans));
		if(x) so[a]=3;
		else so[a]=2;
		if(y) so[b]=3;
		else so[b]=2;
		for(j=1;j<=n;j++)
		{
			if(so[j-1]==3||so[j+1]==3) continue;
			if(so[j]==3)
			{
				ans[j]+=p[j];
				continue;
			}
			if(j>1)
			{
				if(so[j-2])so[j]=1;
				else so[j]=0;
				if(so[j]==1)ans[j]+=p[j];
			}
		}
	}
	cout<<ans[n];
	return 0;
}
