#include<vector>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#define N 5010
using namespace std;
vector<int> s[N];
int n,m,A[N],B[N],w[N],t,c,vis[N],g[N],d[2];
inline void gmin(int* A,int* B){
	for(int i=1;i<=n;++i)
		if(A[i]<B[i]){
			memcpy(B,A,N<<2);
			return;
		} else if(A[i]>B[i]) return;
}
inline void dfs(int x,int p){
	A[++t]=x;
	for(int v,i=0;i<s[x].size();++i)
		if(s[x][i]!=p) dfs(s[x][i],x);
}
inline int fc(int x,int p){
	if(vis[x]){ w[++t]=x; return 1; }
	vis[x]=1;
	for(int i=0;i<s[x].size();++i)
		if(s[x][i]!=p && fc(s[x][i],x)){
			w[++t]=x;  return x!=w[1];
		}
	return vis[x]=0;
}
inline void dgs(int x,int p){
	A[++c]=x;
	for(int v,i=0;i<s[x].size();++i){
		v=s[x][i];
		if(v==p||(v==d[0]&&x==d[1])||(x==d[0]&&v==d[1])) continue;
		dgs(v,x);
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int x,y,i=1;i<=m;++i){
		scanf("%d%d",&x,&y);
		s[x].push_back(y);
		s[y].push_back(x);
	}
	for(int i=1;i<=n;++i) sort(s[i].begin(),s[i].end());
	if(m<n){
		dfs(1,0);
		for(int i=1;i<=n;++i) printf("%d ",A[i]);
		return 0;
	} 
	fc(1,0); B[1]=n;
	for(int i=1;i<t;++i){
		d[0]=w[i]; d[1]=w[i+1];
		c=0; dgs(1,0);
		gmin(A,B);
	}
	for(int i=1;i<=n;++i) printf("%d ",B[i]);
}
