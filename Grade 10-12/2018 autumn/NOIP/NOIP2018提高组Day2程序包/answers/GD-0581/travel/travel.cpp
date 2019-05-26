#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
inline char get_c()
{
	static char buf[1<<14],*p1=buf,*p2=buf;
	return (p1==p2)&&(p2=(p1=buf)+fread(buf,1,1<<14,stdin),p1==p2)?EOF:*p1++;
}
int read()
{
	int f=1,k=0;char c=get_c();
	while(c<'0'||c>'9') c=='-'&&(f=-1),c=get_c();
	while(c>='0'&&c<='9') k=k*10+c-'0',c=get_c();
	return k*f;
}
struct Edge{int ot,nex;}_edge[100100];
int n,m,head[5110],num,a[5110],cnt,now[5110],ans[5110],ret,id[100010][2];
bool vis[5110];
vector<int> q[5110];
void add(int u,int v)
{
	_edge[++num].ot=v;
	_edge[num].nex=head[u];
	head[u]=num; id[num][0]=u; id[num][1]=v;
}
bool dfs(int x,int fa)
{
	vis[x]=true;
	for(int i=head[x];i;i=_edge[i].nex)
	{
		int v=_edge[i].ot;
		if (v==fa) continue;
		if (vis[v]){a[++cnt]=i; return true;}
		if (dfs(v,x)) {a[++cnt]=i; return true;}
	}
	return false;
}
void dfs2(int x,int fa,int idx,int idy)
{
	now[++ret]=x;
	for(int i=head[x];i;i=_edge[i].nex)
	{
		int v=_edge[i].ot;
		if (v==fa||(x==idx&&v==idy)||(v==idx&&x==idy)) continue;
		dfs2(v,x,idx,idy);
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int x,y; bool zx;
	n=read(); m=read();
	for(int i=1;i<=m;i++)
	{
		x=read(); y=read();
		q[x].push_back(y); q[y].push_back(x);
	}
	for(int i=1;i<=n;i++) sort(q[i].begin(),q[i].end());
	for(int i=1;i<=n;i++)
	for(int j=q[i].size()-1;j>=0;j--) add(i,q[i][j]);
	cnt=0; zx=dfs(1,0); memset(ans,0x3f,sizeof(ans));
	if (zx)
	{
		for(int i=1;i<=cnt;i++)
		{
			ret=0; dfs2(1,0,id[a[i]][0],id[a[i]][1]);
			for(int j=1;j<=n;j++)
			{
				if (now[j]>ans[j]) break;
				if (now[j]<ans[j]){for(int k=1;k<=n;k++) ans[k]=now[k]; break;}
			}
		}		
	}
	else{ret=0; dfs2(1,0,0,0); for(int i=1;i<=n;i++) ans[i]=now[i];}
	for(int i=1;i<=n;i++) printf("%d ",ans[i]);
	return 0;
}
