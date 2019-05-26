#include<cstdio>
#include<algorithm>
using namespace std;
struct data
{
	int x,len,last;
}li[100050];
int p,n,m,a,b,l,le[100050],h[50050],dis[50050];
void add(int x,int y,int len)
{
	p++;li[p].x=y;li[p].len=len;li[p].last=h[x];h[x]=p;
}
void dfs(int k,int len,int fa)
{
	dis[k]=len;
	int p=h[k];
	while(p>0)
	{
		int x=li[p].x;
		if(x!=fa)
		{
			dfs(x,len+li[p].len,k);
		}
		p=li[p].last;
	}
}
void work1()
{
	dfs(1,0,1);
	int p,maxk=0;
	for(int i=1;i<=n;i++)
		if(dis[i]>maxk)maxk=dis[i],p=i;
	dfs(p,0,1);
	maxk=0;
	for(int i=1;i<=n;i++)maxk=max(maxk,dis[i]);
	printf("%d",maxk);
}
bool cmp(int a,int b)
{
	return a>b;
}
void work2()
{
	sort(le+1,le+n,cmp);
	int ans=2100000000;
	for(int i=1;i<=m;i++)ans=min(ans,le[i]+le[m+m-i+1]);
	printf("%d",ans);
}
bool check(int k)
{
	int sum=0,s=0;
	for(int i=1;i<n;i++)
	{
		sum+=le[i];
		if(sum>=k)s++,sum=0;
	}
	return s>=m;
}
void work3()
{
	int l=0,r=1;
	for(int i=1;i<n;i++)r+=le[i];
	while(l+1<r)
	{
		int mid=(l+r)/2;
		if(check(mid))l=mid;else r=mid;
	}
	printf("%d",l);
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	bool bo1=true,bo2=true;
	for(int i=1;i<n;i++)
	{
		scanf("%d%d%d",&a,&b,&l);le[i]=l;
		if(a!=1)bo1=false;
		if(a+1!=b)bo2=false;
		add(a,b,l);add(b,a,l);
	}
	if(m==1)work1();else
	if(bo1)work2();else
	if(bo2)work3();else
	if(m==n-1)
	{
		int ans=2100000000;
		for(int i=1;i<n;i++)ans=min(ans,le[i]);
		printf("%d",ans);
	}
	return 0;
}