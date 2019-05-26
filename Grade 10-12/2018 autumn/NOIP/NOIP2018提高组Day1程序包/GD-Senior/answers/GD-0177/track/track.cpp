#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int INT_MAX=(1<<31)-1;

int N, M, a[50100], b[50100], l[50100], d[50100], ans, w2[3000][3000];

bool w1[50100];

void dfs1(int x, int res, int now, int cnt, int k){
	if (k>=M){
		ans=max(ans, now);
		return;
	}
	if (k==M-1) ans=max(ans, min(now, cnt));
	if ((res<=ans && k!=M-1) || now<=ans) return;
	if (N-x-1>(M-k-1)*2) dfs1(x+1, res-d[x], now, cnt+d[x], k);
	if (x>=N || cnt!=0) dfs1(x+1, res, min(now, cnt), 0, k+1);
}

void dfs2(int x, int res, int now, int cnt, int k){
	if (k>=M){
		ans=max(ans, now);
		return;
	}
	if (k==M-1) ans=max(ans, min(now, cnt));
	if ((res<=ans && k!=M-1) || now<=ans) return;
	//bool h=0;
	for (int i=0; i<N; i++) if (w2[x][i] && !w1[i]){
		//printf("w2[%d][%d]=%d\n", x, i, w2[x][i]);
		w1[i]=1;
		//h=1;
		dfs2(i, res-w2[x][i], now, cnt+w2[x][i], k);
		w1[i]=0;
	}
	if (cnt!=0){
		for (int i=0; i<N; i++) if (!w1[i]){
			w1[i]=1;
			//h=1;
			dfs2(i, res, min(now, cnt), 0, k+1);
			w1[i]=0;
		}
	}
	//if (!h) dfs2(x, res, now, cnt, k+1);
}

int main(){
	freopen("track.in", "r", stdin);
	freopen("track.out", "w", stdout);
	scanf("%d%d", &N, &M);
	bool b1=1, b2=1; 
	for (int i=0; i<N-1; i++){
		scanf("%d%d%d", &a[i], &b[i], &l[i]);
		a[i]--; b[i]--;
		if (a[i]!=0) b1=0;
		if (b[i]!=a[i]+1) b2=0;
	}
	if (b1){
		sort(l, l+N);
		printf("%d", l[N-M-1]+l[M-1]); 
	}else {
		int cnt=0;
		for (int i=0; i<N-1; i++){
			cnt+=l[i];
			d[a[i]]=l[i];
		}
		if (!b2){
			for (int i=0; i<N; i++)
				w2[b[i]][a[i]]=w2[a[i]][b[i]]=l[i];
			//for (int i=0; i<N; printf("\n"), i++) for (int j=0; j<N; j++) printf("%d ", w2[i][j]);
		}
		//printf("%d\n", cnt);
		ans=0;
		if (b2) dfs1(0, cnt, INT_MAX, 0, 0); else {
			for (int i=0; i<N; i++){
				//printf("====%d\n", i);
				memset(w1, 0, sizeof (w1));
				w1[i]=1;
				dfs2(i, cnt, INT_MAX, 0, 0);
			}
		}
		printf("%d", ans);
	}
	fclose(stdout);
	return 0;
}