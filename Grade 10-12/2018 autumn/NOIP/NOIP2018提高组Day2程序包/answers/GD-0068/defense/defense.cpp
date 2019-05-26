#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>

#define LL long long 

using namespace std;

const LL maxn=(LL )1<<60;
int n,m,k,tot,root,p[100010],h[100010];
int x1,y,a,b;
int q[100010],tail;
int fa[100010];
int r1,r2;
int remind[100010],treest[100010],dep[100010];
LL f[100010][2];
LL g[100010][2]; 
char c;

struct edge{
	int to,next;
}x[200010];

inline int read()
{
	int x=0;char c=getchar();
	while ((c<'0')||(c>'9'))
		c=getchar();
	while ((c>='0')&&(c<='9'))
		x=(x<<3)+(x<<1)+c-'0',c=getchar();
	return x;
}

void calc();
void add(int ,int );
void getroot(int ,int );
void dfs(int ,int );
int abs(int );
void swap(int &,int &);

int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	n=read();m=read();
	scanf("%c%d",&c,&k);
	for (int i=1;i<=n;i++)
		p[i]=read();
	for (int i=1;i<n;i++)
	{
		r1=read();r2=read();
		add(r1,r2);add(r2,r1);
	}
	switch (c)
	{
		case 'A':
			root=-1;
			calc();
			break;
		case 'B':
			root=1;
			dfs(root,0);
			break;
		case 'C':
			root=0;treest[0]=n;
			getroot(1+rand()%n,0);
			dfs(root,0);
			break;
	}
	for (int i=1;i<=m;i++)
	{
		a=read();x1=read();b=read();y=read();
		switch (root)
		{
			case -1:
				{
					memset(g,0,sizeof(g));
					if (x==0&&y==0&&(abs(a-b)==1)&&(a==n||b==n||a==1||b==1))
					{
						printf("-1\n");
						goto out;
					}
					if (a>b)
						swap(a,b),swap(x1,y);
					g[a][(x1+1)%2]=maxn;
					g[a][x1]=f[a][x1];
					for (int i=a+1;i<=n;i++)
						if (i!=b)
							g[i][0]=g[i-1][1],g[i][1]=min(g[i-1][1],g[i-1][0])+p[i];
						else
						{
							if (y==1)
								g[i][0]=maxn,g[i][1]=min(g[i-1][1],g[i-1][0])+p[i];
							else
								g[i][1]=maxn,g[i][0]=g[i-1][1];
						}
					LL ans=min(g[n][0],g[n][1]);
					if (ans>=maxn)
						printf("-1\n");
					else
						printf("%lld\n",ans);
					goto out;
				}
			default :
				{
					memset(g,0,sizeof(g));
					if (dep[a]<dep[b])
						swap(a,b),swap(x1,y);
					g[a][(x1+1)%2]=maxn;
					g[b][(y+1)%2]=maxn;
					int i,j;
					for (i=fa[a];dep[i]>=dep[b];i=fa[i])
					{
						if (g[i][1]==0)
							g[i][1]=p[i];
						for (int jump=h[i];jump;jump=x[jump].next)
							if (x[jump].to!=fa[i])
							{
								if (g[x[jump].to][1]==0)
									g[x[jump].to][1]=f[x[jump].to][1];
								if (g[x[jump].to][0]==0)
									g[x[jump].to][0]=f[x[jump].to][0];
								if (g[i][0]<maxn)
									g[i][0]+=g[x[jump].to][1];
								if (g[i][1]<maxn)
									g[i][1]+=min(g[x[jump].to][0],g[x[jump].to][1]);
							}
					}
					for (j=fa[b];j;i=fa[i],j=fa[j])
					{
						if (i!=j)
						{
							if (g[i][1]==0)
								g[i][1]=p[i];
							for (int jump=h[i];jump;jump=x[jump].next)
								if (x[jump].to!=fa[i])
								{
									if (g[x[jump].to][1]==0)
										g[x[jump].to][1]=f[x[jump].to][1];
									if (g[x[jump].to][0]==0)
										g[x[jump].to][0]=f[x[jump].to][0];
									if (g[i][0]<maxn)
										g[i][0]+=g[x[jump].to][1];
									if (g[i][1]<maxn)
										g[i][1]+=min(g[x[jump].to][0],g[x[jump].to][1]);
								}
							if (g[j][1]==0)
								g[j][1]=p[j];
							for (int jump=h[j];jump;jump=x[jump].next)
								if (x[jump].to!=fa[j])
								{
									if (g[x[jump].to][1]==0)
										g[x[jump].to][1]=f[x[jump].to][1];
									if (g[x[jump].to][0]==0)
										g[x[jump].to][0]=f[x[jump].to][0];
									if (g[j][0]<maxn)
										g[j][0]+=g[x[jump].to][1];
									if (g[j][1]<maxn)
										g[j][1]+=min(g[x[jump].to][0],g[x[jump].to][1]);
								}
						}
						else
						{
							if (g[i][1]==0)
								g[i][1]=p[i];
							for (int jump=h[i];jump;jump=x[jump].next)
								if (x[jump].to!=fa[i])
								{
									if (g[x[jump].to][1]==0)
										g[x[jump].to][1]=f[x[jump].to][1];
									if (g[x[jump].to][0]==0)
										g[x[jump].to][0]=f[x[jump].to][0];
									g[i][0]+=g[x[jump].to][1],g[i][1]+=min(g[x[jump].to][0],g[x[jump].to][1]);
								}
							if (i==root)
								break;
						}
					}
					LL ans=min(g[root][0],g[root][1]);
					if (ans>=maxn)
						printf("-1\n");
					else
						printf("%lld\n",ans);
					goto out;
				}
		}
		out :
			;
	}
	
	return 0;
}

void calc()
{
	for (int i=1;i<=n;i++)
		f[i][0]=f[i-1][1],f[i][1]=min(f[i-1][1],f[i-1][0])+p[i];
	return ;
}

void dfs(int now,int father)
{
	fa[now]=father;dep[now]=dep[father]+1;
	f[now][1]=p[now];
	for (int jump=h[now];jump;jump=x[jump].next)
		if (x[jump].to!=father)
		{
			dfs(x[jump].to,now);
			f[now][0]+=f[x[jump].to][1];
			f[now][1]+=min(f[x[jump].to][1],f[x[jump].to][0]);
		}
	return ;
}

void getroot(int now,int father)
{
	remind[now]=1;
	for (int jump=h[now];jump;jump=x[jump].next)
		if (x[jump].to!=father)
		{
			getroot(x[jump].to,now);
			treest[now]=max(treest[now],remind[x[jump].to]);
			remind[now]+=remind[x[jump].to];
		}
	treest[now]=max(treest[now],n-remind[now]);
	if (treest[now]<treest[root])
		root=now;
	return ;
}

void add(int u,int v)
{
	x[++tot]=(edge){v,h[u]};h[u]=tot;
	return ;
}

int abs(int x)
{
	return (x>=0)?x:-x;
}

void swap(int &s1,int &s2)
{
	int f;
	f=s1;s1=s2;s2=f;
	return ;
}
