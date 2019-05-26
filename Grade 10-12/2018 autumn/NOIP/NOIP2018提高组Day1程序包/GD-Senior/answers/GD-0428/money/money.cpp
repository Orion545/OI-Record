#include <bits/stdc++.h>
#define maxn 200
#define maxm 25010

using namespace std;

int T, n, M;
int a[maxn], b[maxn];
bool f[maxm];
int m, ans;
bool Vis[maxn], g[maxm];

void Dfs(int x){
	if(x == n + 1){
		m = 0;
		for(int i = 1; i <= n; i++)
			if(Vis[i])  b[++m] = a[i];
		if(!m)  return;
		g[0] = true;
		for(int i = 1; i <= m; i++)
			for(int j = 0; j <= M-b[i]; j++){
				if(!g[j])  continue;
				for(int k = 1; j + b[i] * k <= M; k++)
					g[j + b[i] * k] = true;
			}
		bool d = true;
		for(int i = 1; i <= M; i++)
			if(f[i] != g[i]){
				d = false;
				break;
			}
		if(d)  ans = min(ans, m);
		return;
	}
	Vis[x] = true;
	Dfs(x + 1);
	Vis[x] = false;
	Dfs(x + 1);
}

int main(){
	
	
	freopen("money.in", "r", stdin);
	freopen("money.out", "w", stdout);
	
	scanf("%d", &T);
	
	while(T --){
		scanf("%d", &n);
		M = 0;
		for(int i = 1; i <= n; i++){
			scanf("%d", &a[i]);
			M = max(M, a[i]);
		}
		M += 10;
		memset(f, false, sizeof(f));
		if(n == 2){
			if((a[1] % a[2] == 0) || (a[2] % a[1] == 0))
				printf("1\n");
			else  printf("2\n");
			continue;
		}
		else{
			ans = n;
			f[0] = true;
			for(int i = 1; i <= n; i++)
				for(int j = 0; j <= M-a[i]; j++){
					if(!f[j])  continue;
					for(int k = 1; j + a[i] * k <= M; k++)
						f[j + a[i] * k] = true;
				}
			/*for(int i = 1; i <= M; i++)  cout<<f[i] << ' ';
			cout << endl;*/
			memset(Vis, false, sizeof(Vis));
			Dfs(1);
			printf("%d\n", ans);
		}
	}
	
	return 0;
}
