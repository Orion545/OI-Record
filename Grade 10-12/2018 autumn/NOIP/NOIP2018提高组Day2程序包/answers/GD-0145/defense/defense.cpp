#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
int n,m,a[100005],id,f[2005][2005],x[100005],y[100005];
long long ans=0;
char c;
bool dis[100005],dis1[100005];
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>c>>id;
	for(int i=1;i<=n;i++)
	  scanf("%d",&a[i]);
	if(c=='A')
	{
		for(int i=1;i<n;i++)
		  scanf("%d%d",&x[i],&y[i]);
		for(int i=0;i<=n+1;i++)
		  dis[i]=false;
		dis[0]=dis[n+1]=true;
		for(int i=1;i<=n;i++)
		{
			if(a[i]<a[i-1]+a[i+1])
			  dis[i]=true;
			else
			{
				dis[i]=false;
				dis[i-1]=true;
				dis[i+1]=true;
			}
		}
		for(int i=1;i<=n;i++)
		  if(dis[i])
		    ans+=a[i];
		for(int i=0;i<=n+1;i++)
		  dis1[i]=dis[i];
		for(int u=1;u<=m;u++)
		{
			int aa,bb,xx,yy;
			long long ans1=ans;
			scanf("%d%d%d%d",&aa,&xx,&bb,&yy);
			if(min(aa,bb)+1==max(aa,bb)&&xx==0&&yy==0)
			{
				printf("-1\n");
				continue;
			}
			if(xx==1)
			{
				if(dis1[aa]==false)
				{
					ans+=a[aa];
					dis1[aa]=true;
				}
				if(dis1[aa-1]&&dis1[aa-2]&&aa-1!=bb)
				{
					dis1[aa-1]=false;
					ans-=a[aa-1];
				}
				if(dis1[aa+1]&&dis1[aa+2]&&aa+1!=bb)
				{
					dis1[aa+1]=false;
					ans-=a[aa+1];
				}
			}
			if(xx==0)
			{
				if(dis1[aa]==true)
				{
					ans-=a[aa];
					dis1[aa]=false;
					if(dis1[aa-1]==false&&aa-1!=bb)
					{
						ans+=a[aa-1];
						dis1[aa-1]=true;
						if(dis1[aa-2]&&dis1[aa-3]&&aa-2!=bb)
						{
							dis1[aa-2]=false;
							ans-=a[aa-2];
						}
					}
					if(dis1[aa+1]==false&&aa+1!=bb)
					{
						ans+=a[aa+1];
						dis1[aa+1]=true;
						if(dis1[aa+2]&&dis1[aa+3]&&aa+2!=bb)
						{
							dis1[aa+2]=false;
							ans-=a[aa+2];
						}
					}
				}
			}
			if(yy==1)
			{
				if(dis1[bb]==false)
				  ans+=a[bb];
				dis1[bb]=true;
				if(dis1[bb-1]&&dis1[bb-2]&&bb-1!=aa)
				{
					dis1[bb-1]=false;
					ans-=a[bb-1];
				}
				if(dis1[bb+1]&&dis1[bb+2]&&bb+1!=aa)
				{
					dis1[bb+1]=false;
					ans-=a[bb+1];
				}
			}
			if(yy==0)
			{
				if(dis1[bb]==true)
				{
					ans-=a[bb];
					dis1[bb]=false;
					if(dis1[bb-1]==false&&bb-1!=aa)
					{
						ans+=a[bb-1];
						dis1[bb-1]=true;
						if(dis1[bb-2]&&dis1[bb-3]&&bb-2!=aa)
						{
							dis1[bb-2]=false;
							ans-=a[bb-2];
						}
					}
					if(dis1[bb+1]==false&&bb+1!=aa)
					{
						ans+=a[bb+1];
						dis1[bb+1]=true;
						if(dis1[bb+2]&&dis1[bb+3]&&bb+2!=aa)
						{
							dis1[bb+2]=false;
							ans-=a[bb+2];
						}
					}
				}
			}
			dis1[aa]=dis[aa];dis1[bb]=dis[bb];
			dis1[aa-1]=dis[aa-1];dis1[bb-1]=dis[bb-1];
			dis1[aa+1]=dis[aa+1];dis1[bb+1]=dis[bb+1];
			printf("%lld\n",ans);
			ans=ans1;
		}
	}
	return 0;
}
