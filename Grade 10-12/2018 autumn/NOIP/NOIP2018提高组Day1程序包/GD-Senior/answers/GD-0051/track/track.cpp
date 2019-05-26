#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <vector>
const int mo=1e9+7;
const int inf=1e9;
const int N=5e4+10;
using namespace std;
struct arr
{
	int dis,f;
}li[10][N];
int n,m,d[N],mxd,dis[N],root,fa[N],mp,f[N],ri[10],f2[N],ss;
int lt[N*2],to[N*2],nt[N*2],v[N*2],tot;
int max(int x,int y)
{
	return x>y?x:y;
}
void link(int x,int y,int z)
{
	nt[++tot]=lt[x];
	lt[x]=tot;
	to[tot]=y;
	v[tot]=z;
	mxd=max(mxd,++d[x]);
}
void dg(int x,int y)
{
	if(dis[mp]<dis[x]) mp=x;
	for(int i=lt[x];i;i=nt[i])
	{
		int j=to[i];
		if(j==y) continue;
		fa[j]=x,dis[j]=dis[x]+v[i];
		dg(j,x);
	}
}
bool check(int x)
{
	memset(f,0,sizeof(f));
	for(int i=1;i<=n;i++)
	{
		int vv=upper_bound(dis+1,dis+1+n,dis[i]-x)-dis-1;
		if(dis[i]-dis[vv]>=x) f[i]=f[vv]+1;
	}
	return f[n]>=m;
}
bool check1(int x)
{
	int sum=0;
	for(int i=n;i>=1 && sum<m;)
	{
		if(dis[i]>=x) i--,sum++;
		else
		if(i>1 && dis[i]+dis[i-1]>=x) i-=2,sum++;
		else break;
	}
	return sum>=m;
}
bool cmp(arr x,arr y)
{
	return x.dis<y.dis;
}
int lim,num;
void dg2(int x,int y,int di,int ff)
{
	int sf=0;
	for(int i=lt[x];i;i=nt[i])
	{
		int j=to[i];
		if(j==y) continue;
		sf+=f[j];
	}
	li[num][++ri[num]].dis=di,li[num][ri[num]].f=f[x];
	for(int i=lt[x];i;i=nt[i])
	{
		int j=to[i];
		if(j==y) continue;
		dg2(j,x,di+v[i],ff+sf-f[j]);
	}
}
void dg1(int x,int y)
{
	for(int i=lt[x];i;i=nt[i])
	{
		int j=to[i];
		if(j==y) continue;
		dg1(j,x);
	}
	num=0,ri[0]=ri[1]=0;
	for(int i=lt[x];i;i=nt[i])
	{
		int j=to[i];
		if(j==y) continue;
		dg2(j,x,v[i],0),num++;
	}
	for(int j=0;j<num;j++)
	{
		int f1=0;
		if(!ri[j]) continue;
		sort(li[j]+1,li[j]+ri[j],cmp);
		for(int i=1;i<=ri[j];i++) f1=max(f1,li[j][i].f+(li[j][i].dis>=lim));
		f[x]+=f2[j]=f1;
	}
	if(num<=1) return;
	for(int i=0,p=ri[1],mx1=0,mx2=li[1][ri[1]].f;i<=ri[0];i++)
	{
		mx1=max(mx1,li[0][i].f);
		while(p>0 && li[1][p-1].dis+li[0][i].dis>=lim) p--,mx2=max(mx2,li[1][p].f);
		if(li[1][p].dis+li[0][i].dis>=lim) f[x]=max(f[x],mx1+mx2+1);
	}
}
bool check2(int x)
{
	memset(f,0,sizeof(f));
	lim=x,dg1(root,0);
	return f[root]>=m;
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1,x,y,z;i<n;i++) scanf("%d%d%d",&x,&y,&z),link(x,y,z),link(y,x,z),ss+=z;
	if(mxd<=2)
	{
		dg(1,0);
		int l=0,r=ss;
		while(l+1<r)
		{
			int mid=(l+r)>>1;
			if(check(mid)) l=mid;
			else r=mid;
		}
		printf("%d",check(r)?r:l);
	}
	else
	if(m==1)
	{
		dg(1,0);
		int np=mp;
		dis[np]=0,dg(np,0);
		printf("%d",dis[mp]);
	}
	else
	if(d[1]==n-1)
	{
		dg(1,0);
		int l=0,r=ss;
		sort(dis+1,dis+1+n);
		while(l+1<r)
		{
			int mid=(l+r)>>1;
			if(check1(mid)) l=mid;
			else r=mid;
		}
		printf("%d",check1(r)?r:l);
	}
	else
	if(mxd<=3)
	{
		dg(1,0);
		for(int i=1;i<=n;i++)
			if(d[i]==1) root=i;
		int l=0,r=ss;
		while(l+1<r)
		{
			int mid=(l+r)>>1;
			if(check2(mid)) l=mid;
			else r=mid;
		}
		printf("%d",check2(r)?r:l);
	}
	return 0;
}
