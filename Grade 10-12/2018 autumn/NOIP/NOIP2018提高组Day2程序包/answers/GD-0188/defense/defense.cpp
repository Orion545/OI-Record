#include<bits/stdc++.h>

#define imax(a,b) ((a>b)?(a):(b))
#define imin(a,b) ((a<b)?(a):(b))

using namespace std;

typedef long long ll;

const int N=100010;
const ll inf=1e17; 
int n,m;
char st[4];
int cost[N];
int ne[N<<1],to[N<<1],h[N],tt;
int nop[N][2];
ll f[N][2],ans;

void addedge(int a,int b){
	to[++tt]=b; ne[tt]=h[a]; h[a]=tt;
}

void find(int x,int fa)
{
	f[x][0]=0; f[x][1]=cost[x];
	for(int p=h[x];p;p=ne[p])
	{
		int v=to[p];
		if(v==fa) continue;
		find(v,x);
		f[x][0]+=f[v][1];
		f[x][1]+=imin(f[v][0],f[v][1]);
	}
	f[x][0]=imin(f[x][0],inf);
	f[x][1]=imin(f[x][1],inf);
	if(nop[x][0]) f[x][0]=inf;
	if(nop[x][1]) f[x][1]=inf;
}

int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d%s",&n,&m,&st);
	for(int i=1;i<=n;++i) scanf("%d",&cost[i]);
	for(int i=1;i<n;++i)
	{
		int a,b; scanf("%d%d",&a,&b);
		addedge(a,b); addedge(b,a);
	}
	for(int i=1;i<=m;++i)
	{
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		nop[a][b^1]=1; nop[c][d^1]=1;
		find(1,1);
		ans=imin(f[1][0],f[1][1]);
		printf("%lld\n",(ans!=inf)?ans:-1);
		nop[a][b^1]=0; nop[c][d^1]=0;
	}
	return 0;
}
