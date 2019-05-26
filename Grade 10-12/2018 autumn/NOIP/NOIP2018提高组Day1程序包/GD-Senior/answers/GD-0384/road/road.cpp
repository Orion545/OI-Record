#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<string>

using namespace std;
int a[100005],mn,ans,p,n;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++)
	 scanf("%d",&a[i]);
	while (1)
	{
		p=-1;mn=10000000;
		for (int i=1;i<=n;i++)
		 if (a[i]!=0&&a[i]<mn)
		 {mn=a[i];p=i;}
		if (p==-1) break;
		for (int i=p;i>=1;i--)
		 if (a[i]!=0) a[i]-=mn;
		  else break;
		for (int i=p+1;i<=n;i++)
		 if (a[i]!=0) a[i]-=mn;
		  else break;
		ans+=mn;
	}
	cout<<ans;
	return 0;
}
