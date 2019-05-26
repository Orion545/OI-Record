#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;



ll power(ll a,int n)//a^n
{
	ll re=1;
	while(n)
	{
		if(n&1) re=re*a%MOD;
		a=a*a%MOD;
		n>>=1;
	}
	return re;
}

int n,m;

int ans=0;
int a[100][100],f[100][100];
int cal()
{
	for(int i=n;i>=1;i--)
		for(int j=m;j>=1;j--)
		{
			f[i][j]=max(f[i+1][j],f[i][j+1])+a[i][j];
		}
}

void check()
{
	cal();
	for(int i=1;i<n;i++)
		for(int j=1;j<m;j++)
			if(f[i+1][j]<f[i][j+1]) return ;
//	if(f[2][1]<f[1][2]) return ;
	
	ans++;
	if(ans>=MOD) ans-=MOD;
	/*puts("-----------------");
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++) printf("%d ",a[i][j]);
		puts(""); 
	}*/
}

void dfs(int x,int y)
{
	if(x==n+1) check();
	else if(y==m+1) dfs(x+1,1);
	else
	{
		a[x][y]=0;
		dfs(x,y+1);
		
		a[x][y]=1;
		dfs(x,y+1);
	}
}

int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	
	scanf("%d %d",&n,&m);
	if(n==2)
	{
		printf("%lld\n",4*power(3,m-1)%MOD);
		return 0;
	}
	else// if(n<=8 && m<=8)
	{
		dfs(1,1);
		printf("%d\n",ans);
	}
	return 0;
}

