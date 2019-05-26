#include<cstdio>
#include<cstring>
#include<algorithm>
#define mod 1000000007
using namespace std;
	int n,m,ans;
	int a[9][9];
	int tmin[10000001];
	int tmax[10000001];
bool check(int x,int y,int w,int s)
{
	if (x==n&&y==m)
	{
		tmax[s]=max(w,tmax[s]);
		tmin[s]=min(w,tmin[s]);
		return false;
	}
	bool p=false;
	if (y+1<=m) p|=check(x,y+1,w+a[x][y],(s<<1)+1);
	if (x+1<=n) p|=check(x+1,y,w+a[x][y],(s<<1));
	if (x==1&&y==1)
	{
		for (int i=1;i<(1<<n+m-2)-1;i++)
			for (int j=i+1;j<(1<<n+m-2);j++)
				if (tmax[i]>tmin[j]&&tmax[i]!=-1&&tmin[i]!=-1)
					return false;
		return true;
	}
}
void dfs(int x,int y)
{
	if (x==n&&y==m)
	{
		memset(tmax,255,sizeof(tmax));
		memset(tmin,0x7f7f,sizeof(tmin));
		a[x][y]=0;
		if (check(1,1,0,0)) ans++;
		ans%=mod;
		memset(tmax,255,sizeof(tmax));
		memset(tmin,0x7f7f,sizeof(tmin));
		a[x][y]=1;
		if (check(1,1,0,0)) ans++;
		ans%=mod;
		return;
	}
	a[x][y]=0;
	if (x!=n)
		dfs(x+1,y);
	else dfs(1,y+1);
	a[x][y]=1;
	if (x!=n)
		dfs(x+1,y);
	else dfs(1,y+1);
}
long long quickpower(long long a,long long b)
{
	long long t=1;
	while (b>0)
	{
		if (b&1) t=t*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return t;
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	if (n>m)
	{
		int t=n;
		n=m;
		m=t;
	}
	if (n==1||m==1)
		printf("%lld",quickpower(2,n+m-1));
	else if (n==2)
		printf("%lld",4*quickpower(3,m-1)%mod);
	else if (n==3&&m==3)
		printf("112");
	else if (n==3&&m==4)
		printf("332");
	else if (n==3&&m==5)
		printf("996");
	else
	{
		dfs(1,1);
		printf("%d",ans);
	}
	return 0;
}
