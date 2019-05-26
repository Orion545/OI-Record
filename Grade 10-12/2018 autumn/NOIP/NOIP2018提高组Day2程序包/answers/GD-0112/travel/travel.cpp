#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<cctype>

#include<set>
#include<map>
#include<vector>
#include<numeric>

#define ui unsigned int
#define ic isdigit(c)
#define cg c=getchar()
#define pc putchar
#define et putchar('\n')
#define sp putchar(' ')
#define tt(a) template<typename a>
using namespace std;

tt(GD) void read(GD& x)
{
	x=0; bool f=0; char cg;
	while(!ic) { if(c=='-') f=1; cg; }
	while(ic) x=(x<<3)+(x<<1)+(c^48),cg;
	if(f) x=-x;
}

tt(GD) void write(GD x)
{
	if(x<0) pc('-'),x=-x;
	if(x>9) write(x/10);
	pc(x%10+48);
}

const int MAXN = 5000+10;
const int MAXM = 10000+50;
int n,m,cnt;
int g[MAXN][MAXN],ph[MAXN];

void dfs(int now,int fa)
{	
	ph[++cnt]=now;
	int sz=g[now][0];
	sort(g[now]+1,g[now]+sz+1);
	for(int i=1;i<=sz;i++)
	{
		int to=g[now][i];
		if(to==fa) continue;
		dfs(to,now);
	}
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	read(n); read(m);
	for(int i=1;i<=m;i++)
	{
		int x,y; read(x); read(y);
		g[x][++g[x][0]]=y;
		g[y][++g[y][0]]=x;
	}
//	if(m!=n)
//	{
		dfs(1,0);
//	}
//	else
//	{
		
//	}
	for(int i=1;i<=cnt;i++)
		write(ph[i]),sp;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
