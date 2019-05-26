#include<cstdio>
#include<cstring>
using namespace std;
int len=0,last[5010],next[10010],a[10010],c[5010][5010];
int p[5010],t[5010],l,ss[5010],ans[5010],x,y;
void add(int x,int y)
{
	a[++len]=y;
	next[len]=last[x];
	last[x]=len;
}
void dfs(int k,int fa)
{
	ss[++ss[0]]=k;
	int s=0;
	for(int i=last[k];i;i=next[i]) if(a[i]!=fa&&(x!=k||y!=a[i])&&(x!=a[i]||y!=k)) c[k][++s]=a[i];
	for(int i=1;i<s;i++)
		for(int j=i+1;j<=s;j++) if(c[k][i]>c[k][j]) c[k][0]=c[k][i],c[k][i]=c[k][j],c[k][j]=c[k][0];
	for(int i=1;i<=s;i++) dfs(c[k][i],k);
}
void dg(int k,int fa)
{
	for(int i=last[k];i;i=next[i]) if(a[i]!=fa)
	{
		t[++t[0]]=a[i];
		if(p[a[i]]) 
		{
			l=a[i];
			return;
		}
		p[a[i]]=1;
		dg(a[i],k);
		if(l>0) break;
	}
	if(l==0) t[0]--; else return;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n,m,i,j;
	scanf("%d%d",&n,&m);
	memset(last,0,sizeof(last));
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	if(m==n-1)
	{
		x=y=ss[0]=0;
		dfs(1,0);
		for(i=1;i<=n;i++) printf("%d ",ss[i]);
	}
	else
	{
		memset(p,0,sizeof(p));
		l=0;
		dg(1,0);
		ans[1]=n+1;
		memset(p,0,sizeof(p));
		for(i=t[0];i>0;i--) 
		{
			if(i!=t[0]&&t[i]==l) break;
			x=t[i],y=t[i-1];ss[0]=0;
			dfs(1,0);
			int bz=1;
			for(j=1;j<=n;j++) if(ss[j]>ans[j])
			{
				bz=0;
				break;
			}
			else if(ss[j]<ans[j]) break;
			if(bz) for(j;j<=n;j++) ans[j]=ss[j];
		}
		for(i=1;i<=n;i++) printf("%d ",ans[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
