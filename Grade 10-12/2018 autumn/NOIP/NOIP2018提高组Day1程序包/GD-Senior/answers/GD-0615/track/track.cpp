#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int ans,n,m,a,b,big,l[50008],k;
bool q[50005];
int d[50005];
struct zz
{
	int bg,to,dj,next;
}f[50005];
void add(int x,int y,int k)
{
	ans++;f[ans].bg=x;f[ans].to=y;f[ans].dj=k;
	f[ans].next=l[x];l[x]=ans;
}
void fd(int x)
{
	int hd=1,tl=1,p[50005];
	memset(q,false,sizeof(q));
	memset(d,0,sizeof(d));
	p[hd]=x;q[x]=true;
	while (hd<=tl)
	  {
	  	int e=p[hd];
	  	for (int i=l[e];i;i=f[i].next)
	  	  {
	  	  	int w=f[i].to;
	  	  	if (q[w]) continue;
	  	  	d[w]=d[e]+f[i].dj;
	  	  	big=max(d[w],big);
	  	  	tl++;
	  	  	p[tl]=w;
	  	  	q[w]=true;
	  	  }
	  	tl++;
	  }
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	cin>>n>>m;
	if (m==1)
	  {
	  	for (int i=1;i<=n;i++)
	  	  {
	  	  	cin>>a>>b>>k;
	  	  	add(a,b,k);
	  	  	add(b,a,k);
	  	  }
	  	for (int i=1;i<=n;i++)
	  	  fd(i);
	  	cout<<big;
	  	return 0;
	  }
}
