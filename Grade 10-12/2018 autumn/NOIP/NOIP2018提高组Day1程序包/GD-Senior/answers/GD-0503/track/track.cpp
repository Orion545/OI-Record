#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;
inline int read()
{
	int re=0; char ch=getchar();
	while(ch<'0' || ch>'9') ch=getchar();
	while(ch>='0' && ch<='9') re=re*10+(ch^48),ch=getchar();
	return re;
}
const int MAXN=5e4+10;
struct E{int x,y,z,next;}ed[MAXN*2]; int last[MAXN],len;
void ins(int x,int y,int z) { ed[++len]=(E){x,y,z,last[x]}; last[x]=len; }
int dis[MAXN],z[MAXN],ans;
bool v[MAXN],vis[MAXN];
queue<int> q;
void spfa(int s)
{
	memset(dis,0,sizeof(dis));
	memset(v,false,sizeof(v)); v[s]=true;
	memset(vis,false,sizeof(vis));
	q.push(s);
	while(!q.empty())
	{
		int x=q.front(); q.pop(); v[x]=false;
		for(int k=last[x];k;k=ed[k].next)
		{
			int y=ed[k].y;
			if(vis[k] || vis[k^1]) continue;
			if(dis[y]<dis[x]+ed[k].z)
			{
				dis[y]=dis[x]+ed[k].z;
				ans=max(ans,dis[y]);
				vis[k]=vis[k^1]=true;
				if(!v[y]) v[y]=true,q.push(y);
			}
		}
	}
}
bool cmp(int x,int y) { return x<y; }
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	int n=read(),m=read(),sum=0;
	memset(last,0,sizeof(last)); len=-1;
	for(int i=1;i<n;i++)
	{
		int x=read(),y=read(); z[i]=read();
		ins(x,y,z[i]); ins(y,x,z[i]); sum+=z[i];
	}
	if(m==1)
	{
		ans=0;
		for(int i=1;i<=n;i++) spfa(i);
		printf("%d\n",ans);
	}
	else
	{
		sort(z+1,z+n,cmp);
		if(m==n-1)
		{
			printf("%d\n",z[1]);
			return 0;
		}
		printf("%d\n",sum/m-1);
	}
	return 0;
}
