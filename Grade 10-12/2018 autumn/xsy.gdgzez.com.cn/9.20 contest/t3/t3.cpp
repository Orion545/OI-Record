#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define mp make_pair
#include<cassert>
#define end DEEP_DARK_FANTASY
using namespace std;
inline int read(){
	int re=0,flag=1;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(isdigit(ch)) re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
int n,m,first[1010],cnte,siz[1010],son[1010],root,ans=0,sum;
struct edge{
	int to,next;
}a[1010];int vis[1010]={0},w[1010],c[1010],d[1010];
int dp[4010][4010];
inline void add(int u,int v){
	a[++cnte]=(edge){v,first[u]};first[u]=cnte;
	a[++cnte]=(edge){u,first[v]};first[v]=cnte;
}
int dfn[510],back[4010],end[510],clk;
vector<pair<int,int> >cho[510];
pair<int,int>q[4010];
void getroot(int u,int f){
	int i,v;siz[u]=cho[u].size();son[u]=0;
//	cout<<"	getroot "<<u<<' '<<f<<' '<<sum<<'\n';
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(v==f||vis[v]) continue;
		getroot(v,u);
		siz[u]+=siz[v];
		son[u]=max(son[u],siz[v]);
	}
	son[u]=max(son[u],sum-siz[u]);
	if(son[u]<son[root]) root=u;
}
void getdfn(int u,int f){
	int i,v;
	for(auto tmp:cho[u]) q[++clk]=tmp,back[clk]=u;
	dfn[u]=clk;
//	cout<<"	dfn "<<u<<' '<<dfn[u]<<'\n';
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(vis[v]||v==f) continue;
		getdfn(v,u);
	}
	end[u]=clk;
}
void dfs(int u){
	int i,v,j,cursum=sum;vis[u]=1;
	if(u==133) cout<<"dfs "<<u<<' '<<w[u]<<' '<<c[u]<<' '<<cursum<<' '<<cho[u].size()<<'\n';
	clk=0;memset(q,0,sizeof(q));
	getdfn(u,0);
	memset(dp[clk+1],0,sizeof(dp[clk+1]));
	for(i=clk;i>=1;i--){
		for(j=0;j<=m;j++){
			dp[i][j]=max(dp[i][j-1],dp[end[back[i]]+1][j]);
			if(!q[i].first) dp[i][j]=max(dp[i][j],dp[i+1][j]);
			if(j>=c[back[i]]*q[i].second)
				dp[i][j]=max(dp[i][j],dp[i+1][j-c[back[i]]*q[i].second]+w[back[i]]*q[i].second);
			if(dp[i][j]==6069567) cout<<"	dp "<<i<<' '<<j<<' '<<back[i]<<' '<<q[i].second<<' '<<dp[i][j]<<'\n';
		}
	}
	if(dp[1][m]>ans) cout<<"renew "<<m<<' '<<dp[1][m]<<'\n';
	ans=max(ans,dp[1][m]);
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(vis[v]) continue;
//		cout<<"prepare getroot "<<v<<' '<<siz[v]<<'\n';
		sum=((siz[v]>siz[u])?cursum-siz[u]:siz[v]);
		root=0;son[0]=sum;
		getroot(v,0);
		dfs(root);
	}
}
int main(){
	int T=read(),i,j;
	while(T--){
		n=read();m=read();sum=0;
		for(i=1;i<=n;i++) w[i]=read();
		for(i=1;i<=n;i++) c[i]=read();
		for(i=1;i<=n;i++){
			d[i]=read();j=0;
			cout<<"input d "<<i<<' '<<d[i]<<'\n';
			cho[i].clear();
			assert(cho[i].size()==0);
			while(d[i]>=(1<<j)){
				cho[i].push_back(mp(0,1<<j));
				d[i]-=(1<<j);
				j++;
				cout<<"check "<<d[i]<<' '<<j<<'\n';
//				if(j>10) exit(0);
			}
			if(d[i]) cho[i].push_back(mp(1,d[i]));
			else cho[i][cho[i].size()-1].first=1;
			sum+=cho[i].size();
		}
		memset(first,-1,sizeof(first));memset(a,0,sizeof(a));cnte=0;
		memset(vis,0,sizeof(vis));
		int t1,t2;
		for(i=1;i<n;i++){
			t1=read();t2=read();
			add(t1,t2);
		}
		son[0]=sum;root=0;
		getroot(1,0);ans=0;
		dfs(root);
		printf("%d\n",ans);
	}
}
