#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
#define fup(i,a,b) for(int i=a;i<=b;i++)
#define fow(i,a,b) for(int i=a;i>=b;i--)
const int N = 5005;
int n,m,len,dq[N],la[N],d[N],tot;
int fa[N],rt,b[N],h[N],l,r;
void add(int x,int y){ d[++len] = y; la[len] = dq[x]; dq[x] = len; }
void dfs(int x)
{
	printf("%d ",x); b[x] = 1;
	int mi = 2147483647;
	for(int jz=dq[x];jz;jz=la[jz])
	{
		if(b[d[jz]]==1) continue;
		mi = min(d[jz],mi);
	}
	while(mi!=2147483647)
	{
		dfs(mi); mi = 2147483647;
		for(int jz=dq[x];jz;jz=la[jz])
		{
			if(b[d[jz]]==1) continue;
			mi = min(d[jz],mi);
		}
	}
}
void dfss(int x,int f)
{
	printf("%d ",x); b[x] = 1;
	if(x==l) l = 0; if(x==r) r = 0;
	for(int jz=dq[x];jz;jz=la[jz])
	{
		if(b[d[jz]]==1) continue;
		if((l!=0&&r==0)||(l==0&&r!=0))
		{
			if(l<r) swap(l,r);
			if(d[jz]>l) return;
		} dfss(d[jz],x);
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	fup(i,1,m)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v); add(v,u);
	} 
	if(m==n-1) { dfs(1); return 0; }
	l = 0,r = 0;
	for(int jz=dq[1];jz;jz=la[jz])
	{
		if(l==0) l = d[jz];
			else r = d[jz];
	} dfss(1,0);
	return 0;
}

