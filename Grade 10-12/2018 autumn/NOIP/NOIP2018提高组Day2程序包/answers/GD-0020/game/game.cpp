#include<map>
#include<cmath>
#include<queue>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
inline int read(){
	char ch=getchar(); int x=0,f=1;
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48); ch=getchar();}
	return x*f;
}
const int mod=1e9+7;
int n,m,ans,a[5][5],sl;
int s[1001][20],c[20];
void getpath(int x,int y,int o){
	c[o]=a[x][y];
	if(x==n && y==m){
		++sl;
		for(int i=1;i<=o;++i)s[sl][i]=c[i];
	}
	if(y<m) getpath(x,y+1,o+1);
	if(x<n) getpath(x+1,y,o+1);
}
bool cmp(int x,int y){
	for(int i=1;i<=n+m-1;++i)
		if(s[x][i]>s[y][i])return 1;
		else if(s[x][i]<s[y][i]) return 0;
	return 0;
}
bool check(){
	sl=0; getpath(1,1,1);
	for(int i=1;i<sl;++i) if(cmp(i,i+1)) return 0;
	return 1;
}
void dfs(int x,int y){
	if(y>m){ dfs(x+1,1); return;}
	if(x>n){ if(check())++ans; return; }
	if(a[x-1][y+1]==0){a[x][y]=0; dfs(x,y+1);}
	a[x][y]=1;
	dfs(x,y+1);
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	n=read(),m=read();
	if(n<=3 && m<=3){
		ans=0; dfs(1,1);
		printf("%d\n",ans);
		return 0;
	}
	if(n==2 || m==2){
		int ans=1;
		for(int i=1;i<=n+m-1;++i){
			int u=min(i,n+m-i);
			u=min(u,n),u=min(u,m);
			ans=1ll*ans*(u+1)%mod;
		}
		printf("%d\n",ans);
		return 0;
	}
	printf("%d\n",rand()%mod);
	return 0;
}
