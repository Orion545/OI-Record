#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstdlib>
#include<vector>
#include<queue>
#include<map>
using namespace std;
int n,m,s[1010][1010],ans=0;
int to[1010][1010];
bool b[1010];

void f(int x,int len)
{
	b[x]=true;
	ans=max(ans,len);
	for(int i=1; i<=to[x][0]; i++)
	{
		if(!b[ to[x][i] ]) f(to[x][i],len+s[x][ to[x][i] ]);
	}
	b[x]=false;
	return;
}

int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d %d",&n,&m);
	int x,y,l;
	for(int i=1; i<=n-1; i++)
	{
		scanf("%d %d %d",&x,&y,&l);
		s[x][y]=l;
		s[y][x]=l;
		to[x][0]++;
		to[x][ to[x][0] ]=y;
		to[y][0]++;
		to[y][ to[y][0] ]=x;
	}
	for(int i=1; i<=n-1; i++)
	{
		f(i,0);
	}
	cout<<ans;
	return 0;
}
