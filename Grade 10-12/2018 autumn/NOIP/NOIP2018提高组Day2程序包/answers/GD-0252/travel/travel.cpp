#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
using namespace std;
int n,m,tot,ans[5005],k,a1,b1,a[5005],b[5005],p,bad,an[5005];
vector<int>to[5005];
bool vis[5005];
void dfs(int x,int father)
{
	k++;
	if (p) an[k]=x;
	if (!p&&ans[k]<x) {bad=1;return;}
	if (!p&&ans[k]>x) p=1,an[k]=x;
	vis[x]=1;
	for (int i=0;i<to[x].size();i++)
	  {	
	  if (to[x][i]==father||vis[to[x][i]]) continue;
	  if (x==a1&&to[x][i]==b1||x==b1&&to[x][i]==a1) continue;
	  dfs(to[x][i],x);
	  if (bad) return;
      }
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	  {
	  scanf("%d%d",&a[i],&b[i]);
	  to[a[i]].push_back(b[i]);
	  to[b[i]].push_back(a[i]);
      }
   for (int i=1;i<=n;i++)
     sort(to[i].begin(),to[i].end());
   if (n-1==m)
     {
     p=1;	
	 dfs(1,0);
     }
   if (n==m)
     {
     p=1;	
	 for (int i=1;i<=m;i++)
	   {
	   k=0;a1=a[i],b1=b[i];bad=0;
	   memset(vis,0,sizeof vis);
	   dfs(1,0);
	   if (k==n) {p=0;
	   for (int j=1;j<=n;j++)
	     ans[j]=an[j];}
       }
     } 
	 for (int i=1;i<=n;i++)
	   printf("%d ",ans[i]);
} 
