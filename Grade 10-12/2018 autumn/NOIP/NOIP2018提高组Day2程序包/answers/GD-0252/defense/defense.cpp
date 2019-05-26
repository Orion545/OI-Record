#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
int n,m,head[100005],to[200005],nex[200005],f[100005][2],tot,p[100005][2];
void add(int x,int y)
{
	tot++;
	to[tot]=y;
	nex[tot]=head[x];
	head[x]=tot;
}
void find(int x,int father)
{
	int k1=f[x][0],p=0,h=0;
	if (f[father][1]<f[father][0]) p=1;
	if (f[father][1]<k1)
	  k1=f[father][1],h=f[father][1]-f[father][0];
	f[x][0]+=min(f[father][0],f[father][1]);
	f[x][1]+=min(f[father][0],f[father][1]);
	for (int i=head[x];i;i=nex[i])
	  if (to[i]!=father)
	  {
	  	find(to[i],x);
	  	if (f[to[i]][1]<f[to[i]][0]) p=1;
	  	if (f[to[i]][1]<k1)
	  	  k1=f[to[i]][1],h=f[to[i]][1]-f[to[i]][0];
	  	f[x][0]+=min(f[to[i]][0],f[to[i]][1]);
	  	f[x][1]+=min(f[to[i]][0],f[to[i]][1]);
	  }
	  if (!p) f[x][0]+=h;
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d",&n,&m);
	string st;
	getline(cin,st);
	for (int i=1;i<=n;i++)
	  scanf("%d",&f[i][1]);
	for (int i=1;i<=n-1;i++)
	  {
	  int a,b;	
	  scanf("%d%d",&a,&b);
	  add(a,b);
	  add(b,a);
      }
    find(1,0);
    for (int i=1;i<=m;i++)
      {
      int a,b,c,d;	
      scanf("%d%d%d%d",&a,&b,&c,&d);
	  printf("%d\n",f[a][b]+f[c][d]);
      }
}
