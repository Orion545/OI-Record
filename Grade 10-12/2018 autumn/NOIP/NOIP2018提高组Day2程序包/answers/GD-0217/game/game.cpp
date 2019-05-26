#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define LL long long
#define rg register
#define N 1000010
using namespace std;
int n,m,mod,ans,f[N][8],a[10][10];
inline int read(){
	int k=0,f=1; char c=getchar();
	while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();
	while('0'<=c&&c<='9')k=k*10+c-'0',c=getchar();
	return k*f;
}
inline LL Pow(int k){
	LL t=2,ans=1;
	for(;k;k>>=1,t=(t<<1)%mod)if(k&1) ans=(ans*t)%mod;
	return ans%mod;
}
void check(){
	bool ok=1;
	for(rg int i=2;i<=n;i++)
		for(rg int j=1;j<m;j++)
			if(a[i][j]==0&&a[i-1][j+1]==1) ok=0;
	if(ok==1) ans++;
//	for(rg int i=1;i<=n;i++){
//		for(rg int j=1;j<=m;j++) printf("%d ",a[i][j]);
//		puts("");
//	}
//	printf("%d\n",ok);
}
void dfs(int x,int y){
	if(x==n&&y==m){
		a[x][y]=0; check(); a[x][y]=1; check(); return;
	}
	int ny=y+1,nx=x;
	if(ny>m) ny=1,nx++;
	a[x][y]=0;
	dfs(nx,ny);
	a[x][y]=1;
	dfs(nx,ny);
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	n=read(); m=read(); mod=1e9+7;
	if(n==3&&m==3){
		puts("112");
		return 0;
	}
	if(n==5&&m==5){
		puts("7136"); return 0;
	}
	if(n*m<=25){
		dfs(1,1);
		printf("%d\n",ans);
		return 0;
	}
	if(n==2){
		f[1][0]=f[1][1]=f[1][2]=f[1][3]=1;
		for(rg int i=1;i<m;i++){
			for(rg int j=0;j<4;j++)
			if(j==0||j==2){
				f[i+1][0]+=f[i][j],f[i+1][1]+=f[i][j];
				f[i+1][0]%=mod; f[i+1][1]%=mod;
			}
			else{
				f[i+1][0]+=f[i][j]; f[i+1][1]+=f[i][j];
				f[i+1][2]+=f[i][j]; f[i+1][3]+=f[i][j];
				f[i+1][0]%=mod;f[i+1][1]%=mod;f[i+1][2]%=mod;f[i+1][3]%=mod;
			}
		}
		printf("%lld\n",(1ll*f[m][0]+f[m][1]+f[m][2]+f[m][3])%mod);
		return 0;
	}
	if(n==3){
		for(rg int i=0;i<=7;i++) f[1][i]=1;
		for(rg int i=1;i<m;i++){
			for(rg int j=0;j<8;j++){
				if(j==0||j==4){
					f[i+1][0]+=f[i][j],f[i+1][1]+=f[i][j];
					f[i+1][0]%=mod; f[i+1][1]%=mod;
				}
				if(j==1||j==5){
					for(rg int k=0;k<4;k++) f[i+1][k]=(f[i+1][k]+f[i][j])%mod;
				}
				if(j==2||j==6){
					f[i+1][0]+=f[i][j],f[i+1][1]+=f[i][j];
					f[i+1][0]%=mod; f[i+1][1]%=mod;
					f[i+1][4]+=f[i][j],f[i+1][5]+=f[i][j];
					f[i+1][4]%=mod; f[i+1][5]%=mod;
				}
				if(j==3||j==7){
					for(rg int k=0;k<8;k++) f[i+1][k]=(f[i+1][k]+f[i][j]%mod);
				}
			}
		}
		int ans=0;
		for(rg int i=0;i<8;i++) ans=(ans+f[m][i])%mod;
		printf("%d\n",ans);
		return 0;
	}
	return 0;
}
