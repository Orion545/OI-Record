#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int d[100001];
long long day=0,num,sum=0;
void search(int l,int r)
{
	int i=0,num=100001;
	for(i=l;i<=r;i++)num=min(num,d[i]);
	day+=num;
	sum-=(r-l+1)*num;
	for(i=l;i<=r;i++)d[i]-=num;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(d,0,sizeof(d));
	long long i=0,n,l=0,r=0,l1=0;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>d[i];
		sum+=d[i];
	}
	while(sum!=0)
	{
		for(i=1;i<=n;i++)
	{
		if(l1==0&&d[i]!=0)
		{
			l=i;
			l1=1;
		}
		else if(d[i]!=0)continue;
		else if(l1==1&&d[i]==0)
		{
		   r=i-1;
		   break;	
		}
	}
	if(r==0)r=n;
	search(l,r);
	l=0; r=0; l1=0;
	}
	cout<<day;
	return 0;
}
