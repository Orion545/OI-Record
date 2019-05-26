#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#define qread(x) x=read()
#define qreadl(x) x=readl()
using namespace std;
typedef long long LL;
inline int read() {
	int x=0,f=1;char ch=getchar();
	while(ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return f*x;
}
inline LL readl() {
	LL x=0,f=1;char ch=getchar();
	while(ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return f*x;
}
const int N=110,M=25010;
int f[2*M],a[2*N];
int main() {
	freopen("money.in","r",stdin);freopen("money.out","w",stdout);
	int T;qread(T);
	while(T--) {
		int n;scanf("%d",&n);
		for(int i=1;i<=n;++i)qread(a[i]);
		memset(f,0,sizeof(f));
		sort(a+1,a+n+1);f[0]=1;int ans=0;
		for(int i=1;i<=n;++i) {if(f[a[i]])continue;
			++ans;f[a[i]]=1;
			for(int j=0;j<=M;++j)f[j+a[i]]|=f[j];
		}printf("%d\n",ans);
	}
	return 0;
}
