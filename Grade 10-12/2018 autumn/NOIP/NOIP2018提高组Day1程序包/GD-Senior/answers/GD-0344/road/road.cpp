#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <set>
#include <queue>
#include <vector>
using namespace std;
struct data
{
	int sum,val;
}tree[404040];
struct data1
{
	int num,x;
}b[101010];
int a[101010];
set <int> s;
long long ans;
int n;
bool cmp(data1 x,data1 y)
{
	return (x.x<y.x || (x.x==y.x && x.num<y.num));
}
void build_tree(int l,int r,int root)
{
	if (l==r)
	{
		tree[root].sum=a[l];
		return;
	}
	int mid=(l+r)/2;
	build_tree(l,mid,root*2);
	build_tree(mid+1,r,root*2+1);
	tree[root].sum=tree[root*2].sum+tree[root*2+1].sum;
}
void down(int l,int r,int root)
{
	int Lson=root*2;
	int Rson=root*2+1;
	int mid=(l+r)/2;
	tree[Lson].sum+=(mid-l+1)*tree[root].val;
	tree[Rson].sum+=(r-mid)*tree[root].val;
	tree[Lson].val+=tree[root].val;
	tree[Rson].val+=tree[root].val;
	tree[root].val=0;
}
void updata(int l,int r,int L,int R,int root,int c)
{
	if (r<L || l>R) return;
	if (l>=L && r<=R)
	{
		tree[root].sum+=(r-l+1)*c;
		tree[root].val+=c;
		return;
	}
	if (tree[root].val!=0) down(l,r,root);
	int mid=(l+r)/2;
	updata(l,mid,L,R,root*2,c);
	updata(mid+1,r,L,R,root*2+1,c);
	tree[root].sum=tree[root*2].sum+tree[root*2+1].sum;
}
int query(int l,int r,int L,int R,int root)
{
	if (r<L || l>R) return 0;
	if (l>=L && r<=R) return tree[root].sum;
	if (tree[root].val!=0) down(l,r,root);
	int mid=(l+r)/2;
	int Lson=query(l,mid,L,R,root*2);
	int Rson=query(mid+1,r,L,R,root*2+1);
	return (Lson+Rson);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	  {
	  scanf("%d",&a[i]);
	  b[i].x=a[i];
	  b[i].num=i;
      }
	build_tree(1,n,1);
	sort(b+1,b+n+1,cmp);
	s.insert(0);
	s.insert(n+1);
	for (int i=1;i<=n;i++)
	  {
	  	int v=b[i].x;
	  	int now=b[i].num;
	  	int t=query(1,n,now,now,1);
	  	ans+=t;
	  	int L=*--s.lower_bound(now);
	  	int R=*s.upper_bound(now);
	  	updata(1,n,L,R,1,-t);
	  	s.insert(now);
	  }
	  cout<<ans<<endl;
	  fclose(stdin);
	  fclose(stdout);
	  return 0;
	
	  
}
