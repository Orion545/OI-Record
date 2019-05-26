#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<vector>
#include<queue>
#include<map>
using namespace std;
const int INF=100000005;
int T,n,m,x,y,g;
int a[105];
int q[10000005];
void exgcd(int a,int b)
{
	if(b==0)
	{
		x=1;
		y=0;
		g=a;
	}
	else
	{
		exgcd(b,a%b);
		int k=x;
		x=y;
		y=k-a/b*y;
	}
	return;
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		for(int i=1;i<n;i++)
		{
			if(a[i]==INF) continue;
			for(int j=i+1;j<=n;j++)
			{
				if(a[j]==INF) continue;
				if(a[j]%a[i]==0) a[j]=INF;
			}
		}
		sort(a+1,a+n+1);
		while(a[n]==INF) n--;
		for(int i=1;i<=n;i++) q[i]=a[i];
		m=n;
		for(int i=1;i<m;i++)
			for(int j=i+1;j<=m;j++)
			{
				if(q[i]+q[j]>a[n]) break;
				exgcd(q[j],q[i]);
				int x_=x,y_=y;
				for(int k=n;a[k]>=q[i]+q[j];k--)
					if(a[k]%g==0)
					{
						x=x_;
						y=y_;
						x*=a[k]/g;
						y*=a[k]/g;
						int xx=q[i]/g;
						int yy=q[j]/g;
						while(x<0)
						{
							x+=xx;
							y-=yy;
							if(y<0) break;
						}
						while(y<0)
						{
							x-=xx;
							y+=yy;
							if(x<0) break;
						}
						if(x>0&&y>0)
						{
							a[k]=INF;
							int t=k;
							while(t<n)
							{
								swap(a[t],a[t+1]);
								t++;
							}
							n--;
						}
					}
				while(q[m]>a[n]) m--;
				for(int k=m;k>0;k--)
				{
					if(q[k]==q[i]+q[j]) break;
					if(q[k]<q[i]+q[j])
					{
						m++;
						q[m]=q[i]+q[j];
						int t=m-1;
						while(t>k)
						{
							swap(q[t],q[t+1]);
							t--;
						}
						break;
					}
				}
			}
		printf("%d\n",n);
	}
	return 0;
}
