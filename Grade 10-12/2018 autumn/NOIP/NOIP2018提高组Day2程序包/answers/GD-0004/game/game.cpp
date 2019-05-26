#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

int n,m,i,j;
long long ans;
double s;

int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	
	ans=4;
	scanf("%d%d",&n,&m);
	if(n==1) cout<<2*m<<endl;
	else if(m==1) cout<<2*n<<endl;
	if(n==2)
	{
	    for(i=1;i<m;i++)
	    {
		    ans*=3;
		    if(ans>=1000000007)
		        ans%=1000000007;
        }
    	cout<<ans<<endl;
    }
	if(n==3)
	{
		for(i=1;i<m;i++)
		{
			ans*=3;
			if(ans>=1000000007)
			    ans%=1000000007;
		}
		ans*=2;ans+=ans/2.0;
		for(i=2;i<m;i++)
		{
			ans+=ans/3.0;
			if(ans>=1000000007)
			    ans%=1000000007;
		}
		if(ans>=1000000007)
			ans%=1000000007;
		cout<<ans<<endl;
	}
	return 0;
}
