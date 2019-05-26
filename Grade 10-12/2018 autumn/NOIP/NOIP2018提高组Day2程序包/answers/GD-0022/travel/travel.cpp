#include<iostream>
#include<cstdio>
#include<queue>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<map>
using namespace std;
#define maxn 5005
int n,m;
int mp[maxn][maxn];
bool vis[maxn];
int cnt;
int ans[maxn];
int head[maxn];
int tot=1;
struct node{
	int to;
	int nxt;
}b[maxn<<1];
void into(int x,int y){
	b[++tot].to=y;
	b[tot].nxt=head[x];
	head[x]=tot;
}
void dfs(int root){
	vis[root]=true;
	for(int i=1;i<=mp[root][0];i++){
		int y=mp[root][i];
		if(vis[y])continue;
		ans[++cnt]=y;
		dfs(y);
	}
}
int dfn[maxn];
int low[maxn];
int total;
bool bridge[maxn];
void tarjan(int root,int inedge){
	dfn[root]=low[root]=++total;
	for(int i=head[root];i;i=b[i].nxt){
		int y=b[i].to;		
//		cout<<"check"<<" "<<root<<" "<<y<<endl;
		if(!dfn[y]){
			tarjan(y,i);
			low[root]=min(low[root],low[y]);
		}
		else if(inedge!=i^1){
			low[root]=min(low[root],dfn[y]);
			
		}
	}
        if(dfn[root]<low[b[inedge^1].to]){
  //      	cout<<"c"<<" "<<root<<" "<<y<<endl;
        	bridge[inedge]=bridge[inedge^1]=true;
        }	
}
int dd;
void dfs2(int root,int fa){
	vis[root]=true;
	if(dd)return;
	for(int i=head[root];i;i=b[i].nxt){
		int y=b[i].to;
		if(y==fa)continue;		
		if(vis[y] && !dd){
			dd=y;
			return;
		}
		dfs2(y,root);
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("traval.out","w",stdout);
	scanf("%d%d",&n,&m);
	int x,y;
	for(int i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		mp[x][++mp[x][0]]=y;
		mp[y][++mp[y][0]]=x;
		into(x,y);
		into(y,x);
	}
	for(int i=1;i<=n;i++){
		sort(mp[i]+1,mp[i]+mp[i][0]+1);
	}
	ans[++cnt]=1;
	dfs(1);
	for(int i=1;i<=cnt;i++){
		printf("%d ",ans[i]);
	}
}
