#include <cstdio>
#include <cstring>
#include <algorithm>
#define LL long long
using namespace std;
#define MAXN 1000010

const LL P=1000000007;

int n,m;
LL f[MAXN][4][4];

LL calc(){
	for(int i=1;i<=3;i++)
		for(int j=0;j<=3;j++)
			f[3][i][j]=1;
	for(int i=4;i<=m+1;i++)
		for(int j=0;j<=3;j++)
			for(int k=0;k<=3;k++)
				for(int l=0;l<=3;l++){
					if(l==1 && j!=2) continue;
					((f[i][k][l]+=f[i-1][j][k])>=P)?(f[i][k][l]-=P):0;
				}
	LL ans=0;
	for(int i=0;i<=3;i++)
		for(int j=0;j<=2;j++)
			(ans+=f[m+1][i][j])%=P;
	ans=ans*4%P;
	return ans;
}

int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n>m) swap(n,m);
	if(n==1){
		LL res=1;
		for(int i=1;i<=m;i++)
			res=res*2%P;
		printf("%lld\n",res);
	} else if(n==2){
		LL res=4;
		for(int i=1;i<m;i++)
			res=res*3%P;
		printf("%lld\n",res);
	}else{
		printf("%lld\n",calc());
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
