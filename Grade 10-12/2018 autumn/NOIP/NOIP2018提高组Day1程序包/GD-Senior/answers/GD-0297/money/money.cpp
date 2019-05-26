#include<cstdio>
#include<iostream>
using namespace std;
const int MAXN=25000;
int T,n,a[1010],b[50000],c[50000],ans;
int main()
{
	ios::sync_with_stdio(false);
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	cin>>T;
	for(int IG=1;IG<=T;IG++)
	{
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=MAXN;i++)
		{
			b[i]=false;
			c[i]=false;
		}
		b[0]=true;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=MAXN;j++)if(j>=a[i])
			{
				if(b[j-a[i]])
				{
					b[j]=true;
					if(j!=a[i])c[j]=true;
				}
			}
		}
		ans=0;
		for(int i=1;i<=n;i++)if(!c[a[i]])ans++;
		cout<<ans<<"\n";
	}
}
