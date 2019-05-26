#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100009,
		  MAXM = MAXN*2;
const long long INF = 200000000009ll;

int _head[MAXN],_next[MAXM],_node[MAXM];
int d[MAXN];
int val[MAXN];
long long f[MAXN][2];
int fp=0,n,m,k;
bool mustnt;

void _connect(int a,int b)
{
	_next[fp]=_head[a];
	_node[fp]=b;
	_head[a]=fp++;
	return ;
}

void dfs(int u,int fa)
{
	int v;
	for (int i=_head[u];~i;i=_next[i])
	{
		v=_node[i];
		if (v==fa)
			continue;
		dfs(v,u);
	}
	mustnt=0;
	for (int i=_head[u];~i;i=_next[i])
	{
		v=_node[i];
		if (v==fa)
			continue;
		if (d[v]==0)
			mustnt=1;
	}
	f[u][1]=val[u];
	f[u][0]=0;
	for (int i=_head[u];~i;i=_next[i])
	{
		v=_node[i];
		if (v==fa)
			continue;
		f[u][0]+=f[v][1];
		if (d[v]==1)
			f[u][1]+=f[v][1];
		else
			f[u][1]+=min(f[v][0],f[v][1]);
	}
	f[u][1]=min(f[u][1],INF);
	f[u][0]=min(f[u][0],INF);
	if (d[u]==0)
		f[u][1]=INF;
//	cerr << "%% " << u << " " << f[u][0] << ' ' << f[u][1] << '\n'; 
	return ;
}

int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	memset(_head,-1,sizeof _head);
	memset(d,-1,sizeof d);
	int x,y,Type;
	char c;
	int p[2],q[2];
	scanf("%d%d",&n,&m);
	do {c=getchar();}
		while (c<'A' || c>'C');
	scanf("%d",&Type);
	for (int i=1;i<=n;i++)
		scanf("%d",&val[i]);
	for (int i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		_connect(x,y);
		_connect(y,x);
	}
	for (int i=0;i<m;i++)
	{
		for (int j=0;j<2;j++)
			scanf("%d%d",&p[j],&q[j]),d[p[j]]=q[j];
		dfs(1,0);
	//	cerr << "------------------\n";
		if (d[1]==0)
			printf("%lld\n",f[1][0]>=INF?-1:f[1][0]);
		if (d[1]==1)
			printf("%lld\n",f[1][1]>=INF?-1:f[1][1]);
		if (d[1]==-1)
			printf("%lld\n",min(f[1][0],f[1][1])>=INF?-1:min(f[1][0],f[1][1]));
		for (int j=0;j<2;j++)
			d[p[j]]=-1;
	}
	return 0;
}
