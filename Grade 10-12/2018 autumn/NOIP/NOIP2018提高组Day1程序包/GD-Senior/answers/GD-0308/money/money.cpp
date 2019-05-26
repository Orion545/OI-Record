#include<cstdio>
#include<cstring>
#include<algorithm>
#define fo(i,a,b) for(int i=(a);i<=(b);++i)
#define fd(i,a,b) for(int i=(a);i>=(b);--i)
#define mset(a,x) memset(a,x,sizeof(a))
using namespace std;
typedef long long ll;
int read()
{
	char ch;int n=0,p=1;
	for(ch=getchar();ch<'0' || '9'<ch;ch=getchar()) if(ch=='-') p=-1;
	for(;'0'<=ch && ch<='9';ch=getchar()) n=n*10+ch-'0';
	return n*p;
}
const int N=105,M=25005;
int n,mx,a[N],f[M];
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	for(int cas=read();cas;cas--)
	{
		n=read();mx=0;
		fo(i,1,n) a[i]=read(),mx=max(mx,a[i]);
		sort(a+1,a+n+1);
		int ans=0;
		mset(f,0);
		f[0]=1;
		fo(i,1,n)
		{
			if(f[a[i]]) continue;
			++ans;
			fo(j,a[i],mx) if(f[j-a[i]]) f[j]=1;
		}
		printf("%d\n",ans);
	}
	return 0;
}

