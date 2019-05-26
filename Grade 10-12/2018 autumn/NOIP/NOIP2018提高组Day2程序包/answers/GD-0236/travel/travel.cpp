#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int n,m,e[5005][5005],path[5005],cnt,f,q[100000],cur,ans[5005];
bool vis[5005],v1[5005];
void dfs(int now)
{
	path[++cnt]=now;
	vis[now]=true;
	for (int i=1;i<=n;i++)
	if (e[now][i] && !vis[i]) dfs(i);
}
void zh(int now,int fa)
{
	q[++cur]=now;
	if (v1[now])
	{
		if (!f) f=now;
		return ;
	}
	v1[now]=true;
	for (int i=1;i<=n;i++)
	if (e[now][i] && i!=fa) zh(i,now);
}
bool pd()
{
	int x=1;
	while (path[x]==ans[x]) x++;
	if (x>n) return false;
	if (path[x]<ans[x]) return true;
	return false;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>m;
	memset(vis,false,sizeof(vis));
	memset(v1,false,sizeof(v1));
	for (int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		e[u][v]=e[v][u]=1;
	}
	if (m==n-1)
	{
		dfs(1);
		for (int i=1;i<=n;i++) printf("%d ",path[i]);
		return 0;
	}else{
	
	for (int i=1;i<=n;i++) ans[i]=2000000;
	zh(1,0);
	for (int i=1;i<=cur;i++)
	 if (q[i]==f)
	 {
	 	int j;
	 	for (j=i+1;q[j]!=f;j++) 
	 	{//cout<<q[j-1]<<' '<<q[j]<<endl;
	 		cnt=0;
	 		memset(vis,false,sizeof(vis));
	 		e[q[j-1]][q[j]]=0;
	 		dfs(1);
	 		e[q[j-1]][q[j]]=1;
			if (pd()) for (int i=1;i<=n;i++) ans[i]=path[i];
			//for (int i=1;i<=n;i++) printf("%d ",ans[i]);cout<<endl;
	 	} 		
	 	cnt=0;
		memset(vis,false,sizeof(vis));
	 	e[q[j-1]][f]=0;
	 	dfs(1);
	 	e[q[j-1]][f]=1;
		if (pd()) for (int i=1;i<=n;i++) ans[i]=path[i];
		break;
	 }
	for (int i=1;i<=n;i++) printf("%d ",ans[i]);
	return 0;}
}
