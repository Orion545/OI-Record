#include<cstdio>
#include<cstring>
int a[100010];
long long f[100010][2];
int tot;
int ding1,ding2,t1,t2;
int last[100010],nxt[200010],to[200010];
char type[10];
void insert(int x,int y)
{
	tot++;
	nxt[tot]=last[x];
	last[x]=tot;
	to[tot]=y;
}
void dfs(int x,int fa)
{
	f[x][1]=a[x];
	f[x][0]=0;
	if (ding1==x) f[x][t1^1]=-1;
	if (ding2==x) f[x][t2^1]=-1;
	for (int i=last[x];i!=0;i=nxt[i])
		if (to[i]!=fa)
		{
			dfs(to[i],x);
			if (f[x][1]!=-1)
			{
				if (f[to[i]][0]==-1 && f[to[i]][1]==-1) f[x][1]=-1; else
				{
					long long minf=100000000000000LL;
					if (f[to[i]][0]!=-1) minf=f[to[i]][0]; 
					if (f[to[i]][1]!=-1 && f[to[i]][1]<minf) f[x][1]+=f[to[i]][1]; else f[x][1]+=minf;
				}
			} 
			if (f[x][0]!=-1)
			{
				if (f[to[i]][1]!=-1) f[x][0]+=f[to[i]][1]; else f[x][0]=-1;
			}
		}
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	scanf("%s",type+1);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	int x,y;
	for (int i=1;i<=n-1;i++)
	{
		scanf("%d%d",&x,&y);
		insert(x,y);
		insert(y,x);
	}
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d%d%d",&x,&t1,&y,&t2);
		if (t1==0 && t2==0)
		{
			bool bz=false;
			for (int j=last[x];j!=0;j=nxt[j]) 
				if (to[j]==y)
				{
					bz=true;
					break;
				}
			if (bz)
			{
				printf("-1\n");
				continue;	
			}
		}
		ding1=x; ding2=y;
		memset(f,0,sizeof(f));
		dfs(1,0);
		if (f[1][0]==-1) printf("%lld\n",f[1][1]); else
		if (f[1][1]==-1) printf("%lld\n",f[1][0]); else
		{
			if (f[1][0]<f[1][1]) printf("%lld\n",f[1][0]); else printf("%lld\n",f[1][1]);
		}
	}
	return 0;
}
