#include<cstdio>
#define LL long long
using namespace std;
const int MOD=1e9+7;
LL ans=0;
int n,m,cnt=1;
bool a[10][10];
bool s[15];
bool s2[10000][15];
void dfs2(int x,int y)
{
	s[x+y-1]=a[x][y];
	if(x==n&&y==m)
	{
		for(int i=1;i<=n+m-1;i++) s2[cnt][i]=s[i];
		cnt++;
		return;
	}
	if(y<m) dfs2(x,y+1);
	if(x<n) dfs2(x+1,y);
}
bool judge()
{
	cnt=1;
	dfs2(1,1);
	cnt--;
	for(int i=1;i<=cnt;i++)
		for(int j=i+1;j<=cnt;j++)
			for(int k=1;k<=n+m-1;k++)
			{
				if(s2[i][k]<s2[j][k]) break;
				if(s2[i][k]>s2[j][k]) return 0;
			}
	return 1;
}
void dfs(int x,int y)
{
	if(x==n&&y==m)
	{
		if(judge()) ans=(ans+1<MOD)?ans+1:0;
		return;
	}
	if(y<m) a[x][y+1]=1,dfs(x,y+1);
	else a[x+1][1]=1,dfs(x+1,1);
	if(y<m) a[x][y+1]=0,dfs(x,y+1);
	else a[x+1][1]=0,dfs(x+1,1);
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	dfs(1,0);
	printf("%lld",ans);
	return 0;
}
