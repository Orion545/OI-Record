#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<cstdlib>
#include<cstring>
using namespace std;
int t,n;
int a[15],b[15],c[15];
bool p=false,dis[15];
void work2(int o,int id)
{
	if(id==o+1)
	{
		int sum=0;
		for(int i=1;i<=o;i++)
		  sum+=c[i]*b[i];
		for(int i=2;i<=n;i++)
		{
			if((a[i]-sum)%a[1]==0&&a[i]>sum)
			  dis[i]=true;
		}
		bool p1=true;
		for(int i=2;i<=n;i++)
		{
			if(!dis[i])
			{
				p1=false;
				break;
			}
		}
		if(p1)
		  p=true;
		return ;
	}
	for(int i=0;i<=a[n]/b[id];i++)
	{
		if(p)
		  return ;
		c[id]=i;
		work2(o,id+1);
	}
}
void work(int id,int sum,int o)
{
	if(p)
	  return;
	if(id>n+1)
	  return ;
	if(sum==o)
	{
		work2(o,1);
		if(p)
		  return ;
		p=false;
		for(int i=1;i<=n;i++)
		  dis[i]=false;
		return ;
	}
	sum++;
	b[sum]=a[id];
	work(id+1,sum,o);
	sum--;
	b[sum+1]=0;
	work(id+1,sum,o);
}
bool isok2()
{
	p=false;
	work(2,0,2);
	return p;
}
bool isok3()
{
	p=false;
	work(2,0,3);
	return p;
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&t);
	for(int u=1;u<=t;u++)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		  scanf("%d",&a[i]);
		if(n>5)
		{
			printf("%d\n",n);
			continue;
	    }
	    sort(a+1,a+1+n);
	    bool isok=true;
		for(int i=2;i<=n;i++)
		{
			if(a[i]%a[1]!=0)
			{
				isok=false;
				break;
			}
		}
		if(isok)
		{
			printf("%d\n",1);
			continue;
		}
		isok=false;
		for(int i=2;i<=n;i++)
		{
			bool isok1=true;
			for(int j=2;j<=n;j++)
			{
				if(j!=i)
				{
					p=false;
					for(int k=0;k<=a[j]/a[i];k++)
					{
						if((a[j]-a[i]*k)%a[1]==0)
						{
							p=true;
							break;
						}
					}
					if(!p)
					{
						isok1=false;
						break;
					}
				}
			}
			if(isok1)
			{
				isok=true;
				break;
			}
		}
		if(isok)
		{
			printf("%d\n",2);
			continue;
		}
		for(int i=1;i<=n;i++)
		  dis[i]=false;
		if(isok2())
		{
			printf("%d\n",3);
			continue;
		}
		for(int i=1;i<=n;i++)
		  dis[i]=false;
		if(isok3())
		{
			printf("%d\n",4);
			continue;
		}
		printf("%d\n",5);
	}
	return 0;
}
