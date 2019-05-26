#include<cstdio>
#include<algorithm>
#define maxn 100001

using namespace std;
typedef long long ll;

int n,m,tot;
int p[maxn],nxt[maxn<<1],last[maxn],e[maxn<<1];
int bj[maxn];
ll ans[1<<10];
char ch[10];

void add(int u,int v)
{
	e[++tot]=v,nxt[tot]=last[u];last[u]=tot;
}
int dfs(int u,int fa)
{
	for(int i=last[u];i;i=nxt[i])
	{
		int v=e[i];
		if(v==fa) continue;
		if(!(bj[u] || bj[v])) return 0;
	}
	for(int i=last[u];i;i=nxt[i])
	{
		int v=e[i];
		if(v==fa) continue;
		if(!dfs(v,u)) return 0;
	}
	return 1;
}
void sol1()
{
	for(int s=0;s<1<<n;s++)
	{
		ll res=0;
		for(int j=0;j<n;j++)
		if(s>>j&1) bj[j+1]=1,res+=p[j+1];
		else bj[j+1]=0;
		ans[s]=dfs(1,0)?res:-1;	
	}
	for(int a,b,x,y;m;m--)
	{
		scanf("%d%d%d%d",&a,&x,&b,&y);
		a--;b--;
		ll res=1e11;
		for(int s=0;s<1<<n;s++)
			if( (!(s>>a&1^x)) && (!(s>>b&1^y)) ) 
			if(ans[s]>-1) res=min(ans[s],res);
		if(res<1e11) printf("%lld\n",res);
		else puts("-1");
	}
}

int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d%s",&n,&m,ch); 
	for(int i=1;i<=n;i++) scanf("%d",&p[i]);
	for(int i=1,u,v;i<n;i++)
	{
		scanf("%d%d",&u,&v);
		add(u,v);add(v,u);
	}
	if(n<=10) {sol1();return 0;}
	return 0;
}
