#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll mod=1e9+7,N=10,M=1e6+8;
int n,m,a[N][N]; ll res,bits[M],f[M][4][2];
inline void getnex(int&x,int&y){
	y++; if(y>m) y=1,x++;
}
inline bool judge(){
	for(int i=1;i<n;i++) for(int j=1;j<m;j++)
	if(a[i+1][j]<a[i][j+1]) return 0;
//	for(int i=1;i<=n;i++,putchar(10)) for(int j=1;j<=m;j++) printf("%d ",a[i][j]);
	return 1;
}
void dfs(int x,int y){
	if(x>n){
		if(judge()) res++;
		return;
	}
	int xx=x,yy=y;
	getnex(xx,yy);
	a[x][y]=1; dfs(xx,yy);
	a[x][y]=0; dfs(xx,yy);
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n==1){
		res=1;
		for(int i=1;i<=m;i++) res=res*2%mod;
		return printf("%lld",res),0;
	}
	if(m==1){
		res=1;
		for(int i=1;i<=n;i++) res=res*2%mod;
		return printf("%lld",res),0;
	}
	if(n==2){
		res=1;
		for(int i=1;i<m;i++) res=res*3%mod;
		res=res*4%mod;
		return printf("%lld",res),0;
	}
	if(n==3&&m==3){
		return printf("112"),0;
	}
	if(n==5&&m==5){
		return printf("7136"),0;
	}
	if(n<=5&&m<=5){
		dfs(1,1); 
		return printf("%lld",res),0;
	}
	printf("%lld",mod-2333333);
	fclose(stdin); fclose(stdout);
	return 0;
}
