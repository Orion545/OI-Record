#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<iostream>
using namespace std;
struct AB{
	int a, b, n;
	bool operator < (const AB &A)const{
		return b > A.b;
	}
}d[10005];
int n, m, a, b, c, h[10005], v[10005], st = 1e9, fu[10005], shu[10005], xiao[10005];
bool upianhuan;
void charu(int a, int b){
	d[++c].a =a;
	d[c].b = b;
}
void pian1(int a){
	int b;
	if(!v[a])printf("%d ", a);
	v[a] = 1;
	for(int i = h[a]; i ; i = d[i].n){
		b = d[i].b;
		if(!v[b]){
			fu[b] = a;
			pian1(b);
		}
	}
}
void pian2(int a){
	int b;
	if(!a)return;
	if(!v[a])printf("%d ", a);
	v[a] = 1;
	for(int i = xiao[a]; i; i = d[i].n){
		b = d[i].b;
		//cout<<b<<endl;
		xiao[a] = i;
		if(d[xiao[a]].b <= d[xiao[fu[a]]].b){
			if(!v[b]){
				fu[b] = a;
				pian2(b);
			}
		}
		else{
			pian2(fu[a]);
			if(!v[b]){
				fu[b] = a;
				pian2(b);
			}
		}
	}	
}
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= m; i++){
		scanf("%d %d", &a, &b);
		charu(a, b);charu(b, a);
	}
	sort(d+1, d+1+c);
	for(int i = 1; i <= c; i++){
		a = d[i].a;
		d[i].n = h[a];
		h[a] = i;
		if(a < st)st = a;
		shu[a]++;
		if(shu[a] > 2)upianhuan = 1;
	}
	for(int i = 1; i <= n; i++){
		xiao[i] = h[i];
	}
	if(m == n - 1){
		fu[st] = st;
		pian1(st);
		return 0;
	}
	if(n == m){
		if(!upianhuan){
			pian1(st);
			return 0;
		}
		else pian2(st);
		return 0;
	}
	return 0;
	
}
