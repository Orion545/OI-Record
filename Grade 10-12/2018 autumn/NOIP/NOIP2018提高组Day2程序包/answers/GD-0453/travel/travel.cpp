#include<stdio.h>
#include<string.h>
#include<algorithm>
#define MAXN 5005
#define fo(i,a,b) for (int i=a;i<=b;++i)
#define fd(i,a,b) for (int i=a;i>=b;--i)
#define rep(i,a) for (int i=last[a];i;i=next[i])

using namespace std;

int f[MAXN][MAXN],gx[MAXN],gy[MAXN],ans[MAXN],answer[MAXN];
bool b[MAXN][MAXN],bz[MAXN];
int n,m,tot,pos;

int max(int x,int y)
{
	return x>y?x:y;
}
int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0' || '9'<ch){if (ch=='-')f=-1;ch=getchar();}
	while ('0'<=ch && ch<='9')x=x*10+ch-'0',ch=getchar();
	return x*f;
}
void dfs(int x)
{
	printf("%d ",x),bz[x]=0;
	fo(i,1,n)if (b[x][i] && bz[i])dfs(i);
}
void dfs1(int x)
{
	ans[++pos]=x,bz[x]=0;
	fo(i,1,f[x][0])if (b[x][f[x][i]] && bz[f[x][i]])dfs1(f[x][i]);
}
bool judge()
{
	fo(i,1,n)
	{
		if (ans[i]<answer[i])return 1;
		else if (ans[i]>answer[i])return 0;
	}
	return 0;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	n=read(),m=read();
	fo(i,1,m)
	{
		int x=read(),y=read();
		gx[i]=x,gy[i]=y;
		b[x][y]=b[y][x]=1;
		f[x][++f[x][0]]=y,f[y][++f[y][0]]=x;
	}
	if (n==m+1)
	{
		memset(bz,1,sizeof(bz));
		dfs(1);
		printf("\n");
		return 0;
	}
	fo(i,1,n)sort(f[i]+1,f[i]+f[i][0]+1),answer[i]=1000000007;
	fo(i,1,m)
	{
		memset(bz,1,sizeof(bz));
		int x=gx[i],y=gy[i];
		b[x][y]=b[y][x]=pos=0;
		dfs1(1);
		if (judge())memcpy(answer,ans,sizeof(answer));
		b[x][y]=b[y][x]=1;
	}
	fo(i,1,n)printf("%d ",answer[i]);
	printf("\n");
	return 0;
}
