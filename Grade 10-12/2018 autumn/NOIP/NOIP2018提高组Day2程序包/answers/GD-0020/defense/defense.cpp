#include<map>
#include<cmath>
#include<queue>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
inline int read(){
	char ch=getchar(); int x=0,f=1;
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48); ch=getchar();}
	return x*f;
}
typedef long long LL;
const int N=100010;
const LL inf=1e16;
struct edg{int y,nex;}e[N<<1]; int len,fir[N];
void ins(int x,int y){
	e[++len].y=y,e[len].nex=fir[x],fir[x]=len;
}
int n,m,a[N],fa[N],dep[N]; LL f[N][3]; char s[5];
void dfs(int x){
	f[x][1]=a[x],f[x][0]=0,f[x][2]=inf;
	LL mn=inf;
	for(int k=fir[x];k;k=e[k].nex){
		int y=e[k].y; if(y==fa[x]) continue;
		fa[y]=x; dfs(y); dep[y]=dep[x]+1;
		LL u=min(f[y][0],f[y][1]);
		f[x][1]+=min(u,f[y][2]);
		f[x][0]+=u;
		f[x][2]+=f[y][0];
		mn=min(f[y][1]-u,mn);
	}
	if(mn<inf)f[x][0]+=mn;
}
void rec(int x){
	f[x][1]=a[x],f[x][0]=0,f[x][2]=inf;
	LL mn=inf; int son=0;
	for(int k=fir[x];k;k=e[k].nex){
		int y=e[k].y; if(y==fa[x]) continue;
		LL u=min(f[y][0],f[y][1]); ++son;
		f[x][1]+=min(u,f[y][2]);
		f[x][0]+=u;
		f[x][2]+=f[y][0];
		mn=min(f[y][1]-u,mn);
	}
	if(son)f[x][0]+=mn;
}
int Q[N],ql; LL g[N][3];
void bac(int x){
	Q[++ql]=x,g[x][0]=f[x][0],g[x][1]=f[x][1],g[x][2]=f[x][2];
}
int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	n=read(),m=read(); scanf("%s",s);
	int i;
	for(i=1;i<=n;++i) a[i]=read();
	for(i=1;i<n;++i){
		int x=read(),y=read();
		ins(x,y),ins(y,x);
	}
	dep[1]=1; dfs(1);
	while(m--){
		int x=read(),q=read(),y=read(),p=read();
		if( (x==fa[y]||y==fa[x]) && q==p){puts("-1"); continue;}
		ql=0; bac(x); bac(y);
		if(q==1){f[x][0]=f[x][2]=inf;} else f[x][1]=inf;
		if(p==1){f[y][0]=f[y][2]=inf;} else f[y][1]=inf;
		x=fa[x],y=fa[y];
		if(dep[x]<dep[y]) swap(x,y);
		while(dep[x]>dep[y]){
			bac(x),rec(x);
			x=fa[x];
		}
		while(x!=y){
			bac(x),rec(x),x=fa[x];
			bac(y),rec(y),y=fa[y];
		}
		while(x!=0){
			bac(x),rec(x),x=fa[x];
		}
		printf("%lld\n",min(f[1][0],f[1][1]));
		for(i=1;i<=ql;++i) f[Q[i]][0]=g[Q[i]][0],f[Q[i]][1]=g[Q[i]][1];
	}
	return 0;
}
