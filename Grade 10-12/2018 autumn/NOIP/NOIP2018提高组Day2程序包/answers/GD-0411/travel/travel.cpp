#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<climits>
#include<ctime>
#include<cctype>
#include<algorithm>
#include<queue>
#include<stack>
#include<string>
#include<set>
#include<map>
#include<vector>
using namespace std;
const int N=5005;
int n,m,u,v,cnt,fu,fv,head[N],ans[N],pos[N],pre[N],ring[N],to[N*2],nxt[N*2],rev[N*2];
vector<int> e[N];
bool flag,vis[N],use[N*2];
map<int,int> id[N];
void adde(int u,int v){
	to[++cnt]=v;
	nxt[cnt]=head[u];
	head[u]=cnt;
}
void get1(int pre,int u){
	vis[u]=true;
	int v;
	for(int i=head[u];i;i=nxt[i]){
		v=to[i];
		if(!vis[v]){
			get1(u,v);
			if(flag){
				return;
			}
		}else if(v!=pre){
			flag=true;
			fu=u;
			fv=v;
			ring[++ring[0]]=i;
			return;
		}
	}
}
void get2(int u){
	vis[u]=true;
	if(u==fv){
		while(u!=fu){
			ring[++ring[0]]=pre[u];
			u=to[rev[pre[u]]];
		}
		return;
	}
	int v;
	for(int i=head[u];i;i=nxt[i]){
		v=to[i];
		if(!vis[v]&&!((u==fu&&v==fv)||(u==fv&&v==fu))){
			pre[v]=i;
			get2(v);
		}
	}
}
void getring(){
	memset(vis,0,sizeof(vis));
	get1(0,1);
	memset(vis,0,sizeof(vis));
	get2(fu);
}
void dfs(int u){
	pos[++pos[0]]=u;
	vis[u]=true;
	int v;
	for(int i=head[u];i;i=nxt[i]){
		v=to[i];
		if(!use[i]&&!vis[v]){
			dfs(v);
		}
	}
}
void check(int a[],int b[]){
	bool flag=true;
	for(int i=1;i<=n;i++){
		if(a[i]!=b[i]){
			flag=a[i]<b[i];
			break;
		}
	}
	if(!flag){
		for(int i=1;i<=n;i++){
			a[i]=b[i];
		}
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	for(int i=1;i<=n;i++){
		sort(e[i].begin(),e[i].end());
		for(int j=e[i].size()-1;j>=0;j--){
			adde(i,e[i][j]);
			id[i][e[i][j]]=cnt;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=head[i];j;j=nxt[j]){
			rev[j]=id[to[j]][i];
		}
	}
	if(m==n-1){
		dfs(1);
		for(int i=1;i<=n;i++){
			printf("%d ",pos[i]);
		}
	}else{
		getring();
		memset(ans,127,sizeof(ans));
		for(int i=1;i<=ring[0];i++){
			memset(vis,0,sizeof(vis));
			pos[0]=0;
			use[ring[i]]=use[rev[ring[i]]]=true;
			dfs(1);
			check(ans,pos);
			use[ring[i]]=use[rev[ring[i]]]=false;
		}
		for(int i=1;i<=n;i++){
			printf("%d ",ans[i]);
		}
	}
	return 0;
}
