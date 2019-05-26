#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string>

using namespace std;
struct data
{
	int s,t[5005];
}f[5005];
int ans[6000],sum,opens[5000005],n,m,x,y,visit[5005];
void add(int x,int y)
{
	f[x].s++;
	f[x].t[f[x].s]=y;
}
void find1_()
{
	int head=1,tail=1;
	opens[1]=1;
	visit[1]=1;
	while (head<=tail)
	{
		
		int mn=n+1;
		int x=opens[head];
		for (int i=1;i<=f[x].s;i++)
		 if (visit[f[x].t[i]]==0&&mn>f[x].t[i]) mn=f[x].t[i];
		if (mn==n+1) 
		{
		visit[x]=2;
		for (int i=1;i<=f[x].s;i++)
		 if (visit[f[x].t[i]]==1) mn=f[x].t[i];
		}
		else
		{
		visit[mn]=1;
		sum++;
		ans[sum]=mn;
		if (sum==n) return;
		}
		tail++;
		opens[tail]=mn;
		head++;
	}
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	sum=1;ans[1]=1;
	find1_();
	for (int i=1;i<=n;i++)
	 cout<<ans[i]<<" ";

	return 0;
}

