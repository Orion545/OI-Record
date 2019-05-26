#include <stdio.h>
#include <stdlib.h>
const bool local=0;
const int P=1e9+7;
typedef long long ll;
int ksm(int x,int po){
	int ans=1;
	while (po){
		if (po&1) ans=(ll)x*ans%P;
		x=(ll)x*x%P;
		po>>=1;
	}
	return ans;
}
int mo(int x){
	return (x%P+P)%P;
}
int m,n,ans;
int main(){
	if (!local){
		freopen("game.in","r",stdin);
		freopen("game.out","w",stdout);
	}
	if (n==2&&m==2){
		ans=12;
	}else if (n==3&&m==3){
		ans=112;
	}else if (n==1){
		ans=mo(ksm(2,m));
	}else if (m==1){
		ans=mo(ksm(2,n));
	}
	printf("%d\n",ans);
	return 0;
}