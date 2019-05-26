#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
using namespace std;
const int maxn=5010, inf=1e9;
struct edge{int too, pre;}e[maxn<<1];
int tot, n, m, x, y;
int last[maxn], ans[maxn], ANS[maxn];
bool vis[maxn], v[maxn<<1];
bool mp[maxn][maxn];

template<typename T>
inline void read(T &k)
{
	int f=1; k=0; char c=getchar();
	while(c<'0' || c>'9') c=='-' && (f=-1), c=getchar();
	while(c<='9' && c>='0') k=k*10+c-'0', c=getchar();
	k*=f;
}

inline void add(int x, int y) {e[++tot]=(edge){y, last[x]}; last[x]=tot;}

void dfs(int x)
{
//	printf("%d\n", x);
	vis[x]=1; ans[++ans[0]]=x; 
	for(int i=last[x], too;i;i=e[i].pre)
	if(!vis[too=e[i].too] && !v[i]) dfs(too);
}

int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	read(n); read(m); tot=1;
	for(int i=1;i<=m;i++)
	{
		read(x); read(y);
		mp[x][y]=mp[y][x]=1;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=n;j;j--)
		if(mp[i][j]) add(i, j);
	}
	if(m==n-1) 
	{
		dfs(1);
		for(int i=1;i<=n;i++) printf("%d ", ans[i]);
		puts("");
	}
	else
	{
		ANS[1]=n+1;
		for(int i=1;i<=m;i++) 
		{
			memset(vis, 0, sizeof(vis));
			ans[0]=0;
			v[i*2]=v[i*2+1]=1;
			dfs(1); bool flag=0;
			v[i*2]=v[i*2+1]=0;
//			for(int j=1;j<=n;j++) printf("%d ", ans[j]); puts("");
			for(int j=1;j<=n;j++) flag|=(!vis[j]);
			if(flag) continue;
			for(int j=1;j<=n;j++)
			if(ans[j]<ANS[j])
			{
				flag=1;
				break;
			}
			else if(ans[j]>ANS[j]) break;
			if(!flag) continue;
			memcpy(ANS, ans, sizeof(ans));
		}
		for(int i=1;i<=n;i++) printf("%d ", ANS[i]);
		puts("");
	}
	return 0;
}
