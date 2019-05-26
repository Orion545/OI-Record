#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

struct node{int l,r,lc,rc,t,x;}a[200010];
int n;
int q[100010];
long long ans=0;
int len=0,st=1,ed=2;

int read()
{
	char ch=getchar();
	int tot=0,ttot=1;
	if(ch=='-')ttot=-1,ch=getchar();
	while(ch>='0' && ch<='9')tot=(tot<<3)+(tot<<1)+ch-'0',ch=getchar();
	return tot*ttot;
}

void bt(int l,int r)
{
	len++;int now=len;
	a[len].l=l;a[len].r=r;a[len].t=a[len].rc=a[len].rc=a[len].x=-1;
	if(l<r)
	{
		int mid=(l+r)>>1;
		a[now].lc=len+1;bt(l,mid);
		a[now].rc=len+1;bt(mid+1,r);
		if(a[a[now].lc].t<a[a[now].rc].t)a[now].t=a[a[now].lc].t,a[now].x=a[a[now].lc].x;
		else a[now].t=a[a[now].rc].t,a[now].x=a[a[now].rc].x;
	}
	else a[now].t=q[l],a[now].x=l;
}

int find(int now,int l,int r)
{
	if(a[now].l==l && a[now].r==r)return a[now].x;
	int mid=(a[now].l+a[now].r)>>1;
	if(r<=mid)return find(a[now].lc,l,r);
	else if(mid+1<=l)return find(a[now].rc,l,r);
	else
	{
		int tx=find(a[now].lc,l,mid),ty=find(a[now].rc,mid+1,r);
		if(q[tx]<q[ty])return tx;
		else return ty;
	}
}

void dfs(int l,int r,int t)
{
	int x=find(1,l,r);
	ans+=(q[x]-t);
	if(x!=l)dfs(l,x-1,q[x]);
	if(x!=r)dfs(x+1,r,q[x]);
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
//	scanf("%d",&n);
	n=read();
	for(int i=1;i<=n;i++)
	q[i]=read();
//		scanf("%d",&q[i]);
	bt(1,n);
	dfs(1,n,0);
	printf("%d",ans);
}
/*
*/
