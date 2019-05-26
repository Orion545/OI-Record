#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
using namespace std;
const int N=2010;
const ll inf=1LL<<60;
struct xxx{
	int y,nxt;
}a[N*2];
int h[N],p[N],pre[N],dep[N];
ll f[N][2],orif[N][2];
int lis[N*2];
int mark[N];
int n,m,tot;
char ty[5];
void add(int x,int y){a[++tot].y=y; a[tot].nxt=h[x]; h[x]=tot;}
void pre_dfs(int fa,int x,int d){
	int u;
	pre[x]=fa; dep[x]=d;
	for (int i=h[x];i!=-1;i=a[i].nxt){
		u=a[i].y;
		if (u==fa) continue;
		pre_dfs(x,u,d+1);
	}
}
bool dfs(int fa,int x){
	int u;
	f[x][0]=0; f[x][1]=p[x];
	for (int i=h[x];i!=-1;i=a[i].nxt){
		u=a[i].y;
		if (u==fa) continue;
		if (!dfs(x,u)) return false;
		if (f[u][1]!=inf&&f[x][0]!=inf)
			f[x][0]+=f[u][1];
		else
			f[x][0]=inf;
		if (min(f[u][0],f[u][1])!=inf&&f[x][1]!=inf)
			f[x][1]+=min(f[u][0],f[u][1]);
		else
			f[x][1]=inf;
		if (f[x][0]==inf&&f[x][1]==inf) return false;
	}
	if (mark[x])
		f[x][(mark[x]-1)^1]=inf;
	if (f[x][0]==inf&&f[x][1]==inf) return false;
	return true;
}
void solve(int x,int op1,int y,int op2){
	mark[x]=op1+1; mark[y]=op2+1;
	if (!dfs(0,1)) printf("-1\n");
	else printf("%lld\n",min(f[1][0],f[1][1]));
	mark[x]=0; mark[y]=0;
}
void dp(int x){
	ll son0,son1;
	int u;
	if (!mark[x]) mark[x]=-1;
	lis[++lis[0]]=x;
	f[x][0]=0,f[x][1]=p[x];
	for (int i=h[x];i!=-1;i=a[i].nxt){
		u=a[i].y;
		if (u==pre[x]) continue;
		son0=mark[u]?f[u][0]:orif[u][0]; 
		son1=mark[u]?f[u][1]:orif[u][1]; 
		if (son1!=inf&&f[x][0]!=inf)
			f[x][0]+=son1;
		else
			f[x][0]=inf;
		if (min(son0,son1)!=inf&&f[x][1]!=inf)
			f[x][1]+=min(son1,son0);
		else
			f[x][1]=inf;
	}
	if (mark[x]>0)
		f[x][(mark[x]-1)^1]=inf;
}
void solve1(int x,int op1,int y,int op2){
	int u,son0,son1;
	if (dep[x]<dep[y]) swap(x,y),swap(op1,op2);
	mark[x]=op1+1; mark[y]=op2+1; lis[0]=0;
	while (dep[x]>dep[y])
		dp(x),x=pre[x];
	if (x==y){
		dp(x); x=pre[x];
	}
	else{
		while (pre[x]!=pre[y])
			dp(x),dp(y),x=pre[x],y=pre[y];
		dp(x); dp(y);
		x=pre[x];
	}
	while (x)
		dp(x),x=pre[x];
	if (min(f[1][0],f[1][1])==inf) printf("-1\n");
	else printf("%lld\n",min(f[1][0],f[1][1]));
	for (int i=1;i<=lis[0];++i) mark[lis[i]]=0;
}

int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);

	int x,y,op1,op2;
	scanf("%d%d%s",&n,&m,ty);
	for (int i=1;i<=n;++i) scanf("%d",p+i);
	memset(h,-1,sizeof(h));
	tot=0;
	for (int i=1;i<n;++i){
		scanf("%d%d",&x,&y);
		add(x,y); add(y,x);
	}
	pre_dfs(0,1,1);
	dfs(0,1);
	for (int i=1;i<=n;++i) orif[i][0]=f[i][0],orif[i][1]=f[i][1];
	if (n<=2000&&m<=2000){
		for (int i=1;i<=m;++i){
			scanf("%d%d%d%d",&x,&op1,&y,&op2);
			solve(x,op1,y,op2);
		}
	}
	else if (ty[0]=='B'){
		for (int i=1;i<=m;++i){
			scanf("%d%d%d%d",&x,&op1,&y,&op2);
			solve1(x,op1,y,op2);
		}
	}
}
