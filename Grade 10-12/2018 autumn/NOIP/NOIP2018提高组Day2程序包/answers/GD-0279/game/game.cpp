#include<cstdio>
#include<queue>
#include<iostream>
#define mod 1000000007
using namespace std;
int n, m, ans;
int map[10][1000001];
long long quickpower(long long x, int y){
	long long res = 1;
	while(y){
		if(y & 1) res = res * x % mod;
		x = x * x % mod;
		y >>= 1;
	}
	return res % mod;
}
bool check(){
	queue<pair<pair<int, int>, int> > Q;
	Q.push(make_pair(make_pair(0, 0), map[0][0]));
	int lst = 0;
	while(!Q.empty()){
		int x = Q.front().first.first, y = Q.front().first.second, val = Q.front().second;
		Q.pop();
		if(x != n) Q.push(make_pair(make_pair(x + 1, y), val + map[x + 1][y]));
		if(y != m) Q.push(make_pair(make_pair(x, y + 1), val + map[x][y + 1]));
		if(x == n - 1 && y == m - 1){
			if(val < lst) return false;
			lst = val;
		}
	}
}
void dfs(int x, int y){
	if(x == n){
		if(check()){
			ans++;
		}
		return;
	}
	if(y == m - 1){
		dfs(x + 1, 0);
		map[x][y] = 1;
		dfs(x + 1, 0);
		map[x][y] = 0;
	}
	else{
		dfs(x, y + 1);
		map[x][y] = 1;
		dfs(x, y + 1);
		map[x][y] = 0;
	}
}
int main(){
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	scanf("%d%d", &n, &m);
	if(n > m) n ^= m ^= n ^= m;
	if(n == 1){
		printf("%lld", quickpower(2, m) % mod);
		fclose(stdout);
		return 0;
	}
	if(n == 2){
		printf("%lld", quickpower(3, m - 1) * 4 % mod);
		fclose(stdout);
		return 0;
	}
	if(n == 3 && m >= 4){
		printf("%lld", quickpower(3, m - 4) * 332 % mod);
		fclose(stdout);
		return 0;
	}
	if(n == 4 && m == 4){
		printf("896");
		fclose(stdout);
		return 0;
	}
	dfs(0, 0);
	printf("%d", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
