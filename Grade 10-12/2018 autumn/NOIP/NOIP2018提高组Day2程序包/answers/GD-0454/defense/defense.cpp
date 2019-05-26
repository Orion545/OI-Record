#include<cstdio>
#include<algorithm>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
typedef long long ll;
const ll mx=1e12;
const int N=10000;
int f[N],next[N],h[N],p[N];
ll g[N][2],ans;
int n,m,tot,a,b,x,y;
char type[100];
void add(int x,int y)
{
	f[++tot]=y;
	next[tot]=h[x];
	h[x]=tot;
}
void dfs(int t,int fat)
{
	int pp=h[t];
	g[t][0]=0;
	g[t][1]=p[t];
	while(pp){
		if(f[pp]!=fat){
			dfs(f[pp],t);
			g[t][0]+=g[f[pp]][1];
			g[t][1]+=min(g[f[pp]][0],g[f[pp]][1]);
		}
		pp=next[pp];
	}
	if(t==a)g[t][1-x]=mx;
	if(t==b)g[t][1-y]=mx;
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",type);
	fo(i,1,n)scanf("%d",&p[i]);
	fo(i,1,n-1){
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	fo(i,1,m){
		scanf("%d%d%d%d",&a,&x,&b,&y);
		if(a==b&&x!=y){
			printf("-1\n");
			continue;
		}
		dfs(1,0);
		ans=min(g[1][0],g[1][1]);
		if(ans>=mx)printf("-1\n");
		else printf("%lld\n",ans);
	}
}
