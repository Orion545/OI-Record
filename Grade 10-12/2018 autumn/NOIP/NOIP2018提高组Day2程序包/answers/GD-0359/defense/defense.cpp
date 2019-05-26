#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<queue>
#include<vector>
#define INF 0x3f3f3f3f
using namespace std;
const int N=1e5+10;
inline int read(){
	int x=0;
	char ch=getchar();
	while (ch<48||ch>57) ch=getchar();
	while (ch>=48&&ch<=57) x=(x*10)+(ch^48),ch=getchar();
	return x;
}
struct Edge{
	int to,next;
}edges[N<<1];
int h[N],tot=0;
void AddEdge(int from,int to){
	edges[++tot]=(Edge){to,h[from]};
	h[from]=tot;
}
char s[5];
int n,m,p[N],v[N],in[N],f[N][2],end;
void dfs(int x){
	v[x]=1;
	end=x;
	for (int i=h[x];i;i=edges[i].next){
		int e=edges[i].to;
		if (v[e]) continue;
		f[e][0]+=f[x][1];
		f[e][1]+=f[x][0]+p[e];
		//printf("f[%d][0]=%d[1]=%d\n",e,f[e][0],f[e][1]);
		dfs(e);
	}
}
int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d %d %s",&n,&m,s);
	for (int i=1;i<=n;i++) p[i]=read();
	for (int i=1;i<=n-1;i++){
		int u=read(),v=read();
		AddEdge(u,v);
		AddEdge(v,u);
		in[u]++;
		in[v]++;
	}
		int now=1;
		for (int j=1;j<=n;j++) if (in[j]==1) {
			now=j;
			break;
		}
		for (int i=1;i<=m;i++){
			int a=read(),x=read(),b=read(),y=read();
			memset(f,0,sizeof(f));
			f[a][x^1]=f[b][y^1]=INF;
			memset(v,0,sizeof(v));
			dfs(now);
			if (min(f[end][0],f[end][1])>=INF) printf("-1\n");else printf("%d\n",min(f[end][0],f[end][1]));
		}
		return 0;
}
/*
5 3 A3
6 7 1 1 1
1 2
2 3
3 4
4 5
2 0 3 0
2 1 3 0
1 0 5 0
*/
