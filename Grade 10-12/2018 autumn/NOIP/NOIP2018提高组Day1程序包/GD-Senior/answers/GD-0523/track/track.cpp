#include <bits/stdc++.h>
using namespace std;
const int maxn=50005,INF=0x7FFFFFFF;
typedef multiset <int> Set;
Set S;
Set::iterator A,B;
struct edge { int obj,last,len; } e[maxn<<1];
int n,m,L=INF,R=1,mid,cnt,point[maxn],f[maxn],g[maxn];
void add(int x,int y,int z)
{
	cnt++;
	e[cnt].obj=y;
	e[cnt].last=point[x];
	e[cnt].len=z;
	point[x]=cnt;
}
void dfs(int u,int last)
{
	for (int i=point[u],v;i;i=e[i].last)
	{
		v=e[i].obj;
		if (v!=last) dfs(v,u);
	}
	for (int i=point[u],v;i;i=e[i].last)
	{
		v=e[i].obj;
		if (v==last) continue;
		f[u]+=f[v];
		if (g[v]+e[i].len>=mid) f[u]++; else S.insert(g[v]+e[i].len);
	}
	while (!S.empty())
	{
		A=S.upper_bound(0);
		int tmp=*A;
		S.erase(A);
		B=S.lower_bound(mid-tmp);
		if (B!=S.end()) f[u]++,S.erase(B); else g[u]=tmp;
	}
}
bool check()
{
	memset(f,0,sizeof(f));
	memset(g,0,sizeof(g));
	dfs(1,0);
	return f[1]>=m;
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1,x,y,z;i<n;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);
		add(y,x,z);
		L=min(L,z);
		R+=z;
	}
	while (L+1<R)
	{
		mid=L+R>>1;
		if (check()) L=mid; else R=mid;
	}
	printf("%d\n",L);
	return 0;
}
