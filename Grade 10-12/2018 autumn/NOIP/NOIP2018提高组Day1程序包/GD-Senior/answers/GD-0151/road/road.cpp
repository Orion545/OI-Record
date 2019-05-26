#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int d[100000];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,time,l,r,flag;
	int minn=0x7fffffff;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&d[i]);
	time=0;
	for(int i=1;i<=n;i++)if(d[i]<minn)minn=d[i];
	time=minn;
	for(int i=1;i<=n;i++)d[i]=d[i]-minn;
	for(;;)
	{
		flag=0;
		for(int i=1;i<=n;i++)
		  if(d[i]!=0)
		  {
		  	flag=1;
		  	break;
		  }
		if(flag==0)break;
		l=0;r=0;
		for(int i=1;i<=n;i++)
		if(d[i]!=0)
		{
			l=i;r=i;
			for(int k=l+1;k<=n;k++)
			{
				if(d[k]!=0)r=k;
				else break;
			}
			minn=0x7fffffff;
			for(int k=l;k<=r;k++)if(d[k]<minn)minn=d[k];
			time=time+minn;
	        for(int k=l;k<=r;k++)d[k]=d[k]-minn;
			break;
		}
	}
	printf("%d",time);
	fclose(stdin);fclose(stdout);
	return 0;
}
