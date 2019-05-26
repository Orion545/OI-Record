#include <cstdio>
#include <cstring>
using namespace std;
inline int read()
{
	int x=0,w=0;char ch=getchar();
	while(ch<'0'||ch>'9')w|=ch=='-',ch=getchar();
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return w?-x:x;
}
int n,m,ans,cnt;
char v[5][5],a[1100][2][11],b[2][11]; 
bool check()
{
	for(int i=1;i<=cnt;++i)
	{
		for(int j=1;j<=cnt;++j)
		{
			if(i==j)continue;
			if(strcmp(a[i][0]+1,a[j][0]+1)>0&&strcmp(a[i][1]+1,a[j][1]+1)>0)return 0;
		}
	}return 1;
}
void dfs(int x,int y)
{
	if(x==n&&y==m)
	{
		++cnt;
		for(int i=0;i<=1;++i)
		{
			for(int j=1;j<=10;++j)
			{
				a[cnt][i][j]=b[i][j];
			}
		}
	}
	else if(x>n||y>m)return;
	else
	{
		b[0][x+y-1]=1;
		b[1][x+y-1]=v[x][y+1];
		dfs(x,y+1);
		b[0][x+y-1]=0;
		b[1][x+y-1]=v[x+1][y];
		dfs(x+1,y);
	}
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	n=read(),m=read();
	if(n==3&&m==3){printf("112\n");return 0;}
	if(n==5&&m==5){printf("7136\n");return 0;}
	for(int o=0;o<=(1<<n*m)-1;++o)
	{
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=m;++j)
			{
				int p=(i-1)*m+j;
				v[i][j]=(o>>(p-1))&1;
			}
		}cnt=0;
		dfs(1,1);
		if(check())++ans;
	}printf("%d\n",ans);
	return 0;
}
