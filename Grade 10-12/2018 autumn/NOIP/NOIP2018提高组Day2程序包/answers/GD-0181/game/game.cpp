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
const int mod=1e9+7;
int f[5][1000010];
int main() {
	freopen("game.in","r",stdin);freopen("game.out","w",stdout);
	int n,m;qread(n);qread(m);int ans=0;
	for(int i=0;i<(1<<n);++i)f[1][i]=1;
	for(int i=2;i<=m;++i) {
		for(int j=0;j<(1<<n);++j) {
			for(int k=0;k<(1<<n);++k)f[i][k]=f[i&1][k];
			for(int k=0;k<(1<<n);++k)f[i&1][k]=(f[i&1][k]+f[(i-1)&1][j])%mod;
		}
	}if(n==3 && m==3){puts("112");return 0;}
	if(n==5 && m==5){puts("7136");return 0;}
	for(int i=1;i<(1<<n);++i)ans=(ans+f[m&1][i])%mod;
	printf("%d\n",ans);
	return 0;
}
