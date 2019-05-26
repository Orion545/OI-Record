#include<cstdio>
#include<cstring>
#include<cctype>
#define repu(i,x,y) for(i=x;i<=y;i++)
#define repd(i,x,y) for(i=x;i>=y;i--)
#define max(a,b) (a>b?a:b)
#define N 100001
struct edge{int v,w,next;} e[N];
int first[N],tp=0,f[N],g[N],n,m,ans=0;
int read() {
	char c=getchar(); int f=0;
	while (!isdigit(c)) c=getchar();
	while (isdigit(c)) f=f*10+c-'0',c=getchar();
	return f;
}
void add(int u,int v,int w) {
	e[tp]=(edge){v,w,first[u]}; first[u]=tp++;
	e[tp]=(edge){u,w,first[v]}; first[v]=tp++;
}
void dfs(int u,int fa) {
	int i;
	for (i=first[u];i+1;i=e[i].next) {
		int v=e[i].v,w=e[i].w,t;
		if (v==fa) continue;
		dfs(v,u); t=f[v]+w;
		if (f[u]<t) g[u]=f[u],f[u]=t;
		else if (g[u]<t) g[u]=t;
		ans=max(ans,f[u]+g[u]);
	}
}
int judge(int x) {
	int i,cnt=0,t=0;
	repu(i,1,n-1) {
		t+=f[i];
		if (t>=x) cnt++,t=0;
	}
	if (cnt>=m) return 1;
	cnt=t=0;
	repu(i,n-1,1) {
		t+=f[i];
		if (t>=x) cnt++,t=0;
	}
	if (cnt>=m) return 1;
	return 0;
}
int main() {
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	n=read(),m=read(); int i,x,y,z;
	memset(f,0,sizeof f); memset(g,0,sizeof g);
	if (m==1) {
		memset(e,-1,sizeof e); memset(first,-1,sizeof first);
		repu(i,1,n-1)
			x=read(),y=read(),z=read(),add(x,y,z);
		dfs(1,0);
		printf("%d\n",ans);
	}
	else {
		int l=0,r=0;
		repu(i,1,n-1)
			x=read(),y=read(),z=read(),f[x]=z,r+=z;
		while (l<r) {
			int mid=(l+r+1)>>1;
			if (judge(mid)) l=mid; else r=mid-1;
		}
		printf("%d\n",l);
	}
	return 0;
}
