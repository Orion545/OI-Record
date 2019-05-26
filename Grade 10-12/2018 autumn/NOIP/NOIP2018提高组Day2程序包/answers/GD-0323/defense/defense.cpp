#include<cstdio>
#include<cstring>
using namespace std;
#define LL long long
int last[100010],next[200010],a[200010],len=0;
int w[100010],x,y,p,q;
LL f[100010][2];
char ss[4];
void add(int x,int y)
{
	a[++len]=y;
	next[len]=last[x];
	last[x]=len;
}
void dfs(int k,int fa)
{
	f[k][0]=0,f[k][1]=w[k];
	if(k==x) f[k][1-p]=-1;
	if(k==y) f[k][1-q]=-1;
	for(int i=last[k];i;i=next[i]) if(a[i]!=fa)
	{
		int l=a[i];
		dfs(l,k);
		if(f[k][0]!=-1)
		{
			if(f[l][1]==-1) f[k][0]=-1; else f[k][0]+=f[l][1];
		}
		if(f[k][1]!=-1)
		{
			if(f[l][1]==-1)
			{
				if(f[l][0]==-1) f[k][1]=-1; else f[k][1]+=f[l][0];
			}
			else
			{
				if(f[l][0]==-1) f[k][1]+=f[l][1]; else 
				{
					if(f[l][0]<f[l][1]) f[k][1]+=f[l][0]; else f[k][1]+=f[l][1];
				}
			}
		}
	}
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	int n,m,i,j;
	scanf("%d%d%s\n",&n,&m,ss);
	memset(last,0,sizeof(last));
	for(i=1;i<=n;i++) scanf("%d",&w[i]);
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	for(i=1;i<=m;i++)
	{
		scanf("%d%d%d%d",&x,&p,&y,&q);
		dfs(1,0);
		if((f[1][0]<f[1][1]&&f[1][0]!=-1)||f[1][1]==-1) printf("%lld\n",f[1][0]); else printf("%lld\n",f[1][1]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
