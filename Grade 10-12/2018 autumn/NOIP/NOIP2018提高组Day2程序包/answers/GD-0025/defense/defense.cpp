#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<fstream>
#include<algorithm>
#include<cstring>
#define maxn 200005
#define inf 10000000
#define cin fin
#define cout fout
using namespace std;
ifstream fin("defense.in");
ofstream fout("defense.out");
struct edge{
	int from,to,next;
};struct edge e[maxn];int cnt_e=0;
int head[maxn],vis[maxn],ans[maxn];int cnt_ans=0;
void adde(int start,int end){
	cnt_e++;
	e[cnt_e].from=start,e[cnt_e].to=end,e[cnt_e].next=head[start];
	head[start]=cnt_e;
}
int v[maxn],deep[maxn];
int dp[maxn][1];// 1:x 1 fa 1 2: x1 fa 0 3: x 0 fa 1 4: x 0 fa 0
void dfs1(int x,int fa,int dep){
	deep[x]=dep;
	if(!e[head[x]].to){
		dp[x][0]=0;
		dp[x][1]=v[x];
		return;
	}
	dp[x][1]=v[x];dp[x][0]=0;
	for(int i=head[x];i;i=e[i].next){
		int to=e[i].to;
		if(to==fa) continue;
		dfs1(to,x,dep+1);
		dp[x][1]+=min(dp[to][1],dp[to][0]);
		dp[x][0]+=dp[to][1];
	}
}
int res=0;
void dfs2(int now,int fa,int a,int x,int b,int y,int &status){
	if(now==a){
		if(a==0){
			res+=dp[b][1];
			status=0;
			return;
		}
		else{
			if(b==0){
				res+=dp[b][0];
				status=1;
				return;
			}
			else{
				res+=dp[b][1];
				status=1;
				return;
			}
		}
	}
	for(int i=head[x];i;i=e[i].next){
		int to=e[i].to;
		if(to==fa) continue;
		dfs2(to,x,a,x,b,y,status);
	}
	if(status==0) status=1;
	else if(status==1){
		if(dp[x][1]<dp[x][0]) status=1;
		else status=0;
	}
}
int main(){
	memset(dp,inf,sizeof(dp));
	int n,m;char opt[10];
	cin>>n>>m>>opt;
	for(int i=1;i<=n;i++){
		cin>>v[i];
	}
	for(int i=1;i<=n-1;i++){
		int start,end;
		cin>>start>>end;
		adde(start,end);
		adde(end,start);
	}
	dfs1(1,0,1);
	int len=strlen(opt);
	if(opt[len-1]-'0'==1){
		for(int i=1;i<=m;i++){
			int a,x,b,y;
			cin>>a>>x;
			cout<<dp[a][1]<<endl;
		}
		return 0;
	}
	else if(opt[len-1]-'0'==2){
		for(int i=1;i<=m;i++){
			int a,x,b,y;
			cin>>a>>x>>b>>y;
			if(x==0&&y==0){
				cout<<-1<<endl;
				continue;
			}
			if(deep[a]>deep[b]){
				swap(a,b),swap(x,y);
			}
			int status=-1;
			dfs2(1,0,a,x,b,y,status);
			cout<<dp[1][status]<<endl;
		}
	}
	
}
