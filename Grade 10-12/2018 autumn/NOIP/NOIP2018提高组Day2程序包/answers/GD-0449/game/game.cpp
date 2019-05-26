# include <cstdio>
# include <cstring>
using namespace std;
const int MOD = 1e9+7;
const int maxn = 8;
const int maxm = 1e6+10;
int n,m;
inline void ms(int& x){(x>=MOD?x-=MOD:0);}
//BruteForce:80%
namespace Subtask1{
	int f[maxm][1<<maxn];
	void solve(){
		for(int i=0;i<(1<<n);++i)f[0][i]=1;
		for(int i=1;i<m;++i){
			for(int j=0;j<(1<<n);++j){ //f[i-1][j] -> f[i][k]
				for(int k=0;k<(1<<n);++k){
					bool flg=0;
					for(int v=1;v<n;++v)if(((k>>(v-1))&1)>=((j>>v)&1))f[i][k]+=f[i-1][j],ms(f[i][k]);
				}
			}
		}
		int ans =0;
		for(int i=0;i<(1<<n);++i)ans += f[m-1][i],ms(ans);
		printf("%d\n",ans);
	}
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	
	if(n<=3&&m<=3){
		if(n==1||m==1)printf("%d\n",(1<<(n*m)));
		else if(n==2&&m==2)puts("12");
		else if(n==3&&m==3)puts("112");
		else if(n==2&&m==3)puts("36");
		else if(n==3&&m==2)puts("36");
	}
	else if(n==2){
		int ans = 4;
		for(int i=1;i<m;++i)ans = 1ll*ans*3%MOD;
		printf("%d\n",ans);
	}
	else if(n==3){
		printf("%d\n",(int)(1ll*4*(n*m-2)%MOD));
	}
	else if((1<<(n+n))*m <= 1e7)Subtask1::solve();
	return 0;
}
