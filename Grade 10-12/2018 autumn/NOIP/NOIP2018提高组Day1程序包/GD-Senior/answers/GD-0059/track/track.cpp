#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
#define pii pair<int,int>

struct node { int t,v,next; }a[200010];

pii h[100010];

int head[100010],num[100010],n,m,tt,tot,mid;
bool bo[100010];

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline void add(int x,int y,int z) { a[++tot].t=y;a[tot].v=z;a[tot].next=head[x];head[x]=tot; }

inline bool cmp(int x,int y) { return x>y; }

inline int gao(int x)
{
	int rn=tt,res=0;
	for (int i=1;i<=tt;i++)
	{
		if (i==x) continue;
		if (i>=rn) break;
		while ((num[i]+num[rn]<mid||rn==x)&&rn>i) rn--;
		if (i>=rn) break;
		res++;rn--;
	}
	return res;
}

inline void dfs(int x,int y)
{
	for (int i=head[x];i;i=a[i].next)
	{
		int t=a[i].t;
		if (t==y) continue;
		dfs(t,x);
	}
	tt=0;
	for (int i=head[x];i;i=a[i].next)
	{
		int t=a[i].t;
		if (t==y) continue;
		h[x].first+=h[t].first;
		if (h[t].second+a[i].v>=mid) h[x].first++;
		else num[++tt]=h[t].second+a[i].v;
	}
	sort(num+1,num+tt+1,cmp);
	for (int i=1;i<=tt;i++) bo[i]=false;
	int rn=tt,res=0;
	for (int i=1;i<=tt;i++)
	{
		if (i>=rn) break;
		while (num[i]+num[rn]<mid&&rn>i) rn--;
		if (i>=rn) break;
		bo[i]=bo[rn]=true;
		rn--;res++;
	}
	h[x].first+=res;
	if (res*2==tt) h[x].second=0;
	else
	{
		int l=1,r=tt;
		while (l<r)
		{
			int mid=(l+r)>>1;
			if (gao(mid)==res) r=mid;
			else l=mid+1;
		}
		h[x].second=num[l];
	}
}

inline bool check()
{
	for (int i=1;i<=n;i++) h[i]=pii(0,0);
	dfs(1,0);
	return (h[1].first>=m);
}

int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	n=rd();m=rd();tot=0;
	int sum=0;
	for (int i=1;i<n;i++) { int x=rd(),y=rd(),z=rd();add(x,y,z);add(y,x,z);sum+=z; }
	int l=1,r=sum;
	while (l<r)
	{
		mid=((l+r)>>1)+1;
		if (check()) l=mid;
		else r=mid-1;
	}
	printf("%d\n",l);
	return 0;
}
