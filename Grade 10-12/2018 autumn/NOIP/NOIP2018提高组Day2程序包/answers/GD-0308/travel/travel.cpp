#include<cstdio>
#include<cstring>
#include<algorithm>
#define fo(i,a,b) for(int i=(a);i<=(b);++i)
#define fd(i,a,b) for(int i=(a);i>=(b);--i)
#define mset(a,x) memset(a,x,sizeof(a))
using namespace std;
typedef long long ll;
int read()
{
	char ch;int n=0,p=1;
	for(ch=getchar();ch<'0' || '9'<ch;ch=getchar()) if(ch=='-') p=-1;
	for(;'0'<=ch && ch<='9';ch=getchar()) n=n*10+ch-'0';
	return n*p;
}
const int N=5005;
struct edge
{
	int x,y;
}b[N];
int n,m,c[N],ans[N],a[N][N];
bool vis[N],ban[N][N];
void dfs(int v)
{
	c[++c[0]]=v,vis[v]=1;
	for(int i=1,u=a[v][1];i<=a[v][0];u=a[v][++i]) if(!vis[u] && !ban[v][u])
	{
		dfs(u);
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	n=read(),m=read();
	fo(i,1,m)
	{
		int x=read(),y=read();
		b[i]=(edge){x,y};
		a[x][++a[x][0]]=y,a[y][++a[y][0]]=x;
	}
	fo(i,1,n) sort(a[i]+1,a[i]+a[i][0]+1);
	if(m==n-1)
	{
		c[0]=0;
		dfs(1);
		fo(i,1,n)
		{
			printf("%d",c[i]);
			if(i<n) putchar(' ');
		}
		return 0;
	}
	fo(i,1,n) ans[i]=n+1;
	fo(k,1,m)
	{
		mset(vis,0);
		ban[b[k].x][b[k].y]=ban[b[k].y][b[k].x]=1;
		c[0]=0;
		dfs(1);
		if(c[0]==n)
		{
			bool ok=0;
			fo(i,1,n)
				if(c[i]<ans[i]) {ok=1;break;}
				else
				if(c[i]>ans[i]) {ok=0;break;}
			if(ok) fo(i,1,n) ans[i]=c[i];
		}
		ban[b[k].x][b[k].y]=ban[b[k].y][b[k].x]=0;
	}
	fo(i,1,n)
	{
		printf("%d",ans[i]);
		if(i<n) putchar(' ');
	}
	return 0;
}

