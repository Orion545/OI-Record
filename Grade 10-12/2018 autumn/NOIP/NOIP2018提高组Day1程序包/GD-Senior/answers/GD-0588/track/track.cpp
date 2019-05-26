#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <map>
#define ll long long
const int N=1e5+50;
using namespace std;
int n,m;
int x,y,z;
int ans;
int tot=0;
int dis[N];
int head[N];
bool vis[N];
int cnt[N];
struct node
{
	int to,nxt,cost;
}edge[N<<1];
struct dist
{
	int h,id;
	bool operator<(const dist&a)const{
	return h>a.h;}
};
void add(int x,int y,int z)
{
	edge[++tot].to=y; 
	edge[tot].cost=z;
	edge[tot].nxt=head[x];
	head[x]=tot;
}
priority_queue<dist>q;
void Dijkstra(int s)
{
	memset(vis,false,sizeof(vis));
	memset(dis,127,sizeof(dis));
	dist p;
	dis[s]=0;
	p.h=0,p.id=s;
	q.push(p);
	while (!q.empty()){
	  p=q.top(); q.pop();
	  int x_=p.id;
	  if (!vis[x_]&&(cnt[x_]>1||x_==s)){
	  	vis[x_]=true;
	  	for (int i=head[x_];i;i=edge[i].nxt){
	  	  int y_=edge[i].to,z_=edge[i].cost;
	  	  if (dis[y_]>dis[x_]+z_) {
	  	  	dis[y_]=dis[x_]+z_; 
	  	  	p.id=y_; p.h=dis[y_];
	  	  	q.push(p);
	  	  }
	  	}
	  }
	}
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<n;i++){
	  scanf("%d%d%d",&x,&y,&z);
	  add(x,y,-z); add(y,x,-z);
	  cnt[x]++; cnt[y]++;
	}
	ans=-23333333;
	for (int i=1;i<=n;i++){
	  Dijkstra(i);
	  for (int j=1;j<=n;j++)
	    if (i!=j) ans=max(ans,-dis[j]);
	}
	printf("%d",ans);
	fclose(stdin); fclose(stdout);
	return 0;
}
