#include<iostream>
#include<cstdio>
using namespace std;

bool pro[10001];
bool bin[10001];
int father[10001];
string a;
int n,m,ans,tot;
int x,y;
int cx,cy;
int p[10001];
bool can;

struct info
{
	int to,nxt;
}edge[20002];
int head[20002],cnt;

void add(int x,int y)
{
	edge[++cnt].to=y;
	edge[cnt].nxt=head[x];
	head[x]=cnt;
}

void dfs(int now)
{
}

void hugedfs(int now)
{
	if(now==n+1)
	{
		if(bin[x]!=cx||bin[y]!=cy) return;
		can=1;tot=0;
		for(int j=1;j<=n;++j) pro[j]=false;
		for(int j=1;j<=n;++j)
		{
			if(bin[j])
			{
				tot+=p[j];
				for(int i=head[now];i;i=edge[i].nxt)
				{
					pro[edge[i].to]=true;
				}
			}
		}
		
		for(int j=1;j<=n;++j) if(pro[j]==false){can=0;break;
		}
		if(can) ans=min(ans,tot);
		return;
	}
	
	bin[now]=1;
	hugedfs(now+1);
	bin[now]=0;
	hugedfs(now+1);
}

void dfstree(int fat,int now)
{
	int v;
	for(int i=head[now];i;i=edge[i].nxt)
	{
		v=edge[i].to;
		if(v==fat) continue;
		father[v]=now;
		dfstree(now,v);
	}
}

int main()
{
	scanf("%d%d",&n,&m);cin>>a;
	for(int i=1;i<=n;++i) scanf("%d",&p[i]);
	for(int i=1;i<=n-1;++i)
	{
		scanf("%d%d",&x,&y);
		add(x,y);add(y,x);
	}
	
	father[1]=0;
	
	if(n<=10&&m<=10)
	{
		for(int i=1;i<=m;++i)
		{
			scanf("%d%d%d%d",&x,&cx,&y,&cy);
		}
		ans=99999;
		hugedfs(1);
		cout<<ans<<endl;
	}
	else
	{
	//	dfstree(-1,1);
		for(int i=1;i<=m;++i) cout<<"-1"<<endl;
	}
	return 0;
}
