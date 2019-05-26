#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cctype>
#include<cstdlib>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<vector>
#include<algorithm>
#define inf 5005
using namespace std;

int n,m;

struct edge{
	int y,nxt,p;
	edge(){}
	edge(int yy,int nn){
		y=yy,nxt=nn;
		p=1;
	}
}e[inf*2];
int head[inf],ecnt=1;

void addedge(int x,int y){
	e[++ecnt]=edge(y,head[x]);
	head[x]=ecnt;
	return;
}

int tmp[inf],T;
set <int> nxte[inf];

void dfs(int u,int last){
	tmp[++T]=u;
	nxte[u].clear();
	for (int i=head[u];i;i=e[i].nxt){
		if (e[i].y!=last && e[i].p){
			nxte[u].insert(e[i].y);
		}
	}
	for (set <int>::iterator it=nxte[u].begin();it!=nxte[u].end();it++){
		int v=(*it);
		dfs(v,u);
	}
	return;
}

void cal1(void){
	memset(tmp,0,sizeof(tmp));
	T=0;
	dfs(1,0);
	for (int i=1;i<=n;i++){
		printf("%d ",tmp[i]);
	}
	return;
}

int ans[inf],cir[inf],cnt,vis[inf];
int t1,t2,te;

void dfs1(int u,int last){
	vis[u]=1;
	for (int i=head[u];i;i=e[i].nxt){
		int v=e[i].y;
		if (vis[v] && i!=(last^1)){
			t1=u,t2=v,te=i;
			return;
		}
		if (i!=(last^1)){
			dfs1(v,i);
			if (t1){
				return;
			}
		}
	}
	return;
}

bool dfs2(int u,int last){
	for (int i=head[u];i;i=e[i].nxt){
		int v=e[i].y;
		if (u!=t1 && v==t2){
			cir[++cnt]=i;
			return 1;
		}
		if (i!=(last^1) && i!=te && i!=(te^1)){
			if (dfs2(v,i)){
				cir[++cnt]=i;
				return 1;
			}
		}
	}
	return 0;
}

void findcir(){
	dfs1(1,-1);
	cnt=0;
	dfs2(t1,-1);
	cir[++cnt]=te;
	return;
}

void check(void){
	int flag=0,flag2=1;
	for (int i=1;i<=n;i++){
		if (ans[i]>tmp[i]){
			flag=1;
			break;
		}
		else if (ans[i]<tmp[i]){
			return;
		}
		if (ans[i]!=ans[i-1]+1){
			flag2=0;
		}
	}
	if (flag2 && !flag){
		for (int i=1;i<=n;i++){
			printf("%d ",ans[i]);
		}
		exit(0);
	}
	if (flag){
		for (int i=1;i<=n;i++){
			ans[i]=tmp[i];
		}
	}
	return;
}

void cal2(void){
	findcir();
	ans[1]=n+1;
	for (int i=1;i<=cnt;i++){
		if (i==500){
			i=500;
		}
		e[cir[i]].p=e[cir[i]^1].p=0;
		T=0;
		dfs(1,0);
		check();
		e[cir[i]].p=e[cir[i]^1].p=1;
	}
	for (int i=1;i<=n;i++){
		printf("%d ",ans[i]);
	}
	return;
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	int x,y;
	for (int i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		addedge(x,y);
		addedge(y,x);
	}
	if (n==m+1){
		cal1();
	}
	else{
		cal2();
	}
	return 0;
} 
