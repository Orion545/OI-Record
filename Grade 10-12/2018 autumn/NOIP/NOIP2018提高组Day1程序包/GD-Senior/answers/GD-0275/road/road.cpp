#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
priority_queue<int> q;
long long map[100005],tree[400005],lazy[400005];
int zero[100005];
long long ans,sum;
int n,num;
int read(){
	int a = 0;
	char ch = getchar();
	while (ch <'0'||ch>'9')ch = getchar();
	while (ch <= '9' && ch >= '0'){
		a = (a<<1) + (a<<3) + ch - '0';
		ch = getchar();
	}
	return a;
}
void build(int l,int r,int rt){
	if (l == r){
//		cout << l << ' ' << r << endl;
		tree[rt] = map[l];
		return;
	} 
	int mid = (l+r) >> 1;
	build(l,mid,rt<<1);
	build(mid+1,r,rt<<1|1);
	tree[rt] = min(tree[rt<<1|1],tree[rt<<1]);
}
void pushdown(int rt){
	if (lazy[rt] != 0){
		tree[rt<<1] -= lazy[rt];
		tree[rt<<1|1] -= lazy[rt];
		lazy[rt<<1] += lazy[rt];
		lazy[rt<<1|1] += lazy[rt];		
		lazy[rt] = 0;
	}
}
void update(int l,int r,int L,int R,int rt){
	if (l == r){
		tree[rt] --;
		return;
	}
	int mid = (l + r) >> 1;
	if (L <= l && R >= r){
		tree[rt] --;
		lazy[rt] ++;
		return;
	}
	if (lazy[rt]) pushdown(rt);
	if (mid >= L)
		update(l,mid,L,R,rt<<1);
 	if (mid+1 <= R)
 		update(mid+1,r,L,R,rt<<1|1);
 	tree[rt] = min(tree[rt<<1],tree[rt<<1|1]);
}
void query(int l,int r,int x,int rt){
	if (l == r){
		if (tree[rt] == x){
//			q.push(l);
			tree[rt] = sum<<1;	
			zero[++num] = l;
		}
		return;
	}
	if (lazy[rt]) pushdown(rt);
	int mid = (l + r) >> 1;
	if (tree[rt<<1] == 0)
		query(l,mid,x,rt<<1);
	if (tree[rt<<1|1] == 0)
		query(mid+1,r,x,rt<<1|1);
	tree[rt] = min(tree[rt<<1],tree[rt<<1|1]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n = read();
	for (int i = 1;i <= n;++i){
		map[i] = read();
		sum += map[i];
	}
		
//	scanf("%d",&n);
//	for (int i = 1;i <= n;++i){
//		scanf("%d",&map[i]);
//		sum += map[i];
//	}
	sum = max((long long)100000007,sum);
	
	build(1,n,1);
	
	query(1,n,0,1);
	for (int i = 1;i <= num;++i)
		q.push(zero[i]);
	while (num < n){
		int l=n+1,r;
		while (!q.empty()){
			r = l-1;
			l = q.top();
			q.pop();
			if (l+1 > r) continue;
			ans ++;
			update(1,n,l+1,r,1);
		}
		if (l - 1 >= 1){
			update(1,n,1,l-1,1);
			ans ++;		
		}		
		query(1,n,0,1);					
		for (int i = 1;i <= num;++i)
			q.push(zero[i]);
	}
	
	printf("%lld\n",ans);
	return 0;
}
