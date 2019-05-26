#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#define INF 100000
#define N 100
using namespace std;
int g[N][N],n,m,sum=0,maxsum=0,ans=0;
bool vst[N];
bool isok(int po)
{
	bool fg=0;
	for(int i=1;i<=n;i++)
		if(g[po][i]!=0&&vst[i]==0)
			fg=1;
	if(fg==1)
		return false;
	else
		return true;
}
void dfs(int po)
{
	if(isok(po))
	{
		if(sum>maxsum)
			maxsum=sum;
	}
	for(int i=1;i<=n;i++)
	{
		if(g[po][i]!=0&&vst[i]==0)
		{
			sum+=g[po][i];
			vst[i]=1;
			dfs(i);
			vst[i]=0;
			sum-=g[po][i];
		}
	}
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	int u,v,l;
	cin>>n>>m;
	memset(g,0,sizeof(g));
	for(int i=1;i<n;i++)
	{
		cin>>u>>v>>l;
		g[u][v]=l;
	}
	for(int q=1;q<=n;q++)
	{
		memset(vst,0,sizeof(vst));
		sum=maxsum=0;
		vst[q]=1;
		dfs(q);
		if(maxsum>ans)
			ans=maxsum;
	}
	cout<<ans<<endl;
	return 0;
}
