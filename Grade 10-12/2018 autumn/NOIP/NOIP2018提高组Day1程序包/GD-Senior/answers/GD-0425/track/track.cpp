#include<cstdio>
int n,m,i,j,k,x,y,z,ans,up[50005],back[50005],nxt[100005],last[50005],st[100005],en[100005],len[100005];
void build(int x,int y,int z)
{
	k++,st[k]=x,en[k]=y,len[k]=z,nxt[k]=last[x],last[x]=k;
}
void go(int x,int fa)
{
	for (int i=last[x];i;i=nxt[i])
	if (en[i]!=fa)
	{
		go(en[i],x);
		if (up[x]<up[en[i]]+len[i])
		{
			if (back[x]<up[x])
			back[x]=up[x];
			up[x]=up[en[i]]+len[i];
		}
		else
		if (back[x]<up[en[i]]+len[i])
		back[x]=up[en[i]]+len[i];
	}
	if (up[x]+back[x]>ans)
	ans=up[x]+back[x];
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (i=1;i<n;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		build(x,y,z);
		build(y,x,z);
	}
	go(1,0);
	printf("%d\n",ans);
	return 0;
}

