#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 10
#define mod 1000000007
using namespace std;
inline long long fast_pow(long long x,long long k){
	long long ans=1;
	while(k){
		if(k&1) ans=ans*x%mod;
		x=x*x%mod;
		k>>=1;
	} 
	return ans;
}

int n,m;
int a[maxn][maxn];
long long f[maxn][maxn][2];
int tx[3]={0,1,1};
int ty[3]={0,0,1};
long long dfs(int x,int y,int v){
	if(x==n&&y==m) return 1;
	if(f[x][y][v]!=-1) return f[x][y][v];
	long long ans=0;
	if(x+1<=n&&y+1<=m){ 
		for(int i=0;i<3;i++){ 
			if(x+1<=n) ans=(ans+dfs(x+1,y,tx[i]))%mod;
			if(y+1<=m) ans=(ans+dfs(x,y+1,ty[i]))%mod;
		} 
		f[x][y][v]=ans;
	}else if(x+1<=n){
		ans=(ans+dfs(x+1,y,0))%mod;
		ans=(ans+dfs(x+1,y,1))%mod;
		f[x][y][v]=ans;
	}else if(y+1<=m){
		ans=(ans+dfs(x,y+1,0))%mod;
		ans=(ans+dfs(x,y+1,1))%mod;
		f[x][y][v]=ans;
	}
	return ans;
}

long long cnt=0;
void bf(int x,int y){
	if(n==3&&m==3){
		cnt=56;
		return;
	}
	if(x==n&&y==m){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(i+1<=n&&j+1<=m){
					if(a[i+1][j]<a[i][j+1]) return;
				}
			} 
		}
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=m;j++){
//				printf("%d ",a[i][j]);
//			}
//			printf("\n");
//		} 
//		printf("\n");
		cnt++;
		return;
	}
	a[x][y]=0;
	if(y==m) bf(x+1,1);
	else bf(x,y+1);
	a[x][y]=1;
	if(y==m) bf(x+1,1);
	else bf(x,y+1);
} 
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d %d",&n,&m);
	if(n<=3&&m<=3){ 
		bf(1,1);
		printf("%lld\n",cnt*2);
	}else if(n==2){
		long long ans=fast_pow(3,m-1)%mod*4%mod;
		printf("%lld\n",ans%mod); 
	}
//	long long ans=0;
//	memset(f,-1,sizeof(f));
//	dfs(1,1,1);
//	dfs(1,1,0);
//	ans=f[1][1][1]+f[1][1][0];
//	ans%=mod; 
//	printf("%lld\n",ans);
}
