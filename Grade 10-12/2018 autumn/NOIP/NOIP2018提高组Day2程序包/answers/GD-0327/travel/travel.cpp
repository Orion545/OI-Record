#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#define fo(i,a,b) for(i=a;i<=b;i++)

using namespace std;

const int maxn=6005;

int fi[maxn],ne[maxn*2],dui[maxn*2],qi[maxn*2],qc[maxn],ans[maxn],tot[maxn];
int map[maxn][maxn],g[maxn];
bool b[maxn][maxn],bz[maxn];
int hu[maxn];
int i,j,k,l,m,n,x,y,nc,qq1,qq2,ce;

void add(int x,int y){
	if (fi[x]==0) fi[x]=++nc; else ne[qc[x]]=++nc;
	qc[x]=nc; dui[nc]=y; qi[nc]=x;
}

void fd(int x,int y){
	if (ce==2) return;
	if (x==l) ce++;
	if (ce==2){
		return;
	}
	if (bz[x]==true) return; bz[x]=true;
	int i;
	for(i=fi[x];i;i=ne[i]) if (dui[i]!=y && ce<2){
		hu[++hu[0]]=i;
		fd(dui[i],x);
		if (ce==2) return;
		hu[0]--;
	}
}

void dfs(int x,int y){
	int i;
	tot[++nc]=x;
	fo(i,1,g[x]) if (b[x][i]==true && map[x][i]!=y) dfs(map[x][i],x);
}

void solve(){
	nc=0;
	dfs(1,0);
	int i,j;
	fo(i,1,n) if (tot[i]<ans[i]){
		fo(j,i,n) ans[j]=tot[j];
		break;
	} else if (tot[i]>ans[i]) break;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	nc=0;
	fo(i,1,m){
		scanf("%d%d",&x,&y);
		add(x,y); add(y,x);
		map[x][++g[x]]=y;
		map[y][++g[y]]=x;
	}
	fo(i,1,n) sort(map[i]+1,map[i]+g[i]+1);
	fo(i,1,n) fo(j,1,m) b[i][j]=true;
	ans[1]=n;
	if (m==n-1){
		solve();
		fo(i,1,n) printf("%d ",ans[i]);
		return 0;
	}
	fo(i,1,n){
		l=i; ce=0; memset(bz,false,sizeof(bz)); hu[0]=0;
		fd(i,0);
		if (ce==2) break;
	}
	fo(j,1,hu[0]){
		x=hu[j];
		fo(i,1,g[qi[x]]) if (map[qi[x]][i]==dui[x]){
			b[qi[x]][i]=false; qq1=i;
		}
		fo(i,1,g[dui[x]]) if (map[dui[x]][i]==qi[x]){
			b[dui[x]][i]=false; qq2=i;
		}
		solve();
		x=hu[j];
		b[qi[x]][qq1]=true;
		b[dui[x]][qq2]=true;
	}
	fo(i,1,n) printf("%d ",ans[i]);
	return 0;
}
