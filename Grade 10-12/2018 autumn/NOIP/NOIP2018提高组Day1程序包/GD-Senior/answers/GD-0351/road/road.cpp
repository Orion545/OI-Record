#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define mid (l+r>>1)
#define lch (rt<<1)
#define rch (rt<<1|1)

using namespace std;
const int N=100005;
typedef long long LL;
int n,ql,qr,d[N],t[N<<2];

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

int pushup(int a,int b)
{
	if(d[a]<=d[b]) return a;
	return b;
}

void build(int l,int r,int rt)
{
	if(l==r)
	{
		d[l]=getint(),t[rt]=l;
		return;
	}
	build(l,mid,lch),build(mid+1,r,rch);
	t[rt]=pushup(t[lch],t[rch]);
}

int query(int l,int r,int rt)
{
	if(ql<=l && r<=qr) return t[rt];
	if(qr<=mid) return query(l,mid,lch);
	if(mid<ql) return query(mid+1,r,rch);
	return pushup(query(l,mid,lch),query(mid+1,r,rch));
}

LL solve(int l,int r,int del)
{
	if(l>r) return 0;
	ql=l,qr=r;
	int p=query(1,n,1);
	return d[p]-del+solve(l,p-1,d[p])+solve(p+1,r,d[p]);
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=getint();
	build(1,n,1);
	printf("%lld\n",solve(1,n,0));
	return 0;
}
