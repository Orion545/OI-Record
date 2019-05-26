#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m;
long long ans;
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>m;
	long long g=(1+(m-1))*(n-1)/2;
	ans=12;
    for(int i=1;i<g;i++)
    ans=ans*4%1000000007;
	if((n*m)%2==1)ans=ans*2%1000000007;
	cout<<ans;
	return 0;
}
