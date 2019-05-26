#include<bits/stdc++.h>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef double db;
typedef long long LL;

int get(){
	char ch;
	while(ch=getchar(),(ch<'0'||ch>'9')&&ch!='-');
	if (ch=='-'){
		int s=0;
		while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
		return -s;
	}
	int s=ch-'0';
	while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
	return s;
}

const int N = 100005;
const LL INF = 1e18;

int n,m;
struct edge{
	int x,nxt;
}e[N*2];
int h[N],tot;
struct value{
	LL v[2][2];
	LL *operator [](int x){return v[x];}
	void init(){
		v[0][0]=v[1][0]=v[0][1]=v[1][1]=INF;
	}
};
value operator *(value a,value b){
	value c;
	c.init();
	fo(i,0,1)fo(j,0,1)c[i][j]=min(INF,min(a[i][0]+b[1][j],min(a[i][1]+b[0][j],a[i][1]+b[1][j])));
	return c;
}

void inse(int x,int y){
	e[++tot].x=y;
	e[tot].nxt=h[x];
	h[x]=tot;
}
int dep[N];
int fa[N][20];
value f[N][20];
LL a[N];
db tim;
LL g0[N],g1[N];
LL o0[N],o1[N];
int que[N],k;

void dfs(int x){
	que[++k]=x;
	g0[x]=0,g1[x]=0;
	fo(i,1,tim)fa[x][i]=fa[fa[x][i-1]][i-1];
	for(int p=h[x];p;p=e[p].nxt)
	if (!dep[e[p].x]){
		dep[e[p].x]=dep[x]+1;
		fa[e[p].x][0]=x;
		dfs(e[p].x);
		g0[x]+=g1[e[p].x];
		g1[x]+=min(g0[e[p].x],g1[e[p].x]);
	}
	g1[x]+=a[x];
}

void dfs1(int x){
	for(int p=h[x];p;p=e[p].nxt)
	if (fa[e[p].x][0]==x){
		int y=e[p].x;
		o0[y]=o1[x]+g0[x]-g1[y];
		o1[y]=min(o1[x],o0[x])+g1[x]-min(g0[y],g1[y]);
		dfs1(y);
	}
}

int lca(int x,int y){
	if (dep[x]<dep[y])swap(x,y);
	fd(i,tim,0)
	if (dep[fa[x][i]]>=dep[y])x=fa[x][i];
	if (x==y)return x;
	fd(i,tim,0)
	if (fa[x][i]!=fa[y][i])x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}

int digi[100];
int digiw;

void putans(LL x){
	if (x==0){putchar('0');return;}
	for(;x;x/=10)digi[++digiw]=x%10;
	for(;digiw;digiw--)putchar('0'+digi[digiw]);
}

int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	n=get();m=get();
	char TY[100];
	scanf("%s",TY);
	fo(i,1,n)a[i]=get();
	fo(i,2,n){
		int x=get(),y=get();
		inse(x,y),inse(y,x);
	}
	tim=log(n)/log(2);
	dep[1]=1;
	dfs(1);
	dfs1(1);
	fo(i,0,tim)f[0][i].init();
	fo(d,1,k){
		int x=que[d];
		f[x][0].init();
		f[x][0][0][0]=g0[x];
		f[x][0][1][1]=g1[x];
		int st=x;
		fo(i,1,tim){
			int y=fa[x][i-1];
			value tmp=f[y][i-1];
			if (i==1)st=x;else st=fa[st][i-2];
			fo(c,0,1){
				if (tmp[0][c]!=INF)tmp[0][c]-=g1[st];
				if (tmp[1][c]!=INF)tmp[1][c]-=min(g0[st],g1[st]);
			}
			f[x][i]=f[x][i-1]*tmp;
		}
	}
	fo(cas,1,m){
		int x=get(),vx=get(),y=get(),vy=get();
		if (dep[x]<dep[y])swap(x,y),swap(vx,vy);
		if(!vx&&!vy&&fa[x][0]==y){
			printf("-1\n");
			continue;
		}
		int z=lca(x,y);
		value nx,ny;
		nx.init(),ny.init();
		if (vx)nx[1][1]=g1[x];else nx[0][0]=g0[x];
		if (vy)ny[1][1]=g1[y];else ny[0][0]=g0[y];
		LL ans;
		if (z==y){
			int r=x;
			fd(i,tim,0)
			if (dep[fa[r][i]]>dep[z]){
				value tmp=f[fa[r][0]][i];
				fo(c,0,1){
					if (tmp[0][c]!=INF)tmp[0][c]-=g1[r];
					if (tmp[1][c]!=INF)tmp[1][c]-=min(g0[r],g1[r]);
				}
				nx=nx*tmp;
				r=fa[r][i];
			}
			value tmp=ny;
			fo(c,0,1){
				if(tmp[0][c]!=INF)tmp[0][c]-=g1[r];
				if (tmp[1][c]!=INF)tmp[1][c]-=min(g0[r],g1[r]);
			}
			tmp[1][1]+=min(o0[y],o1[y]);
			tmp[0][0]+=o1[y];
			nx=nx*tmp;
		}
		else{
			int rx=x,ry=y;
			fd(i,tim,0)
			if (dep[fa[rx][i]]>dep[z]){
				value tmp=f[fa[rx][0]][i];
				fo(c,0,1){
					if (tmp[0][c]!=INF)tmp[0][c]-=g1[rx];
					if (tmp[1][c]!=INF)tmp[1][c]-=min(g0[rx],g1[rx]);
				}
				nx=nx*tmp;
				rx=fa[rx][i];
			}
			fd(i,tim,0)
			if (dep[fa[ry][i]]>dep[z]){
				value tmp=f[fa[ry][0]][i];
				fo(c,0,1){
					if (tmp[0][c]!=INF)tmp[0][c]-=g1[ry];
					if (tmp[1][c]!=INF)tmp[1][c]-=min(g0[ry],g1[ry]);
				}
				ny=ny*tmp;
				ry=fa[ry][i];
			}
			
			value tmp;
			tmp.init();
			tmp[0][0]=g0[z]-(g1[rx]+g1[ry])+o1[z];
			tmp[1][1]=g1[z]-(min(g0[rx],g1[rx])+min(g0[ry],g1[ry]))+min(o0[z],o1[z]);
			nx=nx*tmp;
			fo(i,0,1)fo(j,0,1)tmp[j][i]=ny[i][j];
			nx=nx*tmp;
		}
		ans=INF;
		fo(i,0,1)ans=min(ans,min(nx[i][0],nx[i][1]));
		putans(ans);
		putchar('\n');
	}
	return 0;
}
