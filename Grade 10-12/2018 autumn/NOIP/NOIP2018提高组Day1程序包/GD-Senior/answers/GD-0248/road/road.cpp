#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#define ll long long
using namespace std;
const int N=11e5;
inline int read()
{
	int f=1,x=0;
	char c=getchar();
	while(!(c>='0'&&c<='9')){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
	return f*x;
}
int a[N];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n=read();
	int last=0;ll ans=0;
	for(int i=1;i<=n;i++)
	{
		int x=read();
		if(last<=x)ans+=x-last;
		last=x;
	}
	printf("%lld\n",ans);
	return 0;
}
