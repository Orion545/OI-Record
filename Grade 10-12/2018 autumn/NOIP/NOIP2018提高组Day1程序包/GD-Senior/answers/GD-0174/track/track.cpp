#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <set>
#define fo(i,a,b) for(int i=a;i<=b;++i)
#define fod(i,a,b) for(int i=a;i>=b;--i)
#define N 100005
using namespace std;
int fs[N],nt[2*N],dt[2*N],ms[N],pr[2*N],n,m1,ls,lim,ans,d[N],fn[N],rx,mx1[N],mx2[N];
multiset<int> h;
void link(int x,int y,int z)
{
	nt[++m1]=fs[x];
	dt[fs[x]=m1]=y;
	pr[m1]=z;
}
bool cmp(int x,int y)
{
	return ms[x]+fn[x]<ms[y]+fn[y];
}
void dfs(int k,int fa)
{
	ms[k]=0;
	for(int i=fs[k];i;i=nt[i])
	{
		int p=dt[i];
		if(p!=fa) fn[p]=pr[i],dfs(p,k);
	}
	d[0]=0;
	for(int i=fs[k];i;i=nt[i])
	{
		int p=dt[i];
		if(p!=fa) d[++d[0]]=p;
	}
	sort(d+1,d+d[0]+1,cmp);
	int x=1;
	h.clear();
	fo(i,1,d[0])
	{
		if(ms[d[i]]+fn[d[i]]>=ls) ans++;
		else
		{
			 if(!h.empty())
			 {
			 	multiset<int>::iterator it=h.lower_bound(ls-ms[d[i]]-fn[d[i]]);
			 	if(it!=h.end()) ans++,h.erase(it);
			 	else h.insert(ms[d[i]]+fn[d[i]]);
			 }
			 else h.insert(ms[d[i]]+fn[d[i]]);
		}	
	}
	if(!h.empty()) ms[k]=*h.rbegin();
}
bool pd(int mid)
{
	ls=mid;
	ans=0;
	dfs(1,0);
	return (ans>=lim);
}
void fd(int k,int fa)
{
	mx1[k]=mx2[k]=0;
	for(int i=fs[k];i;i=nt[i])
	{
		int p=dt[i];
		if(p!=fa)
		{
			fd(p,k);
			if(mx1[p]+pr[i]>mx2[k])
			{
				if(mx1[p]+pr[i]>=mx1[k]) mx2[k]=mx1[k],mx1[k]=mx1[p]+pr[i];
				else mx2[k]=mx1[p]+pr[i];
			}
		}
	}
	rx=max(rx,mx1[k]+mx2[k]);
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	cin>>n>>lim;
	fo(i,1,n-1)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		link(x,y,z),link(y,x,z);
	}
	fd(1,0);
	int l=0,r=rx;
	while(l+1<r)
	{
		int mid=(l+r)>>1;
		if(pd(mid)) l=mid;
		else r=mid;
	}
	if(pd(r)) printf("%d\n",r);
	else printf("%d\n",l);
}
