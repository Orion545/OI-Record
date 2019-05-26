#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int P=10e9+7;

typedef unsigned long long ull;

int N, M, v[10][10], ans;

vector<ull> w, s;

bool check(){
	// printf("=======\n");
	// for (int i=0; i<N; printf("\n"), i++) for (int j=0; j<M; j++) printf("%d ", v[i][j]); printf("-------\n");
	// for (int i=0; i<w.size(); i++) printf("%d ", w[i]); printf("\n-------\n");
	// for (int i=0; i<s.size(); i++) printf("%d ", s[i]); printf("\n");
	for (int i=0; i<w.size(); i++) for (int j=i+1; j<s.size(); j++) if (w[i]>w[j] && s[i]>s[j] || w[j]>w[i] && s[j]>s[i]) return false;
	//printf("!\n");
	return true;
}

void dfs2(int x, int y, ull tw, ull ts){
	ts=ts*2+v[x][y];
	if (x==N-1 && y==M-1){
		w.push_back(tw);
		s.push_back(ts);
		return;
	}
	if (x+1<N) dfs2(x+1, y, tw*2, ts);
	if (y+1<M) dfs2(x, y+1, tw*2+1, ts);
}

void dfs1(int x, int y){
	if (x>=N){
		w.clear();
		s.clear();
		dfs2(0, 0, 0, 0);
		if (check()) (ans+=1)%=P;
		return;
	}
	if (y+1==M) {
		dfs1(x+1, 0);
		v[x][y]=1;
		dfs1(x+1, 0);
		v[x][y]=0;
	} else{
		dfs1(x, y+1);
		v[x][y]=1;
		dfs1(x, y+1);
		v[x][y]=0;
	}
}

int main(){
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	scanf("%d%d", &N, &M);
	dfs1(0, 0);
	printf("%d", ans);
	fclose(stdout);
	return 0;
}