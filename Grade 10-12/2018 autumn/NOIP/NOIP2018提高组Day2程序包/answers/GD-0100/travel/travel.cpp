#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
vector<int> vec[5010];
int n,m,b[5010],top=0;
struct node{
	int y,next;
}a[10010];int len=0,last[5010];
void ins(int x,int y)
{
	a[++len].y=y;
	a[len].next=last[x];last[x]=len;
}
void dfs_1(int x,int fa)
{
	printf("%d ",x);
	top=0;
	for(int i=last[x];i;i=a[i].next)
	{
		int y=a[i].y;
		//printf("%d->%d\n",x,y);
		if(y==fa) continue;
		b[++top]=y;
	}
	sort(b+1,b+top+1);
	for(int i=1;i<=top;i++) vec[x].push_back(b[i]);
	for(int i=0;i<vec[x].size();i++) dfs_1(vec[x][i],x);
}
int sta[5010],t=0,l=1;
bool vis[5010],c[5010];
bool flag=false;
void pre(int x,int fa)
{
	top=0;vis[x]=true;sta[++t]=x;
	for(int i=last[x];i;i=a[i].next)
	{
		int y=a[i].y;
		if(y==fa) continue;
		if(vis[y])
		{
			while(sta[l]!=y) l++;
			flag=true;return;
		}
		b[++top]=y;
	}
	sort(b+1,b+top+1);
	for(int i=1;i<=top;i++) vec[x].push_back(b[i]);
	for(int i=0;i<vec[x].size();i++)
	{
		pre(vec[x][i],x);
		if(flag) return;
	}
	t--;
}
int Fa[5010];
void dfs_2(int x,int fa,int op)
{
	Fa[x]=fa;
	if(!vis[x]) printf("%d ",x);
	top=0;vis[x]=true;
	for(int i=last[x];i;i=a[i].next)
	{
		int y=a[i].y;
		//printf("%d->%d\n",x,y);
		if(y==fa||vis[y]) continue;
		b[++top]=y;
	}
	if(top==0) return;
	sort(b+1,b+top+1);
	//printf("%d:",x);
	vec[x].clear();
	for(int i=1;i<=top;i++) vec[x].push_back(b[i]);//printf("%d ",b[i]);printf("\n");
	for(int i=0;i<vec[x].size();i++)
	{
		int y=vec[x][i];
		//printf("%d->%d\n",x,y);
		if(!c[x]) dfs_2(y,x,-1);
		if(x==sta[l])
		{
			if(c[y]) dfs_2(y,x,sta[t]);
			else dfs_2(y,x,-1);
		}
		else
		{
			if(!c[y]) dfs_2(y,x,-1);
			else if(c[y]&&op!=-1&&!flag&&y>op&&i==vec[x].size()-1)
			{
				flag=true;
				//dfs_2(op,sta[l],-1);
				return;
			}
			else
			{
				if(i==vec[x].size()-1) dfs_2(y,x,op);
				else dfs_2(y,x,vec[x][i+1]);
			}
		}
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int x,y;scanf("%d %d",&x,&y);
		ins(x,y);ins(y,x);
	}
	if(m==n-1)
	{
		dfs_1(1,0);//puts("");
		return 0;
	}
	else
	{
		memset(vis,false,sizeof(vis));
		pre(1,0);//system("puase");
		memset(c,false,sizeof(c));
		memset(vis,false,sizeof(vis));
		//for(int i=l;i<=t;i++) printf("%d ",sta[i]);printf("\n");
		flag=false;
		for(int i=l;i<=t;i++) c[sta[i]]=true;
		dfs_2(1,0,-1);
	}
}
