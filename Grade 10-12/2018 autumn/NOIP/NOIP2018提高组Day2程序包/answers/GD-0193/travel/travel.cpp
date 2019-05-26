#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>

using namespace std;

int n,m,U,V,cnt,bj;
int ans[10001],res[10001],b[10001],idx[5001];
vector<int> e[5001];
struct eg
{
	int u,v,id;
}p[10001];

bool cmp(eg a,eg b)
{
	return a.v<b.v;
}
int dfs(int u)
{
	res[++cnt]=u;idx[u]=1;
	if(res[cnt]>ans[cnt] && bj) return 0;
	else if(res[cnt]<ans[cnt]) bj=0;
	for(int i=0;i<e[u].size();i++)
	{
		int v=e[u][i];
		if(idx[v]) continue;
		if((v==V && u==U) || (u==V && v==U)) continue;
		if(!dfs(v)) return 0;
	}
	return 1;
}
void update()
{
	for(int i=1;i<=n;i++) ans[i]=res[i];
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<=m;i++) 
	{
		scanf("%d%d",&u,&v);
		p[2*i-1]=(eg){u,v,i};
		p[2*i]=(eg){v,u,i};
	}
	m<<=1;
	sort(p+1,p+m+1,cmp);
	for(int i=1;i<=m;i++)
		e[p[i].u].push_back(p[i].v);
	memset(ans,0x3f,sizeof(ans));
	if((m>>1)==n-1) 
	{
		bj=1;
		if(dfs(1) && cnt==n) update();
	}
	else
	for(int i=1;i<=m;i++)
	if(!b[p[i].id])
	{
		bj=1;cnt=0;b[p[i].id]=1;
		U=p[i].u,V=p[i].v;
		if(dfs(1) && cnt==n) update();
		memset(idx,0,sizeof(idx));
	}
	for(int i=1;i<=n;i++) printf("%d ",ans[i]);
	return 0;
}
