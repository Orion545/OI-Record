#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
int n,m,f[5005][5005],a[5005],b[5005],sum[5005],f2[5005],c[5005];
bool dis[5005],p=false;
void work(int id,int num,int o1)
{
	if(p==true)
	  return;
	if(num==n)
	{
		for(int i=1;i<=n;i++)
		  printf("%d ",b[i]);
		p=true;
		return;
	}
	sort(a+1,a+1+o1);
	int o2=o1;
	for(int i=1;i<=o1;i++)
	{
		if(p==true)
	      return;
		b[num+1]=a[i];
		for(int j=1;j<=o1;j++)
		{
			c[j]=a[j];
			dis[a[j]]=false;
			a[j]=0;
		}
		o1=0;
		dis[b[num+1]]=true;
		int j=b[num+1];
		while(j!=f2[j])
		{
			for(int k=1;k<=sum[j];k++)
			{
				if(!dis[f[j][k]])
				{
					o1++;
					a[o1]=f[j][k];
					dis[f[j][k]]=true;
					f2[f[j][k]]=j;
				}
			}
			j=f2[j];
		}
		for(int k=1;k<=sum[j];k++)
		{
			if(!dis[f[j][k]])
			{
				o1++;
				a[o1]=f[j][k];
				dis[f[j][k]]=true;
				f2[f[j][k]]=j;
			}
		}
		work(b[num+1],num+1,o1);
		for(int k=1;k<=o1;k++)
		{
			dis[a[k]]=false;
			a[k]=0;
		}
		dis[b[num+1]]=false;
		for(int k=1;k<=o2;k++)
		{
			a[k]=c[k];
			dis[a[k]]=true;
		}
		b[num+1]=0;
		o1=o2;
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		dis[i]=false;
		sum[i]=0;
	}
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		sum[x]++;
		sum[y]++;
		f[x][sum[x]]=y;
		f[y][sum[y]]=x;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			dis[j]=false;
			f2[j]=j;
		}
		dis[i]=true;
		int o1=0,j=1,o2=1;
		for(int k=1;k<=sum[i];k++)
		{
			if(!dis[f[i][k]])
			{
				o1++;
			    a[o1]=f[i][k];
			    dis[f[i][k]]=true;
			    f2[f[i][k]]=i;
			}
		}
		b[1]=i;
		work(i,1,o1);
	}
	return 0;
}
