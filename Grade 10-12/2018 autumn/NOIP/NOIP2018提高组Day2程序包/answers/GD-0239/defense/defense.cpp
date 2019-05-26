#include<iostream>
#include<queue>
#include<cstdio>
using namespace std;

int s[100005];
int n,m,f[100005][3],p[100005];
int a,b,x,y;
int h[100005],tot=0;
struct Edge{
	int x,next;
}e[500005];

inline void add_edge(int x,int y){
	e[++tot].x=y;
	e[tot].next=h[x],h[x]=tot;
}

void dfs(int x,int fa){
	int mn=2e9,k;
	bool flag=false;
	for(int i=h[x];i;i=e[i].next){
		if(e[i].x==fa)continue;
		flag=true;
		dfs(e[i].x,x);
		f[x][0]+=f[e[i].x][2];
		f[x][1]+=min(f[e[i].x][0],min(f[e[i].x][1],f[e[i].x][2]))+p[x];
		if(mn>f[e[i].x][1]-f[e[i].x][2]){
			mn=f[e[i].x][1]-f[e[i].x][2];
			k=e[i].x;
		}
	}
	for(int i=h[x];i;i=e[i].next){
		f[x][2]+=f[e[i].x][2];
		if(e[i].x==k)f[x][2]+=mn;
	}
	if(flag==false)f[x][1]=p[x];
}

int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d%s",&n,&m,s);
	for(int i=1;i<=n;i++)scanf("%d",p+i);
	for(int i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		add_edge(x,y);
		add_edge(y,x);
	}
	dfs(1,0);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d%d",&a,&x,&b,&y);
		if(x==1){
			printf("%d\n",f[1][1]);
		}else{
			printf("%d\n",f[1][2]);
		}
	}
	return 0;
}
