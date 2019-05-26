#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int maxn=5010;
const int maxm=10010;
struct data{
	int next,to,seg;
};
data g[maxm];
int head[maxm],vis[maxn],record[maxn],ans[maxn];
int t=0,n,cnt=1;
void add(int from,int to)
{
	++t;
	g[t].next=head[from];
	g[t].to=to;
	g[t].seg=0;
	head[from]=t;
	return;
}
bool compare()
{
	for (int i=1;i<=n;++i)
	if (record[i]<ans[i]) return true;
	else if (record[i]>ans[i]) return false;
	return false;
}
void exc()
{
	for (int i=1;i<=n;++i) ans[i]=record[i];
	return;
}
void dfs(int root)
{
	if (cnt==n)
	if (compare()) 
	{
		exc();
		return;
	}
	for (int i=head[root];i;i=g[i].next)
	{
		int j=g[i].to;
		bool v=0;
		if (g[i].seg) continue;
		if (!vis[j]) ++cnt,record[cnt]=j,vis[j]=1,v=1;
		++g[i].seg;
		dfs(j);
		--g[i].seg;
		if (v) --cnt,vis[j]=0;
	} 
	return;
}
int main()
{
	int m,x,y;
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	memset(head,0,sizeof(head));
	memset(vis,0,sizeof(vis));
	memset(record,0,sizeof(record));
	memset(ans,21/3,sizeof(ans));
	cin>>n>>m;
	for (int i=1;i<=m;++i)
	{
		cin>>x>>y;
		add(x,y); add(y,x);
	}
	record[1]=1; vis[1]=1;
	dfs(1);
	for (int i=1;i<=n;++i) cout<<ans[i]<<" ";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
