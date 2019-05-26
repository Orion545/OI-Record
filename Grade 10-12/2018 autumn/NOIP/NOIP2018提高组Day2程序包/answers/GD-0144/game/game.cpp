#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#define MOD 1000000007ll
using namespace std;

int a[1000010],n,m;
long long ans;
bool b[20][20],c;

void dfs(int x,int y,int t)
{
	if (!c) return;
	if (b[x][y]) t++;
	if (x==n && y==m)
	{
		a[++a[0]]=t;
		if (a[0]==1) return;
		if (a[a[0]]<a[a[0]-1])
		{
			c=false;
			return;
		}
		return;
	}
	
	if (y!=m) dfs(x,y+1,t);
	if (x!=n) dfs(x+1,y,t);
}

void dg(int p,int q)
{
	if (p>n)
	{
		a[0]=0;
		c=true;
		dfs(1,1,0);
		if (c) ans++;
		return;
	}
	
	b[p][q]=false;
	if (q==m) dg(p+1,1);
	else dg(p,q+1);
	
	b[p][q]=true;
	if (q==m) dg(p+1,1);
	else dg(p,q+1);
}

int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	
	if (n==1)
	{
		ans=1ll;
		for (int i=1;i<=m;i++)
		ans=(ans*2ll)%MOD;
		printf("%lld\n",ans);
		
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	
	if (n==2)
	{
		ans=4ll;
		for (int i=2;i<=m;i++)
		ans=(ans*3ll)%MOD;
		printf("%lld\n",ans);
		
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	
	dg(1,1);
		
	printf("%lld ",ans);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
