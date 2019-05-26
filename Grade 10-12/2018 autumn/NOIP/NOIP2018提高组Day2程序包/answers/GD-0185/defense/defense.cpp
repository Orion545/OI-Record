#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
string t;
int n,m,map[2001][2001],maxx;
int a,x,b,y,p[2001],v[2001];
void dfs(int x,int ans)
{
	if(x==n)
	{
		if(v[x]==0)
		ans+=p[x];
		if(ans<maxx)
			maxx=ans;
	}
	else
	{
		dfs(x+1,ans);
		if(v[x]==0)
		{
			for(int o=1;o<=n;o++)
			{
				if(map[x][o]==1)
					v[o]=1;
			}
			dfs(x+1,ans+p[x]);
		}
	}
	
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	cin>>n>>m>>t;
	int i,j,k;
	maxx=0;
	for(i=1;i<=n;i++)
	{
		cin>>p[i];
		maxx+=p[i];
	}
	
	for(i=1;i<n;i++)
	{
		cin>>x>>y;
		map[x][y]=1;
		map[y][x]=1;
	}
	j=maxx;
	while(m>=1)
	{
		cin>>a>>x>>b>>y;
		if(x==y&&map[a][b]==1)
			cout<<"-1"<<endl;
		else
		{
			for(i=1;i<=n;i++)
			v[i]=0;
			k=0;
			if(x==1)
				{
				for(i=1;i<=n;i++)
					if(map[a][i]==1)
						v[i]=1;
				k+=p[a];
			}
			else
			v[a]=1;
			if(y==1)
			{
				for(i=1;i<=n;i++)
					if(map[b][i]==1)
					v[i]=1;
						k+=p[b];
			}
			else
			v[b]=1;
			maxx=j;
			dfs(1,k);
			cout<<maxx<<endl;
		}	
		m--;
	}
	return 0;
}
