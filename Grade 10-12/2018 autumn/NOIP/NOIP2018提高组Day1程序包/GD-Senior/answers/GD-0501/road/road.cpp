#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int n, p[100005], ans, ok, mark, rmq[22][100005], er[22], place[22][100005];
void pian1(){
	for(int i = 1; i <= n; i++){
		mark = 0;
		for(int j = 1; j <= n; j++){
			if(p[j] < p[mark] && p[j]){
				mark = j;
			}
		}
		ans+=p[mark];
		for(int j = mark+1; j <= n; j++){
			if(!p[j])break;
			else p[j]-=p[mark];
		}
		for(int j = mark-1; j>0; j--){
			if(!p[j])break;
			else p[j]-=p[mark];
		}
		p[mark] = 0;
	}
	printf("%d\n", ans);
	return;
}
void yu(){
	for(int i = 1; i <= n; i++){
		rmq[0][i] = p[i];
		place[0][i] = i;
	}
	er[0] = 1;
	for(int i = 1; i <= 18; i++){
		er[i] = er[i-1]<<1;
		for(int j = 1; j <=n; j++){
			if(rmq[i-1][j] < rmq[i-1][j+er[i-1]]){
				rmq[i][j] = rmq[i-1][j];
				place[i][j] = place[i-1][j];
			}
			else{
				rmq[i][j] = rmq[i-1][j+er[i-1]];
				place[i][j] = place[i-1][j+er[i-1]];
			}
		}
	}
}
void anpai(int l, int r, int jian){
	if(l > r)return;
	int len = (r-l+1), cnt = 18, xiao;
	while(er[cnt] > len)cnt--;
	if(rmq[cnt][l] < rmq[cnt][r - er[cnt] + 1]){
		xiao = place[cnt][l];
	}
	else xiao = place[cnt][r - er[cnt] + 1];
	ans += p[xiao] - jian;
	anpai(l, xiao-1, p[xiao]);
	anpai(xiao+1, r, p[xiao]);
	return;
}
void pian2(){
	yu();
	anpai(1, n, 0);
	printf("%d\n", ans);
	return;
}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d", &n);
	p[0] = 1e9;
	for(int i = 1; i <= n; i++){
		scanf("%d", &p[i]);
	}
	if(n<=1000){
		pian1();
		return 0;
	}
	else{
		pian2();
		return 0;
	}
	return 0;	
}
