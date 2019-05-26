#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#define fo(i,a,b) for(i=a;i<=b;++i)
using namespace std;
const int N=5e3+10,inf=1e9+7;
int n,m,i,x,y,tot,cnt,nx[N<<1],he[N],we[N<<1],w[N],p[N],h[N],cir[N];
bool g[N][N]; int w1[N],pp[N],fa[N],j,flag,num;
priority_queue <int> Q[N];
int read(){
	int sum=0;
	char c=getchar();
	while (c<'0'||c>'9') c=getchar();
	while (c>='0'&&c<='9') {
		sum=sum*10+c-'0';
		c=getchar();
	}
	return sum;
}
void add(int x,int y){
	nx[++tot]=he[x],he[x]=tot,we[tot]=y;
}
void dfs(int x,int fr){
	int i,mi;
	pp[x]=1,mi=inf,w[++num]=x;
	for(i=he[x];i;i=nx[i])
	  	if (we[i]!=fr&&!pp[we[i]]&&!g[x][we[i]]){
	  	  		Q[x].push(-we[i]);
	  	  		mi=we[i];
	  	}
	while (!Q[x].empty()){
		dfs(-Q[x].top(),x);
		Q[x].pop();
	}
}
void get(int x,int y){
	if (h[x]<h[y]) swap(x,y);
	flag=1;
	cir[++cnt]=x,cir[++cnt]=y,p[x]=p[y]=1;
	while (h[fa[x]]>=h[y]) {
		x=fa[x];
		if (!p[x]) p[x]=1,cir[++cnt]=x;
	}
	if (x==y) return;
	while (fa[x]!=fa[y]){
		x=fa[x],y=fa[y];
		if (!p[x]) p[x]=1,cir[++cnt]=x;
		if (!p[y]) p[y]=1,cir[++cnt]=y;
	}
	x=fa[x];
	if (!p[x]) p[x]=1,cir[++cnt]=x;
}
void dg(int x){
	int i;
	h[x]=h[fa[x]]+1;
	for(i=he[x];i;i=nx[i]){
		if (we[i]==fa[x]) continue;
		if (fa[we[i]]) {
			if (flag) continue;
			get(x,we[i]);
			continue;
		}
		fa[we[i]]=x,dg(we[i]);
	}
}
bool check(){
	int i;
	fo(i,1,n) if (w[i]<w1[i]) return true;
	  else if (w[i]>w1[i]) return false;
	return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	n=read(),m=read();
	if (m==n-1){
		fo(i,1,m){
			x=read(),y=read();
			add(x,y),add(y,x);
		}
		//p[1]=1;
		dfs(1,0);
		fo(i,1,n-1) printf("%d ",w[i]);
		printf("%d",w[i]);
	} else {
		fo(i,1,m) {
			x=read(),y=read();
			add(x,y),add(y,x);
		}
		dg(1);
		int fl=0;
		fo(i,1,cnt){
			x=cir[i];
			for(j=he[x];j;j=nx[j])
			  if (p[we[j]]) {
			  	  g[x][we[j]]=g[we[j]][x]=true;
			  	  memset(pp,0,sizeof(pp));
			  	  num=0;
			  	  dfs(1,0);
			  	  g[x][we[j]]=g[we[j]][x]=false;
			  }
			if (!fl) {
				fl=1;
				fo(j,1,n) w1[j]=w[j];
			} else if (check()) {
				fo(j,1,n) w1[j]=w[j];
			}
		}
		fo(i,1,n-1) printf("%d ",w1[i]);
		printf("%d",w1[i]);
	}
}
