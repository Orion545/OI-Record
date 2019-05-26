#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

typedef long long ll;

const ll INT_MAX=(1LL<<63)-1;

int N, M, P[100010], r[100010];
ll f[100010][2];
char s[2];

vector<int> son[100010];

bool b[100010], c=1;

void dp(int x){
	if (!c) return;
	b[x]=1;
	f[x][0]=f[x][1]=0;
	if (r[x]==1) f[x][0]=INT_MAX;
	if (r[x]==2) f[x][1]=INT_MAX;
	for (int i=0 ; i<son[x].size(); i++) if (!b[son[x][i]]) {
		int j=son[x][i];
		if (r[j]==1 && r[x]==1) c=0;
		dp(j);
		if (!c) return;
		if (r[x]!=1) f[x][0]+=min(f[j][0], f[j][1]);
		if (r[x]!=2) f[x][1]+=f[j][0];
	}
	if (r[x]!=1) f[x][0]+=P[x];
	if (f[x][0]<0) f[x][0]=INT_MAX;
	if (f[x][1]<0) f[x][1]=INT_MAX;
}

int main(){
	freopen("defense.in", "r", stdin);
	freopen("defense.out", "w", stdout);
	scanf("%d%d%s", &N, &M, s);
	for (int i=0; i<N; i++) scanf("%d", &P[i]);
	for (int i=1; i<N; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		a--; b--;
		son[a].push_back(b);
		son[b].push_back(a);
	}
	for (int i=0; i<M; i++){
		int a1, x, b1, y;
		scanf("%d%d%d%d", &a1, &x, &b1, &y);
		a1--; b1--;
		r[a1]=x+1; r[b1]=y+1;
		c=1;
		memset(b, 0, sizeof(b));
		dp(0);
		//for (int j=0; j<N; j++) printf("%d %lld %lld\n", j, f[j][0], f[j][1]);
		if (c) printf("%lld", min(f[0][0], f[0][1])); 
		else printf("-1");
		cout<<endl;
		r[a1]=r[b1]=0;
	}
	fclose(stdout);
	return 0;
}