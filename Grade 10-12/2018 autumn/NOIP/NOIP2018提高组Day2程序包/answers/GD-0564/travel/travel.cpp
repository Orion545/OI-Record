#include<bits/stdc++.h>
#define fo(i,a,b) for(i=a;i<=b;i++)
#define fd(i,a,b) for(i=a;i>=b;i--)
using namespace std;
const int maxn=5e3+5;
int n,m,i,j;
int ans[maxn],num,f[maxn],b[maxn],cnt;
bool B[maxn][maxn],p,bz[maxn];
vector<int>g[maxn];
void dfs(int x,int fa){
	bz[x]=1,ans[++num]=x,f[x]=fa;
	for(int i=0;i<g[x].size();i++){
		int y=g[x][i];
		if (y==fa||B[x][y]) continue;
		if (!bz[y]) dfs(y,x);else{
			for(int j=x;j!=y;j=f[j]) b[++cnt]=j;
			B[y][x]=1;
		}
	}
}
bool Dfs(int x,int fa){
	if (!p&&ans[num+1]<x) return 0;
	p|=x<ans[num+1],ans[++num]=x;
	for(int i=0;i<g[x].size();i++){
		int y=g[x][i];
		if (y!=fa&&!B[x][y]) {
			if (!Dfs(y,x)) return 0;
		}
	}return 1;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	fo(i,1,m){
		int x,y;
		scanf("%d%d",&x,&y);
		g[x].push_back(y),g[y].push_back(x);
	}
	fo(i,1,n) sort(g[i].begin(),g[i].end());
	dfs(1,0);
	memset(B,0,sizeof(B));
	fo(i,1,cnt){
		int x=b[i],y=f[x];
		B[x][y]=B[y][x]=1;
		p=num=0,Dfs(1,0);
		B[x][y]=B[y][x]=0;
	}
	fo(i,1,n) printf("%d%c",ans[i],i<n?' ':'\n');
	return 0; 
}
