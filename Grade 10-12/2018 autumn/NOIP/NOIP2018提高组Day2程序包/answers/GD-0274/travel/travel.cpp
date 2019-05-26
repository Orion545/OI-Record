#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define maxn 5010
struct edge{
	int u,v,del,pos;
	bool operator<(const edge &x)const{
		if(u==x.u)
			return v<x.v;
		return u<x.u;
	}
}edges[maxn<<1];
int pos[maxn<<1];
int vis[maxn],ordo[maxn],tp;
int n,m,head[maxn];
bool finished=false;
void dfs(int x){
	if(finished) return;
	if(tp==n){
		printf("%d",ordo[1]);
		for(int i=2;i<=n;i++)
			printf(" %d",ordo[i]);
		finished=true;
		return;
	}
	for(int i=head[x];i<head[x+1];i++){
		if(edges[pos[i]].del==0){
			int y=edges[pos[i]].v;
			if(vis[y]==0){
				vis[y]=1;
				ordo[++tp]=y;
				dfs(y);
			}
		}
	}
}
bool cmp(const int &i,const int &j){
	return edges[i]<edges[j];
}
int ans[maxn];
void dfs2(int x){
	if(finished) return;
	if(tp==n){
		/*printf("%d",ordo[1]);
		for(int i=2;i<=n;i++)
			printf(" %d",ordo[i]);
		printf("\n");*/
		if(ans[1]==0) for(int i=1;i<=n;i++)
			ans[i]=ordo[i];
		else{
			bool tf=false;
			for(int i=1;i<=n;i++){
				if(ans[i]<ordo[i]){
					break;
				}else if(ans[i]>ordo[i]){
					tf=true;
					break;
				}
			}
			if(tf){
				for(int i=1;i<=n;i++)
					ans[i]=ordo[i];
			}
		}
		finished=true;
		return;
	}
	for(int i=head[x];i<head[x+1];i++){
		if(edges[pos[i]].del==0){
			int y=edges[pos[i]].v;
			if(vis[y]==0){
				vis[y]=1;
				ordo[++tp]=y;
				dfs2(y);
			}
		}
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m*2;i++)
		pos[i]=i;
	for(int i=1;i<=m;i++){
		scanf("%d%d",&edges[i].u,&edges[i].v);
		edges[i+m].u=edges[i].v;
		edges[i+m].v=edges[i].u;
		edges[i].pos=i;
		edges[i+m].pos=i+m;
	}
	sort(pos+1,pos+1+m+m,cmp);
	for(int i=1;i<=2*m;i++)
		if(head[edges[pos[i]].u]==0)
			head[edges[pos[i]].u]=i;
	for(int i=1;i<=2*m;i++)
		edges[pos[i]].pos=i;
/*	for(int i=1;i<=2*m;i++)
		printf("%d %d %d\n",edges[i].u,edges[i].v,edges[i].pos);
	for(int i=1;i<=2*m;i++)
		printf("%d ",pos[i]);*/
	head[n+1]=2*m+1;
	if(m==n-1){
		tp=0;
		ordo[++tp]=1;
		vis[1]=1;
		dfs(1);
	}else{
		for(int i=1;i<=m*2;i++){
			if(pos[edges[i].pos]<=m){
				finished=false;
				memset(vis,0,sizeof vis);
				edges[i].del=edges[pos[edges[i].pos]+m].del=1;
				tp=0;
				ordo[++tp]=1;
				vis[1]=1;
				dfs2(1);
				edges[i].del=edges[pos[edges[i].pos]+m].del=0;
			}
		}
		printf("%d",ans[1]);
		for(int i=2;i<=n;i++)
			printf(" %d",ans[i]);
	}
	return 0;
}
/*
6 6
1 3
2 3
2 5
3 4
4 5
4 6
*/
/*
6 5
1 3
2 3
2 5
3 4
4 6
*/
