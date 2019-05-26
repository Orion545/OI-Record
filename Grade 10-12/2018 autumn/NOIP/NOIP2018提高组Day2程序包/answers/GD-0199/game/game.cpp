#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int n,m,a[10][10],ans=0,bj,p[100005];
void dfs(int x,int y,int sz,int sum)
{
	sum+=a[x][y]*sz;
	if(x==n-1&&y==m-1)
	{
		bj++;
		p[bj]=sum;
	}
	if(x+1<n)
	{
		dfs(x+1,y,sz/2,sum);
	}
	if(y+1<m)
	{
		dfs(x,y+1,sz/2,sum);
	}
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>m;
	a[0][0]=-1;
	for(int i=0;i<(1<<(n*m));i++)
	{
		a[0][0]++;
		for(int j=0;j<n;j++)
		{
			for(int k=0;k<m;k++)
			{
				if(a[j][k]>1)
				{
					a[j][k]=0;
					if(k+1<n)
						a[j][k+1]++;
					else
						a[j+1][0]++;
				}
			}
		}
		bj=0;
		dfs(0,0,(1<<(n+m)),0);
		bool op=1;
		for(int j=1;j<bj;j++)
		{
			if(p[j+1]>p[j])
			{
				op=0;
				break;
			}
		}
		if(op)
		ans=(ans+1)%1000000007;
	}
	cout<<ans;
	return 0;
} 
