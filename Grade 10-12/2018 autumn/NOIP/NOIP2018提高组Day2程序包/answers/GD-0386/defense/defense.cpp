#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#define ll long long
#define mod 1000000007
#define maxn 100010
inline ll read()
{
	ll x=0; char c=getchar(),f=1;
	for(;c<'0'||'9'<c;c=getchar())if(c=='-')f=-1;
	for(;'0'<=c&&c<='9';c=getchar())x=x*10+c-'0';
	return x*f;
}
struct edge{
	int to,nxt;
}e[2*maxn];
int fir[maxn],fa[maxn],p[maxn];
ll f[maxn][2],g[maxn][2];
int n,m,tot=0;
char type[10];
void add_edge(int x,int y){e[tot].to=y; e[tot].nxt=fir[x]; fir[x]=tot++;}
void dp(int now,int a,int x,int b,int y)
{
	f[now][0]=0; f[now][1]=p[now];
	for(int i=fir[now];~i;i=e[i].nxt)
		if(e[i].to!=fa[now]){
			fa[e[i].to]=now;
			dp(e[i].to,a,x,b,y);
			f[now][0]+=f[e[i].to][1];
			f[now][1]+=std::min(f[e[i].to][0],f[e[i].to][1]);
		}
	if(now==a)f[now][!x]=1ll<<40;
	if(now==b)f[now][!y]=1ll<<40;
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	n=read(); m=read(); scanf("%s",type);
	memset(fir,255,sizeof(fir)); tot=0;
	for(int i=1;i<=n;i++)p[i]=read();
	for(int i=1;i<n;i++){
		int x=read(),y=read();
		add_edge(x,y); add_edge(y,x);
	}
	if(n<=2000){
		for(int i=1;i<=m;i++){
			int a=read(),x=read(),b=read(),y=read();
			fa[1]=-1; dp(1,a,x,b,y);
			ll ans=std::min(f[1][0],f[1][1]);
			printf("%lld\n",(ans<1ll<<40?ans:-1));
		}
		fclose(stdin); fclose(stdout);
		return 0;
	}
	fa[1]=-1; dp(1,0,0,0,0);
	for(int i=1;i<=m;i++){
		int a=read(),x=read(),b=read(),y=read();
		g[b][y]=f[b][y]; g[b][!y]=1ll<<40;
		int now=b;
		while(now>1){
			int k=fa[now];
			g[k][0]=f[k][0]-f[now][0]+g[now][0];
			g[k][1]=f[k][1]-std::min(f[now][0],f[now][1])+std::min(g[now][0],g[now][1]);
			now=k;
		}
		printf("%lld\n",(g[a][x]<1ll<<40?g[a][x]:-1));
	}
	fclose(stdin); fclose(stdout);
	return 0;
}
