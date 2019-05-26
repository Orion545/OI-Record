#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
struct node
{
	int x,y,next;
}a[11000];int len,last[5100];
void ins(int x,int y)
{
	len++;
	a[len].x=x;a[len].y=y;
	a[len].next=last[x];last[x]=len;
}
bool v[5100][5100];
int sta[5100],top;
void dfs(int x)
{
	v[x][0]=true;sta[++top]=x;
	for(int k=last[x];k;k=a[k].next)
	{
		int y=a[k].y;
		if(v[y][0]==false)dfs(y);
	}
}
int fa[5100];
bool f[11000],bk=false;
int ans[5100],st,ed;
void geth(int x)
{
	v[x][0]=true;
	for(int k=last[x];k;k=a[k].next)
	{
		int y=a[k].y;
		if(y!=fa[x]&&v[y][0]==false)
		{
			sta[++top]=k;
			fa[y]=x;
			geth(y);
			if(bk==true)return ;
			sta[top--]=0;
		}
		else if(y!=fa[x])
		{
			int tp=top;
			while(a[sta[tp]].x!=y)tp--;
			sta[++top]=k;
			st=tp;ed=top;
			bk=true;return ;
		}
	}
}
int num[5100],cnt;
void getnum(int x)
{
	v[x][0]=true;num[++cnt]=x;
	for(int k=last[x];k;k=a[k].next)
	{
		int y=a[k].y;
		if(v[y][0]==false&&f[k]==true)getnum(y);
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	len=0;memset(last,0,sizeof(last));
	memset(v,false,sizeof(v));
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		v[x][y]=v[y][x]=true;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=n;j>=1;j--)
		{
			if(v[i][j]==true)
			{
				ins(i,j);
			}
		}
	}
	if(m==n-1)
	{
		top=0;
		dfs(1);
		for(int i=1;i<=top;i++)printf("%d ",sta[i]);
		printf("\n");
	}
	else
	{
		memset(f,true,sizeof(f));
		top=0;
		geth(1);
		bool flag=false;
		for(int i=st;i<=ed;i++)
		{
			f[sta[i]]=false;
			memset(v,false,sizeof(v));
			cnt=0;getnum(1);
			flag=false;
			for(int j=1;j<=cnt;j++)
			{
				if(i==st||ans[j]>num[j])
				{
					flag=true;
					break;
				}
				if(ans[j]<num[j])break;
			}
			if(flag==true)
			{
				for(int j=1;j<=cnt;j++)ans[j]=num[j];
			}
			f[sta[i]]=true;
		}
		for(int i=1;i<=n;i++)printf("%d ",ans[i]);
		printf("\n");
	}
	return 0;
}
