#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int T,n,a[102];
int z[102],iz;
bool mo(int x,int j)
{
	if(x==0) return true;
	else if(x<0) return false;
	bool pp=false;
	for(int k=j-1;k>=1;k--)
	for(int l=1;l<=x/a[z[k]];l++)
	{
		pp=mo(x-a[z[k]]*l,k);
		if(pp) return true;
	}
	return pp;
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		iz=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		sort(a+1,a+n+1);
		z[++iz]=1;
		bool flag;
		for(int i=2;i<=n;i++)
		{
			bool flag=false,fou=false;
			for(int j=iz;j>=1;j--)
			{
				for(int k=1;k<=a[i]/a[z[j]];k++)
				{
				flag=mo(a[i]-a[z[j]]*k,j);
				if(flag==true) break;
				}
				if(flag) 
				{fou=true;break;}
			}
			if(fou==false) 
			{
				z[++iz]=i;
				//cout<<i<<" a[i]="<<a[i]<<endl;
			}
		}
		printf("%d\n",iz);
	}
	return 0;
}
