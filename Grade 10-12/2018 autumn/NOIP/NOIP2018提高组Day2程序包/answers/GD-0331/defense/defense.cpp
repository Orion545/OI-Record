#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<map>
#include<set>
#include<vector>
#include<bitset>
#define LL long long
#define mp(x,y) make_pair(x,y)
using namespace std;
inline int read()
{
	int f=1,x=0;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
inline void write(LL x)
{
	if(!x){putchar('0');return ;}
	if(x<0)putchar('-'),x=-x;
	int sta[20],top=0;
	while(x)sta[++top]=x%10,x/=10;
	while(top)putchar(sta[top--]+'0');
}
inline void pr1(int x){write(x);putchar(' ');}
inline void pr2(LL x){write(x);putchar('\n');}
struct node{int x,y,next;}a[211000];int len,last[111000];
void ins(int x,int y){len++;a[len].x=x;a[len].y=y;a[len].next=last[x];last[x]=len;}
int val[110000];
LL f[110000][2];char ss[15];
int n,m,A,B,u1,u2;
void dp(int x,int fa)
{
	f[x][0]=0;f[x][1]=val[x];
	if(x==u1)
	{
		if(A==0)f[x][1]=(1LL<<61);
		else f[x][0]=(1LL<<61);
	}
	if(x==u2)
	{
		if(B==0)f[x][1]=(1LL<<61);
		else f[x][0]=(1LL<<61);
	}
	for(int k=last[x];k;k=a[k].next)
	{
		int y=a[k].y;
		if(y!=fa)
		{
			dp(y,x);
			f[x][0]+=f[y][1];
			f[x][1]+=min(f[y][0],f[y][1]);
		}
	}
}
int dep[110000],fa[110000];
void pre_tree_node(int x)
{
	for(int k=last[x];k;k=a[k].next)
	{
		int y=a[k].y;
		if(y!=fa[x])
		{
			fa[y]=x;dep[y]=dep[x]+1;
			pre_tree_node(y);
		}
	}
}
LL g[110000][2];
LL lin[110000][2];
int r1[110000],ln;
int ok[110000],tim;
void work(int x,int opt)
{
	if(!x)return ;
	r1[++ln]=x;work(fa[x],opt);
	if(!opt)ok[x]=tim;
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	n=read();m=read();scanf("%s",ss+1);
	for(int i=1;i<=n;i++)val[i]=read();
	for(int i=1;i<n;i++)
	{
		int x=read(),y=read();
		ins(x,y);ins(y,x);
	}
	pre_tree_node(1);
	u1=u2=-1;dp(1,0);
	if(n<=2000&&m<=2000)
	{
		while(m--)
		{
			u1=read();A=read();u2=read();B=read();
			dp(1,0);
			if(f[1][0]>30000000000LL&&f[1][1]>30000000000LL)puts("-1");
			else pr2(min(f[1][0],f[1][1]));
		}
	}
	else
	{
		while(m--)
		{
			u1=read();A=read();u2=read();B=read();
			if(dep[u1]<dep[u2])swap(u1,u2),swap(A,B);
			tim++;ln=0;work(u1,0);
			for(int i=1;i<=ln;i++)g[i][0]=f[r1[i]][0],g[i][1]=f[r1[i]][1];
			for(int i=ln;i>=1;i--)
			{
				g[i][0]-=g[i-1][1];
				g[i][1]-=min(g[i-1][1],g[i-1][0]);
			}
			if(A==0)g[1][1]=(1LL<<61);
			else g[1][0]=(1LL<<61);
			for(int i=1;i<=ln;i++)
			{
				g[i][0]+=g[i-1][1];
				g[i][1]+=min(g[i-1][0],g[i-1][1]);
				lin[r1[i]][0]=g[i][0];
				lin[r1[i]][1]=g[i][1];
			}
			
			ln=0;work(u2,1);
			for(int i=1;i<=ln;i++)
			{
				if(ok[r1[i]]!=tim)g[i][0]=f[r1[i]][0],g[i][1]=f[r1[i]][1];
				else g[i][0]=lin[r1[i]][0],g[i][1]=lin[r1[i]][1];
			}
			for(int i=ln;i>=1;i--)
			{
				g[i][0]-=g[i-1][1];
				g[i][1]-=min(g[i-1][1],g[i-1][0]);
			}
			if(B==0)g[1][1]=(1LL<<61);
			else g[1][0]=(1LL<<61);
			for(int i=1;i<=ln;i++)
			{
				g[i][0]+=g[i-1][1];
				g[i][1]+=min(g[i-1][0],g[i-1][1]);
			}
			if(g[ln][0]>30000000000LL&&g[ln][1]>30000000000LL)puts("-1");
			else pr2(min(g[ln][0],g[ln][1]));
		}
	}
	return 0;
}

