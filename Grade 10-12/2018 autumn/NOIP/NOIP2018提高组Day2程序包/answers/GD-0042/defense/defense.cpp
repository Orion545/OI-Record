#include<cstdio>
#include<cstring>
#define min(a,b) ((a<b)?a:b)
using namespace std;
int i,n,m,x1,y1,x2,y2,z;
int f[2010][2],g[2010];
int tov[4000],pre[4000],las[2010];
char s[10];
int Link(int a,int b)
{
	++z;
	tov[z]=b,pre[z]=las[a],las[a]=z;
	return 0;
}
int dfs(int p,int q)
{
	f[p][0]=0,f[p][1]=g[p];
	for(int i=las[p];i;i=pre[i])
		if(tov[i]^q)
		{
			dfs(tov[i],p);
			f[p][0]+=f[tov[i]][1];
			f[p][1]+=min(f[tov[i]][0],f[tov[i]][1]);
		}
	f[x1][1-y1]=2e9+10;
	f[x2][1-y2]=2e9+10;
	return 0;
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",s);
	for(i=1;i<=n;++i) scanf("%d",&g[i]);	
	for(i=1;i<n;++i)
	{
		scanf("%d%d",&x1,&y1);
		Link(x1,y1),Link(y1,x1);
	}
	for(;m;--m)
	{
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		dfs(1,0);
		x1=min(f[1][0],f[1][1]);
		if(x1>2e9) printf("-1\n");
			else printf("%d\n",x1);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
