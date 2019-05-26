#include<bits/stdc++.h>
using namespace std;

const int maxn = 25000 + 10;

int n,a[maxn],ava[maxn];

inline int read()
{
	int x=0;char c=getchar();
	for(;c<'0'||c>'9';c=getchar());
	for(;c>='0'&&c<='9';c=getchar()) x=x*10+(c^48);
	return x;
}

void input()
{
	memset(ava,0,sizeof(ava));
	
	int i;
	n=read();
	for(i=0;i<n;i++) a[i]=read();
	sort(a,a+n);
}

void solve()
{
	int i,j,ans=0;
	
	ava[0]=1;
	for(i=0;i<n;i++)
	{
		if(!ava[a[i]]) ans++;
		ava[a[i]]=1;
		for(j=0;j<25005-a[i];j++) ava[j+a[i]]|=ava[j];
	}
	cout<<ans<<endl;
}

int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	
	int tt=read();
	while(tt--)
	{
		input();
		solve();
	}
	
	return 0;
}
