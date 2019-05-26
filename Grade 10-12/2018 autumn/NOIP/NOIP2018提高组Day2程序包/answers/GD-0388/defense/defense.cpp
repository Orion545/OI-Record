#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
const int N=300005,M=600005;
typedef long long ll;
int toit[M],next[M],head[N],tot;
int dep[N],cost[N],fa[N][21];
int lg[N];
int q[N],h,t,maxdep,n,m;
int p1,p2;
bool k1,k2,vis[N];
ll f[N][2],f2[N][2];
string strs;

void add(int x,int y)
{
	toit[++tot]=y;
	next[tot]=head[x];
	head[x]=tot;
}

void build(int now)
{
	for (int a=1;a<=lg[dep[now]];++a) fa[now][a]=fa[fa[now][a-1]][a-1];
	int result=0;
	for (int a=head[now];a;a=next[a])
	{
		int v=toit[a];
		if (fa[now][0]==v) continue;
		fa[v][0]=now;
		dep[v]=dep[now]+1;
		build(v);
		f[now][0]+=f[v][1];
		result+=min(f[v][0],f[v][1]);
	}
	f[now][1]=result+cost[now];
}

int getlca(int u,int v)
{
	if (dep[u]<dep[v]) swap(u,v);
	int delta=dep[u]-dep[v];
	for (int a=0;a<=lg[delta];++a)
	{
		if ((1<<a)&delta) u=fa[u][a];
	}
	if (u==v) return u;
	
	for (int a=lg[dep[u]];a>=0;--a)
	{
		if (fa[u][a]!=fa[v][a])
		{
			u=fa[u][a];v=fa[v][a];
		}
	}
	return fa[u][0];
}

ll dfs(int now,int col)
{
	//cout<<now<<endl;
	if (f2[now][col]) return f2[now][col];
	
	ll result=0;
	if (col) result+=cost[now];
	if (col==1)
	{
		for (int a=head[now];a;a=next[a])
		{
			int v=toit[a];
			if (v==fa[now][0]) continue;
			result+=min(dfs(v,0),dfs(v,1));
		}
		f2[now][col]=result;
	}
	else
	{
		for (int a=head[now];a;a=next[a])
		{
			int v=toit[a];
			if (v==fa[now][0]) continue;
			result+=dfs(v,1);
		}
		f2[now][col]=result;
	}
	return f2[now][col];
}


void dfs2(int u,int v)
{
	while (u!=v)
	{
		vis[u]=true;
		u=fa[u][0];
	}
}

int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	cin>>n>>m;
	cin>>strs;
	
	lg[0]=-1;
	for (int a=1;a<=n;++a) lg[a]=lg[a>>1]+1;
	for (int a=1;a<=n;++a) cin>>cost[a];
	for (int a=1;a<n;++a)
	{
		int x,y;
		cin>>x>>y;
		add(x,y);add(y,x);
	}
	build(1);
	//for (int a=1;a<=n;++a) cout<<f[a][0]<<" "<<f[a][1]<<endl;
	//cout<<"\n\n";
	
	//cout<<"*"<<endl;
	while (m--)
	{
		int u,v,k1,k2;
		memset(f2,0,sizeof(f2));
		cin>>u>>k1>>v>>k2;
		if (k1==k2&&k1==0)
		{
			bool k=false;
			for (int a=head[u];a;a=next[a]) if (toit[a]==v) 
			{
				cout<<"-1"<<endl;
				k=true;
			}
			if (k) continue;
		}
		p1=u;p2=v;
		f2[p1][1-k1]=f2[p2][1-k2]=1e15;
		vis[1]=true;
		dfs2(p1,1);dfs2(p2,1);
		for (int a=1;a<=n;++a) if(!vis[a])
		{
			f2[a][1]=f[a][1];
			f2[a][0]=f[a][0];
		}
		if (p1==1)
		{
			cout<<dfs(1,k1)<<endl;
		}
		else if (p2==1)
		{
			cout<<dfs(1,k2)<<endl;
		}
		else
		{
			cout<<min(dfs(1,1),dfs(1,0))<<endl;
		}
	}
	
	
	fclose(stdin);fclose(stdout);return 0;
}
