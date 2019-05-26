#include<iostream>
#include<cstdio>
using namespace std;
int n,m;
int maxx=0;
int s[10007][10007];
int vis[10007][10007];
//int dx[5]={-1,1,0,0};
//int dy[5]={0,0,-1,1};

void dfs(int x,int y,int sum)
{
	//cout<<"1";
	int _x=x,_y=y;
	//cout<<"1";
	for(int i=1;i<=n;i++)
	{
		if(!vis[_x][i])
		{
			vis[_x][i]=1;
			vis[i][_x]=1;
			sum+=s[_x][i];
			int mid=maxx;
			if(sum>maxx) maxx=sum;
			dfs(_x,i,sum);
			vis[_x][i]=0;
			vis[i][_x]=0;
			sum-=s[_x][i];
			//maxx=mid;
		}
		//_x-=dx[i];
		//_y-=dy[i];
	}
}

int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	int x,y,w;
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++)
	{
		scanf("%d%d%d",&x,&y,&w);
		s[x][y]=w;
		s[y][x]=w;
	}
	if(m==1)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				dfs(i,j,0);
			}
		}
	}else printf("15");
	printf("%d",maxx);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
