#include<iostream>
#include<stdio.h>
#include<string.h>
#define N 620000
using namespace std;
long long g[N][2];
long long Next[N],v[N],a[N],h[N];
long long must[N];
long long n,m;
char s[1200];
long long f[N],tot;
long long add(long long x,long long y){
	tot++;
	Next[tot]=h[x];
	v[tot]=y;
	h[x]=tot;
}
long long dfs(long long x,long long fa){
	f[x]=fa;
	for(long long i=h[x];i;i=Next[i]){
		if(v[i]==fa)continue;
		dfs(v[i],x);
	}
}
long long lfs(long long x,long long fa){
	g[x][1]=a[x];
	g[x][0]=0;
	if(must[x])g[x][2-must[x]]=1000000000000000LL;
	for(long long i=h[x];i;i=Next[i]){
		if(v[i]==fa)continue;
		lfs(v[i],x);
		g[x][0]+=g[v[i]][1];
		g[x][1]+=min(g[v[i]][1],g[v[i]][0]);
	}
}
int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%lld%lld%s",&n,&m,s+1);	
	for(long long i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(long long i=1;i<n;i++){
		long long x,y;
		scanf("%lld%lld",&x,&y);
		add(x,y);
		add(y,x);
	}
	dfs(1,0);
	for(long long i=1;i<=m;i++){
		long long x,y;
		scanf("%lld",&x);
		scanf("%lld",&must[x]);
		scanf("%lld",&y);
		scanf("%lld",&must[y]);
		must[x]++;
		must[y]++;
		if((f[x]==y||f[y]==x)&&must[x]==1&&must[y]==1){
			printf("-1\n");
		}
		else{
			lfs(1,0);
			printf("%lld\n",min(g[1][0],g[1][1]));
		}
		must[x]=0;
		must[y]=0;
	}
}
