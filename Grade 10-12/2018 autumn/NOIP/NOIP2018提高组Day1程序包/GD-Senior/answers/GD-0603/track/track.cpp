#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define fo(i,j,k) for(i=j;i<=k;i++)
#define fd(i,j,k) for(i=j;i>=k;i--)
#define cmin(a,b) (a=(a<b)?a:b)
#define cmax(a,b) (a=(a>b)?a:b)
using namespace std;
typedef long long ll;
typedef double db;
const int N=1e5+5;
int f[N],g[N],a[N],b[N],c[N],nxt[N],fst[N],tt;
int le,ri,x,y,z,n,m,i,j,k,l,r,mid,L,R,M,incf,ta,ans;
void cr(int x,int y,int z)
{
	tt++;
	b[tt]=y;
	c[tt]=z;
	nxt[tt]=fst[x];
	fst[x]=tt;
}
int go(int x,int z)
{
	le=1;
	ans=0;
	fd(ri,ta,1)
	{
		if (ri<=le) break;
		if (ri==z) continue;
		if (a[ri]>=mid) 
		{
			ans++;
			continue;
		}
		while (ri>le&&(a[ri]+a[le]<mid||le==z)) le++;
		if (ri<=le) break;
		ans++;
		le++;
	}
	return ans;
}
void dfs(int x,int y)
{
	int p;
	g[x]=f[x]=0;
	for (p=fst[x];p;p=nxt[p])
		if (b[p]!=y)
			dfs(b[p],x);
	a[1]=0;
	ta=1;
	for (p=fst[x];p;p=nxt[p])
		if (b[p]!=y)
		{
			f[x]+=f[b[p]];
			a[++ta]=g[b[p]]+c[p];
		}
	sort(a+1,a+1+ta);
	incf=go(x,1);
	L=1;
	R=ta;
	while (L<R-1)
	{
		M=L+R>>1;
		if (go(x,M)==incf) L=M;else R=M-1;
	}
	if (go(x,R)==incf) L=R;
	f[x]+=incf;
	g[x]=a[L];
}
int check(int mid)
{
	//clear();
	dfs(1,0);
	return f[1]>=m;
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d %d",&n,&m);
	fo(i,1,n-1)
	{
		scanf("%d %d %d",&x,&y,&z);
		cr(x,y,z);
		cr(y,x,z);
		r+=z;
	}
	r=r/m+1;
	l=0;
	while (l<r-1)
	{
		mid=l+r>>1;
		if (check(mid)) l=mid;else r=mid-1;
	}
	if (check(r)) l=r;
	printf("%d\n",l);
}
