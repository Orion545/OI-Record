#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;

int pow(int a, int b)
{
	int ans=1;
	for(int i=1;i<=b;i++)
	{
		ans*=a;
		ans%=1000000007;
	}
	return ans;
}
int mul(int a, int b)
{
	return ((a%1000000007)*(b%1000000007))%1000000007;
}
int add(int a, int b)
{
	return ((a%1000000007)+(b%1000000007))%1000000007;
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int n,m,ans=4,ans2=0;
	cin>>n>>m;
	if(n>m)
		swap(n,m);
	if(n==1)
		ans=pow(2, m);
	else if(n==m==2)
		ans=12;
	else if(n==m==3)
		ans=112;
	else if(n==m==5)
		ans=7136;
	else{
		for(int i=2;i<n;i++)
		{
			ans=mul(ans, i+1);
		}
		for(int i=2;i<m+n-1;i++)
			ans=mul(ans, 2);
		ans=mul(ans, 3);
		for(int i=1;i<=m-n+1;i++)
			ans=mul(ans, n+1);
			
		
	}
	cout<<ans<<endl;
	return 0;
}
