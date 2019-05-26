#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<vector>
#include<map>
#include<queue>
#include<set>
using namespace std;
#define ll long long
inline ll read() {
	ll x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9') { if(f=='-') f=-f; ch=getchar(); }
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*f;
}
#define _ read()
const int N=1e5+5;
int n,d[N],mn[N<<2];
#define lson (rt<<1)
#define rson ((rt<<1)|1)
inline void up(int rt) { mn[rt]=(d[mn[lson]]<=d[mn[rson]])?mn[lson]:mn[rson]; } //如果左子树所代表的区间0的最小值比右子树所代表的区间的最小值小，那最小值在左子树所代表的区间，反之在右子树所代表的区间 
inline void build(int l,int r,int rt) { 
	if(l==r) { mn[rt]=l; return; } //如果是叶子节点，直接返回 
	int mid=(l+r)>>1;
	build(l,mid,lson); build(mid+1,r,rson); //统计左右子树的最小值所在的位置 
	up(rt);
}
inline int ask(int L,int R,int l,int r,int rt) { //L..R区间的最小值的下标是什么 
	if(L<=l&&r<=R) return mn[rt];
	int res=2e9,mid=(l+r)>>1,now=0,ans=0;
	if(L<=mid) { now=ask(L,R,l,mid,lson);  if(d[now]<=res) { res=d[now]; ans=now; } }//如果左子树的答案比res小，那L..R的最小值可能在左子树 
	if(R>mid) { now=ask(L,R,mid+1,r,rson); if(d[now]<=res) { res=d[now]; ans=now; } }//如果右子树的答案比res小，那L..R的最小值可能在右子树 
	return ans; 
}
inline ll solve(int l,int r,long long tag) { //tag为区间[l,r],应该减去多少，但是不实际修改 
	if(l>=r) return d[l]-tag; 
	int pos=ask(l,r,1,n,1);
	ll ans=0ll;
	if(l<=pos-1) ans+=solve(l,pos-1,d[pos]); //对[l,pos-1]打标记 
	if(pos+1<=r) ans+=solve(pos+1,r,d[pos]); //对[pos+1,r]打标记 
	return ans-tag+d[pos]; //答案加上当前区间的最小值减去标记上的值,标记:整个区间被减了多少,大概是标记永久化 
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) 
		scanf("%d",&d[i]);
	build(1,n,1);
	printf("%lld\n",solve(1,n,0ll));
}
