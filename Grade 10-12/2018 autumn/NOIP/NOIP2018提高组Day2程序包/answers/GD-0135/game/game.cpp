#include<cstdio>
#include<cstring>
#include<algorithm>
#define LL long long
using namespace std;
const LL N=5,M=541212,Mo=1E9+7;
LL Map[N][N],f[M],g[M],n,m,tot=0,Ans=0,len;
struct Node{
	LL x,y;
}cnt[M];
void Dfs(LL x,LL y,LL zt,LL s){
	if (x==n&&y==m){
		cnt[++tot].x=zt;
		cnt[tot].y=s;
		return;
	}if (y<m) Dfs(x,y+1,zt,s+Map[x][y+1]*(1<<(len-x-y)));
	if (x<n) Dfs(x+1,y,zt+(1<<(len-x-y)),s+Map[x+1][y]*(1<<(len-x-y)));
}
bool cmp(Node a,Node b){
	return a.x<b.x;
}
bool Judge(){
	Dfs(1,1,0,Map[1][1]*(1<<(len-1)));
	sort(cnt+1,cnt+tot+1,cmp);
	for(LL i=2;i<=tot;i++)
		if (cnt[i].y<cnt[i-1].y)
			return 0;
	return 1;
}
void dfs(LL x,LL y){
	if (y>m) y=1,x++;
	if (x>n){
		tot=0;
		Ans+=Judge();
	}else{
		Map[x][y]=1;dfs(x,y+1);
		Map[x][y]=0;dfs(x,y+1);
	}
}
LL Quick(LL x,LL y){
	LL ret=1;
	while (y){
		if (y&1)
			ret=ret*x%Mo;
		x=x*x%Mo;y/=2;
	}return ret;
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	if (n<=3&&m<=3){
		len=n+m-1;dfs(1,1);
		printf("%lld\n",Ans);
		return 0;
	}f[0]=1;
	for(LL i=1;i<=200000;i++)
		f[i]=f[i-1]*3%Mo;
	g[0]=1;
	for(LL i=1;i<=200000;i++)
		g[i]=g[i-1]*2%Mo;
	if (n==1) printf("%lld\n",g[m]);
	if (n==2) printf("%lld\n",4*f[m-1]%Mo);
	if (n==3) printf("%lld\n",2*g[2*m]%Mo);
	return 0;
}
