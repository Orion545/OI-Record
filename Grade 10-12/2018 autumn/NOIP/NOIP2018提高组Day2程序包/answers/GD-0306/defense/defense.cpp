#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

#define N 2020
#define INF 0x7ffffff

struct note
{
	int y,next;
};

note side[N*2];
int last[N],fa[N],f[N][2],p[N];
int n,m,a,x,b,y,l;
char c,t;

void add(int x,int y)
{
	l++;
	side[l].y=y; side[l].next=last[x];
	last[x]=l;
}

void init()
{
	scanf("%d%d%c%c%c\n",&n,&m,&c,&c,&t);
	for (int i=1;i<=n;i++)
	  scanf("%d",&p[i]);
	for (int i=1;i<=n-1;i++)
	{
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
}

void dfs(int xx)
{
	for (int i=last[xx];i!=0;i=side[i].next)
	{
		int j=side[i].y;
		if (j==fa[xx]) continue;
		fa[j]=xx;
		dfs(j);
		f[xx][0]+=f[j][1];
		f[xx][1]+=min(f[j][0],f[j][1]);
	}
	f[xx][1]+=p[xx];
	if (xx==a) f[xx][x^1]=INF;
	if (xx==b) f[xx][y^1]=INF;
}

int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	init();
	dfs(1);
	for (int i=1;i<=m;i++)
  {
  	memset(f,0,sizeof(f));
  	scanf("%d%d%d%d",&a,&x,&b,&y);
  	if ((fa[a]==b || fa[b]==a) && (x+y==0)) 
  	{
  		printf("-1\n");
  		continue;
  	}
  	dfs(1);
  	printf("%d\n",min(f[1][0],f[1][1]));
  }
  return 0;
}

  
