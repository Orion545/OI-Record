#include<cstdio>
#include<iostream>
using namespace std;
int di[100050];
long long n, ans = 0, i, j;
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n;
	for(i = 1; i <= n; i++){
		cin >> di[i];
	}
	for(i = 1; i <= n;){
		j = i;
		if(di[j] > 0)ans++;
		while((j <= n)&&(di[j] > 0)){
			di[j]--;
			j++;
		}
		if(di[i] <= 0)i++;
	}
	cout << ans;
	return 0;
}
