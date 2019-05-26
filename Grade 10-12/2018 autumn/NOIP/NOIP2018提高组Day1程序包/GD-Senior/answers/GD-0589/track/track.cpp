#include<cstdio>
#include<cctype>
#include<cstring>
#include<algorithm>
using namespace std;
inline int getint()
{
	register int r=0,f=1;
	register char c=getchar();
	while (!isdigit(c))
		f=c=='-'?-f:f,c=getchar();
	while (isdigit(c))
		r=(r<<3)+(r<<1)+(c^48),c=getchar();
	return r*f;
}
const int N=5e4+10,INF=0x7fffffff;
int n,m;
struct Edge
{
	int to,nxt,w;
}edge[N<<1];
int head[N],cnt;
inline void add(int u,int v,int w){edge[++cnt]=(Edge){v,head[u],w},head[u]=cnt;}
int dis[N];
void dfs(int u,int fa)
{
	for (int v=head[u];v;v=edge[v].nxt)
		if (edge[v].to!=fa)
			dis[edge[v].to]=dis[u]+edge[v].w,dfs(edge[v].to,u);
}
int ou[N],ov[N],ow[N];
void solve1()
{
	dfs(1,0);
	int x=1;
	for (int i=2;i<=n;i++)
		if (dis[i]>dis[x])
			x=i;
	dis[x]=0,dfs(x,0);
	int ans=0;
	for (int i=1;i<=n;i++)
		ans=max(ans,dis[i]);
	printf("%d\n",ans);
}
bool cmp(int a,int b){return a>b;}
int fuck[N];
void solve2()
{
	sort(ow+1,ow+n,cmp);
	if (m+m<n)
	{
		for (int i=1;i<=m;i++)
			fuck[i]=ow[i]+ow[m+m-i+1];
		sort(fuck+1,fuck+m+1);
		printf("%d\n",fuck[m]);
	}
	else
	{
		for (int i=1;i<=m;i++)
			fuck[i]=ow[i]+ow[n-i];
		sort(fuck+1,fuck+m+1);
		printf("%d\n",fuck[m]);
	}
}
bool ck(int s)
{
	int sum=0,tot=0;
	for (int i=1;i<n;i++)
		if (sum+ow[i]<s)
			sum+=ow[i];
		else
			sum=0,tot++;
	return tot>=m;
}
void solve3()
{
	int l=INF,r=0,mid;
	for (int i=1;i<n;i++)
		l=min(l,ow[i]),r+=ow[i];
	while (l<=r)
	{
		mid=(l+r)>>1;
		if (ck(mid))
			l=mid+1;
		else
			r=mid-1;
	}
	printf("%d\n",l-1);
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	n=getint(),m=getint();
	bool flag1=1,flag2=1;
	for (int i=1;i<n;i++)
	{
		ou[i]=getint(),ov[i]=getint(),ow[i]=getint(),add(ou[i],ov[i],ow[i]),add(ov[i],ou[i],ow[i]);
		if (ou[i]!=1)
			flag1=0;
		if (ov[i]!=ou[i]+1)
			flag2=0;
	}
	if (m==1)
		solve1();
	else
		if (flag1)
			solve2();
		else
			if (flag2)
				solve3();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
