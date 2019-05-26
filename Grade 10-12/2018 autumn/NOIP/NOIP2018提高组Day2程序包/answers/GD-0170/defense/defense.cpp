#include<bits/stdc++.h>
#define M 100005
#define inf 100000000
using namespace std;
void read(int &x)
{
	x=0;
	char ch=getchar();
	while (!isdigit(ch))
	{
		ch=getchar();
	}
	while (isdigit(ch))
	{
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
}
void out(int x)
{
	if (x>9)
		out(x/10);
	putchar(x%10+'0');
}

struct node
{
	int u,v,nxt;
}a[M*2];
int n,m;
int w[M];
int first[M];
int top;
bool vis[M],army[M];
string s;
int ans,tot;
void addedge(int u,int v)
{
	++top;
	a[top].u=u;
	a[top].v=v;
	a[top].nxt=first[u];
	first[u]=top;
}
bool neighbor(int x,int y)
{
	for (int i=first[x];i;i=a[i].nxt)
		if (a[i].v==y)
			return 1;
	return 0;
}
void cal(int x)
{
	if (!vis[x])
	{
		vis[x]=1;
		tot--;
	}
	for (int i=first[x];i;i=a[i].nxt)
	{
		if (!vis[a[i].v])
		{
			tot--;
			vis[a[i].v]=1;
		}
	}
}

void dfs(int le,int now)
{
	if (!le)
	{
		ans=min(ans,now);
		return;
	}
	for (int i=1;i<=n;i++)
	{
		if (!army[i])
		{
			int c[25];
			int res=le;
			int num=0;
			army[i]=1;
			if (!vis[i])
			{
				vis[i]=1;
				c[++num]=i;
				--res;
			}
			for (int j=first[i];j;j=a[j].nxt)
			{
				if (!vis[a[j].v])
				{
					--res;
					vis[a[i].v]=1;
					c[++num]=a[i].v;
				}
			}
			dfs(res,now+w[i]);
			army[i]=0;
			for (int j=1;j<=num;j++)
				vis[c[j]]=0;
		}
	}
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	cin>>n>>m;
	getline(cin,s);
	for (int i=1;i<=n;i++)
	{
		read(w[i]);
	}
	for (int i=1;i<=n-1;i++)
	{
		int u,v;
		read(u),read(v);
		addedge(u,v);
		addedge(v,u);
	}
	while (m--)
	{
		for (int i=1;i<=n;i++)
		{
			vis[i]=0;
			army[i]=0;
		}
		int x,wx,y,wy;
		read(x),read(wx),read(y),read(wy);
		if (neighbor(x,y)&&!wx&&!wy)//xºÍyÏàÁÚ 
		{
			printf("-1\n");
			continue;
		}
		tot=n;
		ans=inf;
		int now=0;
		army[x]=1,army[y]=1;
		if (wx)
		{
		  	cal(x);
		   	now+=w[x];
		}
  		if (wy)
  		{
		  	cal(y);
		  	now+=w[y];
		}
  		dfs(tot,now);
  		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

