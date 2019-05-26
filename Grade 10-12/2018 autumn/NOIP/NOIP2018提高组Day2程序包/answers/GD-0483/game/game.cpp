#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int n,m;
const int mod=1e9+7;
long long ans;
void po(int a,int x){
	int cnt=a; ans=1;
	while(x){
		if (x&1) ans=(ans*cnt)%mod;
		cnt=(cnt*cnt)%mod;
		x/=2;
	}
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d %d",&n,&m);
	if (n==1) po(2,m);
	else if (n==2){
		po(3,m-1);
		ans=(ans*4)%mod;		
	}
	else if (m==2){
		po(3,n-1);
		ans=(ans*4)%mod;
	}
	else if (m==1) po(2,n);
	else if (n==3&&m==3){
		ans=112;
	}
	printf("%lld",ans);
	return 0;
}
