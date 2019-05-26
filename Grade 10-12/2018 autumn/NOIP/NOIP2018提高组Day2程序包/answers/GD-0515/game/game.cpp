#include<iostream>
#include<stdio.h>
#include<string.h>
#define P 1000000007
#define A(x,y) ((x-1)*(1<<n)+y+1)
using namespace std;
int n,ans,m;
int O[2400][2400],g[2400][2400],p[2400][2400];
int Ans[2400][2400];
int mul(int x[2400][2400],int y[2400][2400]){
	memset(p,0,sizeof(p));
	for(int i=1;i<=n*(1<<n);i++){
		for(int j=1;j<=n*(1<<n);j++){
			for(int k=1;k<=n*(1<<n);k++){
				(p[i][j]+=1LL*x[i][k]*y[k][j]%P)%=P;
			}
		}
	}
	memcpy(x,p,sizeof(p));
}
int add(int x[2400][2400],int y[2400][2400]){
	memset(p,0,sizeof(p));
	int i=1;
		for(int j=1;j<=n*(1<<n);j++){
			for(int k=1;k<=n*(1<<n);k++){
				(p[i][j]+=1LL*x[i][k]*y[k][j]%P)%=P;
			}
		}
	
	memcpy(x,p,sizeof(p));
}
int power(int x[2400][2400],int k){
	for(int i=1;i<2200;i++)Ans[i][i]=1;
	while(k){
		if(k&1)mul(Ans,x);
		mul(x,x);
		k>>=1;
	}
}
int add(int x,int y,int z){
	int f=z;
	z=z<<1;
	int ans=x;
	for(int i=2;i<=n;i++){
		int o=y&(1<<(i-1));
		int oo=z&(1<<(i-1));
		if(oo>o)return 0;
		if(oo!=o&&i>=x+1)return 0;
		if(oo==o)ans=min(ans,i);
	}
//	printf("%d %d\n%d %d\n\n",y,x,f,ans);
	g[A(x,y)][A(ans,f)]++;
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0;i<1<<n;i++)O[1][A(n,i)]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<1<<n;j++){
			for(int k=0;k<1<<n;k++){
		//		printf("%d %d %d\n",i,j,k);
				add(i,j,k);
			}
		}
	}
	if(m<=120){
		for(int i=1;i<=m-1;i++)add(O,g);	
	}else{
	power(g,m-1);
	mul(O,Ans);
	}
	long long ans=0;
	for(int i=1;i<=(1<<n)*(n);i++)(ans+=O[1][i])%=P;
	printf("%lld\n",ans);
}
