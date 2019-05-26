#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define N 2100
using namespace std;
int ma[N][N],bj[N],n,m,cost[N],f[N][3],u[N];
int head[N<<1],to[N<<1],next[N<<1],tot;
int a,b;
char p[20];
void cc(int x,int y)
{
	next[++tot]=head[x];to[tot]=y;head[x]=tot;
}
int dfs(int x,int t)
{
	if(x==a+1||x==b+1||x==n+1)return 0;
	if(head[x]==0){
	u[x]=1;
	if(t==0)return 0;
	else return f[x][1]=cost[x];
	}
	if(u[x])return f[x][t];
	u[x]=1;
	for(int i=head[x];i;i=next[i])
	{
		int v=to[i];
		f[x][0]+=dfs(v,1);
		f[x][1]+=min(dfs(v,0),dfs(v,1))+cost[x];
	}
	return f[x][t];
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d%s",&n,&m,p);
	int x,y;
	for(int i=1;i<=n;i++)scanf("%d",&cost[i]);
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);cc(x,y);
		ma[x][y]=ma[y][x]=1;
	}
	while(m--)
	{
		scanf("%d%d%d%d",&a,&x,&b,&y);
		if(x==0&&y==0&&ma[a][b]==1){
			printf("-1\n");
			continue;
		}
		if(x==1)bj[a]=1;
		if(x==0)bj[a]=2;
		if(y==1)bj[b]=1;
		if(y==0)bj[b]=2;
		if(a>b)swap(a,b);
		memset(f,0,sizeof(f));

		if(y==x==1)
		{
			int sum=0;sum+=min(dfs(1,0),dfs(1,1))+min(dfs(a+1,0),dfs(a+1,1))+min(dfs(b+1,0),dfs(b+1,1))+cost[a]+cost[b];
			printf("%d\n",sum);
		} 
		else
		printf("%d\n",min(dfs(1,0),dfs(1,1)));//先假设1为根
		bj[a]=0;bj[b]=0;
	}
	return 0;
}
