#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define LL long long
const int Maxn=50010;
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x*f;
}
int n,m;
struct Edge{int y,d,next;}e[Maxn<<1];
int last[Maxn],len=0;
void ins(int x,int y,int d)
{
	int t=++len;
	e[t].y=y;e[t].d=d;e[t].next=last[x];last[x]=t;
}
int f[Maxn],g[Maxn],l,tmp[Maxn],lt,pp[Maxn];
bool cmp(int x,int y){return g[x]<g[y];}
bool mark[Maxn];
int nxt[Maxn];
int fn(int x)
{
	if(nxt[x]==x)return x;
	return nxt[x]=fn(nxt[x]);
}
void dfs(int x,int fa,int id)
{
	f[x]=g[x]=0;
	for(int i=last[x];i;i=e[i].next)
	{
		int y=e[i].y;
		if(y==fa)continue;
		dfs(y,x,i);
	}
	lt=0;
	for(int i=last[x];i;i=e[i].next)
	{
		int y=e[i].y;
		if(y==fa)continue;
		f[x]+=f[y];
		if(g[y]>=l)f[x]++;
		else tmp[++lt]=y;
	}
	sort(tmp+1,tmp+1+lt,cmp);
	for(int i=1;i<=lt+1;i++)nxt[i]=i;
	for(int i=1;i<lt;i++)
	{
		if(g[tmp[i]]+g[tmp[lt]]<l)continue;
		int L=i+1,R=lt;
		while(L<=R)
		{
			int mid=L+R>>1;
			if(g[tmp[i]]+g[tmp[mid]]>=l)R=mid-1;
			else L=mid+1;
		}
		pp[i]=R+1;
	}
	for(int i=1;i<lt;i++)
	{
		if(g[tmp[i]]+g[tmp[lt]]<l)continue;
		if(mark[tmp[i]])continue;
		int t=fn(pp[i]);
		if(t<=lt)
		{
//			if(mark[tmp[t]])puts("ok");
			mark[tmp[i]]=mark[tmp[t]]=true,f[x]++,nxt[t]=fn(t+1);
		}
	}
	for(int i=lt;i;i--)
	if(!mark[tmp[i]]){g[x]=g[tmp[i]];break;}
	g[x]+=e[id].d;
//	printf("%d %d %d\n",x,f[x],g[x]);
}
bool check(int o)
{
	memset(mark,false,sizeof(mark));
	l=o;
	dfs(1,0,0);
//	printf("%d %d\n",l,f[1]);
	return(f[1]>=m);
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	memset(last,0,sizeof(last));
//	scanf("%d%d",&n,&m);
	n=read(),m=read();
	int l=1,r=0;
	for(int i=1;i<n;i++)
	{
		int x=read(),y=read(),d=read();
//		scanf("%d%d%d",&x,&y,&d);
		ins(x,y,d),ins(y,x,d);r+=d;
	}
//	check(31);return 0;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(check(mid))l=mid+1;
		else r=mid-1;
	}
	printf("%d",l-1);
}
