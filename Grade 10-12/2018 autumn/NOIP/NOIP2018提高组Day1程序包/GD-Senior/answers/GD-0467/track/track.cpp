#include<cstdio>
#include<iostream>
using namespace std;
int t,n,m,ans,x,y,z;
int head[10000];
int dis[1000][1000];

inline int read()
{
	int s=0;
	char ch=getchar();
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch>='0'&&ch<='9') {s=s*10+ch-48;ch=getchar();}
	return s;
}

int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	n=read(),m=read();
	for (int i=1;i<n;i++)
	{
		x=read(),y=read(),z=read();
		dis[x][y]=dis[y][x]=z;	
	}
	for (int k=1;k<=n;k++)
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
				if (dis[i][j]&&dis[i][k]&&dis[k][j])
					if (dis[i][j]<dis[i][k]+dis[k][j])
						dis[i][j]=dis[i][k]+dis[k][j];			
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			if (dis[i][j]>ans)
				ans=dis[i][j];
	printf("%d",ans);
	return 0;
}
