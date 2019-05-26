#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<stdio.h>
#include<string.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<map>

using namespace std;

int n,m,ans=0,cou;
string pt,st,p[10010],s[10010];
char a[1000][1000];

void dfs(int x,int y)
{
	string ss="",pp="";
	ss=st; pp=pt;
	if (x==n&&y==m) 
	{
	   cou++;
	   p[cou]=pt;
	   s[cou]=st;
	   return;	
	}
	if (x<n&&y<m)
	{
		pt=pp+'D';
		st=ss+a[x+1][y];
		dfs(x+1,y);
		pt=pp+'R';
		st=ss+a[x][y+1];
		dfs(x,y+1);
		return;
	}
    if (x<n)
    {
    	pt=pp+'D';
    	st=ss+a[x+1][y];
    	dfs(x+1,y);
    }
    if (y<n)
    {
    	pt=pp+'R';
    	st=ss+a[x][y+1];
    	dfs(x,y+1);
    }
}

bool check(int k)
{
	for(int i=1; i<=n; i++)
	 for(int j=1; j<=m; j++)
	{
		if (k&(1<<((i-1)*n+j-1))) a[i][j]='1'; else a[i][j]='0'; 
	}
	cou=0;
	pt=""; st=a[1][1];
    dfs(1,1);
    for(int i=1; i<cou; i++)
     for(int j=i+1; j<=cou; j++)
     {
     	if (p[i]>p[j]) if (s[i]>s[j]) return false;
     	if (p[j]>p[i]) if (s[j]>s[i]) return false;
     }
    return true;
}

int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0; i<(1<<(n*m));  i++) if (check(i)) ++ans; 
	printf("%d\n",ans);
	
	return 0;
}
