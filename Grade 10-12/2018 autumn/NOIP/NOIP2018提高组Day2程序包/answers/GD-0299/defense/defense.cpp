#include<cstdio>
#include<algorithm>
#include<cstring>
#define N 100010
#define INF 10000000010
using namespace std;
struct Edge{
	int p,q,n;
}e[N*2];
int num,h[N],a[N],p,pp,q,qq,n,m,flag;
long long dp[N][2];
char c[10];
void ljb(int p,int q){
	e[++num].n=h[p];
	e[num].q=q;
	e[num].p=p;
	h[p]=num;
}
void Dfs(int x,int fa){
	if(x!=p&&x!=q)dp[x][1]=a[x];
	for(int i=h[x];i!=0;i=e[i].n){
		if(e[i].q==fa)continue;
		Dfs(e[i].q,x);
		dp[x][1]=min(INF,dp[x][1]+min(dp[e[i].q][0],dp[e[i].q][1]));
		dp[x][0]=min(INF,dp[x][0]+dp[e[i].q][1]);
	}
}
int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",c+1);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<n;i++){
		scanf("%d%d",&p,&q);
		ljb(p,q);
		ljb(q,p);
	}
	for(int i=1;i<=m;i++){
		flag=1;
		scanf("%d%d%d%d",&p,&pp,&q,&qq);
		if(pp==0&&qq==0){
			for(int j=h[p];j!=0;j=e[j].n){
				if(e[j].q==q){
					flag=0;
					break;
				}
			}
		}
		if(!flag){
			printf("-1\n");
			continue;
		}
		memset(dp,0,sizeof(dp));
		if(pp){
			dp[p][pp]=a[p];
		}
		dp[p][!pp]=INF;
		if(qq){
			dp[q][qq]=a[q];
		}
		dp[q][!qq]=INF;
		Dfs(p,0);
//		for(int j=1;j<=n;j++){
//			printf("%lld %lld\n",dp[j][0],dp[j][1]);
//		}
		if(min(dp[p][1],dp[p][0])==INF)printf("-1\n");
		else printf("%lld\n",min(dp[p][1],dp[p][0]));
	}
}
