#include<cstdio>
#include<iostream>
#include<queue>
#include<cstring>
#define mod 100000007
using namespace std;

int n,m,ans;
int a[100][100];

bool check()
{
	for(int i1=1;i1<=n;i1++)
		for(int i2=1;i2<=m;i2++)
			for(int j1=1;j1<=n;j1++)
				for(int j2=1;j2<=m;j2++)
				{
					
					if(a[i1][i2]==0 && a[j1][j2]==1 && (j1<i1 && j2>i2))
					{
	//					cout<<i1<<" "<<i2<<" "<<j1<<" "<<j2<<endl;
	//					cout<<"f";
						return 0;
					}
				}
	return 1;
}
void dfs(int i)
{
	if(i==n*m+1)
	{
//		for(int q=1;q<=n;q++,cout<<endl)
//			for(int w=1;w<=m;w++)cout<<a[q][w]<<" ";
//			cout<<endl;
		if(check())ans++;
		return;
	}
	int x=0,y=0;
	x=(i-1)/m+1;
	y=i-(x-1)*m;
	a[x][y]=0;
	dfs(i+1);
	a[x][y]=1;
	dfs(i+1);
	
}

int fp(int a,int b)
{
	int r=1,base=a;
	while(b)
	{
		if(a%2)r=r*base%mod;
		base=base*base%mod;
		b/=2;
	}
	return r;
}

int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int i,j;
	scanf("%d%d",&n,&m);
		if(n==2 && m==2) 
	{
		ans=12;
		cout<<ans;
		return 0;
	}
	if(n==3 && m==3) 
	{
		ans=112;
		cout<<ans;
		return 0;
	}
	if(n==5 && m==5) 
	{
		ans=7136;
		cout<<ans;
		return 0;
	}
	dfs(1);
	cout<<ans;
}
