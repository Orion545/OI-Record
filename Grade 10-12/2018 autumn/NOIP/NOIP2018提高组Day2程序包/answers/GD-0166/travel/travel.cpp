#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cstring>
using namespace std;
struct wakk
{
	int d;
	int next;
}f[5005];
int n,k,m,x,y,la,mmi,mj,head[5005],dist[5005],fa[5005],a[5005];
bool p[5005];
int dfs(int t)
{
	int k,mi;
	k=head[t];
	mi=5001;
	while (k!=0)
	{
		if (p[f[k].d]==false&&f[k].d<mi) 
		{
			mi=f[k].d;
		}
		k=f[k].next;
	}
	return mi;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		k++;
		f[k].d=y;f[k].next=head[x];head[x]=k;
		a[x]++;
		k++;
		f[k].d=x;f[k].next=head[y];head[y]=k;
		a[y]++;
	}
	for (int i=1;i<=n;i++) dist[i]=5001;	
	p[1]=true;
	k=head[1];
	dist[1]=dfs(1);
	la=1;
	printf("%d ",1);
	for (int i=1;i<n;i++)
	{
		mmi=5001;
		for (int j=1;j<=n;j++)
		{
			if (dist[j]==5001) continue;
			if (p[dist[j]]==true) dist[j]=dfs(j);
			if (dist[j]<mmi)
			{
				mmi=dist[j];
				mj=j;
			} 
		}
		if (a[la]==1) 
		{
			mmi=dist[la];
		}
		p[mmi]=true;
		fa[mmi]=mj;
		a[mmi]--;
		a[mj]--;
		printf("%d ",mmi);
		dist[mmi]=dfs(mmi);
		k=mmi;
		while (dist[k]==5001) k=fa[k];
		la=k; 
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
