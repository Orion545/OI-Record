#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 300010
#define LL long long
using namespace std;

int read(){
	char c;
	while((c=getchar())<'0' || c>'9');
	int res=c-'0';
	while((c=getchar())>='0' && c<='9') res=res*10+c-'0';
	return res;
}

struct edge{
	int to,next;
	edge(int _to=0,int _next=0):to(_to),next(_next){}
}e[MAXN<<1];

int n,m;
int g[MAXN],nume;
int dep[MAXN];
LL v[MAXN];
LL f[MAXN][21][4],g1[MAXN][2],g2[MAXN][2];
LL s1[MAXN],s2[MAXN];
int pre[MAXN][21];

void addEdge(int u,int v){
	e[nume]=edge(v,g[u]);
	g[u]=nume++;
}

void dfs(int x,int p){
	pre[x][0]=p;
	for(int i=1;i<=20;i++) pre[x][i]=pre[pre[x][i-1]][i-1];
	g1[x][0]=0; g1[x][1]=v[x];
	for(int i=g[x];~i;i=e[i].next)
		if(e[i].to^p){
			dep[e[i].to]=dep[x]+1;
			dfs(e[i].to,x);
			s1[x]+=g1[e[i].to][1];
			s2[x]+=min(g1[e[i].to][0],g1[e[i].to][1]);
		}
	g1[x][0]+=s1[x];
	g1[x][1]+=s2[x];
}

void merge(LL *c,LL *a,LL *b){
	static LL t[4];
	t[0]=t[1]=t[2]=t[3]=1ll<<50;
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
			if(((i&1) || (j&2)) && a[i]+b[j]<t[(i&2)|(j&1)])
				t[(i&2)|(j&1)]=a[i]+b[j];
	for(int i=0;i<4;i++) c[i]=t[i];
}

void dfs2(int x,int p){
	if(p){
		f[x][0][0]=s1[p]-g1[x][1];
		f[x][0][1]=f[x][0][2]=1ll<<50;
		f[x][0][3]=s2[p]-min(g1[x][0],g1[x][1])+v[p];
		g2[x][0]=g2[p][1]+v[p]+s2[p]-min(g1[x][0],g1[x][1]);
		g2[x][1]=min(g2[p][0]+s1[p]-g1[x][1],g2[p][1]+v[p]+s2[p]-min(g1[x][0],g1[x][1]));
	}
	for(int i=1;i<=20;i++)
		if(pre[x][i])
			merge(f[x][i],f[x][i-1],f[pre[x][i-1]][i-1]);
	for(int i=g[x];~i;i=e[i].next)
		if(e[i].to^p)
			dfs2(e[i].to,x);
}

int getLCA(int x,int y){
	if(dep[x]^dep[y]){
		if(dep[x]>dep[y]) swap(x,y);
		for(int i=20;i>=0;i--)
			if(dep[x]<dep[pre[y][i]]) y=pre[y][i];
		y=pre[y][0];
	}
	if(x==y) return x;
	for(int i=20;i>=0;i--)
		if(pre[x][i]!=pre[y][i])
			 x=pre[x][i],y=pre[y][i];
	return pre[x][0];
}

int getf(int x,int d,LL *t){
	d--;
	for(int i=0;i<4;i++)
		t[i]=f[x][0][i];
	x=pre[x][0];
	for(int i=0,l=1;i<=20;i++,l<<=1)
		if(d&l){
			merge(t,t,f[x][i]);
			x=pre[x][i];
		}
	return x;
}

LL query(int x,int vx,int y,int vy){
	if(dep[x]>dep[y]){
		swap(x,y);
		swap(vx,vy);
	}
	if(pre[y][0]==x && !vx && !vy) return -1;
	int lca=getLCA(x,y);
	if(x==lca){
		static LL temp[4];
		getf(y,dep[y]-dep[x],temp);
		LL res=1ll<<50;
		for(int i=0;i<4;i++)
			if(((i&2) || vy) && ((i&1)==vx))
				res=min(res,temp[i]);
		res+=g1[y][vy]+g2[x][vx];
		return res;
	}
	static LL tx[2],ty[2];
	int x2,y2;
	if(dep[x]-dep[lca]==1){
		tx[vx]=g1[x][vx];
		tx[vx^1]=1ll<<50;
		x2=x;
	}else{
		tx[0]=tx[1]=1ll<<50;
		static LL temp[4];
		x2=getf(x,dep[x]-dep[lca]-1,temp);
		for(int i=0;i<4;i++)
			if(vx || (i&2))
				tx[i&1]=min(tx[i&1],g1[x][vx]+temp[i]);
	}
	if(dep[y]-dep[lca]==1){
		ty[vy]=g1[y][vy];
		ty[vy^1]=1ll<<50;
		y2=y;
	}else{
		ty[0]=ty[1]=1ll<<50;
		static LL temp[4];
		y2=getf(y,dep[y]-dep[lca]-1,temp);
		for(int i=0;i<4;i++)
			if(vy || (i&2))
				ty[i&1]=min(ty[i&1],g1[y][vy]+temp[i]);
	}
	LL res=1ll<<50;
	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++)
			for(int k=0;k<2;k++)
				if((k || i) && (k || j)){
					LL temp;
					if(k==0)
						temp=g2[lca][0]+s1[lca]-g1[x2][1]-g1[y2][1];
					else
						temp=g2[lca][1]+v[lca]+s2[lca]-min(g1[x2][0],g1[x2][1])-min(g1[y2][0],g1[y2][1]);
					temp+=tx[i]+ty[j];
					if(temp<res) res=temp;
				}
	return res;
}

int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	memset(g,-1,sizeof g);
	n=read(); m=read(); read();
	for(int i=1;i<=n;i++) v[i]=read();
	for(int i=1;i<n;i++){
		int u=read(),v=read();
		addEdge(u,v);
		addEdge(v,u);
	}
	dfs(1,0);
	dfs2(1,0);
	while(m--){
		int x=read(),vx=read(),y=read(),vy=read();
		printf("%lld\n",query(x,vx,y,vy));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
