#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<cmath>
using namespace std;
const int N=5005;
int n,m;
int map[N][N];
int rd[N],ans[N],tmp[N];
void work(int x,int cnt)
{
	if(cnt==n)
	{
		bool pd=0;
		for(int i=1;i<=n;i++)
		{
			if(ans[i]>tmp[i])
			{
				pd=1;break;
			}
		}
		if(pd)
		{
			for(int i=1;i<=n;i++) ans[i]=tmp[i];
		}
		return;
	}
	if(tmp[cnt-1]>ans[cnt-1]) return;
	for(int v=1;v<=n;v++)
	{
		if(map[x][v]&&map[v][x])
		{
			map[x][v]=0;
			cnt++;
			tmp[cnt]=v;
			work(v,cnt);
			map[x][v]=1;
			tmp[cnt]=0;
			cnt--;
		}
		if(v==-1&&map[x][v]==0&&map[v][x]==1||map[x][v]==1&&map[v][x]==0)
		{
			if(map[v][x]==1) map[v][x]==0;
			else if(map[x][v]==1) map[x][v]==0;
			work(v,cnt);
			if(map[v][x]==0) map[v][x]==1;
			else if(map[x][v]==0) map[x][v]==1;
		}
	}
}
void init()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int x,y;cin>>x>>y;
		map[x][y]=1;
		map[y][x]=1;
		rd[x]++;
		rd[y]++;
	}
	memset(ans,0x3f,sizeof(ans));
}
int main()
{
	init();
	for(int i=1;i<=n;i++)
	{
		if(rd[i]==1)
		{
			tmp[1]=i;
			work(i,1);
			break;
		}
	}
	for(int i=1;i<=n;i++) cout<<ans[i]<<' ';
	fclose(stdin);fclose(stdout);
	return 0; 
}
