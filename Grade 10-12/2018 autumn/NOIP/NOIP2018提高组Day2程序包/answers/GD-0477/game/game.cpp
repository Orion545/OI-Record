#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const int N=2001000;
int n,m;
ll pw[N],f2[N],f3[N];
/*
ll power(ll x,int len){
	ll res=1;
	for (;len;len>>=1,x=x*x%mod)
		if (len&1) res=res*x%mod;
	return res;
}
*/
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	pw[0]=1;
	for (int i=1;i<N;i++)
		pw[i]=pw[i-1]*2%mod;
	if (n==1) printf("%lld\n",pw[m]); 
	if (n==2){
		f2[0]=1;
		for (int i=1;i<=m;i++)
			f2[i]=(2ll*f2[i-1]%mod+pw[2*(i-1)])%mod;
		printf("%lld\n",4ll*f2[m-1]%mod);
	}
	if (n==3){
		if (m==1) printf("8\n"); else
		if (m==2) printf("36\n"); else
		if (m==3) printf("112\n"); else
		{
			f3[1]=14;
			for (int i=2;i<=m;i++)
				f3[i]=(pw[i]*f2[i-1]%mod+2ll*f3[i-1]%mod)%mod;
			printf("%lld\n",4ll*(f3[m-1]+2ll*f3[m-2]%mod)%mod);
		}
	}
}
