#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
int ans,n,m,tot,juhua,lian,head[50005],nex[100005],to[100005],val[100005],f[50005][2],c[50005],anss;
void add(int x,int y,int z)
{
	tot++;
	to[tot]=y;
	nex[tot]=head[x];
	val[tot]=z;
	head[x]=tot;
}
bool cmp(int aa,int bb)
{
	return aa>bb;
}
void dfs(int x,int father)
{
	for (int i=head[x];i;i=nex[i])
	  if (to[i]!=father)
	  {
	  	dfs(to[i],x);
	  	if (f[to[i]][0]+val[i]>f[x][0])
	  	  {
		  f[x][1]=f[x][0],f[x][0]=f[to[i]][0]+val[i];
		  continue;
	      }
	    if (f[to[i]][0]+val[i]>f[x][1])
		  f[x][1]=f[to[i]][0]+val[i]; 
	  }
	ans=max(ans,f[x][0]+f[x][1]);
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	anss=2147483647;
	for (int i=1;i<n;i++)
	  {
	  int a,b;	
	  scanf("%d%d%d",&a,&b,&c[i]);
	  if (a!=1&&b!=1) juhua=1;
	  if (a+1!=b) lian=1;
	  add(a,b,c[i]);
	  add(b,a,c[i]);
	  anss=min(anss,c[i]);
      }
    if (m==1) 
	  {
	  ans=0;	
	  dfs(1,0);
	  printf("%d",ans);
	  return 0;
      }
    if (!juhua)
	  {
	  ans=2147483647;	
	  sort(c+1,c+n,cmp);
	  for (int i=m+1;i<n;i++)
	    if (m-(i-m)+1<1) break; 
	      else ans=min(c[i]+c[m-(i-m)+1],ans);
	  for (int i=1;i<=2*m-n+1;i++)
	    ans=min(c[i],ans);  
	  printf("%d",ans);
	  return 0;
      } 
    printf("%d",anss);
}
