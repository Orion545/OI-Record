#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define fo(i,j,k) for(i=j;i<=k;i++)
#define fd(i,j,k) for(i=j;i>=k;i--)
#define cmax(a,b) (a=(a>b)?a:b)
#define cmin(a,b) (a=(a<b)?a:b)
using namespace std;
typedef long long ll;
typedef double db;
const int N=2e5+5,mo=1e9+7;
int n,m,v[N],X,Y,x,y,cx,cy,z,i,j;
ll f[N][2];
char s[105];
int tt,b[N],nxt[N],fst[N];
struct rec
{
	ll a[2][2];
	ll prt()
	{
		ll ret=1e13;
		int i,j;
		fo(i,0,1) fo(j,0,1) cmin(ret,a[i][j]);
		if (ret>=1e13) return -1;
		return ret;
	}
}tr[N*4],tmp;
void cr(int x,int y)
{
	tt++;
	b[tt]=y;
	nxt[tt]=fst[x];
	fst[x]=tt;
}
void dfs(int x,int y)
{
	f[x][0]=0;
	f[x][1]=v[x];
	for(int p=fst[x];p;p=nxt[p])
	if (b[p]!=y)
	{
		dfs(b[p],x);
		z=b[p];
		f[x][1]+=min(f[z][0],f[z][1]);
		f[x][0]+=f[z][1];
	}
	if (Y==x)
		f[x][1-cy]=1e13;
}
rec merge(rec a,rec b)
{
	int i,j;
	rec ret;
	fo(i,0,1) fo(j,0,1) ret.a[i][j]=1e13;
	fo(i,0,1)
		fo(j,0,1)
				ret.a[i][j]=min(ret.a[i][j],min(min(a.a[i][0],a.a[i][1])+b.a[1][j],a.a[i][1]+b.a[0][j]));
	return ret;
}
void make(int x,int l,int r)
{
	if (l==r)
	{
		tr[x].a[0][0]=0;
		tr[x].a[1][0]=tr[x].a[0][1]=1e13;
		tr[x].a[1][1]=v[l];
		return ;
	}
	int m=l+r>>1;
	make(x*2,l,m);
	make(x*2+1,m+1,r);
	tr[x]=merge(tr[x*2],tr[x*2+1]);
}
rec get(int x,int l,int r,int i,int j)
{
	if (l==i&&r==j) return tr[x];
	int m=l+r>>1;
	if (j<=m) return get(x*2,l,m,i,j);else
	if (m<i) return get(x*2+1,m+1,r,i,j);else
	return merge(get(x*2,l,m,i,m),get(x*2+1,m+1,r,m+1,j));
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d %d %s",&n,&m,s+1);
	fo(i,1,n) scanf("%d",v+i);
	fo(i,1,n-1)
	{
		scanf("%d %d",&x,&y);
		cr(x,y);
		cr(y,x);
	}
	if (n>2000)
		make(1,1,n);
	fo(i,1,m)
	{
		scanf("%d %d %d %d",&X,&cx,&Y,&cy);
		if (X>Y) swap(X,Y),swap(cx,cy);
		if (n>2000)
		{
			tmp=get(1,1,n,X,Y);
			fo(j,0,1) tmp.a[1-cx][j]=tmp.a[j][1-cy]=1e13;
			if (X>1) tmp=merge(get(1,1,n,1,X-1),tmp);
			if (Y<n) tmp=merge(tmp,get(1,1,n,Y+1,n));
			printf("%lld\n",tmp.prt());
		}
		else
		{	
			dfs(X,0);
			if (f[X][cx]>=1e13) f[X][cx]=-1;
			printf("%lld\n",f[X][cx]);
		}
	}
}
