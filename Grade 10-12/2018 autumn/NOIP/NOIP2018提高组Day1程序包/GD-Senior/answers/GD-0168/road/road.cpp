#include<algorithm>
#include<cstdio>
#include<cctype>

#define fo(i,a,b) for(int i=a;i<=b;++i)
#define fd(i,a,b) for(int i=a;i>=b;--i)

using namespace std;

const int N=1e5+5;
int n,a[N],z[N];

inline void read(int &n)
{
	int x=0,w=0; char ch=0;
	while(!isdigit(ch)) w|=ch=='-',ch=getchar();
	while(isdigit(ch)) x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	n=w?-x:x;
}

inline void write(int x)
{
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read(n);
	int cnt=0,ans=0;
	fo(i,1,n) read(a[i]);
	fo(i,1,n)
	{
		int now=cnt;
		while(cnt&&a[i]<=z[cnt]) --cnt;
		if(now==cnt) ans+=(a[i]-z[cnt]);
		z[++cnt]=a[i];
	}
	write(ans);
}

