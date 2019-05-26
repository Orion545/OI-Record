#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
const int maxn=50010, inf=1e9;
struct edge{int too, dis, pre;}e[maxn<<1];
int n, m, tot, mid, x, y, z;
int last[maxn], f[maxn], g[maxn], a[maxn], b[maxn];

template<typename T>
inline void read(T &k)
{
	int f=1; k=0; char c=getchar();
	while(c<'0' || c>'9') c=='-' && (f=-1), c=getchar();
	while(c<='9' && c>='0') k=k*10+c-'0', c=getchar();
	k*=f;
}

inline void add(int x, int y, int z) {e[++tot]=(edge){y, z, last[x]}; last[x]=tot;}

inline int query(int n, int *a)
{
	int ans=0, r=n;
	for(int i=1;i<r;i++)
	if(a[i]+a[r]>=mid) ans++, r--;
	return ans;
}

void dfs(int x, int fa)
{
	for(int i=last[x], too;i;i=e[i].pre)
	if((too=e[i].too)!=fa) dfs(too, x), f[x]+=f[too];
	int cnt=0;
	for(int i=last[x], too;i;i=e[i].pre)
	if((too=e[i].too)!=fa) 
	{
		if(g[too]+e[i].dis>=mid) f[x]++;
		else a[++cnt]=g[too]+e[i].dis;
	}
//	printf("x:%d cnt:%d\n", x, cnt);
//	for(int i=1;i<=cnt;i++) printf("%d ", a[i]); puts("");
	sort(a+1, a+1+cnt);
	int mx=query(cnt, a);
	int l=0, r=cnt;
	while(l<r)
	{
		int mid=(l+r+1)>>1;
		int cnt2=0;
		for(int i=1;i<=cnt;i++)
		if(i!=mid) b[++cnt2]=a[i];
//		printf("mx:%d q:%d\n", mx, query(cnt2, b));
		if(query(cnt2, b)==mx) l=mid;
		else r=mid-1;
	}
	f[x]+=mx; g[x]=a[l];
//	printf("x:%d f[x]:%d g[x]:%d\n", x, f[x], g[x]);
}

inline bool check()
{
	memset(f, 0, sizeof(f));
	memset(g, 0, sizeof(g));
	dfs(1, 0);
	return f[1]>=m;
}

int main()
{
	freopen("track.in", "r", stdin);
	freopen("track.out", "w", stdout);
	read(n); read(m); int sum=0;
	for(int i=1;i<n;i++) read(x), read(y), read(z), add(x, y, z), add(y, x, z), sum+=z;
	int l=0, r=sum;
	while(l<r)
	{
		mid=(l+r+1)>>1;
//		printf("%d\n", mid);
		if(check()) l=mid;
		else r=mid-1;
	}
	printf("%d\n", l);
	return 0;	
}
