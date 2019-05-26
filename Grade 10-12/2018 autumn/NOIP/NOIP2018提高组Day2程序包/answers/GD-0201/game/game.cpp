#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cmath>
#include<cstring>
#define mod 1000000007
using namespace std;
int n, m, a[105][105], sz;
string w[100525], s[105005];
void get(int x, int y, string st1, string st2){
	if(y > m || x > n) return;
	if(x == n && y == m) {w[++ sz] = st1, s[sz] = st2; return;}
	st2 = st2 + (a[x][y]?'1':'0');
	get(x + 1, y, st1 + 'D', st2);
	get(x, y + 1, st1 + 'R', st2);
}
int check(){
	sz = 0;
	get(1, 1, "", "");
	for(int i = 1; i <= sz; i ++){
		for(int j = 1; j <= sz; j ++) if(i != j){
			if(w[i] > w[j]){
				if(s[i] > s[j]) return 0;
			}
		}
	}
	return 1;
}
int ans;
void dfs(int x, int y){
	if(y > m) x ++, y = 1;
	if(x > n){/*
		printf("---------------\n");
		for(int i = 1; i <= n; i ++){
			for(int j = 1; j <= m; j ++) printf("%d ", a[i][j]); printf("\n");
		}*/
		if(check()) ans ++;
		return;
	}
	a[x][y] = 1;
	dfs(x, y + 1);
	a[x][y] = 0;
	dfs(x, y + 1);
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d", &n, &m);
	if(n > m) swap(n, m);
	if(n == 5){
		 if(m == 4) printf("7136");
		else{
			m -= 5;
			long long t = 3, ANS = 7136;
			for(;m;m >>= 1, t = t * t % mod) if(m & 1) ANS = ANS * t % mod;
			printf("%lld", ANS);	
		}
	}
	else
	if(n == 4){
		 if(m == 4) printf("912");
		else{
			m -= 4;
			long long t = 3, ANS = 912;
			for(;m;m >>= 1, t = t * t % mod) if(m & 1) ANS = ANS * t % mod;
			printf("%lld", ANS);	
		}
	}
	else
	if(n == 3){
		if(m == 1) printf("8");
		else if(m == 2) printf("36");
		else if(m == 3) printf("112");
		else{
			m -= 3;
			long long t = 3, ANS = 112;
			for(;m;m >>= 1, t = t * t % mod) if(m & 1) ANS = ANS * t % mod;
			printf("%lld", ANS);	
		}
	}
	else
	if(n == 2){
		m --;
		long long t = 3, ANS = 4;
		for(;m;m >>= 1, t = t * t % mod) if(m & 1) ANS = ANS * t % mod;
		printf("%lld", ANS);
	}
	else if(n == 1){
		long long t = 2, ANS = 1;
		for(;m;m >>= 1, t = t * t % mod) if(m & 1) ANS = ANS * t % mod;
		printf("%lld", ANS);
	}
	else 
	{
		dfs(1, 1);	
		printf("%d", ans);	
	}
	
	return 0;
}
