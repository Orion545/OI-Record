#include<bits/stdc++.h>
#define ct(x) nx[x].ct 
#define st(x) sort(nx[x].s+1,nx[x].s+1+ct(x))
using namespace std;
int n,m,x,y,u[5050],line[5050],cnt,ct,h[5050],flag[5050],f[5050];
struct node
{
	int s,n;
}nx[10050];
struct nw
{
	int x,y;
}gt[5050];
bool cmp(nw x,nw y)
{
	if(x.x==y.x)return x.y>y.y;
	return x.x>y.x;
}
void add(int x,int v)
{
	u[x]++;
	nx[++ct].s=v;
	nx[ct].n=h[x];
	h[x]=ct;
}
void dfs(int x,int y)
{
	line[++cnt]=x;
	int tmp=9999;
	for(int i=h[x];i;i=nx[i].n)
		if(!flag[nx[i].s]&&u[nx[i].s]==1)
		{
			line[++cnt]=nx[i].s;
			flag[nx[i].s]=1;
		}
	for(int i=h[x];i;i=nx[i].n)
	{
		if(!flag[nx[i].s]&&nx[i].s<y)
		{
			f[nx[i].s]=x;
			flag[nx[i].s]=1;
			for(int j=nx[i].n;j;j=nx[i].n)
				if(!flag[nx[j].s])
				{
					tmp=min(y,nx[j].s);
					break;
				}
			dfs(nx[i].s,tmp);
		}
		if(nx[i].s==f[x])continue;
		if(!flag[nx[i].s]&&nx[i].s>y){u[nx[i].s]--;return;}
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%d%d",&gt[i].x,&gt[i].y);
	sort(gt+1,gt+m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		add(gt[i].x,gt[i].y);
		add(gt[i].y,gt[i].x);
	}
	flag[1]=1;
	dfs(1,9999);
	for(int i=1;i<=cnt;i++)printf("%d ",line[i]);
}

