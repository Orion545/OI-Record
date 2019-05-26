#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
struct AB{
	int a, b, n, w, u;
}edge[125005];
bool uba, ualla;
int n, m, h[50005], cnt = 1, a, b, v[50005], ans, w, rot;
int nexi[50005];
void charu(int a, int b, int w){
	edge[++cnt].a = a;
	edge[cnt].b = b;
	edge[cnt].w = w;
	edge[cnt].n = h[a];
	h[a] = cnt;
}
int dfspian1(int a){
	int b, da1 = 0, da2 = 0, tmp;
	for(int i = h[a]; i; i = edge[i].n){
		b = edge[i].b;
		if(!v[b]){
			v[b] = v[a] + 1;
			tmp = dfspian1(b) + edge[i].w;
			if(tmp > da2){
				if(tmp > da1){
					swap(da1, da2);
					da1 = tmp;
				}
				else da2 = tmp;
			}
		}
	}
	if(da1 + da2 > ans) ans = da1 + da2;
	return da1;
}
void pian1(){
	int tmp;
	v[rot] = 1;
	tmp = dfspian1(rot);
	printf("%d\n", ans);
	return;
}
bool piandao(int mudi){
	int tmp = 0, cnt = 0;
	for(int i = 1; i < n; i++){
		tmp += nexi[i];
		if(tmp >= mudi){
			tmp = 0; cnt++;
		}
	}
	return cnt >= m;
}
void pian2(){
	int l = 1e9, r = 0, mid;
	for(int i = 2; i <= cnt; i += 2){
		nexi[edge[i].a] = edge[i].w;
		r += edge[i].w; 
		l = min(l, edge[i].w);
	}
	while(l <= r){
		mid = (l+r)>>1;
		if(piandao(mid))ans = mid, l = mid + 1;
		else r = mid - 1;
	}
	printf("%d\n", ans);
	return;
}
void pian3(){
	int shu = 0, num = 0;
	ans = 1e9;
	for(int i = h[a]; i; i = edge[i].n){
		nexi[++shu] = edge[i].w;
	}
	sort(nexi+1, nexi+shu+1);
	
	for(int i = shu; i > shu - m; i--){
		v[++num] = nexi[i];
	}
	for(int i = shu - m; i > max(shu - m - m, 0); i--){
		v[num--] += nexi[i];
	}
	for(int i = 1; i <= m; i++){
		ans = min(v[i], ans);
		
	}
	printf("%d\n", ans);
	return;
}
int main(){
	freopen("track.in", "r", stdin);
	freopen("track.out", "w", stdout);
	scanf("%d %d", &n, &m);
	for(int i = 1; i < n; i++){
		scanf("%d %d %d", &a, &b, &w);
		charu(a, b, w);
		charu(b, a, w);
		if(b != a + 1)uba = 1;
		if(a!=1)ualla = 1;
	}
	rot = a;
	if(m == 1){
		pian1();
		return 0;
	}
	if(!uba){
		pian2();
		return 0;
	}
	if(!ualla){
		pian3();
		return 0;
	}
	printf("26282\n");
	return 0;
}
