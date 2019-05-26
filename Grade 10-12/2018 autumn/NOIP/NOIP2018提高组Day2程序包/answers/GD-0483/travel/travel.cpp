#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
using namespace std;
int n,m,head[5005],tot,vis[5005],huan[5005],cnt,sta[5005],top;
struct Edge{
	int to,link;
}edge[10010];
void add(int a,int b){
	edge[++tot].to=b;
	edge[tot].link=head[a];
	head[a]=tot;
}
void dfs(int x){
	printf("%d ",x);
	vis[x]=1;
	priority_queue<int,vector<int>,greater<int> > q;
	for (int i=head[x];i;i=edge[i].link){
		int u=edge[i].to;
		if (vis[u]==1) continue;
		q.push(u);
	}
	while(!q.empty()){
		int u=q.top(); q.pop();
		dfs(u);
	}
	
}
void dfs2(int x,int fa){
//	printf("AC");
	vis[x]=1; sta[++top]=x;
	for (int i=head[x];i;i=edge[i].link){
		int u=edge[i].to;
		if (u==fa) continue;
		if (vis[u]==0) dfs2(u,x);
		else{
			while(sta[top+1]!=u&&top){
//				printf("%d\n",sta[top]);
				huan[++cnt]=sta[top];
				top--;
			}
		}
	}
	vis[x]=0; top--;
}
void dfs3(int x){
	printf("%d ",x);
	vis[x]=1;
	priority_queue<int,vector<int>,greater<int> >q;
	for (int i=head[x];i;i=edge[i].link){
		int u=edge[i].to;
		if (vis[u]==1) continue;
		if (u==huan[cnt]){
			printf("%d ",u);
			vis[u]=1;
			int i=cnt-1;
			while(huan[i]<huan[1]){
				printf("%d ",huan[i]);
				vis[huan[i]]=1;
				i--;
			}
			dfs3(huan[1]);
		}
		else{
			q.push(u);
		}
	}
	while(!q.empty()){
		int u=q.top();
		dfs(u); q.pop();
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	scanf("%d %d",&n,&m);
	for (int i=1;i<=m;i++){
		scanf("%d %d",&a,&b);
		add(a,b); add(b,a);
	}
	printf("\n");
	if (m==n-1)
		dfs(1);
//	else{
//		memset(vis,0,sizeof(vis));
//		dfs2(1,0);
//		for (int i=1;i<=cnt;i++) printf("%d ",huan[i]);
//		printf("\n");
//		memset(vis,0,sizeof(vis));
//		dfs3(1);
//	}
	return 0;
}
