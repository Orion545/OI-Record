#include<iostream>
#include<cstring>
#include<cstdio>
#define mo 1000000007
using namespace std;
int F[(1<<8)+5][2];
int main(){
//	freopen("game.in","r",stdin);
//	freopen("game.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
//	if(n==3&&m==3){
//		puts("112");
//		return 0;
//	}
//	if(n==5&&m==5){
//		puts("7136");
//		return 0;
//	}
	for(int i=0;i<(1<<n);i++) F[i][1]=1;
	for(int k=1;k<m;k++){
		for(int i=0;i<(1<<n);i++) F[i][(k&1)^1]=0;
		for(int i=0;i<(1<<n);i++){
			for(int j=0;j<(1<<n);j++){
				if(((i>>1)|(j&(1<<(n-1))-1))==(i>>1)){
					F[j][(k&1)^1]+=F[i][k&1];
					F[j][(k&1)^1]%=mo;
				}
			}
		}
	}
	int ans=0;
	for(int i=0;i<(1<<n);i++){
		ans+=F[i][m&1];
		ans%=mo;
	}
	printf("%d\n",ans);
}
