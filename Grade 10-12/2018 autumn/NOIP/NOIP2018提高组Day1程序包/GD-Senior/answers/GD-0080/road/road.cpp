#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1e5 + 5;

struct node
{
	int val,tag;
}tr[N << 2];

struct point
{
	int L,R,d,id;
}f[N];

int n,top;
int a[N],stk[N];
long long ans;

void pushdown(int rt,int l,int r)
{
	if (!tr[rt].tag) return;
	tr[rt << 1].tag += tr[rt].tag;
	tr[rt << 1 | 1].tag += tr[rt].tag;
	int mid = l + r >> 1;
	tr[rt << 1].val += (mid - l + 1) * tr[rt].tag;
	tr[rt << 1 | 1].val += (r - mid) * tr[rt].tag;
	tr[rt].tag = 0;
}

void build(int rt,int l,int r)
{
	if (l == r) { tr[rt].val = a[l]; return; }
	tr[rt].tag = 0;
	int mid = l + r >> 1;
	build(rt << 1,l,mid),build(rt << 1 | 1,mid + 1,r);
	tr[rt].val = tr[rt << 1].val + tr[rt << 1 | 1].val;
}

int query(int rt,int l,int r,int pos)
{
	if (l == r) return tr[rt].val;
	int mid = l + r >> 1;
	pushdown(rt,l,r);
	if (pos <= mid) return query(rt << 1,l,mid,pos);
	else return query(rt << 1 | 1,mid + 1,r,pos);
}

void update(int rt,int l,int r,int l_,int r_,int k)
{
	if (l > r_ || r < l_) return;
	if (l_ <= l && r_ >= r)
	{
		tr[rt].val += (r - l + 1) * k;
		tr[rt].tag += k;
		return;
	}
	int mid = l + r >> 1;
	pushdown(rt,l,r);
	update(rt << 1,l,mid,l_,r_,k),update(rt << 1 | 1,mid + 1,r,l_,r_,k);
	tr[rt].val = tr[rt << 1].val + tr[rt << 1 | 1].val;
}

int cmp(point x,point y)
{
	return x.d > y.d;
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for (int i = 1 ; i <= n ; i++) scanf("%d",&a[i]),f[i].L = f[i].R = f[i].id = i;
	build(1,1,n);
	for (int i = 1 ; i <= n + 1 ; i++)
	{
		while (top && a[stk[top]] > a[i]) f[stk[top--]].R = i - 1;
		stk[++top] = i;
	}
	memset(stk,0,sizeof(stk));
	top = 0;
	for (int i = n ; ~i ; i--)
	{
		while (top && a[stk[top]] > a[i]) f[stk[top--]].L = i + 1;
		stk[++top] = i;
	}
	for (int i = 1 ; i <= n ; i++) f[i].d = f[i].R - f[i].L + 1;
	sort(f + 1,f + n + 1,cmp);
	for (int i = 1 ; i <= n ; i++)
	{
		int p = query(1,1,n,f[i].id);
		update(1,1,n,f[i].L,f[i].R,-p);
		ans += p;
	}
	printf("%lld\n",ans);
	return 0;
}
