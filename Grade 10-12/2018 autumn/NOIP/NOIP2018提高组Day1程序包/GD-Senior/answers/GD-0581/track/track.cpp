#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
inline char get_c()
{
	static char buf[1<<14],*p1=buf,*p2=buf;
	return (p1==p2)&&(p2=(p1=buf)+fread(buf,1,1<<14,stdin),p1==p2)?EOF:*p1++;
}
int read_()
{
	int f=1,k=0;char c=get_c();
	while(c<'0'||c>'9') c=='-'&&(f=-1),c=get_c();
	while(c>='0'&&c<='9') k=k*10+c-'0',c=get_c();
	return k*f;
}
struct Edge{int ot,nex,dis;}_edge[200100];
int n,m,num,head[100100],mx[100100],se[100100],ans,a[100100],cnt;
void add(int u,int v,int w)
{
	_edge[++num].ot=v;
	_edge[num].nex=head[u];
	_edge[num].dis=w;
	head[u]=num;
}
void dfs11(int x,int fa)
{
	for(int i=head[x];i;i=_edge[i].nex)
	{
		int v=_edge[i].ot;
		if (v==fa) continue;
		dfs11(v,x);
		if (mx[v]+_edge[i].dis>mx[x]) {se[x]=mx[x]; mx[x]=mx[v]+_edge[i].dis;}
		else if (mx[v]+_edge[i].dis>se[x]) se[x]=mx[v]+_edge[i].dis;
	}
	ans=max(ans,mx[x]+se[x]);
}
void dfs2(int x,int fa)
{
	for(int i=head[x];i;i=_edge[i].nex)
	{
		int v=_edge[i].ot;
		if (v==fa) continue;
		a[++cnt]=_edge[i].dis; dfs2(v,x);
	}
}
bool judge(int mi)
{
	int ret=0,z=0;
	for(int i=1;i<=n;i++)
	{
		ret+=a[i];
		if (ret>=mi){z++; ret=0;}
	}
	if (z>=m) return true;
	return false;
}
bool che(int mi)
{
	int l=1,r=cnt,z=0;
	while(a[r]>=mi&&r>=l) {z++; r--;}
	if (z>=m) return true;
	for(int i=r;i>l;i--)
	{
		while(l<r&&a[l]+a[i]<mi) l++;
		z++; l++;
	}
	if (z>=m) return true;
	return false;
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	int x,y,z,ms=2e8;
	n=read_(); m=read_();
	bool zx1=true,zx2=true;
	for(int i=1;i<n;i++)
	{
		x=read_(); y=read_(); z=read_(); ms=min(ms,z);
		if (x!=1) zx1=false;
		if (y!=x+1) zx2=false;
		add(x,y,z); add(y,x,z);
	}
	if (m==1)
	{
		ans=0; dfs11(1,0);
		printf("%d",ans);
		return 0;
	}
	if (zx2)
	{
		int l=0,r=0,mid;
		cnt=0; dfs2(1,0); ans=0;
		for(int i=1;i<=cnt;i++) r+=a[i];
		while(l<=r)
		{
			mid=(l+r)>>1;
			if (judge(mid)) l=mid+1,ans=mid;
			else r=mid-1;
		}
		printf("%d",ans);
		return 0;
	}
	if (zx1)
	{
		cnt=0; int l=0,r=0,mid;
		for(int i=head[1];i;i=_edge[i].nex)
		{
			int v=_edge[i].ot;
			a[++cnt]=_edge[i].dis;
			r+=a[cnt];
		}
		sort(a+1,a+cnt+1);
		while(l<=r)
		{
			mid=(l+r)>>1;
			if (che(mid)) l=mid+1,ans=mid;
			else r=mid-1;
		}
		printf("%d",ans);
		return 0;
	}
	if (m==n-1){printf("%d",ms); return 0;}
	return 0;
}
