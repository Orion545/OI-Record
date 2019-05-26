#include<iostream>
#include<algorithm>
#include<cstdio>
#include<fstream>
using namespace std;
int du()
{
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if (c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	return x*f;
}
int n,a[500005],ans=0,m=0;
bool flag=true;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=du();
	for (int i=0;i<n;i++) a[i]=du();
	for (int i=0;i<n;i++)
	{
		if (a[i]>a[i+1])
		{
			if (flag)
			{
				ans+=a[i]-m;
				flag=false;
				m=a[i+1];
			}
			else
			m=a[i+1];
		}
		else flag=true;
	}
	cout<<ans;
	return 0;
}
