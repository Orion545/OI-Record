#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<iostream>
using namespace std;
int n;
int a[100050],feng[100050][2];
int shu,shu1,di,jiao;//峰顶的数目,最低点,更新中的山脚 
bool pan(int h)
{
	bool la=true,ha=true;
	while(la)
	{
		if(a[h]<a[h-1])
		  ha=false;
		if(a[h]!=a[h-1])
		  la=false;
		h--;
	}
	return ha;
}
bool pan2(int h)
{
	bool la=true,ha=true;
	while(la)
	{
		if(a[h]<a[h+1])
		  ha=false;
		if(a[h]!=a[h+1])
		  la=false;
		h++;
	}
	return ha;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	a[0]=-1;
	scanf("%d",&n);
	a[n+1]=-1; 
	for(int i=1;i<=n;i++)
	  scanf("%d",&a[i]);
	shu=0;
	di=a[1];
	jiao=a[1];
	for(int i=2;i<=n;i++)//正着找峰顶和高度
	{
		if(di>a[i])
		  di=a[i];
		if(a[i]<a[i-1])
		{
			if(pan(i-1))
			{
				shu++;
				feng[shu][0]=a[i-1];
			    feng[shu][1]=jiao;
			}
			jiao=a[i];
		}
	}
	if(pan(n))
	{
		shu++;
		feng[shu][0]=a[n];
		feng[shu][1]=jiao;
	}
	jiao=a[n];
	shu1=shu;
	for(int i=n-1;i>=1;i--)//反着再找一遍
	{
		if(a[i]<a[i+1])
		{
			if(pan2(i+1))
			{
				if(jiao<feng[shu][1])
			      feng[shu][1]=jiao;
			    shu--;
			}
			jiao=a[i];
		}
	}
	if(pan2(1))
	  feng[1][1]=jiao;
	if(a[1]>a[2])
	  feng[shu][1]=jiao;
	int ans;
	ans=0;
	for(int i=1;i<=shu1;i++)
	  ans+=feng[i][0]-feng[i][1];
	ans+=di;
	printf("%d",ans);
	return 0;
}
