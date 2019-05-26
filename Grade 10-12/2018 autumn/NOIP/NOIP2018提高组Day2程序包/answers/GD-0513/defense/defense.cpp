#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const int N=5000;
int last[N],cnt,f[N][2],n,m,hjy[N][N],p[N];
struct data{int to,next;}e[N*2];
char c[1];
void add(int x,int y){
	e[++cnt].to=y; e[cnt].next=last[x]; last[x]=cnt; 
	e[++cnt].to=x; e[cnt].next=last[y]; last[y]=cnt;
}

void dfs(int x,int fa){
	if (f[x][1]!=-1) f[x][1]=p[x];
	for (int i=last[x];i;i=e[i].next)
	if (e[i].to!=fa) {
		dfs(e[i].to,x);
		if (f[x][0]!=-1&&f[e[i].to][1]!=-1)f[x][0]+=f[e[i].to][1];
		if (f[e[i].to][1]==-1) f[x][0]=-1;
		if (f[x][1]!=-1&&f[e[i].to][1]!=-1&&f[e[i].to][0]!=-1) f[x][1]+=min(f[e[i].to][0],f[e[i].to][1]);
		if (f[x][1]!=-1&&f[e[i].to][1]==-1) f[x][1]+=f[e[i].to][0];	
		if (f[x][1]!=-1&&f[e[i].to][0]==-1) f[x][1]+=f[e[i].to][1];	
	}
}

int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d%s",&n,&m,c);
	for (int i=1;i<=n;i++) scanf("%d",&p[i]);
	for (int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		hjy[u][v]=1;
		hjy[v][u]=1;
	}
	for (int i=1;i<=m;i++){
		int a,x,b,y;
		scanf("%d%d%d%d",&a,&x,&b,&y);
		if (x==0&&y==0&&hjy[a][b]){
			printf("-1\n");
			continue;
		}
		memset(f,0,sizeof(f));
		if (x==1) f[a][0]=-1;
				else f[a][1]=-1;
		if (y==1) f[b][0]=-1;
				else f[b][1]=-1;
		dfs(1,0);
		int o;
		if (f[1][1]!=-1) o=f[1][1];
		if (f[1][0]<o&&f[1][0]!=-1) o=f[1][0];
		printf("%d\n",o);
	}
	return 0;
}
