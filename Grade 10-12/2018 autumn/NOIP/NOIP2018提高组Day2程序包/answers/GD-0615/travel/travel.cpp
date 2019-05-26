#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int l[5005],n,m,u[5005],v[5005],ans,p;
bool qw[5005];
struct zz
{
	int bg,to,next;
}f[5005];
struct z
{
	int u,v;
}a[10005];
bool cmp(z q,z w)
{
	if (q.u!=w.u) return q.u<w.u;
	  else return q.v>w.v;
}
void add(int x,int y)
{
	ans++;f[ans].bg=x;f[ans].to=y;
	f[ans].next=l[x];l[x]=ans;
}
void dfs(int x)
{
	for (int i=l[x];i;i=f[i].next)
	  {
	  	int y=f[i].to;
	  	if (qw[y]) continue;
	  	cout<<y<<" ";
	  	qw[y]=true;
	  	dfs(y);
	  }
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=m;i++)
	  {
	  cin>>a[i].u>>a[i].v;
      a[i+m].u=a[i].v;a[i+m].v=a[i].u;
	  }
	sort(a+1,a+2*m+1,cmp);
	for (int i=1;i<=2*m;i++)
	  add(a[i].u,a[i].v);
	if (m==n-1)
	  {
	  	cout<<1<<" ";
	  	qw[1]=true;
	  	dfs(1);
      }
     else 
       for (int i=1;i<=n;i++)
         cout<<i<<" ";
    return 0;
}
