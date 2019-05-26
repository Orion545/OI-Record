#include<iostream>
#include<cstdio>
using namespace std;
const int N=100005;
struct node
{
	int next;
	int to;
}edge[N*2+5];
int head[N],tot;
int check[N];
int rd[N];
void add(int u,int v)
{
	tot++;
	edge[tot].to=v;
	edge[tot].next=head[u];
	head[u]=tot;
}
int n,m;
string c;
int cost[N];
void init()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	cin>>n>>m>>c;
	for(int i=1;i<=n;i++) cin>>cost[i];
	for(int i=1;i<=(n-1);i++)
	{
		int x,y;cin>>x>>y;
		add(x,y);add(y,x);
		rd[x]++;rd[y]++;
	}
} 
bool pd=0;
int ans=0;
void work(int x,int cnt)
{
	if(cnt==n) return;
	for(int i=head[x];i;i=edge[i].next)
	{
		int v=edge[i].to;
		if(check[v]==2&&check[x]==2) pd=1;
		else if(check[x]==1&&check[v]==0) check[v]=0;
		else if(check[v]==2&&check[x]==0)
		{
			check[x]=1;
			ans+=cost[x];
		}
		else if(check[x]==0||check[x]==2) 
		{
			check[v]=1;
			ans+=cost[v];
		}
		else if(check[x]==1&&check[v]==1)
		{
			ans+=cost[v];
		}
		work(v,++cnt);
		return;
	}
}
int main()
{
	init();
	while(m--)
	{
		int k=0;
		memset(check,0,sizeof(check));
		ans=0;pd=0;
		int a,x,b,y;
		cin>>a>>x>>b>>y;
		if(x==0) 
		{
			check[a]=2;
		}
		else check[a]=1;
		if(y==0)
		{
			check[b]=2;
		}
		else check[b]=1;
		for(int i=1;i<=n;i++)
		{
			if(rd[i]==1) k=i;
		}
		work(k,1);
		if(pd==1) cout<<-1<<endl;
	    else cout<<ans<<endl;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
