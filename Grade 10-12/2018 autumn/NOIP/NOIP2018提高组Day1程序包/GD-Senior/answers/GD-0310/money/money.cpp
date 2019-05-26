#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<fstream>
using namespace std;
int n,a[500],T;
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	cin>>T;
	while(T--)
	{
		cin>>n;
		for (int i=0;i<n;i++) cin>>a[i];
		if (n==2) 
		{
			if (a[0]%a[1]==0||a[1]%a[0]==0) 
			{
				cout<<1<<endl;
				continue;
			}
			else
			{
				cout<<2<<endl;
				continue;
			}
		}
		else
		{
			if (n==1) cout<<1<<endl;
			continue;
		}
	}
	return 0;
}

