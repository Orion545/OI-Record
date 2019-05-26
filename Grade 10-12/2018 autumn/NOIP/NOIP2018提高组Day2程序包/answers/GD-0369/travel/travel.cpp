#include<bits/stdc++.h>
#define sz 6666
using namespace std;
int n,m;
struct hh{int t,nxt;}edge[sz<<1];
int head[sz],ecnt;
void make_edge(int f,int t)
{
	edge[++ecnt]=(hh){t,head[f]};
	head[f]=ecnt;
	edge[++ecnt]=(hh){f,head[t]};
	head[t]=ecnt;
}
#define go(x) for (int i=head[x];i;i=edge[i].nxt)
#define v edge[i].t
int ans[sz],cnt;
void dfs_tree(int x,int fa)
{
	vector<int>ans;
	::ans[++cnt]=x;
	go(x) if (v!=fa) ans.push_back(v);
	sort(ans.begin(),ans.end());
	for (int i=0;i<ans.size();i++) dfs_tree(ans[i],x);
}
bool vis[sz];
void dfs_circle(int x,bool back,int st)
{
	vis[x]=1;ans[++cnt]=x;
	int y=-1;
	go(x) if (!vis[v]) {y=v;break;}
	if (y==-1) return;
	if (!back) return dfs_circle(y,0,0);
	if (y<st) return dfs_circle(y,1,st);
	dfs_circle(st,0,0);
}
int main()
{
//	freopen("a.txt","r",stdin);//freopen("out.txt","w",stdout);
	freopen("travel.in","r",stdin);freopen("travel.out","w",stdout);
	int i,j,k,x,y,z;
	scanf("%d %d",&n,&m);
	for (i=1;i<=m;i++) 
		scanf("%d %d",&x,&y),make_edge(x,y);
	if (m==n-1)
	{
		dfs_tree(1,0);
		for (i=1;i<=n;i++) printf("%d ",ans[i]);
		return 0;
	}
	y=z=0;
	go(1) 
		if (!y) y=v;
		else z=v;
	ans[cnt=1]=1;vis[1]=1;
	if (y<z) dfs_circle(y,1,z);
	else dfs_circle(z,1,y);
	for (i=1;i<=n;i++) printf("%d ",ans[i]);
	return 0;
}
