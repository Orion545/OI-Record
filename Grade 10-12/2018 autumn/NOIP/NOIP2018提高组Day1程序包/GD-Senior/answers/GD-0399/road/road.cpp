#include<bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;

inline int read()
{
	int x=0;char c=getchar();
	for(;c<'0'||c>'9';c=getchar());
	for(;c>='0'&&c<='9';c=getchar()) x=x*10+(c^48);
	return x;
}

int n,a[maxn];

void input()
{
	n=read();
	for(int i=1;i<=n;i++) a[i]=read();
}

void solve()
{
	int i;long long ans=0;
	for(i=1;i<=n;i++) ans+=max(0,a[i]-a[i-1]);
	cout<<ans<<endl;
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	input();
	solve();
	
	return 0;
}
