#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int map[5000][5000]={0},n,m,k=0,v[5000]={0};
priority_queue <int> q;
priority_queue <int> p;
void dfs(int x,int y)
{
	bool vv=true;
	for(int i=1;i<=n;i++)
	{
		if(map[x][i]>0&&v[i]==0)
		{
			vv=false;
			v[i]=1;
			dfs(i,y+map[x][i]);
			v[i]=0;
		}
	}
	if(vv)
		q.push(y);
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n-1;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		map[a][b]=c;
		map[b][a]=c;
	}
	for(int i=1;i<=n;i++)
	{
		v[i]=1;
		dfs(i,0);
		v[i]=0;
		k=0;
		while(!q.empty())
		{
			k++;
			if(k==m)
			{
				int u=q.top();
				p.push(u);	
			}
			q.pop(); 
		}
	}
	cout<<p.top();
	return 0;
}
