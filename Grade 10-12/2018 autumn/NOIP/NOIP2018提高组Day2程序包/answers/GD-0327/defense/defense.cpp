#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#define fo(i,a,b) for(i=a;i<=b;i++)

using namespace std;

const int maxn=2005,mx=234567890;

int map[maxn][maxn];
int f[maxn],g[maxn],h[maxn],a[maxn],bt[maxn];
int i,j,k,l,m,n,x,y,t1,t2,t3,t4,ans;
char s[10];

void dfs(int x,int y){
	int i,tc=0;
	f[x]=a[x]; g[x]=0; h[x]=0;
	fo(i,1,map[x][0])if (map[x][i]!=y){
		dfs(map[x][i],x);
		f[x]=f[x]+min(g[map[x][i]],f[map[x][i]]);
	}
	fo(i,1,map[x][0])if (map[x][i]!=y){
		g[x]=g[x]+f[map[x][i]];
	}
	fo(i,1,map[x][0])if (map[x][i]!=y) h[x]=h[x]+g[map[x][i]];
	if (bt[x]==1) f[x]=mx;
	if (bt[x]==2){
		g[x]=mx; h[x]=mx;
	}
}

int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",&s);
	fo(i,1,n) scanf("%d",&a[i]);
	fo(i,1,n-1){
		scanf("%d%d",&x,&y);
		map[x][++map[x][0]]=y;
		map[y][++map[y][0]]=x;
	}
	while (m--){
		scanf("%d%d%d%d",&t1,&t2,&t3,&t4);
		bt[t1]=t2+1; bt[t3]=t4+1;
		dfs(1,0);
		bt[t1]=0; bt[t3]=0;
		ans=min(f[1],g[1]);
		if (ans>=mx) ans=-1;
		printf("%d\n",ans);
	}
	return 0;
}
