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
#define M 100005
#define L long long
#define INF (1LL<<40)
using namespace std;

L f[M][3]={0},g[M][2]={0},p[M]={0};
struct edge{int u,next;}e[M*2]={0}; int head[M]={0},use=0;
void add(int x,int y){use++;e[use].u=y;e[use].next=head[x];head[x]=use;}
int n,m,fa[M]={0}; char op[10];
void dfs(int x){
	for(int i=head[x];i;i=e[i].next) if(e[i].u!=fa[x]){
		fa[e[i].u]=x;
		dfs(e[i].u);
	}
	f[x][1]=p[x]; f[x][0]=0; f[x][2]=0;
	for(int i=head[x];i;i=e[i].next) if(e[i].u!=fa[x]){
		f[x][1]+=min(f[e[i].u][0],min(f[e[i].u][1],f[e[i].u][2]));
		f[x][0]+=f[e[i].u][1];
		f[x][2]+=min(f[e[i].u][0],f[e[i].u][1]);
	}
}

int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d%s",&n,&m,op);
	for(int i=1;i<=n;i++) scanf("%lld",p+i);
	for(int i=1;i<n;i++){
		int x,y; scanf("%d%d",&x,&y);
		add(x,y); add(y,x);
	}
	while(m--){
		int a,x,b,y; 
		scanf("%d%d%d%d",&a,&x,&b,&y);
		L lastp1=p[a],lastp2=p[b];
		
		if(x==1) p[a]-=INF;else p[a]+=INF;
		if(y==1) p[b]-=INF;else p[b]+=INF;
		dfs(1);
		if(x==1) p[a]+=INF;else p[a]-=INF;
		if(y==1) p[b]+=INF;else p[b]-=INF;
		
		L ans=min(f[1][0],f[1][1]);
		
		if(x==0&&y==0&&ans>=INF){
			printf("-1\n");
			continue;
		}
		ans+=INF*x+INF*y;
		printf("%lld\n",ans);
	}
}
