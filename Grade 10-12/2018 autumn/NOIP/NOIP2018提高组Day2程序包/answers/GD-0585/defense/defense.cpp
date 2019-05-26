#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int n,m,i,j,x,y,a,b;
int last[100005],nex[200005],dm[200005],mon[100005],f[100005][2],sum[100005][2];
char s[10];

void add(int x, int y)
{
	j++;
	nex[j]=last[x];
	last[x]=j;
	dm[j]=y;
}

int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for (i=1; i<=n; i++) scanf("%d",&mon[i]);
	for (i=1; i<n; i++)
	{
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	/*if (s[1]=='A')
	{*/
		int ans=0;
		for (i=1; i<=n; i++)
		{
			f[i][0]=f[i-1][1];
			f[i][1]=min(f[i-1][1]+mon[i],f[i-1][0]+mon[i]);
		}
		while (m--)
		{
			scanf("%d%d%d%d",&a,&x,&b,&y);
			if (abs(a-b)==1&&x==0&&y==0)
			{
				printf("-1\n");
				continue;
			}
			int t;
			if (a>b) t=a,a=b,b=t,t=x,x=y,y=t;
			if (x==0)
			{
				ans+=f[a-1][1];
				sum[a+1][1]=mon[a+1];
				sum[a+1][0]=1047483647;
				sum[a+2][0]=sum[a+1][1];
				sum[a+2][1]=sum[a+1][1]+mon[a+2];
				for (i=a+3; i<=b-1; i++)
				{
					sum[i][0]=sum[i-1][1];
					sum[i][1]=min(sum[i-1][1]+mon[i],sum[i-1][0]+mon[i]);
				}
			}
			else
			{
				ans+=min(f[a-1][1],f[a-1][0])+mon[a];
				sum[a+1][1]=mon[a+1];
				sum[a+1][0]=0;
				for (i=a+2; i<=b-1; i++)
				{
					sum[i][0]=sum[i-1][1];
					sum[i][1]=min(sum[i-1][1]+mon[i],sum[i-1][0]+mon[i]);
				}
			}
			if (y==0)
			{
				ans+=sum[b-1][1];
				sum[b+1][1]=mon[b+1];
				sum[b+1][0]=1047483647;
				sum[b+2][0]=sum[b+1][1];
				sum[b+2][1]=sum[b+1][1]+mon[b+2];
				for (i=b+3; i<=n; i++)
				{
					sum[i][0]=sum[i-1][1];
					sum[i][1]=min(sum[i-1][1]+mon[i],sum[i-1][0]+mon[i]);
				}
				if (b<n)
				ans+=min(sum[n][0],sum[n][1]);
			}
			else
			{
				ans+=min(sum[b-1][1],sum[b-1][0])+mon[b];
				sum[b+1][1]=mon[b+1];
				sum[b+1][0]=0;
				for (i=b+2; i<=n; i++)
				{
					sum[i][0]=sum[i-1][1];
					sum[i][1]=min(sum[i-1][1]+mon[i],sum[i-1][0]+mon[i]);
				}
				if (b<n)
				ans+=min(sum[n][0],sum[n][1]);
				//printf("%d\n",ans);
			}
			printf("%d\n",ans);
		}
		//return 0;
	//}
	return 0;
}
