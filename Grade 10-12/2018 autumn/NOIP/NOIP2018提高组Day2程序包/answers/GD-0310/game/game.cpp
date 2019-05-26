#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#define M 1000000007
using namespace std;
int n,m,sum,h[2000000],hs;
void huan(int &a,int &b)
{
	int t=a;
	a=b;
	b=t;
}
long long ans;
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>m;sum=n*m;;
	if (m<n) huan(n,m);
	/*bhf[0]=1;
	for (int i=m;i>=2;i--)
	{
		if (i==m)
		{
			for (int j=2;j<=n;j++)
			{
				bhf[++hs]=bhf[hs-1]*(j-1);
			}
		}
		else
		{
			bhf[++hs]=bhf[hs-1]*(min(i,n)-1);
		}
	}
	for (int i=2;i<=m;i++)
	{
		int x=min(i,n),r;
		r=sum-((m+1+m+1-min(i+1,)+1)*x/2);
		if (i!=m)
		{
			ans=(ans%M)+(min(i))
		}
		
	}*/
	for (int i=2;i<=n+m-3;i++)
	{
		int s,s1,r;
		if (i<=m)
		{
			s=min(n,i);
		}
		else s=min(n,i)-i+m;
		if (i+1<=m) s1=min(n,i+1);
		else s1=min(n,i+1)-i-1+m;
		if (i+1<=m-1)
		{
			r=((m-(i+1))+m)*n/2;
		}
		else r=(m-(i+1)+s1-1)*(n-i+1-m)/2;
		ans=(ans%M)+((s+1)*(s1-1)*(1<<r)%M)%M;
	}
	cout<<ans;
	return 0;
}
