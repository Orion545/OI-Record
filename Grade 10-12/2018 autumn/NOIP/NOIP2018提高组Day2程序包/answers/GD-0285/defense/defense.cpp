#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
inline int rd(){
	char c=getchar();int x=0,flag=1;
	for(;c<'0'||c>'9';c=getchar())
		if(c=='-')
			flag=-1;
	for(;c>='0'&&c<='9';c=getchar())
		x=x*10+c-'0';
	return x*flag;
}
const int inf=0x3f3f3f3f;
struct edge{
	int to,nxt;
}e[200010];
int n,m,p[100010],head[100010]={0};
char type[3];int dp[100010][2];
void dfs(int u,int fa,int x,int a,int y,int b){
	int sum0=0,sum1=0;
	for(int i=head[u];i;i=e[i].nxt){
		int v=e[i].to;
		if(v==fa)
			continue;
		dfs(v,u,x,a,y,b);
		sum0=min(sum0+dp[v][1],inf);
		sum1=min(sum1+min(dp[v][0],dp[v][1]),inf);
	}
	dp[u][0]=sum0;
	dp[u][1]=min(sum1+p[u],inf);
	if(u==x)
		dp[u][a^1]=inf;
	if(u==y)
		dp[u][b^1]=inf;
	return;
}
void solve_bl(){
	for(int i=1;i<=m;i++){
		int x=rd(),a=rd(),y=rd(),b=rd();
		dfs(1,0,x,a,y,b);
		int ans=min(dp[1][0],dp[1][1]);
		printf("%d\n",(ans==inf)?-1:ans);
	}
	return;
}
int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	n=rd();m=rd();scanf("%s",type);
	for(int i=1;i<=n;i++)
		p[i]=rd();
	for(int i=1;i<n;i++){
		int u=rd(),v=rd();
		e[i]=(edge){v,head[u]};
		head[u]=i;
		e[n+i]=(edge){u,head[v]};
		head[v]=n+i;
	}
	if(n<=2000&&m<=2000)
		solve_bl();
	return 0;
}
