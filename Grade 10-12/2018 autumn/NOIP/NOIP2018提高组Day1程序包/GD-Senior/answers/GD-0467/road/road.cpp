#include<cstdio>
using namespace std;
long long n,ans,x,y,kk,pp;
struct tree{
	int l,r,min,minsite;
}t[500000];

inline int read()
{
	int s=0;
	char ch=getchar();
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch>='0'&&ch<='9') {s=s*10+ch-48;ch=getchar();}
	return s;
}

int min(int a,int b)
{
	if (a<b) return a;
	else return b;	
}

void build(int l,int r,int k)
{
	t[k].l=l;
	t[k].r=r;
	if (l==r)
	{
		t[k].l=t[k].r=l;
		t[k].min=read();
		t[k].minsite=l;
		return;
	}
	int mid=(l+r)/2;
	build(l,mid,k*2);
	build(mid+1,r,k*2+1);
	if (t[k*2].min<=t[k*2+1].min)
	{
		t[k].min=t[k*2].min;
		t[k].minsite=t[k*2].minsite;
	}
	else
	{
		t[k].min=t[k*2+1].min;
		t[k].minsite=t[k*2+1].minsite;
	}
}

void ask(int k)
{
	if (t[k].l>=x&&t[k].r<=y)
	{
		if (t[k].min<kk)
		{
			kk=t[k].min;
			pp=t[k].minsite;
		}	
		return;
	}
	int mid=(t[k].l+t[k].r)/2;
	if (x<=mid) ask(k*2);
	if (y>mid)	ask(k*2+1);
}

void dfs(int l,int r,int addtor)
{
	x=l,y=r;
	kk=999999;
	ask(1);
	int k=kk;
	int p=pp;
	if (l==r)
	{
		ans+=kk-addtor;
		return;
	}
	if (p==l)
	{
		dfs(l+1,r,addtor);
		return;
	}
	else if (p==r)
	{
		dfs(l,r-1,addtor);
		return;
	}
	dfs(l,p-1,k);
	dfs(p+1,r,k);
	ans+=k-addtor;
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	build(1,n,1);
	dfs(1,n,0);
	printf("%lld",ans);
	return 0;
}
