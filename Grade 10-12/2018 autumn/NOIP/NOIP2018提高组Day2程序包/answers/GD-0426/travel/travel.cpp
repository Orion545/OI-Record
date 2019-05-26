#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>

using namespace std;
int data[5005][5005];
int n,m,a[10005],ans[10005];
int f[10005],fis[10005];
int que[10005];
void check()
{
	for (int i=1;i<=n;i++) 
	  if (ans[i]>a[i]) 
	  {
	  	for (int j=0;j<=n;j++) ans[j]=a[j];
	  	break;
	  }
	  else if (ans[i]<a[i]) break;
}

void dfs(int root)
{
	if (a[0]==n) 
	{
		check();
		return;
	}
	for (int i=1;i<=data[root][0];i++)
	{
		if (!f[data[root][i]])
		{
			f[data[root][i]]=1;
			a[++a[0]]=data[root][i];
			dfs(data[root][i]);
		}
	}
}


int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		data[x][++data[x][0]]=y;
		data[y][++data[y][0]]=x;
	}
	for (int i=1;i<=n;i++) sort(data[i]+1,data[i]+data[i][0]+1);
	memset(ans,127,sizeof(ans));
	for (int i=1;i<=n;i++)
	{
		memset(f,0,sizeof(f));
		memset(a,0,sizeof(a));
		a[++a[0]]=i; 
		f[i]=1;
		dfs(i);
		if (ans[0]==n) break;
	}
	for (int i=1;i<=n;i++) printf("%d ",ans[i]);
	return 0;
}
