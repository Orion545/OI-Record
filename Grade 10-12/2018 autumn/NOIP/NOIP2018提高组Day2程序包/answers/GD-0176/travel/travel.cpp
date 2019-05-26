#include<bits/stdc++.h>
using namespace std;
int n,m,u,v,cnt=0,len[10000],node[10000];
bool vis[10000],pot[10000];
vector <int> to[10000];
/*bool dfs(int x,int f){
	int siz=to[x].size();
	vis[x]=true;
	bool flag=false;
	for(int i=0;i<siz;i++){
		if(to[x][i]!=f){
			if(vis[to[x][i]]){flag=false;continue;}
			if(dfs(to[x][i],x)){flag=true;}
		}
	}
	pot[x]=flag;
	return flag;
}*/
void dfs(int x,int f){
	printf("%d ",x);
	int siz=to[x].size(),c=0;
	for(int i=0;i<siz;i++){
	    if(to[x][i]!=f){
	    	c++;len[cnt+c]=to[x][i];
	    }
	}
	sort(len+cnt+1,len+cnt+c+1);
	int l=cnt+1,r=cnt+c;
	cnt+=c;
	for(int i=l;i<=r;i++){
		dfs(len[i],x);
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){vis[i]=false;}
	for(int i=1;i<=m;i++){
		scanf("%d%d",&u,&v);
		to[u].push_back(v);
		to[v].push_back(u);
	}
	for(int i=1;i<=m;i++){vis[i]=false;}
	dfs(1,0);
}
