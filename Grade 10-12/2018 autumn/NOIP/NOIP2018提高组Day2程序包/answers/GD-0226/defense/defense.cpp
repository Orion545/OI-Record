#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;
int dp[5000][2];
int key[110000];
string s;
int n,m;
int head[110000],a[220000],al[220000],an=0;
void addline(int u,int v){
	a[an]=v;
	al[an]=head[u];
	head[u]=an;
	an++;
	return;
}
void dfs1(int now,int father){
	if(dp[now][1]!=-1)dp[now][1]=key[now];
	if(dp[now][0]!=-1)dp[now][0]=0;
	int v,sum0=0,sum1=0;
	for(int l=head[now];l!=-1;l=al[l]){
		v=a[l];
		if(v==father)continue;
		dfs1(v,now);
		if(dp[v][0]==-1&&dp[v][1]==-1){
			dp[now][0]=-1;
			dp[now][1]=-1;
			break;
		}
		else if(dp[v][0]==-1){
			sum0+=dp[v][1];
			sum1+=dp[v][1];
		}
		else if(dp[v][1]==-1){
			dp[now][0]=-1;
			sum1+=dp[v][0];
		}
		else{
			sum0+=dp[v][1];
			sum1+=min(dp[v][0],dp[v][1]);
		}
	}
	if(dp[now][0]!=-1)dp[now][0]+=sum0;
	if(dp[now][1]!=-1)dp[now][1]+=sum1;
	return;
}
void solve1(){
	int p1,x,p2,y;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d%d",&p1,&x,&p2,&y);
		memset(dp,0,sizeof(dp));
		dp[p1][x^1]=-1;
		dp[p2][y^1]=-1;
		dfs1(1,0);
		if(dp[1][0]==-1&&dp[1][1]==-1)printf("-1\n");
		else if(dp[1][0]>=0&&dp[1][1]>=0)printf("%d\n",min(dp[1][0],dp[1][1]));
		else if(dp[1][0]==-1)printf("%d\n",dp[1][1]);
		else printf("%d\n",dp[1][0]);
	}
}
int main(){
	memset(head,-1,sizeof(head));
	memset(al,-1,sizeof(al));
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>s;
	for(int i=1;i<=n;i++)
		scanf("%d",&key[i]);
	int u,v;
	for(int i=1;i<=n-1;i++){
		scanf("%d%d",&u,&v);
		addline(u,v);
		addline(v,u);
	}
	if(n<=2000&&m<=2000)
		solve1();
	
	return 0;
}
