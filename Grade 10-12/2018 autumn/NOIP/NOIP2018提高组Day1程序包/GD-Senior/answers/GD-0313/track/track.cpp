#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const int N = 50005;


int n, m, res, ResM, vis[N], LenA[N], LenB[N];
int MapM[1005][1005];
struct T{
	int a, b, l;
}edge[N];

bool cmp(int a,int b){
	return a>b;
}

int SolveA(){
	sort(LenA+1,LenA+n,cmp);
	int ResA, i = m, j = m+1;
	while ( i>0 && j<n ) LenA[i--]+=LenA[j++];
	ResA = LenA[1];
	for (int i = 1; i <=m; i ++) ResA = min(ResA,LenA[i]);
	return ResA; 
}

int isok(int ans){
	int k = 0, tot = 0;
	for (int i = 1; i < n; i ++){
		tot += LenB[i];
		if ( tot>=ans ){
			k ++;
			tot = 0;
		}
	}
	if ( k>=m ) 
		return 1;
	else
		return 0;
	
}

int SolveB(){
	int L = 1, R = 500000001, M;
	while ( L+1<R ){
		M = (L+R)/2;
		if ( isok(M) )
			L = M;
		else
			R = M;
	}
	return L;
}

void dfs(int K,int tot){
	ResM = max(ResM,tot);
	for (int i = 1; i <= n; i ++){
		if ( MapM[K][i] && vis[i]==0 ){
			vis[i] = 1;
			dfs(i,tot+MapM[K][i]); 
			vis[i] = 0;
		}
	}
	return ;
}

int SolveM(){
	for (int i = 1; i < n; i ++){
		vis[i] = 1;
		if ( MapM[i][0]==1 ) dfs(i,0);
		vis[i] = 0;
	}
	return ResM;
}

int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);

	scanf("%d%d", &n, &m);
	int SA = 1, SB = 1;
	for (int i = 1; i < n; i ++){
		scanf("%d%d%d", &edge[i].a, &edge[i].b, &edge[i].l);
		if ( edge[i].a>edge[i].b ) swap(edge[i].a,edge[i].b);
		int aa = edge[i].a, bb = edge[i].b, ll = edge[i].l;
		res = max(res,ll);
		LenA[i] = ll;
		LenB[aa] = ll;
		if ( edge[i].a!=1 ) SA = 0;
		if ( edge[i].b!=edge[i].a+1 ) SB = 0;
		if ( m==1 && n<=1000 ){
			MapM[aa][bb]=MapM[bb][aa]=ll;
			MapM[aa][0] ++;
			MapM[bb][0] ++;
		}
	}
	
	if (SA) 
		printf("%d", SolveA());
	else if (SB) 
		printf("%d", SolveB());
	else if ( m==1 && n<=1000 )
		printf("%d", SolveM());
	else 
		printf("%d", res);
	
	return 0;
}
