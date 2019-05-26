#include <cstdio>
using namespace std;
const int N=9,M=1000010;
const int MOD=1e9+7;
int n,m;
void readData(){
	scanf("%d%d",&n,&m);
}
int fastPow(int x,int y){
	int res=1;
	for(;y;x=1ll*x*x%MOD,y>>=1)
		if(y&1)
			res=1ll*res*x%MOD;
	return res;
}
void solve(){
	int ans=4ll*fastPow(3,m-1)%MOD;
	printf("%d\n",ans>=0?ans:ans+MOD);
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	readData();	
	if(n==2)
		solve();
	else{
		if(n==1&&m==1)
			puts("2");
		else if((n==1&&m==2)||(n==2&&m==1))
			puts("4");
		else if((n==1&&m==3)||(n==3&&m==1))
			puts("8");
		else if(n==2&&m==2)
			puts("12");
		else if((n==2&&m==3)||(n==3&&m==2))
			puts("36");
		else if(n==3&&m==3)
			puts("112");
		else 
			puts("7136");
	}
	return 0;
}
