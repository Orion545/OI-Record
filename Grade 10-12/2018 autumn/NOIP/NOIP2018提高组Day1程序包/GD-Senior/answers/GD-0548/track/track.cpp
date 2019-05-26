#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=50010;
const int maxm=50010;
int head[maxn],cnt=0;
int fa[maxn];
int n,m,x,y,p,maxp=9999999;
int f[2000][2000];
	
struct node{
	int to;
	int next;
	int w;
}edge[maxm];

void add(int a,int b,int w)
{
    edge[++cnt].next=head[a];
	edge[cnt].to=b;
	edge[cnt].w=w;
	head[a]=cnt;
}


int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	memset(head,0,sizeof(head));
    memset(f,0x3f,sizeof(f));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
	}
	for(int i=1;i<=n-1;i++)
	{
		scanf("%d%d%d",&x,&y,&p);
		add(x,y,p);
		add(y,x,p);
		f[x][y]=f[y][x]=p;
	}
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	for(int k=1;k<=n;k++)
	{
		if(i!=k&&i!=j&&k!=j)
		{
			f[j][k]=min(f[j][k],f[j][i]+f[i][k]);
			if(f[j][k]<maxp)
			maxp=f[j][k];
		}
	}	
	printf("%d",maxp);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
