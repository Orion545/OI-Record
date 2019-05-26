#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
#include<stack>
#include<map>
#include<cstring>
#include<string>
#define ll long long int
#define INF 0x3f3f3f3f 
#define MAXN 1005
#define MAXN1 50005
#define MAXM 100010
using namespace std;

struct edge{
	int u,v,next;
}e[MAXM];

int dis[MAXN][MAXN];
int n,m;
int head[MAXN1];
int cnt=0;
int ans=0;
int tem[MAXN1];

inline void addedge(int u,int v){
	e[++cnt].v=v;
	e[cnt].next=head[u];
	head[u]=cnt;
}

int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(m==1&&n<=5){
		memset(dis,-1,sizeof(dis));
		int u,v,w;
		for(int i=1;i<n;i++){
			scanf("%d%d%d",&u,&v,&w);
			dis[u][v]=w;
			dis[v][u]=w;
			dis[i][i]=0;
		}
		dis[n][n]=0;
		for(int k=1;k<=n;k++)
		 for(int i=1;i<=n;i++)
		  for(int j=1;j<=n;j++){
		  	dis[i][j]=max(dis[i][k]+dis[k][j],dis[i][j]);
		  	ans=max(ans,dis[i][j]);
		  }
		printf("%d",ans);
		return 0;
	}
	if(n<=15){
		int u,v,w;
		int ok=1;
		for(int i=1;i<n;i++){
			scanf("%d%d%d",&u,&v,&w);
			if(u!=1)ok=0;
			tem[i]=w;
		}
		if(!ok){
			return 0;
		}
		else{
			sort(tem+1,tem+n);
			printf("%d",tem[n-m]);
			return 0;
		}
	}
	int u,v,w;
	int ok=1;
	for(int i=1;i<n;i++){
			scanf("%d%d%d",&u,&v,&w);
			if(u!=1)ok=0;
			//addedge(u,v,w);
			//addedge(v,u,w);
			tem[i]=w;
	}
	if(ok){
		sort(tem+1,tem+n);
		printf("%d",tem[n-m]);
		return 0;
	}
	else return 0;
}
