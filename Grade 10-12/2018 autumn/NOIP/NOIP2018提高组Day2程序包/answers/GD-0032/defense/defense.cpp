#include<cstdio>
#include<cstring>
#define inf 1ll<<40
#define ll long long
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
ll dp[2050][2];
int tot=0;
int first[2050],p[2050];
struct enode{
	int nxt,y;
}e[4050];
void adde(int x,int y){
	e[tot].nxt=first[x];
	e[tot].y=y;
	first[x]=tot++;
}
void dfs(int x,int fa){
	for (int i=first[x];i>=0;i=e[i].nxt){
		int y=e[i].y;
		if (y!=fa) {
			dfs(y,x);
			dp[x][1]+=min(dp[y][1],dp[y][0]);
			dp[x][0]+=dp[y][1];
		}
	}
	dp[x][1]+=p[x];
}
int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	int n,m;char s[20];
	scanf("%d%d%s",&n,&m,s);
	for (int i=1;i<=n;i++)
	first[i]=-1,scanf("%d",&p[i]);
	for (int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		adde(x,y);
		adde(y,x);
	}
	for (int i=1;i<=m;i++){
		int a,x,b,y;
		scanf("%d%d%d%d",&a,&x,&b,&y);
		memset(dp,0,sizeof(dp));
		dp[a][1-x]=inf;
		dp[b][1-y]=inf;
		dfs(1,0);
		ll ans=min(dp[1][0],dp[1][1]);
		if (ans>=inf) ans=-1;
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
