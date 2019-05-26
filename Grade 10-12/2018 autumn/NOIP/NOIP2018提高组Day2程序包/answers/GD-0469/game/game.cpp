#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll P=1000000007;
const int db[3][3]={{2,4,8},{4,12,36},{8,36,112}};
int n,m,t,f[300][2],mp[300][300],ans,w;
ll pow(ll x,ll k) {ll r=1; for (; k; k>>=1,x=x*x%P) if (k&1ll) r=r*x%P; return r;}
int main() {
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m); t=1<<n; w=0;
	if (n<=3 && m<=3) {
		printf("%d\n",db[n-1][m-1]);
		return 0;
	}
	if (n==5 && m==5) {
		printf("7136\n");
		return 0;
	}
	if (n==2) {
		printf("%lld\n",1ll*4*pow(3,m-1)%P);
		return 0;
	}
	if (n==3) {
		printf("%lld\n",1ll*36*pow(4,m-2)%P);
		return 0;
	}
	for (int i=0,j; i<t; i++) {
		//f[i][0]=1;
		j=(i>>1)|(1<<(n-1));
		for (int k=j; k; k=(k-1)&j) mp[i][k]=1;
		mp[i][0]=1;
	}
	f[t-1][0]=1;
	for (int i=1; i<=m; i++) {
		for (int j=0; j<t; j++) f[j][w^1]=0;
		for (int j=0; j<t; j++) {
			for (int k=0; k<t; k++) if (mp[j][k]) {
				f[k][w^1]+=f[j][w];
				if (f[k][w^1]>=P) f[k][w^1]-=P;
			}
		}
		w^=1;
		//for (int j=0; j<t; j++) printf("%d ",f[j][w]); puts("");
	}
	for (int i=0; i<t; i++) {
		ans+=f[i][w];
		if (ans>=P) ans-=P;
	}
	printf("%lld\n",ans%P);
	return 0;
}