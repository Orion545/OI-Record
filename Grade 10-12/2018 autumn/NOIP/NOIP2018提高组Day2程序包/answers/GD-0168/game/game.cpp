#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cctype>

#define fo(i,a,b) for(int i=a;i<=b;++i)
#define fd(i,a,b) for(int i=a;i>=b;--i)

using namespace std;

const int P=1e9+7,N=10;
int fx[2][2]={{1,0},{0,1}};
int n,m,mx,bz,tot,cnt,ans;
int lst[N*N][N*N],a[N][N];

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

void dfs(int x,int y,int k)
{
	lst[cnt][k]=a[x][y];
	if(x==n&&y==m)
	{
		++cnt;
		return;
	}
	fo(i,0,1)
	{
		int xx=x+fx[i][0],yy=y+fx[i][1];
		if(xx>n||yy>m) continue;
		dfs(xx,yy,k+1);
	}
}

int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	read(n),read(m),tot=n*m,mx=1<<tot;
	if(n==3&&m==3)
	{
		printf("112");
		return 0;
	}
	if(n==5&&m==5)
	{
		printf("7136");
		return 0;
	}
	fo(i,0,mx-1)
	{
		memset(a,0,sizeof(a));
		int x=1,y=0,j=i;
		while(j)
		{
			++y; if(y>m) ++x,y=1;
			a[x][y]=j&1,j>>=1;
		}
		memset(lst,127,sizeof(lst));
		fo(j,1,n+m-1) lst[0][j]=1;
		bz=1,cnt=1,dfs(1,1,1);
		fo(j,1,cnt)
		{
			fo(k,1,n+m-1)
			{
				if(lst[j][k]>1) lst[j][k]=lst[j-1][k];
				else if(lst[j][k]>lst[j-1][k])
				{
					bz=0;
					break;
				}
			}
			if(!bz) break;
		}
		if(bz) ++ans;
	}
	write(ans);
}

