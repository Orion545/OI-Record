#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define ll long long 
#define maxn 100010
using namespace std;

int n,m,i,j,k,x,y,a,aa,b,bb;
int em,e[maxn*2],nx[maxn*2],ls[maxn];
ll f[maxn][2],c[maxn];
char tp1,tp2;

void insert(int x,int y){
	em++; e[em]=y; nx[em]=ls[x]; ls[x]=em;
	em++; e[em]=x; nx[em]=ls[y]; ls[y]=em;
}

void dfs(int x,int p){
	if (x==a) f[x][aa]=aa*c[x]; else
	if (x==b) f[x][bb]=bb*c[x]; else 
		f[x][0]=0,f[x][1]=c[x];
	for(int i=ls[x];i;i=nx[i]) if (e[i]!=p){
		dfs(e[i],x);
		if (f[x][1]!=-1){
			if (f[e[i]][0]!=-1&&f[e[i]][1]!=-1) f[x][1]+=min(f[e[i]][0],f[e[i]][1]);
			else if (f[e[i]][0]!=-1) f[x][1]+=f[e[i]][0];
			else if (f[e[i]][1]!=-1) f[x][1]+=f[e[i]][1];
			else f[x][1]=-1;
		} 
		if (f[x][0]!=-1){
			if (f[e[i]][1]!=-1) f[x][0]+=f[e[i]][1];
			else f[x][0]=-1;
		}
	}
}

int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d %d %c%c",&n,&m,&tp1,&tp2);
	for(i=1;i<=n;i++) scanf("%lld",&c[i]);
	for(i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		insert(x,y);
	}
	while (m--){
		scanf("%d%d%d%d",&a,&aa,&b,&bb);
		for(i=1;i<=n;i++) f[i][0]=f[i][1]=-1;
		dfs(1,0);
		if (f[1][0]==-1&&f[1][1]==-1) printf("-1\n");
		else if (f[1][0]!=-1&&f[1][1]!=-1) printf("%lld\n",min(f[1][0],f[1][1]));
		else if (f[1][0]!=-1) printf("%lld\n",f[1][0]);
		else if (f[1][1]!=-1) printf("%lld\n",f[1][1]);
	}
}
