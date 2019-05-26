#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cctype>

#define fo(i,a,b) for(int i=a;i<=b;++i)
#define fd(i,a,b) for(int i=a;i>=b;--i)
#define P(c) putchar(c)

using namespace std;

const int N=1e5+5,inf=1e9+9;
int n,m,num,A,B,X,Y;
int p[N],last[N]/*,f[N][2]*/,g[N][2];
char s[10];
struct edge{int to,next;}e[2*N];

inline void read(int &n)
{
	int x=0,w=0; char ch=0;
	while(!isdigit(ch)) w|=ch=='-',ch=getchar();
	while(isdigit(ch)) x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	n=w?-x:x;
}

inline void write(int x)
{
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}

void link(int x,int y)
{
	e[++num]=(edge){y,last[x]},last[x]=num;
}

/*void dfs(int x,int fa)
{
	for(int w=last[x];w;w=e[w].next)
	{
		int y=e[w].to;
		if(y==fa) continue;
		dfs(y,x);
		f[x][0]+=f[y][1];
		f[x][1]+=min(f[y][0],f[y][1]);
	}
}*/

void solve(int x,int fa)
{
	if(x==A) g[A][X^1]=inf;
	if(x==B) g[B][Y^1]=inf;
	for(int w=last[x];w;w=e[w].next)
	{
		int y=e[w].to;
		if(y==fa) continue;
		solve(y,x);
		g[x][0]=g[y][1]>=inf?inf:g[x][0]+g[y][1];
		g[x][1]+=min(g[y][0],g[y][1]);
	}
}

int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	read(n),read(m),scanf("%s",s+1);
	fo(i,1,n) read(p[i])/*,f[i][1]=p[i]*/;
	fo(i,1,n-1)
	{
		int x,y;
		read(x),read(y);
		link(x,y),link(y,x);
	}
	//dfs(1,0);
	fo(i,1,m)
	{
		read(A),read(X),read(B),read(Y);
		if(X==0&&Y==0)
		{
			int bz=0;
			for(int w=last[A];w;w=e[w].next) if(e[w].to==B)
			{
				write(-1),P('\n');
				bz=1; break;
			}
			if(bz) continue;
		}
		memset(g,0,sizeof(g));
		fo(j,1,n) g[j][1]=p[j];
		solve(1,0);
		int ans=min(g[1][0],g[1][1]);
		write(ans<inf?ans:-1),P('\n');
	}
}

