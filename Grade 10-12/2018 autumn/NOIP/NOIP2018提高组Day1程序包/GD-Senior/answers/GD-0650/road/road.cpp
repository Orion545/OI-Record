#include<iostream>
#include<cstdio>
using namespace std;
struct II
{
	int i,v,c;
}tree[100050*4],z;
struct OO
{
	int l,r;
}q[1005000];
int n,a,s,t,ans;
void down(int now,int l,int r)
{
	tree[now*2].c+=tree[now].c;
	tree[now*2+1].c+=tree[now].c;
	tree[now*2].v-=tree[now].c;
	tree[now*2+1].v-=tree[now].c;
	tree[now].c=0;
}
void build(int now,int l,int r,int s,int v)
{
	if (l>s||r<s) return;
	if (l==r) 
	{
		tree[now].v=v;
		tree[now].i=s;
		return;
	}
	build(now*2,l,(l+r)/2,s,v);
	build(now*2+1,(l+r)/2+1,r,s,v);
	if (tree[now*2].v<=tree[now*2+1].v)
	 tree[now].i=tree[now*2].i; else tree[now].i=tree[now*2+1].i;
	tree[now].v=min(tree[now*2+1].v,tree[now*2].v); 
}
void update(int now,int l,int r,int s,int t,int v)
{
	if (l>t||r<s) return;
	if (s<=l&&r<=t)
	{
		tree[now].v-=v;
		tree[now].c+=v;
		return;
	}
	down(now,l,r);
	update(now*2,l,(l+r)/2,s,t,v);
	update(now*2+1,(l+r)/2+1,r,s,t,v);
	if (tree[now*2].v<=tree[now*2+1].v)
	 tree[now].i=tree[now*2].i; else tree[now].i=tree[now*2+1].i;
	tree[now].v=min(tree[now*2+1].v,tree[now*2].v);
}
II query(int now,int l,int r,int s,int t)
{
	if (l>t||r<s) return z;
	if (s<=l&&r<=t) return tree[now];
	down(now,l,r);
	II x=query(now*2,l,(l+r)/2,s,t);
	II c=query(now*2+1,(l+r)/2+1,r,s,t);
	if (x.v<=c.v) return x; else return c;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=4*n;i++) tree[i].v=1000000;
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a);
		build(1,1,n,i,a);
	}
	q[0].l=1;q[0].r=n;
	s=0;t=1;
	while (s!=t)
	{
		z.v=10000000;
		z=query(1,1,n,q[s].l,q[s].r);
		ans+=z.v;
		update(1,1,n,q[s].l,q[s].r,z.v);
		if (q[s].l<=z.i-1)
		{
			q[t].l=q[s].l;
			q[t].r=z.i-1;
			t++;
		}
		if (q[s].r>=z.i+1)
		{
			q[t].l=z.i+1;
			q[t].r=q[s].r;
			t++;
		}
		s++;
	}
	cout<<ans;
	return 0;
}
