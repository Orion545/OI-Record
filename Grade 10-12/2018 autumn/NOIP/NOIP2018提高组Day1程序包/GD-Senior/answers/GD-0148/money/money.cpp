#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
const int Mx=25000;
int n,ans,x;
bool f[30010], g[30010];
inline int read() {
	int tmp=0, fh=1; char c=getchar();
	while (c<'0'||c>'9') {if (c=='-') fh=-1; c=getchar();}
	while (c>='0'&&c<='9') tmp=tmp*10+c-48, c=getchar();
	return tmp*fh;
}
int main() {
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	for (int T=read();T;T--) {
		n=read(); ans=0;
		memset(f,0,sizeof(f));
		memset(g,0,sizeof(g));
		f[0]=g[0]=1;
		for (int i=1;i<=n;i++) {
			x=read();
			for (int j=0;j+x<=Mx;j++) f[j+x]|=f[j];
		}
		for (int i=1;i<=Mx;i++) if (f[i]&&(!g[i])) {
			ans++;
			for (int j=0;j+i<=Mx;j++) g[j+i]|=g[j];
		}
		printf("%d\n",ans);
	}
	return 0;
}
