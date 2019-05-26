#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)

using namespace std;
const int N=105,M=25005;
int n,mx,a[N],tot,ans;
bool f[M];

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

void solve()
{
	n=getint(),mx=0;
	rep(i,1,n) mx=max(mx,a[i]=getint());
	sort(a+1,a+1+n),tot=0;
	rep(i,1,n) if(i==1 || a[i]!=a[i-1]) a[++tot]=a[i];
	rep(i,1,mx) f[i]=0;
	n=tot,f[0]=1,ans=0;
	rep(i,1,n) if(!f[a[i]])
	{
		++ans;
		rep(j,a[i],mx) f[j]|=f[j-a[i]];
	}
	printf("%d\n",ans);
}	

int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	for(int T=getint(); T--; solve());
	return 0;
}
