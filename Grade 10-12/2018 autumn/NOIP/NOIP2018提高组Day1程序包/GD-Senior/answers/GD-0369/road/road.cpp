#include<bits/stdc++.h>
#define sz 100010
using namespace std;
typedef long long ll;
void read(ll &x)
{
	char ch=getchar();x=0;
	while (ch>'9'||ch<'0') ch=getchar();
	while (ch<='9'&&ch>='0') x=x*10+ch-'0',ch=getchar();
}
ll b[sz],a[sz];
int n;
int main()
{
	freopen("road.in","r",stdin);freopen("road.out","w",stdout);
	ll i,x;
	cin>>n;
	for (i=1;i<=n;i++) read(b[i]),b[i]*=-1;
	for (i=1;i<=n;i++) a[i]=b[i]-b[i-1];
	x=0;
	for (i=1;i<=n;i++) 
		if (a[i]<0) x-=a[i];
	cout<<x;
	return 0;
}
