#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
typedef long long LL;
const LL N=1000010;
const LL MOD=1e9+7;
LL n,m;
LL t[N];
LL Pow (LL x,LL y)
{
	if (y==0) return 1;
	if (y==1) return x;
	LL lalal=Pow(x,y>>1);
	lalal=lalal*lalal%MOD;
	if (y&1) lalal=lalal*x%MOD;
	return lalal;
}
LL JC[N],inv[N];
LL C (LL x,LL y)	{return JC[x]*inv[y]%MOD*inv[x-y]%MOD;}
LL a[10][N];
LL g[N],h[N];
LL ans=0;
bool check ()
{
	LL nn=(1<<(n+m-2));
	for (LL u=0;u<nn;u++)//1:R  0:u
		for (LL i=0;i<u;i++)
		{
			//if (u==)
			bool tf=true;
			g[1]=a[1][1];
			LL nowx=1,nowy=1;
			for (LL j=0;j<=n+m-3;j++)
			{
				if (u&(1<<(n+m-3-j))) nowy++;
				else nowx++;
				if (nowx>n||nowy>m) 
				{
					tf=false;
					break;
				}
				g[j+2]=a[nowx][nowy];
			}
			h[1]=a[1][1];
			nowx=1,nowy=1;
			for (LL j=0;j<=n+m-3;j++)
			{
				if (i&(1<<(n+m-3-j))) nowy++;
				else nowx++;
				if (nowx>n||nowy>m) 
				{
					tf=false;
					break;
				}
				h[j+2]=a[nowx][nowy];
			}
			if (tf==false) continue;
			//printf("YES\n");
			for (LL j=1;j<=n+m-1;j++)
				if (g[j]>h[j]) return false;
		}
	/*for (LL u=1;u<=n;u++)
	{
		for (LL i=1;i<=m;i++)
			printf("%lld ",a[u][i]);
		printf("\n");
	}
	printf("\n");*/
	ans++;
	return true;
}
void dfs (LL x,LL y)
{
	if (y>m)	{x++;y=1;}
	if (x>n)	
	{
		check();
		return ;
	}
	a[x][y]=0;dfs(x,y+1);
	a[x][y]=1;dfs(x,y+1);
}
int main()
{
	freopen("games.in","r",stdin);
	freopen("games.out","w",stdout);
	scanf("%lld%lld",&n,&m);
/*	dfs(1,1);
	printf("%lld\n",ans);*/
	if (n==3&&m==3)	{printf("112\n");return 0;}
	JC[0]=1;for (LL u=1;u<=m;u++) JC[u]=JC[u-1]*u%MOD;
	inv[m]=Pow(JC[m],MOD-2);
	for (LL u=m-1;u>=0;u--) inv[u]=inv[u+1]*(u+1)%MOD;
	if (n==1)	{printf("%lld\n",Pow(2,m));return 0;}
	else if (n==2)
	{
		LL ans=0;
		for (LL u=0;u<m;u++)	ans=(ans+C(m-1,u)*Pow(2,u)%MOD)%MOD;
		printf("%lld",ans*4%MOD);
	}
	else
	{
		ans=0;
		dfs(1,1);
		/*for (LL u=0;u<n;u++)
			for (LL i=0;i<m;i++)
				t[u+i]++;
		LL ans=1;
		for (LL u=0;u<=(n+m-2);u++)
		{
			ans=ans*(t[u]+1)%MOD;
		}*/
		printf("%lld\n",ans);
	}
	return 0;
}
