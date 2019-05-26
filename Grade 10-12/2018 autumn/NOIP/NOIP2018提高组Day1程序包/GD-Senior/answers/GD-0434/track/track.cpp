#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

const int MAXN = 50009,
		  MAXM = MAXN*2;

int _head[MAXN],_next[MAXM],_node[MAXM],_val[MAXM];
int c[MAXN],a[MAXN],Max[MAXN];
int Min;
bool used[MAXN];
int n,fp=0,k,m,j,st;

void _connect(int a,int b,int v)
{
	_next[fp]=_head[a];
	_node[fp]=b;
	_val[fp]=v;
	_head[a]=fp++;
	return ;
}

bool _cmp(int a,int b) {return a>b;}

void dfs(int u,int fa)
{
//	cerr << u << endl;
	c[u]=0;
	Max[u]=0;
	int v,i;
	for (int i=_head[u];~i;i=_next[i])
	{
		v=_node[i];
		if (v==fa)
			continue;
		dfs(v,u);
	}
	k=0;
	for (i=_head[u];~i;i=_next[i])
	{
		v=_node[i];
		if (v==fa)
			continue;
		a[k++]=Max[v]+_val[i];
		c[u]+=c[v];
	}
	if (!k)
		return ;
//	cerr << "-----" << u << "-" << Min << "-----\n";
//	cerr << "^^ " << c[u] << "\n";
//	for (int i=0;i<k;i++)
//		cerr << a[i] << '\n';
	sort(a,a+k,_cmp);
	for (i=0;i<k;i++)
		used[i]=0;
	j=k-1,st=0;
	while (st<k && a[st]>=Min)
	{
		used[st]=1;
		c[u]++;
		st++;
	}
	for (i=st+1;i<j;i++)
	{
		while (i<j && a[i]+a[j]<Min)
			j--;
		if (i<j && a[i]+a[j]>=Min)
		{
			c[u]++;
			used[i]=used[j]=1;
			j--;
		}
	}
	for (i=k-1;i>st && (!used[st]);i--)
		if ((!used[i]) && a[st]+a[i]>=Min)
		{
			used[i]=used[st]=1;
			c[u]++;
		}
	for (i=0;i<k;i++)
		if (!used[i])
		{
			Max[u]=a[i];
			break;
		}
	return ;
}

bool check(int val)
{
	Min=val;
	dfs(1,0);
//	cerr << "## " << val << ' ' << c[1] << '\n';
	return c[1]>=m;
}

int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	int x,y,z;
	memset(_head,-1,sizeof _head);
	scanf("%d%d",&n,&m);
	for (int i=1;i<n;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		_connect(x,y,z);
		_connect(y,x,z);
	}
	int l=0,r=1000000000,mid;
	while (l+1<r)
	{
		mid=(l+r)/2;
		if (check(mid))
			l=mid;
		else
			r=mid;
	}
	printf("%d\n",l);
	return 0;
}
