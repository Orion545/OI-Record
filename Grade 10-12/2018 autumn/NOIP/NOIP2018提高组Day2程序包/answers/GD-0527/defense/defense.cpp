#include<bits/stdc++.h>
#define N 200001
using namespace std;
int son[N],f[N][2],a[N],next[N],last[N],tov[N],fa[N],tot,o,p,x,y,i,j,k,n,m,head,tail,b,bz[N],dl[N];
char ch;
void lian(int x,int y){tot++,tov[tot]=y,next[tot]=last[x],last[x]=tot;}
void dfs(int x)
{
	if(son[x]==0)
	{
		f[x][0]=0,f[x][1]=a[x];
		return;
	}
	int i,j,k,l;
	j=k=l=0;
	for(i=last[x];i;i=next[i])
	{
		if(tov[i]==fa[x])continue;
		dfs(tov[i]);
		if(f[tov[i]][1]==2147483647/5)l=1;
		j+=f[tov[i]][1];
		k+=min(f[tov[i]][1],f[tov[i]][0]);
	}
	f[x][0]=j;f[x][1]=k+a[x];
	if(l==1)f[x][0]=2147483647/5;
	if(x==o)f[x][1-b]=2147483647/5;
	if(x==p)f[x][1-y]=2147483647/5;
}
int main()
{
	freopen("defense.in","r",stdin);freopen("defense.out","w",stdout);
	scanf("%d%d",&n,&m);
	ch=getchar(),ch=getchar(),ch=getchar();
	for(i=1;i<=n;i++)scanf("%d",&a[i]);
	for(i=1;i<=n-1;i++)scanf("%d%d",&x,&y),lian(x,y),lian(y,x);
	head=0,tail=1,dl[tail]=1,bz[1]=1;
	while(head<tail)
	{
		head++;
		x=dl[head];
		for(i=last[x];i;i=next[i])
		{
			if(bz[tov[i]]==1)continue;
			fa[tov[i]]=x,son[x]++;
			tail++,dl[tail]=tov[i],bz[tov[i]]=1;
		}
	}
	for(i=1;i<=m;i++)
	{
		scanf("%d%d%d%d",&o,&b,&p,&y);
		if(fa[p]==o||fa[o]==p)
		{
			printf("-1\n");
			continue;
		}
		dfs(1);
		printf("%d\n",min(f[1][0],f[1][1]));
	}
}
