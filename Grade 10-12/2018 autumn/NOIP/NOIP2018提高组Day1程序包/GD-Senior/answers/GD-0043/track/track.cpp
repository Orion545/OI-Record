#include<bits/stdc++.h>
using namespace std;

int n,m,a,b,c[500001],flag;

/*void add(int u,int v,int w){
	edge[++cnt].to=v;
	edge[cnt].next=head[u];
	head[u]=cnt;
	edge[cnt].w=w;
}*/

/*void spfa(int x){
	dis[x]=0;
	vis[x]=1;
	q.push(x);
	while(!q.empty()){
		int u=q.front();
		for(int i=head[u];i;i=edge[i].next){
			int v=edge[i].to;
			if(vis[v]&&dis[u]+edge[i].w>dis[v]){
				vis[v]=1;
				dis[v]=dis[u]+edge[i].w;
				q.push(v);
			}
		}
	}
}*/

int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++){
		scanf("%d%d%d",&a,&b,&c[i]);
		if(a!=1) flag=1;
		//add(a,b,c[i]);
		//add(b,a,c[i]);
	}
	if(m==1&&!flag){
		sort(c+1,c+n+1);
		printf("%d",c[n]);
		return 0;
	}
	if(m==n-1){
		sort(c+1,c+n+1);
		printf("%d",c[1]);
		return 0;
	}
}
