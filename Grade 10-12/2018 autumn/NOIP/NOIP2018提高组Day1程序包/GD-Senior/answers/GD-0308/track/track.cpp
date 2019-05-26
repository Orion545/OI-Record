#include<cstdio>
#include<cstring>
#include<algorithm>
#define fo(i,a,b) for(int i=(a);i<=(b);++i)
#define fd(i,a,b) for(int i=(a);i>=(b);--i)
#define bfo(i,v,u) for(int i=BB[v],u=B[i][1];i;u=B[i=B[i][0]][1])
#define mset(a,x) memset(a,x,sizeof(a))
using namespace std;
typedef long long ll;
int read()
{
	char ch;int n=0,p=1;
	for(ch=getchar();ch<'0' || '9'<ch;ch=getchar()) if(ch=='-') p=-1;
	for(;'0'<=ch && ch<='9';ch=getchar()) n=n*10+ch-'0';
	return n*p;
}
const int N=5e4+5;
int n,m,B0,BB[N],B[N<<1][3];
void link(int u,int v,int w){B[++B0][1]=v,B[B0][0]=BB[u],B[B0][2]=w,BB[u]=B0;}
int lim,f[N],g[N],a[N];
bool bz[N];
void dfs(int v,int fr=0)
{
	bfo(i,v,u) if(u!=fr) dfs(u,v);
	int num=0;
	bfo(i,v,u) if(u!=fr)
	{
		f[v]+=f[u];
		a[++num]=g[u]+B[i][2];
	}
	sort(a+1,a+num+1);
	fo(i,1,num) bz[i]=0;
	int i=1,j=num,cnt=0;
	for(;j && a[j]>=lim;--j) ++cnt,bz[j]=1;
	for(;i<j;--j)
	{
		while(i<num && a[i]+a[j]<lim) ++i;
		if(i>=j) break;
		bz[i]=bz[j]=1;
		++cnt,++i;
	}
	f[v]+=cnt;
	int pos=0;
	fd(k,num,1) if(!bz[k])
	{
		g[v]=a[k],pos=k;
		break;
	}
	int l=pos,r=num+1;
	while(l<r-1)
	{
		int mid=(l+r)>>1;
		int i=1,j=num,t=0;
		for(;j && a[j]>=lim;--j) if(j!=mid) ++t;
		for(;i<j;--j) if(j!=mid)
		{
			while(i==mid || (i<num && a[i]+a[j]<lim)) ++i;
			if(i>=j) break;
			++t,++i;
		}
		if(t==cnt) l=mid;else r=mid;
	}
	pos=max(pos,l);
	g[v]=max(g[v],a[pos]);
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	n=read(),m=read();
	int l=0,r=0;
	fo(i,1,n-1)
	{
		int x=read(),y=read(),z=read();r+=z;
		link(x,y,z),link(y,x,z);
	}
	r=(r/m)+1;
	while(l<r-1)
	{
		lim=(l+r)>>1;
		mset(f,0);mset(g,0);
		dfs(1);
		if(f[1]>=m) l=lim;
		else r=lim;
	}
	printf("%d\n",l);
	return 0;
}

