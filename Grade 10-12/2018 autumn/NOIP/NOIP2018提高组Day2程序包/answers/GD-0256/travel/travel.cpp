#include<cstdio>
using namespace std;
const int N=5010;
int head[N],next[N*2][2],tot=0;
int circle[N];
int s[N],cnt=1;
bool vis[N];
int n,m;
int flag=0;
int min=100000000;
int fa;
void connect(int,int);
int search(int,int);
void dfs(int,int);
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		connect(u,v);
	}
	if(m==n)
	{
		vis[1]=1;
		search(1,0);
		vis[1]=0;
	}
	vis[1]=1;
	s[1]=1;
	dfs(1,0);
	vis[1]=0;
	for(int i=1;i<=cnt;i++)
		if(i==1) printf("%d",s[i]);
		else printf(" %d",s[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
void dfs(int x,int father)
{
	if(flag==0&&circle[x]==1)
	{
		flag=1;
		int mm=10000;
		for(int p=head[x];p;p=next[p][0])
		{
			int temp=next[p][1];
			if(temp==father||vis[temp]==1) continue;
			if(temp<mm) mm=temp;
		}
		vis[mm]=1;
		for(int p=head[x];p;p=next[p][0])
		{
			int temp=next[p][1];
			if(temp==father||vis[temp]==1) continue;
			if(temp<min) min=temp;
		}
		fa=x;
		while(1)
		{
			s[++cnt]=mm;
			vis[mm]=1;
			dfs(mm,x);
			mm=10000;
			int you=0;
			for(int p=head[x];p;p=next[p][0])
			{
				int temp=next[p][1];
				if(temp==father||vis[temp]==1) continue;
				you=1;
				if(temp<mm) mm=temp;
			}
			if(you==0) return;
		}
	}
	else if(flag==1&&circle[x]==1)
	{
		while(1)
		{
			int sum=0;
			int mm=10000,mmi=10000;
			int you=0;
			for(int p=head[x];p;p=next[p][0])
			{
				int temp=next[p][1];
				if(temp==father||vis[temp]||temp==min) continue;
				you=1;
				if(circle[temp]==0)
				{
					sum=1;
					if(temp<mmi) mmi=temp;
				}
				if(temp<mm) mm=temp;
			}
			if(you==0) return;
			if(sum==0&&flag==1)
			{
				if(mm>min)
				{
					flag=2;
					dfs(fa,fa);
				}
				else
				{
					s[++cnt]=mm;
					vis[mm]=1;
					dfs(mm,x);
				}
			}
			else
			{
				if(mm==mmi)
				{
					s[++cnt]=mm;
					vis[mm]=1;
					dfs(mm,x);
				}
				else
				{
					flag=2;
					s[++cnt]=mm;
					vis[mm]=1;
					dfs(mm,x);
				}
			}
		}
	}
	else
	{
		while(1)
		{
			int mm=10000;
			int you=0;
			for(int p=head[x];p;p=next[p][0])
			{
				int temp=next[p][1];
				if(temp==father||vis[temp]==1) continue;
				if(temp<mm) mm=temp,you=1;
			}
			if(you==0) return;
			s[++cnt]=mm;
			vis[mm]=1;
			dfs(mm,x);
		}
	}
}
int search(int x,int father)
{
	for(int p=head[x];p;p=next[p][0])
	{
		int temp=next[p][1];
		if(temp==father) continue;
		if(vis[temp]==1)
		{
			circle[temp]=2;
			circle[x]=1;
			return 1;
		}
		vis[temp]=1;
		int kind=search(temp,x);
		vis[temp]=0;
		if(kind==1)
		{
			if(circle[x]==2)
			{
				circle[x]=1;
				return 2;
			}
			else
			{
				circle[x]=1;
				return 1;
			}
		}
		else if(kind==2)
		{
			return 2;
		}
	}
}
void connect(int u,int v)
{
	next[++tot][0]=head[u];
	head[u]=tot;
	next[tot][1]=v;
	next[++tot][0]=head[v];
	head[v]=tot;
	next[tot][1]=u;
}
