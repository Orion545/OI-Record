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
#define ll long long
#define INF (int)2e9
#define inf 20005
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

int val[inf],f[inf][2],p[inf];
int X,Y,t1,t2;

void dfs(int u,int last){
	f[u][1]=val[u];
	f[u][0]=0;
	if (p[u]==1){
		f[u][1]=INF;
	}
	else if (p[u]==0){
		f[u][0]=INF;
	}
	for (int i=head[u];i;i=e[i].nxt){
		int v=e[i].y;
		if (v!=last){
			dfs(v,u);
			if (p[u]!=0){
				if (f[v][1]==INF){
					p[u]=0;
					f[u][0]=INF;
				}
				else{
					f[u][0]+=f[v][1];
				}
			}
			if (p[u]!=1){
				f[u][1]+=min(f[v][0],f[v][1]);
			}
		}
	}
	return;
}

bool check(void){
	for (int i=head[X];i;i=e[i].nxt){
		if (e[i].y==Y){
			return 0;
		}
	}
	return 1;
}

int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	char opt[5];
	scanf("%d%d%s",&n,&m,opt);
	for (int i=1;i<=n;i++){
		scanf("%d",&val[i]);
	}
	for (int i=1;i<n;i++){
		scanf("%d%d",&X,&Y);
		addedge(X,Y);
		addedge(Y,X);
	}
	for (int i=1;i<=m;i++){
		scanf("%d%d%d%d",&X,&t1,&Y,&t2);
		if (!check() && t1==0 && t2==0){
			puts("-1");
			continue;
		}
		memset(p,-1,sizeof(p));
		p[Y]=(!t2);
		dfs(X,0);
		printf("%d\n",f[X][t1]);
	}
	return 0;
}
