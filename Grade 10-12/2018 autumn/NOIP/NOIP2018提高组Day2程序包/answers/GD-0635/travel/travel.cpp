#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
typedef long long ll;
inline int read()
{
	int x=0,f=1; char ch=getchar();
	while(ch<'0' || ch>'9'){if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0'; ch=getchar();}
	return x*f;
}
inline ll lread()
{
	ll x=0,f=1; char ch=getchar();
	while(ch<'0' || ch>'9'){if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0'; ch=getchar();}
	return x*f;	
}
const int N=5010;
const int M=5010;
const int INF=0x3f3f3f3f;
struct edge
{
	int x,y,next;
}a[M*2]; int len,last[N];
void ins(int x,int y)
{
	a[++len].x=x;a[len].y=y;
	a[len].next=last[x];last[x]=len;
}/*
int len2,last2[N];
void ins2(int x,int y)
{
	b[++len2].x=x;b[len2].y=y;
	b[len2].next=last2[x];last2[x]=len2;		
}*/
int n,m;
vector<int> dcc[N];
int cnt;
int low[N],dfn[N],id;
int sta[N],top;
void tarjan(int x,int fa)
{
	dfn[x]=low[x]=++id; sta[++top]=x;
	for(int k=last[x];k;k=a[k].next)
	{
		int y=a[k].y;
		if(y==fa) continue;
		if(!dfn[y])
		{
			tarjan(y,x);
			low[x]=min(low[x],low[y]);
			if(dfn[x]<low[y])
			{
				int i;
				cnt++;
				do{
					i=sta[top--];
					dcc[cnt].push_back(i);
				}while(i!=y);
			}
		}
		else low[x]=min(low[x],dfn[y]);
	}
}
int nowx,nowy;
int ans2[N][N],ans[N],tot;
bool vis[N];
int mn[N][N];
bool check(int x,int y)
{
	if(x==nowx && y==nowy) return false;
	else if(x==nowy && y==nowx) return false;
	return true;	
}
void dfs2(int x,int fa)
{
	vis[x]=true;  ans[++tot]=x;
//	if(x==73) printf("%d\n",fa);
	int deg=0;
	for(int k=last[x];k;k=a[k].next)
	{
		int y=a[k].y;
		if(vis[y]) continue;
		mn[x][++deg]=y;
	}
	sort(mn[x]+1,mn[x]+deg+1);
	for(int i=1;i<=deg;i++)
	{
		int y=mn[x][i];
		dfs2(y,x);
	}
}
void dfs(int now,int x,int fa)
{
	vis[x]=true;  ans2[now][++tot]=x;
//	if(x==73) printf("%d\n",fa);
	int deg=0;
	for(int k=last[x];k;k=a[k].next)
	{
		int y=a[k].y;
		if(vis[y] || !check(x,y)) continue;
		mn[x][++deg]=y;
	}
	sort(mn[x]+1,mn[x]+deg+1);
	for(int i=1;i<=deg;i++)
	{
		int y=mn[x][i];
		dfs(now,y,x);
	}
}
struct qq{int x,y;}e[M];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	n=read(),m=read();
	len=1; memset(last,0,sizeof(last));
	if(m==n)
	{
		for(int i=1;i<=m;i++)
		{
			e[i].x=read(),e[i].y=read();
			ins(e[i].x,e[i].y);
			ins(e[i].y,e[i].x);	
		}
		ins(0,1); ins(1,0);
		cnt=0;
		tarjan(0,-1);
		/*printf("%d\n\n",cnt);
		for(int i=1;i<=cnt;i++)
		{
			for(int j=0;j<dcc[i].size();j++)
				printf("%d\n",dcc[i][j]);
				
			puts("");
		}*//*
		len2=1; memset(last2,0,sizeof(last2)); 
		for(int i=1;i<=m;i++)
		{
			ins2(e[i].x,e[i].y);
			ins2(e[i].y,e[i].x);		
		}*/
		for(int i=1;i<=cnt;i++)
		{
			int size=dcc[i].size();
			if(size>1)
			{
				int now=0;
				for(int j=0;j<size-1;j++)
				{
					nowx=dcc[i][j],nowy=dcc[i][j+1];
					memset(vis,false,sizeof(vis)); vis[0]=true;
					memset(mn,0,sizeof(mn));
					now++; tot=0; dfs(now,1,0);
//					printf("%d %d\n",nowx,nowy);
				}
				nowx=dcc[i][size-1],nowy=dcc[i][0];
				memset(vis,false,sizeof(vis)); vis[0]=true;
				memset(mn,0,sizeof(mn));
				now++; tot=0; dfs(now,1,0);
//				printf("%d %d\n",nowx,nowy);
				
				memset(vis,false,sizeof(vis));
				for(int i=1;i<=now;i++)
				{
					bool flag=true;
					for(int j=1;j<=n;j++)
					{
//						printf("%d ",ans2[i][j]);
						for(int k=1;k<=now;k++)
						{
							if(vis[k]) continue;
							if(k==i) continue;
							if(ans2[k][j]>ans2[i][j])
							{
								vis[k]=true;
							}
							if(ans2[k][j]<ans2[i][j])
							{
								vis[i]=true;
								flag=false;
								break;
							}
						}
						if(!flag) break;
					}
					if(vis[i]) continue;
					flag=true;
					for(int k=1;k<=now;k++)
						if(k!=i)
							if(vis[k]==false)
							{
								flag=false;
								break;
							}
					if(flag)
						for(int j=1;j<=n;j++)
							printf("%d ",ans2[i][j]);
					break;
				}
				break;		
			}
		}
			
	}
	else if(m==n-1)
	{
		for(int i=1;i<=m;i++)
		{
			int x=read(),y=read();
			ins(x,y);
			ins(y,x);	
		}
		memset(vis,false,sizeof(vis)); tot=0;
		memset(mn,0,sizeof(mn));
		dfs2(1,0); 
		for(int i=1;i<=tot;i++) printf("%d ",ans[i]);	
	}
}
