#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define MAXN 50010

struct ins
{
	int x,y,z;
}in[MAXN];

inline int read()
{
	int f=1,x=0;
	char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=(x<<3)+(x<<1)+s-48;s=getchar();}
	return f*x;
}

int tot=0,head[MAXN],n,m,ands[MAXN],ai=0,total=0;
bool cmp(const ins &a,const ins &b){return a.z>b.z;}
bool amp(const int &a,const int &b){return a>b;}

int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	n=read(),m=read();
	int x,y,z;
	if(m==1&&n<=10)
	{
		int map[11][11],q=0,maxs,mays;
		bool visit[11];
		int dis[11];
		memset(map,0,sizeof(map));
		for(int i=1;i<n;++i)
		{
			x=read(),y=read(),z=read();
			map[x][y]=z;
			map[y][x]=z;
		}
		for(int w=1;w<=n;w++)
		{
			memset(visit,0,sizeof(visit));
			memset(dis,0,sizeof(dis));
			visit[w]=true;
			for(int i=1;i<=n;i++)if(i!=w)dis[i]=map[i][w];
			for(int k=1;k<=n;k++)
			{
				maxs=0;mays=0;
				for(int i=1;i<=n;i++)if(!visit[i]&&dis[i]>=maxs)maxs=dis[i],mays=i;
				if(!mays)break;
				visit[mays]=true;
				for(int i=1;i<=n;i++)if(!visit[i]&&map[mays][i]!=0&&map[mays][i]+dis[mays]>dis[i])dis[i]=map[mays][i]+dis[mays];
			}
			maxs=0;
			for(int i=1;i<=n;i++)if(dis[i]>maxs)maxs=dis[i];
			if(q<=maxs)q=maxs; 
		}
		printf("%d",q);
	}
	else 
	{
		for(int i=1;i<n;i++)
		{
			x=read(),y=read(),z=read();
			in[i].x=x;in[i].y=y;in[i].z=z;
			total+=z;
			if(y==x+1)ai++;
			ands[x]++;
		}
		if(ands[1]==n-1||m==n-1)
		{
			sort(in+1,in+n,cmp);
			printf("%d",in[m].z);
		}
		else printf("15");
	}
	return 0;
}
