#include <bits/stdc++.h>

using namespace std;
const int mod=1000000007;
int n,m,ans;
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>m;
	if (n==1)
	{
		ans=1;
		for (int i=1;i<=m;i++) ans=ans*2%mod;
		cout<<ans;
		return 0;
	}
	if (n==2)
	{
		ans=4;
		for (int i=1;i<m;i++) ans=((ans+ans)%mod+ans)%mod;
		cout<<ans;
		return 0;
	}
	return 0;
}
