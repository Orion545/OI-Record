#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, q[5010];
bool b[5010];
vector<int> d[5010];

void f(int x){
	b[x]=1;
	q[++q[0]]=x+1;
	for (int i=0; i<d[x].size(); i++) if (!b[d[x][i]]) f(d[x][i]);
}

int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	scanf("%d%d", &N, &M);
	for (int i=0; i<M; i++){
		int a, b;
		scanf("%d%d", &a, &b);
		a--; b--;
		d[a].push_back(b);
		d[b].push_back(a);
	}
	if (M==N-1) {
		for (int i=0; i<N; i++) sort(d[i].begin(), d[i].end());
		f(0);
		for (int i=1; i<=q[0]; i++) printf("%d ", q[i]);
	}else{
		bool change=1;
		int cnt=1, r=d[0][0], l=d[0][1], la=0;
		printf("1 ");
		if (r>l) swap(r, l);
		while (cnt<N){
			printf("%d ", r+1);
			cnt++;
			if (d[r][0]==la) {
				la=r;
				r=d[r][1]; 
			}else{ 
				la=r;
				r=d[r][0];
			}
			if (change && r>l){
				change=0;
				la=0;
				swap(r, l);
			}
		}
	}
	fclose(stdout);
	return 0;
}