#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll INF=1ll<<50;
const int MAXN=100010;

inline int read()//·Ç¸º
{
	int re=0;char ch=getchar();
	while(ch<'0' || ch>'9') ch=getchar();
	while(ch>='0' &&ch<='9') re=re*10+(ch^48),ch=getchar();
	return re;
}

char opt[5];
int n,m;
int a[MAXN];
ll f[MAXN][2],g[MAXN][2];

struct E{int y,next;}e[MAXN*2];int len=1,last[MAXN];
void ins(int x,int y)
{
	e[++len]=(E){y,last[x]};last[x]=len;
}

namespace solve1
{
	int A,X,B,Y;
	void dp(int x,int fa)
	{
		if(x==A)
		{
			if(X==0) f[x][0]=0,f[x][1]=INF;
			else f[x][0]=INF,f[x][1]=a[x];
		}
		else if(x==B)
		{
			if(Y==0) f[x][0]=0,f[x][1]=INF;
			else f[x][0]=INF,f[x][1]=a[x];
		}
		else//debug 
		{
			f[x][0]=0;
			f[x][1]=a[x];
		}
//		bool flag=false;ll tmp=INF;
		for(int k=last[x];k;k=e[k].next)
		{
			int y=e[k].y;
			if(y==fa) continue;
			dp(y,x);
			f[x][1]+=min(f[y][0],f[y][1]);//debug f[x][0]
			f[x][0]+=f[y][1];//debug
			/*if(f[y][1]<=f[y][0])//debug
			{
				flag=true;
				f[x][0]+=f[y][1];
			}
			else//if(f[y][1]>f[y][0])
			{
				f[x][0]+=f[y][0];
				tmp=min(tmp,f[y][1]-f[y][0]);
			}*/
		}
//		if(!flag) f[x][0]+=tmp;
	}
	void main()
	{
		while(m--)
		{
			A=read(),X=read(),B=read(),Y=read();
			dp(1,0);
			ll ans=min(f[1][0],f[1][1]);
			printf("%lld\n",ans>=INF?-1:ans);
		}
	}
	void prework_f()
	{
		A=1,X=1;B=0;
		dp(1,0);
	}
}

namespace solve2
{
	void dp(int x,int fa)
	{
		for(int k=last[x];k;k=e[k].next)
		{
			int y=e[k].y;
			if(y==fa) continue;
			g[y][0]=f[y][0]+g[x][1]-min(f[y][0],f[y][1]);
			g[y][1]=f[y][1]+min(g[x][1]-min(f[y][0],f[y][1]) , g[x][0]-f[y][1]);
			dp(y,x);
		}
	}
	void main()
	{
		solve1::prework_f();
		g[1][0]=f[1][0];g[1][1]=f[1][1];
		dp(1,0);
		while(m--)
		{
			int A=read(),X=read(),B=read(),Y=read();
			printf("%lld\n",g[B][Y]>=INF?-1:g[B][Y]);
		}
	}
}

int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	
	n=read(),m=read();scanf("%s",opt);
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<n;i++)
	{
		int x=read(),y=read();
		ins(x,y);ins(y,x);
	}
	
	if(opt[1]=='1') solve2::main();
	else solve1::main();
	return 0;
}
/*
6 100 A1
8 9 6 4 5 1
1 2
2 3
3 4
3 5
4 6

1 1 6 0
18

*/
