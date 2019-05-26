#include<algorithm>
#include<cstdio>
#define LL long long
using namespace std;
int n,m,x,y,p,q,sl,fh,a[100010];
LL dp[100010][2];
int t,h[100010];
char str[5];
struct Tre
{
	int to,nxt;
}e[200010];
int rd()
{
	sl=0;fh=1;
	char ch=getchar();
	while(ch<'0'||'9'<ch) {if(ch=='-') fh=-1; ch=getchar();}
	while('0'<=ch&&ch<='9') sl=sl*10+ch-'0',ch=getchar();
	return sl*fh;
}
void add(int u,int v)
{
	e[++t]=(Tre){v,h[u]};h[u]=t;
	e[++t]=(Tre){u,h[v]};h[v]=t;
}
void dfs(int u,int f)
{
	int v;dp[u][0]=dp[u][1]=1e12;
	LL sum0,sum1;sum0=0;sum1=a[u];
	for(int i=h[u];i;i=e[i].nxt)
		if((v=e[i].to)!=f)
		{
			dfs(v,u);
			sum0+=dp[v][1];
			sum1+=min(dp[v][0],dp[v][1]);
		}
	if(u==p)
	{
		if(x==1) dp[u][1]=sum1;
		else dp[u][0]=sum0;
	}
	else if(u==q)
	{
		if(y==1) dp[u][1]=sum1;
		else dp[u][0]=sum0;
	}
	else
	{
		dp[u][0]=sum0;
		dp[u][1]=sum1;
	}
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	n=rd();m=rd();scanf("%s",str);
	for(int i=1;i<=n;++i) a[i]=rd();
	for(int i=1;i<n;++i) x=rd(),y=rd(),add(x,y);
	while(m--)
	{
		p=rd(),x=rd(),q=rd(),y=rd();
		dfs(1,0);
		if(min(dp[1][0],dp[1][1])>=1e12) {puts("-1"); continue;}
		printf("%lld\n",min(dp[1][0],dp[1][1]));
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
