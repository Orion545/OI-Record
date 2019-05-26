#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <set>
#include <queue>
#include <vector>
using namespace std;
bool vis[250000];
int a[500];
int n,mxa,T;
void dfs(int rmb,int t)
{
	for (int i=1;i<=n;i++)
	if (rmb+a[i]<=mxa)
	if (vis[rmb+a[i]]==false)
	{
		if (t>=1) vis[rmb+a[i]]=true;
		dfs(rmb+a[i],t+1);
	}
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&T);
	for (int i=1;i<=T;i++)
	  {
	  	scanf("%d",&n);
	  	memset(vis,false,sizeof(vis));
	  	mxa=0;
	  	for (int i=1;i<=n;i++)
	  	  {
	  	    scanf("%d",&a[i]);
	  	    mxa=max(mxa,a[i]);
	      }
	      dfs(0,0);
	    int ans=0;  
	    for (int i=1;i<=n;i++)
	      if (!vis[a[i]]) ans++;
	    printf("%d\n",ans);  
	  }
	fclose(stdin);
	fclose(stdout);
	return 0;  
}
