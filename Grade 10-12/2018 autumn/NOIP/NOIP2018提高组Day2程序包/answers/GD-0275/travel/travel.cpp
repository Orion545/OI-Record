#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
queue<int>q;
int n,m,num;
bool map[5005][5005];
int ans[5005],fa[5005],dep[5005];
int read(){
	int a = 0;
	char ch = getchar();
	while (ch < '0'||ch >'9') ch = getchar();
	while (ch <= '9'&& ch >= '0'){
		a = (a<<1)+(a<<3)+ch -'0';
		ch = getchar();
	}
	return a;
}
void bfs(int s){
	q.push(s);
	dep[s] = 1;
	fa[s] = 0;
	while (!q.empty()){
		int u = q.front();
		q.pop();
		for (int i = 1;i <= n;++i){
			if (map[u][i]){
				if (!dep[i]){
					q.push(i);
					dep[i] = dep[u] + 1;
					fa[i] = u; 
				}else if(dep[i] > dep[u]){
					if (fa[i] < u){
						fa[i] = u;
						dep[i] = dep[u]+ 1;
					}
				}
			}
		}
	}
}

void dfs(int s){
	for (int i = 1;i <= n;++i){
		if (fa[i] == s){
			ans[++num] = i;
			dfs(i);
		}
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	n = read();
	m = read();
	int x,y;
	for (int i = 1;i <= m;++i)
	{
		x = read();
		y = read();
		map[x][y] = 1;
		map[y][x] = 1;
	}
	for (int i = 1;i <= n;++i)
		if (!dep[i])
			bfs(i);
	for (int i = 1;i <= n;++i)
		if (dep[i] == 1)
			dfs(i);
	
	for (int i = 0;i < n;++i)
		printf("%d ",ans[i]);
//	printf("%d\n",ans[n]);
	
	return 0;
}
