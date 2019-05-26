#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,p[100050],map[2500][2500],v[2500],ans=0;
string tape;
void dfs(int xx,int ll,int yy)
{
	if(xx==n)
	{
		if(ll==n&&yy<ans)ans=yy;
	}
	else
	{
		int tt=ll;
		if(v[xx]>=0)
		{
			for(int i=1;i<=map[xx][0];i++)
			{
				if(v[map[xx][i]]==0)
				{
					v[map[xx][i]]=xx+1;
					tt++;
				}
				if(v[map[xx][i]]==-1)
				{
					v[map[xx][i]]=-2;
					tt++;
				}	
			}
			if(v[xx]==0)tt++;
			v[xx]=1;
			dfs(xx+1,tt,yy+p[xx]);
			v[xx]=0;
			for(int i=1;i<=map[xx][0];i++)
			{
				if(v[map[xx][i]]==xx+1)
					v[map[xx][i]]=0;
				if(v[map[xx][i]]==-2)
					v[map[xx][i]]=-1;
			}
			
		}
		 dfs(xx+1,ll,yy);
	
	}
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	cin>>n>>m>>tape;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	for(int i=1;i<=n-1;i++)
	{
		int a,b;
		cin>>a>>b;
		map[a][++map[a][0]]=b;
		map[b][++map[b][0]]=a;
	}
	if(n<=10)
	{
		for(int i=1;i<=m;i++)
		{
			int a,x,b,y,t=0,u=0;
			ans=1000000009;
			cin>>a>>x>>b>>y;
			if(x==0)v[a]=-1;
			if(x==1)
			{
				v[a]=1;
				u+=p[a];
				for(int j=1;j<=map[a][0];j++)
				{
					v[map[a][j]]=a+1;
					t++;
				}
				t++;
			}
			if(y==0)v[b]=-1;
			if(y==1)
			{
				v[b]=1;
				u+=p[b];
				for(int j=1;j<=map[b][0];j++)
				{
					v[map[b][j]]=b+1;
					t++;
				}
				t++;
			}
			dfs(1,t,u);
			cout<<ans<<'\n';
		}
	}
	return 0;
}
