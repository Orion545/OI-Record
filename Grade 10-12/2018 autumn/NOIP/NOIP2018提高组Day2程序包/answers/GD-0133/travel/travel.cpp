#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int lst[5005],nxt[20005],e[20005],cnt;
bool b[5005];
int s[5005],w;
struct edge{
	int x,y;
}a[20005];
bool cmp(const edge &a,const edge &b)
{
	return (a.x<b.x)||((a.x==b.x)&&(a.y>b.y));
}
void build(int x,int y)
{
	e[++cnt]=y;
	nxt[cnt]=lst[x];
	lst[x]=cnt;
}
int n,m;
void dfs(int x,int fa)
{
	printf("%d ",x);
	for(int u=lst[x];u;u=nxt[u])
	{
		int y=e[u];
		if(y==fa) continue;
		dfs(y,x);
	}
}
bool ok=false;
int cir[5005],tot=0;
int c[5005],cng=0;
void dfscir(int x,int fa)
{
	b[x]=true;
	s[++w]=x;
	for(int u=lst[x];u;u=nxt[u])
	{
		int y=e[u];
		if(y==fa) continue;
		if(b[y])
		{
			cir[++tot]=y;
			while(s[w+1]!=y)
			{
				cir[++tot]=s[w];
				w--;
			}
			ok=true;
			return;
		}
		dfscir(y,x);
		if(ok) return;
	}
	w--;
	b[x]=false;
}
bool sml=false;
void dfscut(int tpy,int x,int fa)
{
	++cng;
	if(tpy==1) c[cng]=x;
	else
	{
		if(ok) c[cng]=x;
		if(!ok&&x<c[cng]) c[cng]=x,ok=true;
		if(!ok&&x>c[cng]) 
		{
			sml=true;
			return;
		}
	}
	for(int u=lst[x];u;u=nxt[u])
	{
		int y=e[u];
		if(y==fa) continue;
		if((y==cir[tpy]&&x==cir[tpy+1])||(x==cir[tpy]&&y==cir[tpy+1])) continue;
		dfscut(tpy,y,x);
		if(sml) return;
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d%d",&a[i*2].x,&a[i*2].y);
		a[i*2+1].x=a[i*2].y;
		a[i*2+1].y=a[i*2].x;
	}
	sort(a,a+2*m,cmp);
	for(int i=0;i<2*m;i++)
		build(a[i].x,a[i].y);
	if(m==n-1)
	{
		dfs(1,0);
		printf("\n");
		return 0;
	}
	ok=false;
	dfscir(1,0);
	for(int i=1;i<tot;i++)
	{
		cng=0;
		ok=false;
		sml=false;
		dfscut(i,1,0);
	}
	for(int i=1;i<=n;i++)
		printf("%d ",c[i]);
	printf("\n");
	return 0;
}
