#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<algorithm>
#include<stack>
#define M 5005
using namespace std;
int n,m; vector<int> v[M];
int nx=0,ny=0,t=0;
int vis[M]={0},now[M]={0},ans[M]={0};

void dfs(int x,int fa){
	vis[x]=1; now[++t]=x;
	for(int i=0;i<v[x].size();i++)
	if(v[x][i]!=fa&&vis[v[x][i]]==0){
		if(nx==x&&ny==v[x][i]) continue;
		if(ny==x&&nx==v[x][i]) continue;
		dfs(v[x][i],x);
	}
}
int U[M]={0},V[M]={0};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int x,y; 
		scanf("%d%d",&x,&y);
		U[i]=x; V[i]=y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for(int i=1;i<=n;i++) 
	sort(v[i].begin(),v[i].end());
	if(n==m+1){
		dfs(1,0);
		for(int i=1;i<=n;i++) printf("%d ",now[i]);
		return 0;
	}
	for(int i=1;i<=n;i++) ans[i]=n-i+1;
	for(int i=1;i<=m;i++){
		memset(vis,0,sizeof(vis));
		memset(now,0,sizeof(now)); t=0;
		nx=U[i]; ny=V[i];
		dfs(1,0);
		if(t!=n) continue;
		for(int i=1;i<=n;i++){
			if(now[i]==ans[i]) continue;
			if(now[i]<ans[i]){
				for(int j=1;j<=n;j++)
				ans[j]=now[j];
				break;
			}else break;
		}
	}
	for(int i=1;i<=n;i++) printf("%d ",ans[i]);
}
