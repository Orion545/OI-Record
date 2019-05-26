#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<map>
#include<set>
#define maxn 100005
using namespace std;
int n,A[maxn];
int ans=0;
int minm=0x7f7f7f7f;

void dfs(int l,int r,int last,int nu)
{
	if(l==r)
	{
		ans+=A[l]-last;
		return;
	}
	
	int minx=minm;
	int tot=0;
	//int k=r-l+5;
	int w[maxn-nu+5];
    //cout<<(r+5)-l<<" ";
	for(int i=l;i<=r;i++)
	{
		if(minx>A[i]-last)
		{
			tot=1;
			w[tot]=i;
			minx=A[i]-last;
		}
		else
		{
			if(minx==A[i]-last)
			{
				tot++;
				w[tot]=i;
			}
		}
	}
	int now=last+minx;
	ans+=minx;
	int tmpl,nl,nr;
	nl=l,nr=r;
	tmpl=l;
	int i=1;
	if(w[1]-1<l)
	    {
	    	i=2;
	    	tmpl=w[1]+1;
	    }
	for(;i<=tot;i++)
	{
		nr=w[i]-1;
		nl=tmpl;
		tmpl=w[i]+1;
		dfs(nl,nr,now,++nu);
	}
	if((w[tot]+1)<=r)
	    dfs(tmpl,r,now,++nu);
	return;
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d", &n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d", &A[i]);
	}
	dfs(1,n,0,0);
	printf("%d\n",ans);
	return 0;
}
