#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>

#define F(i,x,y) for(int i=x;i<=y;++i)

using namespace std;

int lb(int x){
	return (x&(-x));
}


int min(int x,int y){
	return x<y?x:y;
}
const int M=100010,inf=999999999;

int n,m;
char c1,c2;

int tr[M*2];
void add(int x,int s){
	while(x<=n){
		tr[x]+=s;
		x+=lb(x);
	}
}
int query(int x){
	int ret=0;
	while(x){
		ret+=tr[x];
		x-=lb(x);
	}
	return ret;
}


int tot=0,nxt[M*2],to[M*2],las[M*2];
void Link(int x,int y){
	to[++tot]=y;
	nxt[tot]=las[x];
	las[x]=tot;
}

long long f[M][2],a[M],fa[M],dep[M];
int bz[M];



void dfs(int u,int x){
	
		fa[u]=x;
		f[u][0]=0;
		f[u][1]=a[u];
		for(int j=las[u];j;j=nxt[j]){
			int v=to[j];
			if(v==x) continue;
			
			dfs(v,u);
			
			f[u][0]+=f[v][1];
			f[u][1]+=min(f[v][1],f[v][0]);
		}
	
		if(bz[u]==1) f[u][1]=inf;
		if(bz[u]==2) f[u][0]=inf;

}

int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d ",&n,&m);
	scanf("%c%c",&c1,&c2);
	

	F(i,1,n) scanf("%lld",&a[i]);
	F(i,1,n-1){
		int x,y;
		scanf("%d%d",&x,&y);
		Link(x,y),Link(y,x);
	}
	
	dfs(1,0);
//	printf("%lld\n",min(f[1][1],f[1][0]));
	while(m--){
		int p,x,q,y;
		scanf("%d%d%d%d",&p,&x,&q,&y);
		if(fa[p]==q||fa[q]==p){
			if(!x&&!y){
				printf("-1\n");
				continue;
			}
		}
		bz[p]=x+1,bz[q]=y+1;
		dfs(1,0);
		bz[p]=0,bz[q]=0;
		
		printf("%lld\n",min(f[1][1],f[1][0]));

	}
	return 0;
}
