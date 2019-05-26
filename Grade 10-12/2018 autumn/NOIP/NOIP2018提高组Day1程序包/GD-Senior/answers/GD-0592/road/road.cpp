#include<bits/stdc++.h>
using namespace std;
#define F(j,a,b) for(register int j=a;j<=b;++j)
#define Fu(j,a,b) for(register int j=a;j<b;++j)
#define Fd(j,a,b) for(register int j=a;j>=b;--j)
#define LL long long
inline int read()
{
	int x=0,w=0;char ch=0;
	while(!isdigit(ch))w|=(ch=='-'),ch=getchar();
	while(isdigit(ch))x=(x*10)+(ch^48),ch=getchar();
	return w?-x:x;
}

const int N=1000000;
const int M=N;
const int INF=2e9;
LL ans;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	LL a,n,pre;
	cin>>n;
	pre=0;
	ans=0;
	while(n--)
	{
		int k=read();
		a=k;
		if(a>pre)ans+=(a-pre);
		pre=a;
	}
	
	cout<<ans;
	return 0;
}
