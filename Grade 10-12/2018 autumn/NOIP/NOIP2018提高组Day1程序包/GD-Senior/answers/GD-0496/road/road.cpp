#include<iostream>
#include<cstdio>
using namespace std;
int n,minn=99999999;
int d[100005],num=1;
long long unsigned ans=0;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&d[i]);
		if(d[i]<minn) minn=d[i];
	}
	d[n+1]=0;
	ans=ans+minn;
	for(int i=1;i<=n;i++) d[i]=d[i]-minn;
	//cout<<ans<<endl;
	while(num!=0)
	{
		num=0;
		for(int i=1;i<=n;i++)
		{
			if(d[i]!=0 && d[i+1]!=0)
			{
				int k=i,minn=99999999;
				while(d[k]!=0 && k<=n)
				{
					if(minn>d[k]) minn=d[k];
					k++;
				}
				for(int j=i;j<k;j++) d[j]=d[j]-minn;
				num++;
				ans=ans+minn;
			}
		}
	}
	for(int i=1;i<=n;i++) 
	{
		//cout<<d[i]<<" ";
		ans=ans+d[i];
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
