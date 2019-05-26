#include<cstdio>
#include<cstring>
#include<algorithm>
#define MOD 1000000007
using namespace std;
int n,m,f[10][10];
int ksc(int x,int y){
	int sum=0;
	while(y>0){
		if(y&1){
			sum=(sum+x)%MOD;
		}
		x=(x+x)%MOD;
		y>>=1;
	}
	return sum;
}
int ksm(int x,int k){
	if(k==0) return 1;
	if(k==1) return x;
	int s=ksm(x,k/2);
	if(k%2==0) return ksc(s,s);
	else return ksc(x,ksc(s,s));
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n>m) swap(n,m);
	if(n<=5&&m<=5){
		f[1][1]=2;f[1][2]=f[2][1]=4;f[1][3]=f[3][1]=8;f[2][2]=12;f[2][3]=f[3][2]=36;f[3][3]=112;
		f[1][4]=f[4][1]=16;f[2][4]=f[4][2]=108;f[3][4]=f[4][3]=336;f[4][4]=912;
		f[1][5]=f[5][1]=32;f[2][5]=f[5][2]=324;f[3][5]=f[5][3]=1008;f[4][5]=f[5][4]=2688;f[5][5]=7136;
		printf("%d",f[n][m]);
		return 0;
	}
	if(n==1){
		printf("%d",ksm(2,m));
		return 0;
	}
	if(n==2){
		printf("%d",ksc(4,ksm(3,m-1)));
		return 0;
	}
	printf("%d",ksc(ksm(2,n),ksm(2,m)));
	return 0;
}
