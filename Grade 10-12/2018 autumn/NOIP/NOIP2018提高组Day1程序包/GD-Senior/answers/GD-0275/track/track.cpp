#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
//int read(){
//	int a = 0;
//	char ch = getchar();
//	while (ch <'0'||ch>'9')ch = getchar();
//	while (ch <= '9' && ch <= '0'){
//		a = (a<<1) + (a<<3) + ch - '0';
//		ch = getchar();
//	}
//	return a;
//}
queue<int>q;
int n ,tot, m,fir[50005],nex[100005],to[100005],wei[100005];
int dis[50005];
bool vis[50005];
void add(int x,int y,int w){
	to[++tot] = y;
	wei[tot] = w;
	nex[tot] = fir[x];
	fir[x] = tot;
}
void dfs(int s){
//	vis[s] = 1;
	for (int i = fir[s];i;i=nex[i]){
		int v = to[i];
		if (vis[v]) continue;
		vis[v] = 1;
		dfs(v);	
		dis[s] = max(dis[s],dis[v]+wei[i]);
		
	}
}
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	int x,y,w;
	for (int i = 1;i < n;++i){
		scanf("%d%d%d",&x,&y,&w);
		add(x,y,w);
		add(y,x,w);
	}
	if (m == 1){
		vis[1] = 1;
		dfs(1);
		int max1 = 0,max2 = 0;
		for (int i = fir[1];i;i = nex[i]){
			int v = to[i];
			if (dis[v] + wei[i] >= max1){ 
				max2 = max1;
				max1 = dis[v]+wei[i];
			}else if(dis[v] + wei[i] > max2){
				max2= dis[v] + wei[i];
			}
		}
		int ans = max1+max2;
		printf("%d\n",ans);
	}


	return 0;
}

