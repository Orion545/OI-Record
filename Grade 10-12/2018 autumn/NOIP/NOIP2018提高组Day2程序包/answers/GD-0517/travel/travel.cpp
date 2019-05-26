#include<cstdio>
#include<cctype>
#include<cstring>
#include<algorithm>
#define repu(i,x,y) for(i=x;i<=y;i++)
#define N 5005
struct edge{int v,next;} e[N*2];
int first[N],f[N*2],tp=0,ans[N],rec[N],p=0,flag=0;
int read() {
	char c=getchar(); int f=0;
	while (!isdigit(c)) c=getchar();
	while (isdigit(c)) f=f*10+c-'0',c=getchar();
	return f;
}
void add(int u,int v) {
	e[tp]=(edge){v,first[u]}; first[u]=tp++;
	e[tp]=(edge){u,first[v]}; first[v]=tp++;
}
void dfs(int u,int fa) {
	if (flag==-1) return;
	if (u>ans[p+1]&&!flag) {flag=-1; return;}
	if (u<ans[p+1]) flag=1;
	rec[++p]=u; int i,a[N],x=0;
	for (i=first[u];i+1;i=e[i].next) {
		int v=e[i].v;
		if (v==fa||f[i]) continue;
		a[++x]=v;
	}
	std::sort(a+1,a+x+1);
	repu(i,1,x)
		dfs(a[i],u);
}
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n=read(),m=read(),i,j,x,y;
	memset(e,-1,sizeof e); memset(first,-1,sizeof first);
	memset(ans,127,sizeof ans); memset(rec,0,sizeof rec); memset(f,0,sizeof f);
	repu(i,1,m)
		x=read(),y=read(),add(x,y);
	if (m==n-1) {
		dfs(1,0);
		if (p==n) memcpy(ans,rec,sizeof ans);
	}
	else 
		repu(i,0,m-1) {
			f[i<<1]=f[(i<<1)+1]=1;
			p=flag=0; dfs(1,0);
			f[i<<1]=f[(i<<1)+1]=0;
			if (p==n) memcpy(ans,rec,sizeof ans);
		}
	repu(i,1,n)
		printf("%d ",ans[i]);
	printf("\n");
	return 0;
}
