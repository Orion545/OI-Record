#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=100077;
char s[10];
int n,m,c[maxn],list[maxn],cnt,ctot,b[maxn],t[2];
long long a[maxn];
struct E
{
	int to,next;
}e[maxn*2];
void add(int u,int v)
{
	e[++cnt].to=v; e[cnt].next=list[u]; list[u]=cnt;
}
void dfs(int u,int cl)
{
	for(int i=list[u]; i; i=e[i].next)
	{
		int v=e[i].to;
		if(b[v]) continue;
		b[v]=1; t[cl]+=a[v]; dfs(v,cl^1);
	}
}
bool bj(int u)
{
	for(int i=list[u]; i; i=e[i].next)
	{
		int v=e[i].to;
		if(b[v]==-1) return 0;
		if(!b[v]) c[++ctot]=v; b[v]=2;
	}
	return 1;
}
int main()
{
	freopen("defense.in","r",stdin); freopen("defense.out","w",stdout);
	scanf("%d%d%s",&n,&m,s);
	for(int i=1; i<=n; i++) scanf("%lld",&a[i]);
	for(int i=1,x,y; i<=n-1; i++) scanf("%d%d",&x,&y),add(x,y),add(y,x);
	while(m--)
	{
		long long ans=0;
		for(int i=0; i<=n; i++) b[i]=0,c[i]=0;
		int x1,x2,y1,y2;
		scanf("%d%d%d%d",&x1,&x2,&y1,&y2);
		if(!x2) b[x1]=-1,bj(x1);else
		{
			if(!b[x1]) c[++ctot]=x1;
			b[x1]=2;
		}
		if(!y2)
		{
			if(!bj(y1))
			{
				printf("-1\n"); continue;
			}
			b[y1]=-1;
		}else
		{
			if(!b[y1]) c[++ctot]=y1;
			b[y1]=2; 
		}
		for(int i=1; i<=ctot; i++)
		{
			t[0]=t[1]=0;
			ans+=a[c[i]];
			for(int j=list[c[i]]; j; j=e[j].next) if(!b[e[j].to])
				dfs(e[j].to,0);
			ans+=min(t[0],t[1]);
		}
		printf("%lld\n",ans);
	}
}











