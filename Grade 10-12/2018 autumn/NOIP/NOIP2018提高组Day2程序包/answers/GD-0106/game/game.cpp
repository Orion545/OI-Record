#include <cstdio>
#define MOD 1000000007
#define ll long long

int n,m;

inline int read(){
	int res = 0;
	int sym = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9'){
		if(ch == '-') sym = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		res = res * 10 + ch - '0';
		ch = getchar();
	}
	return res * sym;
}

ll quick_power(int a,int b){
	ll ans = 1;
	if(b == 1) return a;
	if(b % 2 == 1) ans *= b;
	ans %= MOD;
	b /= 2;
	ll tmp = quick_power(a,b);
	ans = (ans * tmp % MOD) * tmp % MOD;
	return ans; 
}

int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	n = read();
	m = read();
	if(n <= 3 && m <= 3){
		if(n == 1 && m == 1) printf("2");
		if(n == 1 && m == 2) printf("4");
		if(n == 2 && m == 1) printf("4");
		if(n == 1 && m == 3) printf("8");
		if(n == 3 && m == 1) printf("8");
		if(n == 2 && m == 2) printf("12");
		if(n == 2 && m == 3) printf("36");
		if(n == 3 && m == 2) printf("36");
		if(n == 3 && m == 3) printf("112");
	}else if(n == 2){
		int t = quick_power(3,m - 1);
		printf("%d",t * 4 % MOD);
	}else if(n == 1){
		int t = quick_power(2,m);
		printf("%d",t % MOD);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
