#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

const int N=100010,INF=5e8,M=262222;

typedef long long LL;

int n,m,tot,h[N],e[N],nxt[N],len[N],l,r,mid,ans,b[N],Path[N],D[N],sum,fa[N];

bool vis[N];

char c;

int read()
{
	int x=0,sig=1;
	for (c=getchar();c<'0' || c>'9';c=getchar()) if (c=='-') sig=-1;
	for (;c>='0' && c<='9';c=getchar()) x=x*10+c-48;
	return x*sig;
}

void Add(int x,int y,int z)
{
	e[++tot]=y; nxt[tot]=h[x]; len[tot]=z; h[x]=tot;
}

bool Check(int l)
{
	ans=0;
	memset(Path,255,sizeof(Path));
	for (int i=n,j,x,k,mx,t,cnt;i;i--)
	{
		x=D[i];
		sum=0;
		for (j=h[x];j;j=nxt[j]) if (e[j]!=fa[x] && Path[e[j]]!=-1)
		{
			b[++sum]=Path[e[j]]+len[j];
		}
		sort(b+1,b+sum+1);
		for (;sum && b[sum]>=l;sum--) ans++;
		mx=0;
		for (j=1,k=sum;j<k;j++)
		{
			if (b[j]+b[k]>=l)
			{
				k--; mx++;
			}
		}
		ans+=mx;
		int le,ri,md;
		for (le=0,ri=sum,md=le+ri>>1;le<ri;md=le+ri>>1)
		{
			cnt=0;
			for (j=1,k=sum;j<k;j++) if (j!=md)
			{
				if (k==md) k--;
				if (j<k && b[j]+b[k]>=l)
				{
					k--; cnt++;
				}
			}
			if (cnt==mx) le=md+1;else ri=md;
		}
		cnt=0;
			for (j=1,k=sum;j<k;j++) if (j!=le)
			{
				if (k==le) k--;
				if (j<k && b[j]+b[k]>=l)
				{
					k--; cnt++;
				}
			}
		if (cnt!=mx) le--;
		Path[x]=b[le];
	}
	return ans>=m;
}

int main()
{
	freopen("track.in","r",stdin); freopen("track.out","w",stdout);
	n=read(); m=read();
	for (int i=1,x,y,z;i<n;i++)
	{
		x=read(); y=read(); z=read();
		Add(x,y,z); Add(y,x,z);
	}
	D[tot=1]=1;
	for (int i=1,j,x;i<=tot;i++)
	{
		x=D[i];
		for (j=h[x];j;j=nxt[j]) if (e[j]!=fa[x])
		{
			D[++tot]=e[j]; fa[e[j]]=x;
		}
	}
	for (l=1,r=INF,mid=l+r>>1;l<r;mid=l+r>>1)
		if (Check(mid)) l=mid+1;else r=mid;
	if (!Check(l)) l--;
	printf("%d\n",l);
	return 0;
}
