#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 5005
#define INF 0x3f3f3f3f
struct node
{
	int In,depth,idx;
	bool operator < (const node&t) const {return (In==t.In)?((depth==t.depth)?(idx<t.idx):(depth<t.depth)):(In<t.In);}
}p[N];
inline bool p_cmp(node a,node b){return (a.In==b.In)?((a.depth==b.depth)?(a.idx<b.idx):(a.depth<b.depth)):(a.In<b.In);}
priority_queue<node>Q;
struct edge
{
	int x,y;
}e[(N<<1)];
int n,m,st[N][2],ans[N];
bool vis[N];
inline bool cmp(const edge&a,const edge&b){return (a.x==b.x)?(a.y<b.y):(a.x<b.x);}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	memset(vis,0,sizeof(vis));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&e[i].x,&e[i].y);
		if(e[i].x==1) p[e[i].y].depth=2;
		else if(p[e[i].x].depth<p[e[i].y].depth)
		{
			p[e[i].y].depth=min(p[e[i].y].depth,p[e[i].x].depth+1);
			swap(e[i].x,e[i].y);
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(!vis[e[i].x])
		{
			printf("%d ",e[i].x);
			vis[e[i].x]=1;
		}
		if(!vis[e[i].y])
		{
			printf("%d ",e[i].y);
			vis[e[i].y]=1;
		}
	}
//	sort(e+1,e+1+m,cmp);
//	for(int i=1;i<=m;i++) printf("%d %d\n",e[i].x,e[i].y);
//	st[1][0]=1;
//	p[1].In=0,p[1].depth=1,p[1].idx=1;
//	for(int i=2;i<=n;i++) p[i].idx=i,p[i].In=0,p[i].depth=INF;
//	for(int i=1;i<=m;i++)
//	{
//		if(i>1&&e[i].x!=e[i-1].x) st[e[i].x][0]=i,st[e[i-1].x][1]=i-1;
//		p[e[i].y].depth=min(p[e[i].y].depth,p[e[i].x].depth+1);
//		p[e[i].y].In++;
//	}
//	st[e[m].x][1]=m;
//	for(int i=1;i<=n;i++) printf("%d %d\n",st[i][0],st[i][1]);
//	sort(p+1,p+1+n,p_cmp);
//	for(int i=1;i<=n;i++) printf("%d %d %d\n",p[i].idx,p[i].In,p[i].depth);
//	int a_cnt=0;
//	ans[a_cnt]=1;
//	Q.push(p[1]);
//	while(1)
//	{
//		node t=Q.top();
//		Q.pop();
//		ans[++a_cnt]=t.idx;
//		int i;
//		for(i=st[t.idx][0];i<=st[t.idx][1];i++)
//		{
//			p[e[i].y].In--;
//			for(int j=1;j<=n;j++) printf("%d %d\n",p[j].idx,p[j].In);
//			printf("\n");
//			if(p[e[i].y].In==0) Q.push(p[e[i].y]);
//		}
//		if(i==m) break;
//	}
//	for(int i=1;i<=n;i++) printf("%d ",ans[i]);
	fclose(stdin);fclose(stdout);
	return 0;
}
