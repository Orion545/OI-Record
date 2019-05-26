#include <bits/stdc++.h>
#define maxn 50010

using namespace std;

int n, m, cur = -1;

int Head[maxn], dep[maxn];
struct Data{
	int obj, nxt, len;
}Edg[maxn<<1];

void Addedge(int a, int b, int c){
	Edg[++cur].nxt = Head[a];
	Edg[cur].obj = b;
	Edg[cur].len = c;
	Head[a] = cur;
}

void Dfs(int x, int fa){
	for(int i = Head[x]; ~ i; i = Edg[i].nxt){
		int v = Edg[i].obj, l = Edg[i].len;
		if(v == fa)  continue;
		dep[v] = dep[x] + l;
		Dfs(v, x);
	}
}

void Sol1(){
	Dfs(1, 0);
	int pos, mmax = 0;
	for(int i = 1; i <= n; i++)
		if(dep[i] > mmax){
			mmax = dep[i];
			pos = i;
		}
	for(int i = 1; i <= n; i++)  dep[i] = 0;
	Dfs(pos, 0);
	
	mmax = 0;
	for(int i = 1; i <= n; i++)
		mmax = max(mmax, dep[i]);
	printf("%d\n", mmax);
}

int e[maxn], cnt;

bool Check(int x){
	int j = 0, tiao = 0;
	for(int i = cnt; i > j; i--){
		if(e[i] >= x)  tiao ++;
		else{
			j ++;
			while(j < i && e[i] + e[j] < x)  j ++;
			if(j == i)  break;
			tiao ++;
		}
	}
	return tiao >= m;
}

void Sol2(){
	for(int i = Head[1]; ~ i; i = Edg[i].nxt)
		e[++cnt] = Edg[i].len;
	sort(e+1, e+cnt+1);
	int L = 1, R = e[cnt] * 2 + 1;
	while(L + 1 < R){
		int mid = (L + R) >> 1;
		if(Check(mid))  L = mid;
		else  R = mid;
	}
	printf("%d\n", L);
}

void Dfs5(int x, int fa){
	for(int i = Head[x]; ~ i; i = Edg[i].nxt){
		int v = Edg[i].obj, l = Edg[i].len;
		if(v == fa)  continue;
		e[++cnt] = l;
		Dfs5(v, x);
	}
}

bool cc(int x){
	int s = 0, tiao = 0;
	for(int i = 1; i <= n; i++){
		s += e[i];
		if(s >= x){
			tiao ++;
			s = 0;
		}
	}
	return tiao >= m;
}

void Sol3(){
	Dfs5(1, 0);
	int L = 1, R = 0;
	for(int i = 1; i <= cnt; i++)
		R += e[i];
	R ++;
	while(L + 1 < R){
		int mid = (L + R) >> 1;
		if(cc(mid))  L = mid;
		else  R = mid;
	}
	printf("%d\n", L);
}

int main(){
	
	freopen("track.in", "r", stdin);
	freopen("track.out", "w", stdout);
	
	scanf("%d%d", &n, &m);
	
	for(int i = 1; i <= n; i++)  Head[i] = -1;
	
	bool flag = true, lzxkawayi = true;
	int a, b, c;
	for(int i = 1; i < n; i++){
		scanf("%d%d%d", &a, &b, &c);
		if(a != 1)  flag = false;
		if(a + 1 != b)  lzxkawayi = false;
		Addedge(a, b, c);
		Addedge(b, a, c);
	}
	
	if(m == 1)  Sol1();
	else if(flag)  Sol2();
	else if(lzxkawayi)  Sol3();
	
	return 0;
}
