#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cstdlib>
#include <ctime>

#define oo 2147483647

using namespace std;

const int MAXN=5010;

int n,m,i,j,k,l,t[MAXN][MAXN],cir[2*MAXN],ban1=-1,ban2=-1;
bool ved[MAXN],p;

stack<int>s;

void qs(int l,int r,int wh)
{
	int i=l,j=r,mid=t[wh][(l+r)/2];
	while(i<=j)
	{
		while(t[wh][i]<mid)i++;
		while(t[wh][j]>mid)j--;
		if(i<=j)
		{
			int sw;
			sw=t[wh][i];t[wh][i]=t[wh][j];t[wh][j]=sw;
			i++;j--;
		}
	}
	if(i<r)qs(i,r,wh);
	if(j>l)qs(l,j,wh);
}

void dfs(int nown)
{
	int i,j;
	printf("%d ",nown);
	ved[nown]=1;
	for(i=1;i<=t[nown][0];i++)
	{
		if((nown==ban1&&t[nown][i]==ban2)||(nown==ban2&&t[nown][i]==ban1))continue;
		if(!ved[t[nown][i]])dfs(t[nown][i]);
	}
}

void work1()
{
	dfs(1);
}

void dfs2(int nown,int fa)
{
	int i,j;
	ved[nown]=1;
	s.push(nown);
	for(i=1;i<=t[nown][0];i++)
	{
		int nextn=t[nown][i];
		if(ved[nextn]&&nextn!=fa)
		{
			int snow=-1;
			while(snow!=nextn)
			{
				snow=s.top();
				s.pop();
				cir[++cir[0]]=snow;
			}
			p=1;
			return;
		}
		if(!ved[nextn])dfs2(nextn,nown);
		if(p)return;
	}
}
			
void work2()
{
	p=0;
	dfs2(1,0);
	cir[++cir[0]]=cir[1];
	cir[++cir[0]]=cir[2];
	int maxn=0,maxl,maxr;
	for(i=2;i<cir[0];i++)
	{
		if(cir[i]>maxn)
		{
			maxn=cir[i];
			maxl=cir[i-1];
			maxr=cir[i+1];
		}
	}
	ban1=maxn;
	ban2=min(maxl,maxr);
	//for(i=1;i<=cir[0];i++)printf("%d ",cir[i]);
	//printf("\n-------------------------------\n");
	for(i=1;i<=n;i++)ved[i]=0;
	dfs(1);
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		t[u][++t[u][0]]=v;
		t[v][++t[v][0]]=u;
	}
	for(i=1;i<=n;i++)
	{
		qs(1,t[i][0],i);
	}
	if(m==n-1)work1();
	     else work2();
	return 0;
}
