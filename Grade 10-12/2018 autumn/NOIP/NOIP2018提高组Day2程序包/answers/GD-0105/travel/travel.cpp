#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
const int N=5020;
vector<int> e[N];
int ans[N];
struct data{
	int x,y;
};
data x[N];
int bo[N],h[N],hu[N],sum[N];
int p=0,pp=0;
int fr,to;
int gg=0;
int xx[N],yy[N];
void solve(int u,int pre)
{
//	printf("%d\n",u);
	for(int i=0;i<e[u].size();i++)
	{
		int v =e[u][i];
		if(v!=pre && (!(to==u&&fr==v)))
		{
			if(to==v && fr==u);
			else 
			solve(v,u);
		}
	}
	ans[++p] = u;
	return ;
}
bool cmp(data a,data b)
{
	if(a.x>b.x)return 1;
	if(a.x<b.x)return 0;
	if(a.y>b.y)return 1;
	return 0;
}
void huan(int u,int k,int pre)
{
	bo[u] = ++k;
	h[k] = u;
	for(int i=0;i<e[u].size();i++)
	{
		if(gg==1)return; 
		int v =e[u][i];
		if(v==pre) continue;
		if(bo[v]==0)
			huan(v,k,u);
		else
		{
			for(int i=bo[v];i<=k;i++)
			{
			  hu[++pp] = h[i];
			  if(i!=bo[v])xx[pp] = h[i-1];
			  else xx[pp] = h[k];
		//	  if(i!=k) yy[pp] = h[i+1];
		//	  else  yy[pp] = h[bo[v]];
			}
			gg = 1;
			return ;
		}
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&x[i].x,&x[i].y);
		if(x[i].x>x[i].y) swap(x[i].x,x[i].y);
	}
	sort(x+1,x+m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		e[x[i].x].push_back(x[i].y);
		e[x[i].y].push_back(x[i].x);
	}
	huan(1,0,0);
	memset(sum,127,sizeof(sum));
	if(m==n)
	{
	for(int i=1;i<=pp;i++)
	{
		p = 0;
		fr = xx[i];
		to = hu[i];
		solve(1,0);
		int t = 0;
		for(int j=p;j>0;j--)
		{
		  if(ans[j] > sum[j]) {t = 1;break;}
		  if(ans[j] < sum[j]) {t = 0;break;}
		}
		if(t==0) for(int i=p;i>0;i--) sum[i]=ans[i];
		p=0;
		swap(fr,to);
		solve(1,0);
		t = 0;
		for(int j=p;j>0;j--)
		{
		  if(ans[j] > sum[j]) {t = 1;break;}
		  if(ans[j] < sum[j]) {t = 0;break;}
		}
		if(t==0) for(int i=p;i>0;i--) sum[i]=ans[i];
	}
	for(int i=p;i>0;i--)printf("%d ",sum[i]);
	}
	else 
	{
		solve(1,0);
		for(int i=p;i>0;i--)printf("%d ",ans[i]);
	}
	return 0;
}
/*
6 6
1 3
2 3
2 5
3 4
4 5
4 6

3 3
1 2
1 3
2 3

*/
