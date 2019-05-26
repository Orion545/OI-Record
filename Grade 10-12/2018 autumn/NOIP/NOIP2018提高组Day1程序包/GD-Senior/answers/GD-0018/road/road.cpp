#include <iostream>
#include <cstdio>
using namespace std;
int n,cnt;
long long sum;
int a[100010],w[100010];
struct tree
{
	int left;
	int right;
	int maxn;
	int minn;
	int tag; 
}t[400010];
void build(int p,int l,int r)
{
	t[p].left=l;
	t[p].right=r;
	t[p].tag=0;
	if(l==r)
	{
		t[p].maxn=t[p].minn=a[l];
		return;
	}
	int mid=(t[p].left+t[p].right)/2;
	build(p*2,l,mid);
	build(p*2+1,mid+1,r);
	t[p].maxn=max(t[p*2].maxn,t[p*2+1].maxn);
	t[p].minn=min(t[p*2].minn,t[p*2+1].minn);
}
void pushdown(int p)
{
	if(t[p].tag)
	{
		t[p*2].maxn-=t[p].tag;
		t[p*2].minn-=t[p].tag;
		t[p*2].tag+=t[p].tag;
		t[p*2+1].maxn-=t[p].tag;
		t[p*2+1].minn-=t[p].tag;
		t[p*2+1].tag+=t[p].tag;
		t[p].tag=0;
	}
}
void change(int p,int l,int r,int num)
{
	if(l<=t[p].left&&r>=t[p].right)
	{
		t[p].maxn-=num;
		t[p].minn-=num;
		t[p].tag+=num;
		return;
	}
	pushdown(p);
	int mid=(t[p].left+t[p].right)/2;
	if(l<=mid) change(p*2,l,r,num);
	if(r>mid) change(p*2+1,l,r,num);
	t[p].maxn=max(t[p*2].maxn,t[p*2+1].maxn);
	t[p].minn=min(t[p*2].minn,t[p*2+1].minn);
}
int query1(int p,int l,int r)
{
	if(l<=t[p].left&&r>=t[p].right)
	return t[p].minn;
	pushdown(p);
	int mid=(t[p].left+t[p].right)/2,ans=10010;
	if(l<=mid) ans=min(ans,query1(p*2,l,r));
	if(r>mid) ans=min(ans,query1(p*2+1,l,r));
	return ans;
}
int query2(int p,int l,int r)
{
	if(l<=t[p].left&&r>=t[p].right)
	return t[p].maxn;
	pushdown(p);
	int mid=(t[p].left+t[p].right)/2,ans=0;
	if(l<=mid) ans=max(ans,query2(p*2,l,r));
	if(r>mid) ans=max(ans,query2(p*2+1,l,r));
	return ans;
}
void find(int p,int l,int r)
{
	if(t[p].left==t[p].right)
	{
		if(t[p].minn==0) w[++cnt]=t[p].left;
		return;
	}
	pushdown(p);
	int mid=(t[p].left+t[p].right)/2;
	if(l<=mid) find(p*2,l,r);
	if(r>mid) find(p*2+1,l,r);
}
void dfs(int l,int r)
{
	if(l>r) return;
	int cut=query1(1,l,r);
	sum+=(long long)(cut);
	change(1,l,r,cut);
	if(l<r&&query2(1,l,r))
	{
		int tcnt,tw[100010];
		cnt=0;
		find(1,l,r);
		tcnt=cnt;
		for(int i=1;i<=tcnt;i++)
			tw[i]=w[i];
		tw[0]=l-1;
		tw[tcnt+1]=r+1;
		for(int i=0;i<=cnt;i++)
			dfs(tw[i]+1,tw[i+1]-1);
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	build(1,1,n);
	dfs(1,n);
	printf("%lld\n",sum);
	return 0;
}
