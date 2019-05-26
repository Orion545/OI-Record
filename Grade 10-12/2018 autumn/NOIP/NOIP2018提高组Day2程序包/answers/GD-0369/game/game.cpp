#include<bits/stdc++.h>
#define mod (ll)(1e9+7)
using namespace std;
typedef long long ll;
int n,m;
ll ans;
int mat[666][666];
int t[999][999],cnt;
int cur[999];
void judge(int x,int y)
{
	cur[x+y-1]=mat[x][y];
	if (x==n&&y==m)
	{
		++cnt;
		for (int i=1;i<n+m;i++) t[cnt][i]=cur[i];
		return; 
	}
	if (y!=m) judge(x,y+1);
	if (x!=n) judge(x+1,y);
}
bool cmp(int *x,int *y)
{
	for (int i=1;i<n+m;i++) if (x[i]!=y[i]) return x[i]<y[i];
	return 1;
}
bool judge()
{
	cnt=0;
	judge(1,1);
	for (int i=1;i<cnt;i++) if (!cmp(t[i],t[i+1])) return 0;
	return 1;
}
void dfs(int dep)
{
	if (dep==n*m+1) return (void)(ans+=judge());
	int x=(dep-1)/m+1,y=(dep-1)%m+1;
//	if (y==m||x==1||mat[x-1][y+1]==0)
//	{
		mat[x][y]=0;
	dfs(dep+1);
//	}
	mat[x][y]=1;
	dfs(dep+1);
}
ll ksm(ll x,int y)
{
	ll ret;
	for (ret=1;y;y>>=1,x=x*x%mod) if (y&1) ret=ret*x%mod;
	return ret;
}
int main()
{
//	freopen("a.txt","r",stdin);
	freopen("game.in","r",stdin);freopen("game.out","w",stdout);
	int i,j,k,x,y,z;
	cin>>n>>m;
	if (n==1)
	{
		cout<<ksm(2,m)%mod;
		return 0;
	}
	if (n==2)
	{
		cout<<4ll*ksm(3,m-1)%mod;
		return 0;
	}
	if (n==3)
	{
		cout<<ksm(3,m-3)*16ll%mod*7ll%mod;
		return 0;
	}
	dfs(1);cout<<ans;return 0;
}

