#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 100005
#define LL long long 
int redd(){
   int re=0;char c=getchar();
   while(c<'0'||c>'9') c=getchar();
   while(c>='0'&&c<='9') re=re*10+c-'0',c=getchar();
   return re;
}
int head[N],tu[N*2][2],w=1;
void star(int a,int b){
	tu[w][0]=a;tu[w][1]=head[b];head[b]=w;w++;
	tu[w][0]=b;tu[w][1]=head[a];head[a]=w;w++;
}
LL v[N],dp[N][2];
void dp1(LL &x,int y){
	if(x==-1) return;
	if(dp[y][0]==-1) {x+=dp[y][1];return;}
	if(dp[y][1]==-1) {x+=dp[y][0];return;}
	x+=min(dp[y][0],dp[y][1]);
}
void dp0(LL &x,int y){
	if(x==-1) return;
	if(dp[y][1]==-1) {x=-1;return;}
	x+=dp[y][1];
}
bool flag;
void dfs(int a,int fa){
	for(int i=head[a];i;i=tu[i][1]){
		if(flag) return;
		int to=tu[i][0];if(to==fa) continue;
		dfs(to,a);
		dp1(dp[a][1],to); //printf("%d:%lld\n",a,dp[a][1]);
		dp0(dp[a][0],to); //printf("%d:%lld\n",a,dp[a][0]);
		if(dp[a][0]<0&&dp[a][1]<0) flag=true;
	}
	if(dp[a][1]>=0) dp[a][1]+=v[a];
//	printf("%d:%lld %lld\n",a,dp[a][1],dp[a][0]);
}
int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	char c1[5];int n,m;
	scanf("%d %d",&n,&m); scanf("%s",c1);
	for(int n1=1;n1<=n;n1++) scanf("%lld",&v[n1]);
	for(int n1=1;n1<n;n1++) star(redd(),redd());
	int a,x,b,y;
	while(m--){
		memset(dp,0,sizeof(dp));
		scanf("%d %d %d %d",&a,&x,&b,&y);
		dp[a][!x]=-1;dp[b][!y]=-1;
		flag=false;
		dfs(1,0);
		if(flag) {printf("-1\n");continue;}
		LL ans1=dp[1][0],ans2=dp[1][1];
		if(ans1==-1) printf("%lld\n",ans2);
		else if(ans2==-1) printf("%lld\n",ans1);
		else printf("%lld\n",min(ans1,ans2));
	} 
}

