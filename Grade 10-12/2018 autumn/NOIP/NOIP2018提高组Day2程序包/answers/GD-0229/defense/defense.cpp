#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdlib>
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9')x=x*10+ch-'0',ch=getchar();
	return x*f;
}
inline void write(int x)
{
	if(x<0)putchar('-');
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
struct node
{
	int x,y,nex;
}a[200010];int len,last[100010];
inline void ins(int x,int y)
{
	len++;
	a[len].x=x;a[len].y=y;
	a[len].nex=last[x];last[x]=len;
}
char ss[5];
int w[100010];
long long f[100010][2];
inline long long mymin(long long dx,long long dy)
{
	if(dx>dy)swap(dx,dy);
	if(dx==-1)return dy;
	else return dx;
}
inline void dfs(int x,int fa)
{
	if(f[x][1]!=-1)f[x][1]=w[x];
	for(int k=last[x];k;k=a[k].nex)
	{
		int y=a[k].y;
		if(y==fa)continue;
		dfs(y,x);
		if(f[x][0]!=-1)
		{
		 	if(f[y][1]!=-1)f[x][0]+=f[y][1];
		 	else f[x][0]=-1;
		}
		if(f[x][1]!=-1)
		{
			long long mn=mymin(f[y][0],f[y][1]);
			if(mn==-1)f[x][1]=-1;
			else f[x][1]+=mn;
		}
	}
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	int n=read(),m=read();scanf("%s",ss+1);
	for(int i=1;i<=n;i++)w[i]=read();
	for(int i=1;i<n;i++)
	{
		int x=read(),y=read();
		ins(x,y),ins(y,x);
	}
	if(n<=2000)
	{
		for(int i=1;i<=m;i++)
		{
			memset(f,0,sizeof(f));
			int x=read(),idx=read(),y=read(),idy=read();
			f[x][idx^1]=f[y][idy^1]=-1;
			dfs(1,0);
			printf("%lld\n",mymin(f[1][0],f[1][1]));
		}
	}
	else
	{
	}
	return 0;
}
