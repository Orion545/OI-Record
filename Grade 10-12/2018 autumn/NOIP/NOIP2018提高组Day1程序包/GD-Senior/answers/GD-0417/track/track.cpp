#include<cstdio>
#include<iostream>
using namespace std;
int way[1050][1050], n, m, i, a[1050], b[1050], l[1050];
long long ans = 0;
void search(int now, long long ans0){
	long long aaa = ans0;
	int j;
	for(j = 1; j <= n; j++){
		if(now == j)continue;
		if(way[now][j] == 0)continue;
		ans0 = aaa;
		ans0 += way[now][j];
		int temp1, temp2;
		temp1 = way[now][j];
		temp2 = way[j][now];
		way[now][j] = 0;
		way[j][now] = 0;
		search(j, ans0);
		way[now][j] = temp1;
		way[j][now] = temp2;
		if(ans0 > ans)
			ans = ans0;
	}
}
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	cin >> n >> m;
	for(i = 1; i <= n-1; i++){
		cin >> a[i] >> b[i] >> l[i];
		way[a[i]][b[i]] = l[i];
		way[b[i]][a[i]] = l[i];
	}
	for(i = 1; i <= n; i++){
		search(i, 0);
	}
	if(m == 1)
		cout << ans;
	else cout << ans/2;
	return 0;
}
