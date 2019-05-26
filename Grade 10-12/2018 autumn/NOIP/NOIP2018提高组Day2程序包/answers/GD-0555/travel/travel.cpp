#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int last[5010],nxt[10010],to[10010];
int b[5010];
int ans[5010];
int du[5010];
int tot;
int bz;
int n,m;
void insert(int x,int y)
{
	tot++;
	nxt[tot]=last[x];
	last[x]=tot;
	to[tot]=y;
}
int jin1=0; int jin2=0;
void dfs(int x,int fa)
{
	b[++b[0]]=x;	
	if (b[b[0]]<ans[b[0]]) bz=-1;
	if (bz==0 && b[b[0]]>ans[b[0]]) 
	{
		bz=1;
		return;
	}
	if (bz==1) return;
	int len=0;
	int a[du[x]+10];
	for (int i=last[x];i!=0;i=nxt[i])
		if (to[i]!=fa && !(x==jin1 && to[i]==jin2) && !(x==jin2 && to[i]==jin1)) a[++len]=to[i];
	sort(a+1,a+len+1);
	for (int i=1;i<=len;i++) dfs(a[i],x);
}
int cc[10010];
int qi;
int lenc=0;
bool pd=false;
int tf[5010];
void dfs2(int x,int fa)
{
	if (pd) return;
	for (int i=last[x];i!=0;i=nxt[i])
		if (to[i]!=fa)
		{
			if (tf[to[i]])
			{
				qi=tf[to[i]];
				pd=true;
				return;
			} else
			{
				cc[++lenc]=to[i];
				tf[to[i]]=lenc;
				dfs2(to[i],x);
				if (pd) return;
				tf[to[i]]=0;
				lenc--;
			}		
		}
	if (pd) return;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	int x,y;
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		insert(x,y);
		insert(y,x);
		du[x]++;
		du[y]++;
	}	
	memset(ans,50,sizeof(ans));
	if (m==n-1)
	{
		b[0]=0;
		bz=0;
		dfs(1,0);
		for (int i=1;i<=n;i++) printf("%d ",b[i]);
		return 0;
	} else
	{
		lenc=1;
		cc[lenc]=1;
		tf[1]=1;
		dfs2(1,0);
		for (int i=qi;i<=lenc;i++)
		{
			jin1=cc[i];
			if (i==qi) jin2=cc[lenc]; else jin2=cc[i-1];
			b[0]=0;
			bz=0;
			dfs(1,0);
			if (bz==-1)
			{
				for (int j=1;j<=n;j++)
					if (ans[j]<b[j]) 
					{
						bz=1;
						break;
					} else
					if (b[j]<ans[j]) break;
			}
			if (bz==-1)
				for (int j=1;j<=n;j++) ans[j]=b[j];
		}
		for (int i=1;i<=n;i++)
			printf("%d ",ans[i]);
	}
	return 0;
}
