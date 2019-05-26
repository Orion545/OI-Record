#include<bits/stdc++.h>
#define add(u,v) to[++top]=head[u],head[u]=top,w[top]=v
#define For(x) for(int h=head[x],o=w[h];h;o=w[h=to[h]])
#define N 100050
#define INF 100000000000000
using namespace std;
typedef long long ll;
ll f[N][2],g[N][2];
int p[N],top=0,head[N<<1],to[N<<1],w[N<<1];
int n,m,u,v,a,b,X,Y,bo;
char s[20];
inline void dfs2(int x,int fa){
	g[x][1]=p[x],g[x][0]=0;
	For(x) if (o!=fa){
		dfs2(o,x);
		g[x][1]+=min(g[o][0],g[o][1]),g[x][0]+=g[o][1];
	}
	if (x==a) g[x][1-X]=INF;
	if (x==b) g[x][1-Y]=INF;
}
int main(){
	freopen("defense.in","r",stdin),freopen("defense.out","w",stdout);
	scanf("%d%d%s",&n,&m,s);
	for (int i=1;i<=n;i++) scanf("%d",&p[i]);
	for (int i=1;i<n;i++) scanf("%d%d",&u,&v),add(u,v),add(v,u);
	while (m--){
		scanf("%d%d%d%d",&a,&X,&b,&Y);
		bo=0;
		if (X==0&&Y==0){
			For(a) if (o==b) {bo=1;break;}
		}
		if (bo) {printf("-1\n");continue;}
		dfs2(1,0);
		printf("%lld\n",min(g[1][0],g[1][1]));
	}
}
