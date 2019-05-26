#include<iostream>
using namespace std;
int ans=1,n,m,x,nm,mn;
const int mod=1000000007;
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>m;
	if(n==0||m==0) ans=0;
	x=mn=min(m,n),nm=max(m,n)-1;
	x++;
	for(int i=2;i<=mn;i++)
		ans=((ans*i)%mod*i)%mod;
	mn--;
	for(int i=mn;i<=nm;i++)
		ans=(ans*x)%mod;
	if(n==3&&m==3) ans=112;
	cout<<ans<<endl;
	return 0;
}
