#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iostream>
#define fo(i,a,b) for(int i=a;i<=b;++i)
#define fod(i,a,b) for(int i=a;i>=b;--i)
#define N 100005
#define M 100005
using namespace std;
int n,m,a1[N][2],pt[M][2],st[M],ans[N],sc[M],s1[N];
bool bz[M],b1[N],pd;
struct node
{
	int x,y,w;
	friend bool operator <(node x,node y)
	{
		return (x.x<y.x)||(x.x==y.x&&x.y<y.y);
	}
}a[M];
void dfs(int k,int fa)
{
	ans[++ans[0]]=k;
	if(a1[k][0]!=0)
	fo(i,a1[k][0],a1[k][1])
	{
		int p=a[i].y;
		if(!bz[i]&&p!=fa) dfs(p,k);
	}
}
void fd(int k,int fa)
{
	b1[k]=1;
	if(a1[k][0]!=0)
	fo(i,a1[k][0],a1[k][1])
	{
		int p=a[i].y;
		if(p!=fa)
		{
			if(!b1[p]) 
			{
				st[++st[0]]=i;
				fd(p,k);
				if(pd) return;
				st[st[0]--]=0;
			}
			else 
			{
				pd=1;
				st[++st[0]]=i;
				while(st[0]>0&&a[st[st[0]]].x!=p) sc[++sc[0]]=a[st[st[0]]].w,st[0]--;
				sc[++sc[0]]=a[st[st[0]]].w,st[0]--;
				return;
			}
		}
	}
}
bool upd()
{
	fo(i,1,n)
	{
		if(ans[i]<s1[i]) return 1;
		if(ans[i]>s1[i]) return 0;
	}
	return 0;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>m;
	fo(i,1,m)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		a[2*i-1]=(node){x,y,i};
		a[2*i]=(node){y,x,i};
	}
	sort(a+1,a+2*m+1);
	fo(i,1,2*m)
	{
		if(a[i].x<a[i].y) pt[a[i].w][0]=i;
		else pt[a[i].w][1]=i;
		if(a[i].x!=a[i-1].x||i==1)
		{
			a1[a[i].x][0]=i;
			a1[a[i-1].x][1]=i-1;
		}
	}
	a1[a[2*m].x][1]=2*m;
	if(m==n-1)
	{
		dfs(1,0);
		fo(i,1,n) s1[i]=ans[i];
	}
	else
	{
		fd(1,0);
		s1[1]=n+1;
		fo(j,1,sc[0]) 
		{
			ans[0]=0;
			bz[pt[sc[j]][0]]=bz[pt[sc[j]][1]]=1;
			dfs(1,0);
			if (upd()) fo(i,1,n) s1[i]=ans[i];
			bz[pt[sc[j]][0]]=bz[pt[sc[j]][1]]=0;
		}
	}
	fo(i,1,n) printf("%d ",s1[i]);
}
