#include<cstdio>
#include<algorithm>
using namespace std;
struct node{
	int st,en;
}a[10005];
bool cmp(node a,node b)
{
	return a.st<b.st||(a.st==b.st&&a.en<b.en);
}
bool b[5005];
int n,m,i,k,c,st[5005],en[5005],ans[5005],to[5005],f[5005];
void go2(int x,int fa1,int fa2)
{
	for (int i=st[x];i&&i<=en[x];i++)
	if (a[i].en!=fa1&&a[i].en!=fa2&&!b[a[i].en])
	{
		k++,ans[k]=a[i].en,b[a[i].en]=true;
		go2(a[i].en,x,0);
	}
}
void go(int x,int fa)
{
	for (int i=st[x];i&&i<=en[x];i++)
	if (a[i].en!=fa)
	{
		if (b[a[i].en])
		{
			for (;ans[k]!=to[a[i].en];b[k]=false,k--);
			b[k]=false,k--;
			for (int j=to[a[i].en];j<x;j=to[j])
			k++,ans[k]=j,b[j]=true,go2(j,to[j],f[j]);
			k++,ans[k]=x,b[x]=true,go2(x,a[i].en,0);
			c=a[i].en;
			return;
		}
		k++,ans[k]=a[i].en,b[a[i].en]=true,to[x]=a[i].en,f[a[i].en]=x;
		go(a[i].en,x);
		if (c)
		{
			if (a[i].en==c)
			c=0;
			else
			return;
		}
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (i=1;i<=m;i++)
	{
		scanf("%d%d",&a[i].st,&a[i].en);
		a[i+m].en=a[i].st,a[i+m].st=a[i].en;
	}
	m*=2;
	sort(a+1,a+m+1,cmp);
	for (i=1;i<=m;i++)
	{
		if (!st[a[i].st])
		st[a[i].st]=i;
		en[a[i].st]=i;
	}
	k=ans[1]=1,b[1]=true;
	go(1,0);
	for (i=1;i<=n;i++)
	printf("%d ",ans[i]);
	return 0;
}
