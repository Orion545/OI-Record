#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
using namespace std;

int tree[400010],a[100010],n,ans;

void Build(int l,int r,int p)
{
	if (l>r) return;
	
	if (l==r)
	{
		tree[p]=a[l];
		return;
	}
	
	Build(l,(l+r)/2,p*2);
	Build((l+r)/2+1,r,p*2+1);
	
	tree[p]=min(tree[p*2],tree[p*2+1]);
}

int cha(int l,int r,int p,int x,int y)
{
	if (l>r || l>y || r<x) return (1<<30);
	
	if (x<=l && r<=y) return tree[p];
	
	return min(cha(l,(l+r)/2,p*2,x,y),cha((l+r)/2+1,r,p*2+1,x,y));
}

void dg(int l,int r,int o)
{
	if (l>r) return;
	
	int t=cha(1,n,1,l,r)-o;
	o+=t;
	ans+=t;
	
	int x=l-1;
	for (int i=l;i<=r;i++)
	{
		if (a[i]<=o)
		{
			if (i!=l) dg(x+1,i-1,o);
			x=i;
		}
	}
	if (x!=r) dg(x+1,r,o);
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	
	Build(1,n,1);
	
	dg(1,n,0);
	
	printf("%d\n",ans);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
