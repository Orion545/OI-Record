#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<memory.h>
#define MAXN 10
#define INF 0x3f3f3f3f
using namespace std;
int n,m,maxans=-INF,vis[MAXN],Map[MAXN][MAXN];
void bfs(int s) {
	queue<int> q;
	q.push(s);
	while(!q.empty()) {
		int top=q.front();
		q.pop();
		for(int i=1;i<=n;i++) {
			if(Map[top][i]!=INF&&!vis[i]) {
				Map[s][i]=min(Map[s][i],Map[s][top]+Map[top][i]);
				maxans=max(maxans,Map[s][i]);
				q.push(i);
				vis[i]=1;
			}
		}
	}
}
int main() {
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	int x,y,len;
	memset(Map,0x3f,sizeof(Map));
	for(int i=1;i<=n;i++) {
		scanf("%d%d",&x,&y,&len);
		Map[x][y]=Map[y][x]=len;
	}
	if(m==1) {
		bfs(1);
		printf("%d",maxans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
