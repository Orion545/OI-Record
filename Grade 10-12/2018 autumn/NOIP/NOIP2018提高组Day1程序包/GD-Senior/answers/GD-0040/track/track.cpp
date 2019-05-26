#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
bool p1=true,p2=true;
struct node{
	int to,next,val;
}edge[50005*2];
int cnt,head[50005],vis[50005],dis[50005],n,m,x,y,z,ans,ru[50005],minn;
queue <int> q;
inline void add(int x,int y,int z){
	edge[++cnt].to=y;
	edge[cnt].next=head[x];
	edge[cnt].val=z;
	head[x]=cnt;
}
inline void dfs(int now,int pre,int tot,int cntt){
	if (cntt==m) {
		ans=min(ans,tot);
		return;	
	}
	for (int i=head[now];i;i=edge[i].next){
		int to=edge[i].to;
		if (to==pre) continue;
		//printf("%d\n",to);
		dfs(to,x,tot+edge[i].val,cntt);
		dfs(to,x,tot,cntt+1);
	}
}
inline void spfa(int x){
	q.push(x);
	vis[x]=1;
	dis[x]=0;
	while (!q.empty()){
		int now=q.front();
		q.pop();
		for (int i=head[now];i;i=edge[i].next){
			int to=edge[i].to;
			if (dis[to]>dis[now]+edge[i].val){
				dis[to]=dis[now]+edge[i].val;
				if (!vis[to]){
					vis[to]=1;
					q.push(to);
				}
			}
		}
	}
}
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<n;++i){
		scanf("%d%d%d",&x,&y,&z);
		minn=max(minn,z);
		ru[y]++;
		add(x,y,z);
		add(y,x,z);
		if (x!=1) p1=false;
		if (y!=x+1) p2=false;
	}
	//printf("%d %d",p1,p2);
	if (m==1) {
		for (int i=1;i<=n;++i){
			memset(dis,127,sizeof(dis));
			memset(vis,0,sizeof(vis));
			spfa(i);
			for (int j=1;j<=n;++j) ans=max(ans,dis[j]);
		}
		printf("%d\n",ans);
	}else if (p1){
		ans=999999999;
		for (int i=head[1];i;i=edge[i].next){
			int to=edge[i].to;
			dis[to]=edge[i].val;
		}
		sort(dis+1,dis+n);
		int k=n,cn=0;
		for (int i=1;i<=n;++i){
			cn++;
			ans=min(ans,dis[k]+dis[i]);
			if (cn==m) break;
		}
		printf("%d\n",ans);
	}else if (p2){
		printf("%d\n",minn);
	}
	return 0;
}
