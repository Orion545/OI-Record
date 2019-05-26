#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

int n,m;
long long mod=1e9+7;
long long f[3][1000010][2];

long long ksm(long long x,long long t){
	long long tot=1;
	while(t>0){
		if(t%2) (tot*=x)%=mod;
		(x*=x)%=mod;
		t/=2;
	}
	return tot;
}

int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d %d",&n,&m);
	if(n==1 || m==1) {
		long long x=2,t=n+m-1;
		printf("%lld",ksm(2,t));
	}
	else if(n==2){
		f[1][1][0]=1;f[1][1][1]=1;
		for(int i=2;i<=m;i++) f[1][i][1]=((f[1][i][0]=f[1][i-1][0]+f[1][i-1][1])%=mod);
		f[2][1][0]=f[2][1][1]=1;
		for(int i=2;i<=m;i++) f[2][i][0]=((f[2][i][1]=f[2][i-1][0]*f[1][i][0]+f[2][i-1][1]*f[1][i][0]+f[2][i-1][1]*f[1][i][1])%=mod);
		printf("%lld",f[2][m][0]+f[2][m][1]);
	}
	else if(n==m){
		for(int i=1;i<=n-1;i++) printf("1");
		printf("2");
	}
}
