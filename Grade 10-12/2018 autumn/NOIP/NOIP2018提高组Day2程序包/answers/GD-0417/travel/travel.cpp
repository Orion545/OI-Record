#include<cstdio>
#include<iostream>
using namespace std;
int n, m, u, v, i, j, judge1 = 0, temp1, judge2 = 9999, ooo;
int city[5005][5005];
int ans[5005];
int tick = 1;
int asearch(int now){
	ans[tick] = now;
	if(tick == n)return 1;
	int k;
	for(k = 1; k <= n; k++){
		if(now == k)continue;
		if(city[now][k] == 0)continue;
		city[now][k] = 0;
		city[k][now] = 0;
		tick++;
		asearch(k);
		if(tick == n)return 1;
	}
}
int bsearch(int now, int l){
	ans[tick] = now;
	int k;
	for(k = 1; k <= n; k++){
		if(now == k)continue;
		if(city[now][k] == 0)continue;
		city[now][k] = 0;
		city[k][now] = 0;
		tick++;
		if(k > l){
			ooo = k;
			return 2;
		}
		if(asearch(k) == 2)return 2;
	}
}
int search(int now){
	ans[tick] = now;
	if(tick == n)return 1;
	int k;
	for(k = 1; k <= n; k++){
		if(k == now)continue;
		if(city[now][k] == 0)continue;
		city[now][k] = 0;
		city[k][now] = 0;
		tick++;
		if(search(k) == 1)return 1;
	}
	return 3;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> n >> m;
	for(i = 1; i <= m; i++){
		cin >> u >> v;
		city[u][v] = 1;
		city[v][u] = 1;
	}
	for(i = 1; i <= n; i++){
		temp1 = 0;
		for(j = 1; j <= n; j++){
			temp1 += city[i][j];
		}
		if(temp1 > judge1)judge1 = temp1;
		if(temp1 < judge2)judge2 = temp1;
	}
	if(judge1 == 2){
		if(judge2 == 1){
			asearch(1);
		}
		if(judge2 == 2){
			for(i = 2; i <= n; i++){
				if(city[1][i] == 1)break;
			}
			for(i = i + 1; i <= n; i++){
				if(city[1][i] == 1)break;
			}
			if(i == n)asearch(1);
			else {
				bsearch(1, i);
				asearch(i);
			}
		}
	}
	if(judge1 >= 3)
		for(i = 1; i <= n; i++){
			if(search(i) == 2)break;
		}
	for(i = 1; i < n; i++){
		cout << ans[i] << " ";
	}
	cout << ans[i];
	return 0;
}
