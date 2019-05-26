#include <cstdio>
#include <iostream>

using namespace std;

#define int long long
#define INF 10000000005LL

struct EDGE
{
	int t,n;
} edge[200005];

int n,m,p[100005],f[100005][2],faz[100005],dep[100005],
	cur,last[100005];
bool leaf[100005],failed;
char type[5];

void AddEdge(int u,int v)
{
	++cur;
	edge[cur].t=v;
	edge[cur].n=last[u];
	last[u]=cur;
}

void DFS(int u)
{
	f[u][1]=p[u],f[u][0]=0;
	int Min=INF,MinSon=0;
	bool ok=false,nosons=true;
	for (int tmp=last[u];tmp;tmp=edge[tmp].n)
	{
		int v=edge[tmp].t;
		if (v==faz[u]) continue;
		faz[v]=u; dep[v]=dep[u]+1;
		DFS(v);
		nosons=false;
		
		f[u][1]+=min(f[v][0],f[v][1]);
		
		if (leaf[v]) f[u][0]+=f[v][1],ok=true; else
			if (f[v][1]<=f[v][0]) f[u][0]+=f[v][1],ok=true;
				else f[u][0]+=f[v][0];
		
		if (f[v][1]<Min)
		{
			Min=f[v][1];
			MinSon=v;
		}
	}
	if (nosons)
	{
		leaf[u]=true;
		return;
	}
	if (ok) return;
	f[u][0]=f[u][0]-f[MinSon][0]+f[MinSon][1];
	return;
}

void Update(int u,int sign)
{
	if (f[u][1]<INF || sign==2) f[u][1]=p[u];
	if (f[u][0]<INF || sign==2) f[u][0]=0;
	if (leaf[u]) return;
	
	int Min=INF,MinSon=0;
	bool ok=false;
	for (int tmp=last[u];tmp;tmp=edge[tmp].n)
	{
		int v=edge[tmp].t;
		if (v==faz[u]) continue;
		
		if (min(f[v][0],f[v][1])>=INF)
		{
			failed=true;
			return;
		}
		
		f[u][1]+=min(f[v][0],f[v][1]);
		
		if (leaf[v]) f[u][0]+=f[v][1],ok=true; else
			if (f[v][1]<=f[v][0]) f[u][0]+=f[v][1],ok=true;
				else f[u][0]+=f[v][0];
		
		if (f[v][1]<Min)
		{
			Min=f[v][1];
			MinSon=v;
		}
	}
	if (f[u][0]>INF) f[u][0]=INF;
	if (f[u][1]>INF) f[u][1]=INF;
	if (ok) return;
	if (Min==INF) f[u][0]=INF;
		else f[u][0]=f[u][0]-f[MinSon][0]+f[MinSon][1];
	return;
}

void WORK(int x,int sign)
{
	if (sign==0) f[x][1]=INF;
	if (sign==1) f[x][0]=INF;
	if (sign==2) Update(x,sign);
	x=faz[x];
	while (x)
	{
		int last0=f[x][0],last1=f[x][1];
		Update(x,sign);
		if (failed || f[x][0]==last0 && f[x][1]==last1) break;
		x=faz[x];
	}
	return;
}

signed main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	
	scanf("%lld%lld%s",&n,&m,type);
	
	for (int i=1;i<=n;i++) cin >> p[i];
	
	for (int i=1,u,v;i<n;i++)
	{
		scanf("%lld%lld",&u,&v);
		AddEdge(u,v),AddEdge(v,u);
	}
	
	DFS(1);
	
	for (int i=1;i<=m;i++)
	{
		int a,b,x,y;
		scanf("%lld%lld%lld%lld",&a,&x,&b,&y);
		
		if (dep[a]<dep[b]) {int t=a;a=b;b=t;}
		
		failed=false;
		WORK(a,x);
		WORK(b,y);

		if (failed || min(f[1][1],f[1][0])>=INF) printf("-1\n");
			else printf("%lld\n",min(f[1][1],f[1][0]));
		
		failed=false;
		
		WORK(a,2);
		WORK(b,2);
	}
	
	return 0;
}
