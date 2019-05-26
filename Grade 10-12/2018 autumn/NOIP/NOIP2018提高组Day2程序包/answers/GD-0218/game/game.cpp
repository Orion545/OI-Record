/*
45
*/
#include <cstdio>
using namespace std;
const int MOD=1e9+7;
typedef long long int64;
int n, m, ans;
int a[5][5];
int s[100005], stop;
inline int qpow(int b, int p, int mod){
	int res=1;
	while(p){
		if(p&1) res=(int64)res*b%mod;
		b=(int64)b*b%mod;
		p>>=1;
	}
	return res;
}
inline void solve1(){
	printf("%d\n", qpow(2, m, MOD));
}
inline void solve2(){
	printf("%d\n", (int64)qpow(3, m-1, MOD)*4%MOD);
}
void dfs2(int x, int y, int tot){
	tot=tot<<1|a[x][y];
	if(x==n-1 and y==m-1) s[++stop]=tot;
	if(y+1<m) dfs2(x, y+1, tot);
	if(x+1<n) dfs2(x+1, y, tot);
}
void dfs(int x, int y){
	if(x>=n){
		stop=0;
		dfs2(0, 0, 0);
		int i;
		for(i=1; i<=stop and s[i-1]<=s[i]; i++);
		if(i>stop) ans++;
		return;
	}
	a[x][y]=0;
	dfs(x+(y==m-1), (y+1)%m);
	a[x][y]=1;
	dfs(x+(y==m-1), (y+1)%m);
}
void brust(){
	dfs(0, 0);
	printf("%d\n", ans);
}
int main(){
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	
	scanf("%d %d", &n, &m);
	if(n==1) solve1();
	else if(n==2) solve2();
	else brust();
	return 0;
}
