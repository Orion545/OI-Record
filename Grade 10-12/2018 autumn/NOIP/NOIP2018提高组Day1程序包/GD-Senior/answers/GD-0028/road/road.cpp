#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
struct node
{
	int d,num;
}a[100051],rmq[300051][17];
int n;
long long ans=0;
inline void solve(int l,int r,int sum)
{
	if (l>r) return;
	int j=r-l+1,now=l,Ma=INT_MAX,Ma1=-1;
	for (int i=0;j>0;i++,j/=2)
	{
		if (j%2==1)
		{
			if (rmq[now][i].d<Ma)
			{
				Ma=rmq[now][i].d;
				Ma1=rmq[now][i].num;
			}
			now+=(1<<i);
		}
	}
	ans+=Ma-sum;
	solve(l,Ma1-1,Ma);
	solve(Ma1+1,r,Ma);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(rmq,127,sizeof(rmq));
	scanf("%d",&n);
	for (int i=0;i<n;i++) 
	{
		scanf("%d",&a[i].d);
		a[i].num=i;
	}
	for (int i=0;i<n;i++) rmq[i][0]=a[i];
	for (int i=1;i<=16;i++)
		for (int j=0;j<n;j++) 
		if (rmq[j][i-1].d<rmq[j+(1<<(i-1))][i-1].d)
		{
			rmq[j][i].d=rmq[j][i-1].d;
			rmq[j][i].num=rmq[j][i-1].num;
		} else
		{
			rmq[j][i].d=rmq[j+(1<<(i-1))][i-1].d;
			rmq[j][i].num=rmq[j+(1<<(i-1))][i-1].num;
		}
	solve(0,n-1,0);
	printf("%lld\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
