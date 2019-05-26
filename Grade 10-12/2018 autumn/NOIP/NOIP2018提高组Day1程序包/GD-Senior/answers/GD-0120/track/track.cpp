#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define fo(i,a,b) for (i=a; i<=b; i++)
#define foo(i,a,b) for (i=a; i>=b; i--)
#define ll long long
using namespace std;

const int N=5e4+5, M=N*2;
int n, m, i, k, x, y, t, q, tot, root;
ll len, p, mid, ans;
int lst[N], e[M][3];
ll a[N], b[N];
bool bz[N], flag;

void link(int x,int y) {e[++t][0]=lst[x], e[t][1]=y, e[t][2]=k, lst[x]=t;}
void dg(int x,int fx)
{
	if (len>p) p=len, t=x;
	int i=lst[x];
	while (i)
	{
		int y=e[i][1];
		if (fx!=y) len+=e[i][2], dg(y,x), len-=e[i][2];
		i=e[i][0];
	}
}
void dg2(int x,int fx)
{
	int i=lst[x], j; b[x]=0;
	while (i)
	{
		int y=e[i][1]; i=e[i][0];
		if (fx!=y) dg2(y,x);
	}
	tot=0, i=lst[x];
	while (i)
	{
		int y=e[i][1];
		if (fx!=y) 
		{
			if (b[y]+e[i][2]<mid) a[++tot]=b[y]+e[i][2]; else q++;
		}
		i=e[i][0];
	}
	if (!tot) return;
	if (tot==1) {b[x]=a[1]; return;}
	sort(a+1,a+tot+1);
	fo(i,1,tot) bz[i]=0;
	fo(i,1,tot) if (!bz[i])
	{
		int k=0;
		foo(j,tot,i+1)
			if (a[i]+a[j]>=mid) k=!bz[j]?j:k; else break;
		if (!k) b[x]=a[i]; else q++, bz[k]=1;
	}
}

bool pd()
{
	q=0, dg2(1,0); return q>=m;
}
bool pd2()
{
	q=0, len=0; int i;
	fo(i,1,n-1)
		if (len+b[i]>=mid) q++, len=0; else len+=b[i];
	return q>=m;
}

int main()
{
	freopen("track.in","r",stdin), freopen("track.out","w",stdout);
	
	scanf("%d%d",&n,&m), flag=1;
	fo(i,2,n) 
	{
		scanf("%d%d%d",&x,&y,&k), link(x,y), link(y,x);
		if (x+1!=y) flag=0; b[x]=y;
	}
	
	if (flag)
	{
		ll l=1, r=p; ans=p;
		while (l<=r)
		{
			mid=(l+r)>>1; 
			if (pd2()) ans=mid, l=mid+1; else r=mid-1;
		}
		printf("%lld",ans); return 0;
	}
	
	dg(1,0), root=t, p=len=0, dg(root,0);
	if (m==1) {printf("%lld",p); return 0;}
	
	ll l=1, r=p; ans=p;
	while (l<=r)
	{
		mid=(l+r)>>1;
		if (pd()) ans=mid, l=mid+1; else r=mid-1;
	}
	printf("%lld",ans);
}
