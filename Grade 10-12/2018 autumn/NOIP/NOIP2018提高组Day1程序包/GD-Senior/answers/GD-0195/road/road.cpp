#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define MAXN 110000
#define inf 1000000000
using namespace std;
void debug()
{
	return ;
}
int n,a[MAXN];
struct node
{
	int x,loc;
	node()
	{
		x=inf;loc=0;
	}
}f[MAXN][18];
void pre_work()
{
	for(int i=1;i<=n;i++)f[i][0].x=a[i],f[i][0].loc=i;
	int now=1,bit=2;
	while(bit<=n)
	{
		for(int i=1;i+bit/2<=n;i++)
		{
			if(f[i][now-1].x>f[i+bit/2][now-1].x)
				f[i][now]=f[i+bit/2][now-1];
			else f[i][now]=f[i][now-1];
		}
		now++;
		bit*=2;
	}
	return ;
}
node get(int x,int y)
{
	int bit=1,now=0;
	while(bit*2<=y-x+1)bit*=2,now++;
	if(f[x][now].x>f[y-bit+1][now].x)return f[y-bit+1][now];
	else return f[x][now];
}
int ans;
void work(int l,int r,int val)
{
	if(!(l<=r))return ;
	node x=get(l,r);
	if(x.x==val)
	{
		work(l,x.loc-1,val);
		work(x.loc+1,r,val);
	}
	else
	{
		ans+=(x.x-val);
		work(l,x.loc-1,x.x);
		work(x.loc+1,r,x.x);
	}
	return ;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	pre_work();
	ans=0;
	work(1,n,0);
	printf("%d\n",ans);
	return 0;
}
