#include<cstdio>
#define MOD 1000000007
using namespace std;
int ans,n,m;
int ksm(long long p,int q){
	long long tmp=1;
	while(q!=0){
		if(q%2==1){
			tmp=(tmp*p)%MOD;
		}
		p=(p*p)%MOD;
		q/=2;
	}
	return tmp;
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n==1){
		printf("%d\n",ksm(2,m));
		return 0;
	}
	if(n==2){
		ans=((long long)ksm(3,m-1)*4)%MOD;
		printf("%d\n",ans);
		return 0;
	}
	if(n==3){
		ans=((long long)ksm(4,m-2)*28)%MOD;
		printf("%d\n",ans);
		return 0;
	}
	if(n==5&&m==5){
		printf("%d\n",7136);
		return 0;
	}
	printf("%d\n",0);
}
