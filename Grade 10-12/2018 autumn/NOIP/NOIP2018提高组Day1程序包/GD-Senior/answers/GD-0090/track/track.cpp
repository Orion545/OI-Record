#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <cstdlib>

#define ll long long
#define For(i,a,b) for(int i=a;i<=b;++i)
#define Rep(i,a,b) for(int i=a;i>=b;--i)

#define p(x) ('0'<=x&&x<='9')
char cc;
template <class T> void read(T &x)
{
	static int re;
	x=0; re=1; cc=getchar();
	while(!p(cc)) { re= cc=='-'?-1:1; cc=getchar(); }
	while(p(cc)) { x=x*10+cc-'0'; cc=getchar(); }
	x=x*re;
}
#undef p

using namespace std;

#define N 50010
int fst[N],nxt[N<<1],to[N<<1],val[N<<1],etot;
int cnt[N];
void add_e()
{
	static int a,b,c;
	read(a); read(b); read(c);
	++cnt[a]; ++cnt[b];
	nxt[etot]=fst[a];to[etot]=b; val[etot]=c; fst[a]=etot++;
	nxt[etot]=fst[b];to[etot]=a; val[etot]=c; fst[b]=etot++;
}

#define TO to[i]
#define VAL val[i]
#define NXT nxt[i]

int dep[N],maxd,rt;
void dfs(int x,int fa)
{
	if(dep[x]>maxd) rt=x,maxd=dep[x];
	for(int i=fst[x];~i;i=NXT)
	{
		if(TO==fa) continue;
		dep[TO]=dep[x]+VAL;
		dfs(TO,x);
	}
}
#undef TO
#undef VAL
#undef NXT

int a[N],n,m;

bool p(int d)
{
	int cur=0,cnt=0;
	For(i,1,n-1)
	{
		cur+=a[i];
		if(cur>=d) { cur=0; ++cnt; }
	}
	if(cnt>=m) return 1;
	return 0;
}

int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	memset(fst,-1,sizeof(fst));
	read(n); read(m);
	For(i,1,n-1) add_e();
	if(m==1) //solve1();
	{
		dfs(1,0);
		memset(dep,0,sizeof(dep));
		dfs(rt,0);
		printf("%d",maxd);
	}
	else if(cnt[1]==n-1)
	{
		For(i,1,n-1) a[i]=val[-1+(i<<1)];
		sort(a+1,a+n);
		if((m<<1)>n) printf("%d",a[n-m]);
		else
		{
			int MIN_D=a[n-1]*2;
			Rep(i,n-1,n-m) MIN_D=min(MIN_D,a[i]+a[n*2-2*m-i-1]);
			printf("%d",MIN_D);
		}
	}
	else
	{
		For(i,2,n-1) if(cnt[i]!=2) return 0;
		int node=1,tmp;
		while(node!=n)
		{
			tmp=fst[node];
			while(to[tmp]<node) tmp=nxt[tmp];
			a[node]=val[tmp];
			node=node+1;
		}
		int l=1,r=500000010,mid;
		while(r>l+1)
		{
			mid=(l+r)>>1;
			if(p(mid)) l=mid;
			else r=mid;
		}
		if(p(r)) printf("%d",r);
		else printf("%d",l);
	}
	return 0;
}
