#include<bits/stdc++.h>
using namespace std;
int ans,cnt,head[50050],dp[50050][2],n,m,x,y,vl,cd[50050];
struct Ed{
	int nxt,to,vl;
}e[100050];
void add(int u,int v,int w){
	e[++cnt]=(Ed){head[u],v,w};head[u]=cnt;
	e[++cnt]=(Ed){head[v],u,w};head[v]=cnt;
}

void dfs(int u,int fa){
	dp[u][0]=0,dp[u][1]=0;
	for(int i=head[u];i;i=e[i].nxt){
		int v=e[i].to,w=e[i].vl;
		if(v==fa) continue;
		dfs(v,u);
		if(dp[v][0]+w>dp[u][0]) dp[u][1]=dp[u][0],dp[u][0]=dp[v][0]+w;
		else if(dp[v][0]+w>dp[u][1]) dp[u][1]=dp[v][0]+w;
		else if(dp[v][1]+w>dp[u][1]) dp[u][1]=dp[v][1]+w;
	}
	ans=max(ans,dp[u][0]+dp[u][1]);
}

bool judge(int x){
	int tmp=0,cnt=0;
	for(int i=1;i<n;i++){
		tmp+=cd[i];
		if(tmp==x) tmp=0,cnt++;
		else if(tmp>x) tmp=cd[i],cnt++;
	}
	if(tmp) cnt++;
	return cnt>=m;
}

int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1,vl;i<n;i++){
		scanf("%d%d%d",&x,&y,&vl);
		add(x,y,vl);
		if(y==x+1) cd[x]=vl;
	}
	if(m==1){
		dfs(1,-1);
		printf("%d\n",ans);
		return 0;
	}
	int l=0,r=1000000;
	while(l<=r){
		int mid=(l+r)>>1;
		if(judge(mid)) ans=mid,l=mid+1;
		else r=mid-1;
	}
	printf("%d\n",ans);
}
/*
7 1
1 2 10
1 3 5
2 4 9
2 5 8
3 6 6
3 7 7

9 1
1 2 6
2 3 3
3 4 5
4 5 10
6 2 4
7 2 9
8 4 7
9 4 4
*/
