#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=3e4+10;
int w[N*2],ne[N*2],la[N],fa[N],s[N],ans[N],n,m,t;
int sx,sy,vis[N],tf[N],ban[N],dep[N],lx[N],f[N];
struct edge{int x,y,fr;}d[N*2];
bool comp(edge a,edge b){return a.y>b.y;}
void link(int x,int y,int z){
	w[++t]=y;
	ne[t]=la[x];
	la[x]=t;
	lx[t]=z;
}
void update(){
	int can=0;
	for (int i=1;i<=n;i++)
		if (s[i]!=ans[i]){
			can=(s[i]<ans[i]);
			break;
		}
	if (can)memcpy(ans,s,sizeof s);
}
void dfs(int x){
	s[++t]=x;
	for (int y=la[x];y;y=ne[y]){
		int z=w[y];
		if (z==fa[x]||ban[lx[y]])continue;
		fa[z]=x;
		dfs(z);
	}
}
void find(int x){
	vis[x]=1;ans[++t]=x;
	for (int y=la[x];y;y=ne[y]){
		int z=w[y];
		if (z==fa[x])continue;
		if (vis[z]){
			sx=x;
			sy=z;
			continue;
		}
		f[z]=fa[z]=x;
		tf[z]=lx[y];
		dep[z]=dep[x]+1;
		find(z);
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=m;i++){
		scanf("%d%d",&d[i].x,&d[i].y);d[i].fr=i*2;
		d[i+m].x=d[i].y,d[i+m].y=d[i].x;d[i+m].fr=i*2+1;
	}
	sort(d+1,d+m*2+1,comp);
	for (int i=1;i<=2*m;i++)link(d[i].x,d[i].y,d[i].fr);
	t=0;
	if (n==m+1){
		dfs(1);
		for (int i=1;i<=n;i++)printf("%d ",s[i]);
		return 0;
	}
	find(1);
	if (dep[sx]<dep[sy])swap(sx,sy);
	for (;sx!=sy;sx=f[sx]){
		ban[tf[sx]]=ban[tf[sx]^1]=1;
		t=0;dfs(1);update();
		ban[tf[sx]]=ban[tf[sx]^1]=0;
	}
	for (int i=1;i<=n;i++)printf("%d ",ans[i]);
	return 0;
}
