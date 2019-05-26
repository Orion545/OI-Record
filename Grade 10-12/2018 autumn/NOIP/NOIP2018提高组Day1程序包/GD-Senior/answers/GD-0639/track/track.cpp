#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <bitset>
#include <queue>
#include <cstring>
using namespace std;
typedef long long ll;
inline int read()
{
	int f=1,k=0;char c=getchar();
	while (c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();
	while (c>='0'&&c<='9')k=k*10+c-'0',c=getchar();
	return k*f;
}
const int maxn=50000*2+100;
struct mc{int too,nxt,val;}e[maxn<<1];
struct zmc{int too,nxt;}store[maxn<<2];
int m,last[maxn],tot,pre[maxn],mid;
ll f[maxn],remain[maxn],tmp[maxn],pp[maxn];
bitset<maxn>used;
inline ll max(const ll a,const ll b){return a>b?a:b;}
inline int min(const int a,const int b){return a<b?a:b;}
inline void add(const int a,const int b)
{
	store[++tot].too=b,store[tot].nxt=pre[a];pre[a]=tot;
}
void dfs(const int cur,const int fa)
{
	f[cur]=0;
	remain[cur]=0;
	int ans=0;
	for (int i=last[cur];i;i=e[i].nxt)
	if (e[i].too!=fa)
	{
		dfs(e[i].too,cur);
		f[cur]+=f[e[i].too];
		if (remain[e[i].too]+e[i].val>=mid)++ans;
		else add(cur,remain[e[i].too]+e[i].val);
	}
	int cnt=0;
	for (int i=pre[cur];i;i=store[i].nxt)tmp[++cnt]=store[i].too;
	sort(tmp+1,tmp+1+cnt);
	for (int i=1;i<=cnt;i++)used[i]=0;
	int posl=cnt+1,posr=cnt;
	for (int i=1;i<cnt;i++)
	if (tmp[i]+tmp[cnt]>=mid)
	{
		posl=i;
		break;
	}
//	while (posl<posr-1&&tmp[posl]+tmp[posr-1]>=mid)--posr;
	while (posl<posr)
	{
		if (tmp[posl]+tmp[posr]>=mid)++ans,used[posl]=used[posr]=1,pp[posr]=tmp[posl],++posl,--posr;
		else ++posl;
	}
	f[cur]+=ans;
	if (posl+1!=posr)
		for (int i=posr;i<=cnt;i++)
			if (used[i]&&tmp[posr-1]+pp[i]>=mid)
			{
				remain[cur]=tmp[i];
				break;
			}
	for (int i=1;i<=cnt;i++)
	if (!used[i])remain[cur]=max(remain[cur],tmp[i]);
//	cout << cur <<" ans:"<<f[cur]<<" remain:"<<remain[cur]<< endl;
}
inline bool check()
{
	memset(pre,0,sizeof(pre));
	tot=0;
	dfs(1,0);
//	cout << f[1]<<" "<<remain[1]<<endl;
	return f[1]>=m;
}
signed main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	int n=read();m=read();
	for (int i=1,a,b,c;i<n;i++)
	a=read(),b=read(),c=read(),
	e[i<<1].too=b,e[i<<1].nxt=last[a],last[a]=i<<1,
	e[i<<1|1].too=a,e[i<<1|1].nxt=last[b],last[b]=i<<1|1,
	e[i<<1].val=e[i<<1|1].val=c;
	int l=0,r=1e9;
	while (l<r)
	{
		mid=((l+r)>>1)+1;
		if (check())l=mid;else r=mid-1;
	}
	printf("%d\n",l);
}
