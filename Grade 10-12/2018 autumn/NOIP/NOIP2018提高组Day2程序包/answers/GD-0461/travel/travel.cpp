#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 5050;
int e[N][N];
int n,m;
int vis[N],cir[N],S[N];

void findcir(int x,int fa) {
	vis[x]=1; S[++S[0]] = x;
	for (int j = 1; j <= e[x][0]; j++) {
		int i = e[x][j];
		if (i != fa) {
			if (vis[i]) {
				if (cir[0] != 0) break;
				int T = S[0];
				while (S[T] != i) {
					cir[++cir[0]] = S[T--];
				}
				cir[++cir[0]] = S[T--];
			} else {
				findcir(i,x);
			}
		}
	}
	S[0]--;
}

int ans[N],now[N],ban1,ban2;
void getseq(int x,int from){
	now[++now[0]] = x;
	for (int j = 1; j <= e[x][0]; j++) {
		int i = e[x][j];
		if (i != from && !(i==ban1 && x==ban2 || i==ban2 && x==ban1)) {
			getseq(i,x);
		}
	}
}

void go(){
	now[0] = 0;
	getseq(1,0);
	for (int i = 1; i <= n; i++) if (ans[i] != now[i]){
		if (now[i] < ans[i]) memcpy(ans,now,sizeof ans);
		return;
	}
}

int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>m;
	ans[1] = n + 1;
	for (int i = 1; i <= m; i++) {
		int u,v; scanf("%d %d\n",&u,&v);
		e[u][++e[u][0]] = v;
		e[v][++e[v][0]] = u;
	}
	for (int i = 1; i <= n; i++) sort(e[i]+1,e[i]+1+e[i][0]);
	findcir(1,0);
	if (cir[0]==0) {
		go();
	} else {
		ban1 = cir[cir[0]], ban2 = cir[1]; go();
		for (int i = 1; i < cir[0]; i++) {
			ban1 = cir[i], ban2 = cir[i+1];
			go();
		}
	}
	for (int i = 1; i < n; i++) printf("%d ",ans[i]);
	printf("%d\n",ans[n]);
}
