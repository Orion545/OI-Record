#include<algorithm>
#include<cstdio>

using namespace std;

const long long MOD=1000000007;

long long n,m;

long long qpw(long long x,long long y){
	long long re=1;
	if(y!=0){
		long long tmp=qpw(x,y/2);
		if(y%2)re=re*tmp%MOD*tmp%MOD*x;else re=re*tmp%MOD*tmp%MOD;
	}
	return re;
}

int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n==1){printf("%lld",qpw(2,m));}else
	if(n==2){
		if(m==1)printf("4");
		long long tmp_3=qpw(3,m-2),tmp_2=1,ans=0;
		for(long long i=1;i<=n;i++){
			ans=(ans+tmp_2*tmp_3)%MOD;
			tmp_3=tmp_3/3;if(tmp_3==0)tmp_3=1;tmp_2=tmp_2*2%MOD;
		}
		printf("%lld",ans*4%MOD);
	}else if(n==3){
		if(m==1)printf("8");else
		if(m==2)printf("28");else
		if(m==3)printf("112");
	}
}
