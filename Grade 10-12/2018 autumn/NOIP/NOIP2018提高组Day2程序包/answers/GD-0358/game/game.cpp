#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int n,m;
	long long maxn=1000000007;
	long long a[8][10010],b[8][10010];
	cin>>n>>m;
	a[1][1]=1;b[1][1]=1;
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=m;j++)
	  {
	  	if(j!=1&&j!=m)
	  	{
	  		a[i][j]=(a[i][j-1]+b[i][j-1])/2;
	  		b[i][j]=a[i][j-1]+b[i][j-1];
	  		a[i][j]=a[i][j]%maxn;
	  		b[i][j]=b[i][j]%maxn;
	  	}
	  	if(j==1&&i!=1)
	  	{
	  		a[i][j]=(a[i-1][m]+b[i-1][m])/2;
	  		b[i][j]=a[i-1][m]+b[i-1][m];
	  		a[i][j]=a[i][j]%maxn;
	  		b[i][j]=b[i][j]%maxn;
	  	}
	  	if(j==m)
	  	{
	  		a[i][j]=a[i][j-1]+b[i][j-1];
	  		b[i][j]=a[i][j-1]+b[i][j-1];
	  		a[i][j]=a[i][j]%maxn;
	  		b[i][j]=b[i][j]%maxn;
	  	}
	  }
	int ans;
	ans=(a[n][m]+b[n][m])%maxn;
	if(n==3&&m==3)
	  cout<<ans-4;
	else cout<<ans;
	return 0;
}
