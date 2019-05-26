#include<algorithm>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
using namespace std;
struct AB{
	int a, b, n;
}d[200005];
int n, m, a, b, p[100005], c, h[100005], v[100005], y, x;
int wen[100005][6];
long long f[100005][2];
string lei;
void charu(int a, int b){
	d[++c].a = a;
	d[c].b = b;
	d[c].n = h[a];
	h[a] = c;
}
int check(int j){
	int a[15], x, y, sum = 0;;
	for(int i = 1; i <= n; i++){
		a[i] = j&1;
		if(a[i])sum+=p[i];
		j>>=1;
	}
	for(int i = 1; i <= c; i+=2){
		x = d[i].a; y = d[i].b;
		if(a[x]|a[y])continue;
		else return 0;
	}
	return sum;
}
void pian1(){
	int a, b, x, y, ans = 1e9, temp;
	for(int i = 1; i <= m; i++){
		ans = 1e9;
		a = wen[i][0]; x = wen[i][1]; b = wen[i][2]; y = wen[i][3];
		for(int j = 0; j < (1<<n); j++){
			if(x == 1){
				if(!((1<<(a-1))&j))continue;
			}else if((1<<(a-1))&j)continue;
			if(y == 1){
				if(!((1<<(b-1))&j))continue;
			}else if((1<<(b-1))&j)continue;
			temp = check(j);
			if(temp){
				ans = min(temp, ans);
			}
		}
		if(ans == 1e9)printf("-1\n");
		else printf("%d\n", ans);
	}
	
	return;
}
void dfs(int xian){
	int nexi;
	bool u = 0;
	for(int i = h[xian]; i; i = d[i].n){
		nexi = d[i].b;
		if(!v[nexi]){
			u = 1;
			v[nexi] = v[xian] + 1;
			dfs(nexi);
			f[xian][0] += min(f[nexi][0], f[nexi][1]);
			f[xian][1] += f[nexi][0];
		}
	}
	f[xian][0] += p[xian];
	if(!u)f[xian][0] = p[xian];
	if(xian == a){
		if(x == 1)f[xian][1] = 2e9 + 7;
		else f[xian][0] = 2e9 + 7;
	}
	if(xian == b){
		if(y == 1)f[xian][1] = 2e9 + 7;
		else f[xian][0] = 2e9 + 7;
	}
	//cout<<xian<<" "<<f[xian][0]<<" "<<f[xian][1]<<endl;
}
void pian2(){
	long long ans = 0;
	for(int i = 1; i <= m; i++){
		memset(f, 0, sizeof(f));
		memset(v, 0, sizeof(v));
		a = wen[i][0]; x = wen[i][1]; b = wen[i][2]; y = wen[i][3];
		v[1] = 1;dfs(1);
		ans = min(f[1][0], f[1][1]);
		if(ans >= 2e9 + 7) printf("-1\n");
		else printf("%d\n", ans);
	}
	return;
}
int main(){
	freopen("defense.in", "r", stdin);
	freopen("defense.out", "w", stdout);
	scanf("%d %d", &n, &m);
	cin>>lei;
	for(int i = 1; i <= n; i++){
		scanf("%d", &p[i]);
	}
	for(int i = 1; i < n; i++){
		scanf("%d %d", &a, &b);
		charu(a, b);
		charu(b, a);
	}
	for(int i = 1; i <= m; i++){
		scanf("%d %d %d %d", &wen[i][0], &wen[i][1], &wen[i][2], &wen[i][3]);
	}
	if(n <= 10 && m <= 10){
		pian1();
		return 0;
	}
	if(n <= 2000 && m <= 2000){
		pian2();
		return 0;
	}
	return 0;
}
