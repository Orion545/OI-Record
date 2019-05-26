#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
typedef long long ll;
const int N=2010;
int w[N*2],ne[N*2],la[N],fa[N];
ll f[N][2];
int da,db,dx,dy,n,m,t,v[N];
void link(int x,int y){
	w[++t]=y;
	ne[t]=la[x];
	la[x]=t;
}
void dfs(int x){
	f[x][0]=0;f[x][1]=v[x];
	for (int y=la[x];y;y=ne[y]){
		int z=w[y];
		if (z==fa[x])continue;
		fa[z]=x;
		dfs(z);
		f[x][1]+=min(f[z][0],f[z][1]);
		f[x][0]+=f[z][1];
	}
	if (x==da)f[x][dx^1]=1<<30;
	if (x==db)f[x][dy^1]=1<<30;
}
int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	cin>>n>>m;getchar();getchar();getchar();
	for (int i=1;i<=n;i++)scanf("%d",&v[i]);
	for (int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		link(x,y);
		link(y,x);
	}
	for (int i=1;i<=m;i++){
		scanf("%d%d%d%d",&da,&dx,&db,&dy);
		dfs(1);
		if (min(f[1][0],f[1][1])>=1LL<<30)printf("-1\n");
		else printf("%d\n",min(f[1][0],f[1][1]));
	}
}
