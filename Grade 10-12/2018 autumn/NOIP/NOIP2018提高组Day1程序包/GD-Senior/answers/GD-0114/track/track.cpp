#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int n,m;
int map[100005][5],degs=1;//[1,2n-2][0,2](to,next,len)
int head[50005];
bool vis[50005];

bool ai1 = 1;
int ans;

void put(int from,int to,int len){
	map[degs][0] = to;
	map[degs][1] = head[from];
	map[degs][2] = len;
	head[from] = degs++;
}

void part1(bool bo){
	if(!bo) return;
	short k[50005];//[1,n-1]
	for(int i = 1;i <= n-1;i++){
		k[i] = map[i*2][2];
	}
	sort(&k[1],&k[n]);
	cout << k[n-m];
}
/*
5 2
1 2 5
1 3 2
1 4 3
1 5 4
*/

int lowest(int a[]){
	int lown = 1e9;
	int lowp = 0;
	for(int i = 1 ;i <= m;i++){
		if(lown > a[i]){
			lown = a[i];
			lowp = i;
		}
	}
	return lowp;
}

void part2(bool bo){
	if(!bo) return;
	short k[50005];//[1,n-1]
	int border[50005];//[1,m]
	int sum[50005];//[1,m]
	for(int i = 1;i <= n-1;i++){
		k[i] = map[i*2][2];
	}
	for(int i = 1;i <= m;i++){
		border[i] = (n-1)*i/m;
		for(int j = border[i-1]+1;j <= border[i];j++){
			sum[i] += k[j];
		}
	}
	while(true){
		
	}
	for(int i = 1;i <= m;i++){
		cout << sum[i] << " ";
	}
	cout << lowest(sum);
}
/*
6 3
1 2 3
2 3 1
3 4 1
4 5 4
5 6 5
*/

void dfs(int pos,int tot){
	int next = head[pos];
	bool w;
	while(next){
		if(!vis[map[next][0]]){
			vis[map[next][0]] = 1;
			dfs(map[next][0],tot+map[next][2]);
		}
		next = map[next][1];
	}
	if(tot > ans){
		ans = tot;
	}
}

void part3(){
	if(m != 1) return;
	for(int i = 1;i <= n;i++){
		dfs(n,0);
	}
	cout << ans;
}

void part4(){
	if(m != n-1) return;
	int l = 1e9;
	for(int i = 1;i <= n-1;i++){
		if(l > map[i*2][2]) l = map[i*2][2];
	}
	cout << l;
}

int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	int t1,t2,t3;
	for(int i = 1;i <= n-1;i++){
		scanf("%d%d%d",&t1,&t2,&t3);
		put(t1,t2,t3);
		put(t2,t1,t3);
		if(t1!=1) ai1 = 0;
	}
	if(ai1){
		part1(ai1);
	}
	part3();
	part4();
}
