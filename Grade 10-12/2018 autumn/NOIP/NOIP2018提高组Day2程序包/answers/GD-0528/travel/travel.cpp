#include<iostream>
#include<string>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
using namespace std;
int n,m,tot=0,ans[5010];
bool b[5010];
vector<int> to[5010];

void f(int x)
{
	b[x]=true;
	tot++;
	ans[tot]=x;
	if(tot==n) return;
	for(int i=0; i<to[x].size(); i++)
	{
		if(!b[to[x][i]]) f(to[x][i]);
	}
	return;
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d %d",&n,&m);
	int x,y,r;
	for(int i=1; i<=m; i++)
	{
		scanf("%d %d",&x,&y);
		to[x].push_back(y);
		to[y].push_back(x);
		r=to[x].size()-1;
		while(r>0&&to[x][r]<to[x][r-1])
		{
			swap(to[x][r],to[x][r-1]);
			r--;
		}
		r=to[y].size()-1;
		while(r>0&&to[y][r]<to[y][r-1])
		{
			swap(to[y][r],to[y][r-1]);
			r--;
		}
	}
	f(1);
	for(int i=1; i<=n; i++) cout<<ans[i]<<' ';
	return 0;
}
