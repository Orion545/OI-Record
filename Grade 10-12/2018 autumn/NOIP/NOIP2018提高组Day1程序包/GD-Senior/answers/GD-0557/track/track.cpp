#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
struct edge{int to,val;};
vector<edge> G[50005];
int n,m,a,b,c,Cnt,Cntc,Root,Cnt3,CntVal,CntRoad,Cs[50005];
int dp[50005],Ans[50005],Cnt4,f[50005][17],Sum[50005],Ans2,Dep[50005];
bool vis[50005],used[50005];
void dfs1(int node){
	vis[node]=true;
	int sz=(int)G[node].size();
	if(sz<2) Root=node;
	if(Root) return;
	for(int i=0;i<sz;i++)
		if(!vis[G[node][i].to])
			dfs1(G[node][i].to);
}
void dfs2(int node,int lim){
	vis[node]=true;
	if(CntVal>=lim) {
		CntVal=0;
		CntRoad++;
	}
	int sz=G[node].size();
	for(int i=0;i<sz;i++)
		if(!vis[G[node][i].to]){
			CntVal+=G[node][i].val;
			dfs2(G[node][i].to,lim);
		}
}
void dfs3(int node){
	vis[node]=true;
	int sz=G[node].size(); int Ret=0;
	for(int i=0;i<sz;i++)
		if(!vis[G[node][i].to]){
			dfs3(G[node][i].to);
			Ret=max(dp[G[node][i].to]+G[node][i].val,Ret);
		}
	dp[node]=Ret;
}
void dfs4(int node){
	vis[node]=1;
	int sz=G[node].size();
	for(int i=0;i<sz;i++)
		if(!vis[G[node][i].to]){
			Sum[G[node][i].to]=Sum[node]+G[node][i].val;
			f[G[node][i].to][0]=node;
			Dep[G[node][i].to]=Dep[node]+1;
			dfs4(G[node][i].to);
		}
}
bool check(int x){
	memset(vis,0,sizeof(vis));
	CntVal=0; CntRoad=0;
	dfs2(Root,x);
	if(CntRoad>=m) return true;
	return false;
}
bool check2(int x){
	CntRoad=0;
	for(int i=1;i<n;i++)
		used[i]=0;
	for(int i=1;i<n;i++){
		if(Cs[i]>=x) CntRoad++;
		else {
			int Minabs=2100000000,Pos2=-1;
			for(int j=i+1;j<n;j++)
				if(Cs[i]+Cs[j]>=x&&Cs[i]+Cs[j]-x<Minabs&&!used[j]){
					Minabs=Cs[i]+Cs[j]-x;
					Pos2=j;
				}
			if(Pos2!=-1){
				CntRoad++;
				used[Pos2]=1;
			}
		}
	}
	if(CntRoad>=m) return true;
	return false;
}
int GetLCA(int x,int y){
	if(Dep[x]<Dep[y]) swap(x,y);
	while(Dep[x]>Dep[y]){
		int jump=0;
		for(;jump<=16;jump++)
			if(Dep[f[x][jump]]<Dep[y]) break;
		x=f[x][jump-1];
	}
	while(x!=y){
		int jump=0;
		for(;jump<=16;jump++)
			if(f[x][jump]==f[y][jump]) break;
		if(jump==0) x=f[x][0],y=f[y][0];
		else{x=f[x][jump-1]; y=f[y][jump-1];}
	}
	return x;
}
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++){
		scanf("%d%d%d",&a,&b,&c);
		Cs[i]=c;
		if(a==1) Cnt3++;
		Cntc+=c;
		if(b==a+1) Cnt++;
		G[a].push_back((edge){b,c});
		G[b].push_back((edge){a,c});
	}
	if(Cnt==n-1){
		dfs1(1);
		int l=0,r=Cntc;
		while(l<=r){
			int mid=(l+r)>>1;
			if(check(mid)) l=mid+1;
			else r=mid-1;
		}
		printf("%d",l-1);
		return 0;
	}else if(m==1){
		if(n<5005){
			Dep[1]=1; dfs4(1);
			for(int j=1;j<=16;j++)
			for(int i=1;i<=n;i++)
				f[i][j]=f[f[i][j-1]][j-1];
			for(int i=1;i<n;i++)
			for(int j=i+1;j<=n;j++)
				Ans2=max(Ans2,Sum[i]+Sum[j]-(Sum[GetLCA(i,j)]<<1));
			printf("%d",Ans2);
		}else{
			dfs3(1);
			int sz=G[1].size();
			for(int i=0;i<sz;i++)
				Ans[++Cnt4]=dp[G[1][i].to]+G[1][i].val;
			sort(Ans+1,Ans+1+Cnt4);
			printf("%d",Ans[1]+Ans[2]);
		}
		return 0;
	}else if(Cnt3==n-1){
		int l=0,r=Cntc;
		while(l<=r){
			int mid=(l+r)>>1;
			if(check2(mid)) l=mid+1;
			else r=mid-1;
		}
		printf("%d",l-1);
		return 0;
	}
	return 0;
}
