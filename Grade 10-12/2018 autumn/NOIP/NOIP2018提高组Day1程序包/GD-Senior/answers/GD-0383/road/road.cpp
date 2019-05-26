#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
#define LL long long
#define inf 0x3f3f3f3f
#define N 100010
int read()
{
	int x = 0; char ch = getchar();
	for(;ch<'0'||ch>'9';ch = getchar());
	for(;ch>='0'&&ch<='9';ch = getchar()) x = (x<<3)+(x<<1)+(ch^48);
	return x;
}
int n,a[N];
int f[N][20],g[N][20];
int ask(int l,int r)
{
	int k = (floor)(log(r-l+1)/log(2.0));
	//cout<<k<<endl;
	if(f[l][k] > f[r-(1<<k)+1][k])
		return g[r-(1<<k)+1][k];
	else
		return g[l][k];
}

LL solve(int l,int r,int d)
{
	if(l>r) return 0;
	if(l == r) return a[l] - d;
	int id = ask(l,r);
	return (LL)(a[id] - d) + solve(l,id-1,a[id]) + solve(id+1,r,a[id]);
}
void init()
{
	for(int i=1;i<=n;i++) f[i][0] = a[i],g[i][0] = i;
	for(int j=1;(1<<j)<=n;j++)
		for(int i=1;i+(1<<j)-1<=n;i++)
		{
			int t = 1<<(j-1);
			if(f[i][j-1] > f[i+t][j-1])
			{
				f[i][j] = f[i+t][j-1];
				g[i][j] = g[i+t][j-1];
			}
			else
			{
				f[i][j] = f[i][j-1];
				g[i][j] = g[i][j-1];
			}
		}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n = read();
	for(int i=1;i<=n;i++) a[i] = read();
	init();
	/*for(int i=0;(1<<i)<=n;i++)
	{
		for(int j=1;j<=n;j++)
			printf("%d ",f[j][i]);
		printf("\n");
	}*/
	cout<<solve(1,n,0)<<endl;
	return 0;
}

