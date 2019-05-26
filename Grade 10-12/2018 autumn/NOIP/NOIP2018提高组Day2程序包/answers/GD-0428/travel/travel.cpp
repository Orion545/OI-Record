#include <bits/stdc++.h>
#define maxn 5005

using namespace std;

int n, m, Dfn, Ans[maxn], S[maxn];
int f[maxn];
int Head[maxn], cur = -1;
struct Data{
	int obj, nxt;
}Edg[maxn<<1];

vector <int> Son[maxn];
bool used[maxn], ban[maxn], ff;
int Po[maxn], Prev[maxn], ban1, ban2;

void Addedge(int a, int b){
	Edg[++cur].nxt = Head[a];
	Edg[cur].obj = b; 
	Head[a] = cur;
}

void Dfs(int x, int fa){
	f[++Dfn] = x;
	int cnt = 0;
	for(int i = Head[x]; ~ i; i = Edg[i].nxt){
		int v = Edg[i].obj;
		if(v == fa || (ban1 == x && ban2 == v) || (ban2 == x && ban1 == v))  continue;
		S[++cnt] = v;
	}
	sort(S+1, S+cnt+1);
	
	Son[x].clear();
	for(register int i = 1; i <= cnt; i++)  Son[x].push_back(S[i]);
	for(register int i = 0; i < cnt; i++)
		Dfs(Son[x][i], x);
}

void Find(int x, int fa){
	used[x] = true;
	for(register int i = Head[x]; ~ i; i = Edg[i].nxt){
		int v = Edg[i].obj;
		if(ff)  break;
		if(v == fa)  continue;
		Prev[v] = x;
		if(used[v]){
			for(register int j = x; Prev[j] != x; j = Prev[j])  Po[++Po[0]] = j;
			Po[++Po[0]] = v;
			ff = true;
			return;
		}
		Find(v, x);
	}
}

bool Check(){
	for(register int i = 1; i <= n; i++){
		if(f[i] < Ans[i])  return true;
		if(f[i] > Ans[i])  return false;
	}
	return false;
}

int main(){
	
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	scanf("%d%d", &n, &m);
	
	for(register int i = 1; i <= n; i++)  Head[i] = -1;
	
	int a, b;
	for(register int i = 1; i <= m; i++){
		scanf("%d%d", &a, &b);
		Addedge(a, b);
		Addedge(b, a);	
	}
	
	if(m == n-1){  
		Dfn = 0;
		Dfs(1, 0);
		for(register int i = 1; i <= n; i++)  Ans[i] = f[i];
	}
	else{
		Find(1, 0);
		for(register int i = 1; i <= Po[0]; i++){
			ban1 = Po[i];
			ban2 = Prev[ban1];
			Dfn = 0;
			Dfs(1, 0);
			if(i == 1 || Check())
				for(register int j = 1; j <= n; j++)  Ans[j] = f[j];
		}
	}
	
	for(register int i = 1; i <= n; i++)  printf("%d ", Ans[i]);
	printf("\n");
	
	return 0;
}
