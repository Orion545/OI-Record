#include<cstdio>
#include<algorithm>
using namespace std;
struct data
{
	int x,last;
}li[10050];
int n,m,p,ans[5050],a[5050],deep[5050],s,h[5050],l=0,d;
bool b[5050],t[5050],finds[5050],bo;
void dfs(int k,int fa)
{
	s++;ans[s]=k;
	int p=h[k],r=l;
	while(p>0)
	{
		int x=li[p].x;
		if(x!=fa)
		{
			r++;
			a[r]=x;
		}
		p=li[p].last;
	}
	int k1=l+1,k2=r;l=r;
	sort(a+k1,a+1+k2);
	for(int i=k1;i<=k2;i++)dfs(a[i],k);
}
void work1()
{
	dfs(1,1);
	for(int i=1;i<=n;i++)printf("%d ",ans[i]);
}
void dfsh(int k,int fa,int de)
{
	b[k]=true;deep[k]=de;
	int p=h[k];
	while(p>0)
	{
		int x=li[p].x;
		if(x!=fa)
		{
			if(b[x])t[k]=true,deep[k]=deep[x];else
			{
				dfsh(x,k,de+1);
				if(t[x]&&deep[x]<=deep[k])t[k]=true,deep[k]=deep[x];
			}
		}
		p=li[p].last;
	}
}
void dfss(int k,int fa)
{
	s++;ans[s]=k;finds[k]=true;
	int p=h[k],r=l;
	while(p>0)
	{
		int x=li[p].x;
		if(!finds[x])
		if(x!=fa)
		{
			r++;
			a[r]=x;
		}
		p=li[p].last;
	}
	int k1=l+1,k2=r;l=r;
	sort(a+k1,a+1+k2);
	bool t1=false;
	for(int i=k1;i<=k2;i++)
	{
		int x=a[i];
		if(t[x])
		{
			if(t1)
			{
				bo=true;
				d=x;
			}else t1=true;
		}
	}
	for(int i=k1;i<=k2;i++)
	{
		int x=a[i];
		if(t[x]&&bo&&x>d)
		{
			bo=false;
			continue;
		}else dfss(x,k);
	}
}
void work2()
{
	dfsh(1,1,0);
	bo=false;
	dfss(1,1);
	for(int i=1;i<=n;i++)printf("%d ",ans[i]);
}
void add(int x,int y)
{
	p++;li[p].x=y;li[p].last=h[x];h[x]=p;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);add(y,x);
	}
	if(n==m+1)work1();else work2();
	return 0;
}