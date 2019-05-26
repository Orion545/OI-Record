#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define fo(i,a,b) for (i=a; i<=b; i++)
#define foo(i,a,b) for (i=a; i>=b; i--)
#define ll long long
using namespace std;

const int N=1e5+5;
const ll W=(ll)1e15;
int n, m, i, x, y, dy, bx, by, t;
char s[5];
int lst[N], e[N*2][2];
int v[N];
ll f[N][2];

void link(int x,int y) {e[++t][0]=lst[x], e[t][1]=y, lst[x]=t;}
void dg(int x,int fx)
{
	int i=lst[x]; f[x][0]=0, f[x][1]=v[x];
	while (i)
	{
		int y=e[i][1]; i=e[i][0];
		if (fx!=y)
		{
			dg(y,x); if (dy==y) f[y][1-by]=W;
			f[x][0]+=f[y][1], f[x][1]+=min(f[y][0],f[y][1]);
		}
	}
}

int main()
{
	freopen("defense.in","r",stdin), freopen("defense.out","w",stdout);
	
	scanf("%d%d%s",&n,&m,s);
	fo(i,1,n) scanf("%d",&v[i]);
	fo(i,2,n) scanf("%d%d",&x,&y), link(x,y), link(y,x);
	fo(i,1,m)
	{
		scanf("%d%d%d%d",&x,&bx,&dy,&by);
		if (!bx && !by)
		{
			int j=lst[x]; bool flag=0;
			while (j)
			{
				y=e[j][1], j=e[j][0];
				if (dy==y) {flag=1; break;}
			}
			if (flag) {printf("-1\n"); continue;}
		}
		dg(x,0), printf("%lld\n",f[x][bx]);
	}
}
