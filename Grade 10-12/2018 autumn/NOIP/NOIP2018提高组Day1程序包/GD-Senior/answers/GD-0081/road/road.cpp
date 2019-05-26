#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>
#include<cstring>
#include<queue>
using namespace std;
#define rep(i,j,k) for(int i=j;i<=k;++i)
typedef long long ll;
char cch;
inline int rd(){
	int x=0,fl=1;
	cch=getchar();
	while(cch>'9'||cch<'0'){
		if(cch=='-') fl=-1;cch=getchar();
	}
	while(cch>='0'&&cch<='9') x=(x<<1)+(x<<3)+cch-'0',cch=getchar();
	return fl*x;
}
const int N=1e5+100;
int ans,mn[N<<2],a[N],n;
void build(int l,int r,int o){
	if(l==r){
		mn[o]=l;return;
	}
	int mid=l+r>>1,ls=o<<1,rs=o<<1|1;
	build(l,mid,ls),build(mid+1,r,rs);
	if(a[mn[ls]]<a[mn[rs]]) mn[o]=mn[ls];
	else mn[o]=mn[rs];
}
int get(int l,int r,int o,int ql,int qr){
	if(l>=ql&&r<=qr){
		return mn[o];
	}
	int mid=l+r>>1,lv=0,rv=0;
	if(ql<=mid) lv=get(l,mid,o<<1,ql,qr);
	if(qr>mid) rv=get(mid+1,r,o<<1|1,ql,qr);
	if(!lv) return rv;
	if(!rv) return lv;
	if(a[lv]<a[rv]) return lv;
	return rv;
}
void qry(int l,int r,int val){
	if(l>r) return;
	int t=get(1,n,1,l,r);
	int tmp=a[t]-val;
	ans+=tmp;
	qry(l,t-1,val+tmp),qry(t+1,r,val+tmp);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=rd();
	rep(i,1,n) a[i]=rd();
	build(1,n,1);
	qry(1,n,0);
	printf("%d",ans);
}
/*
6
4 3 2 5 3 5
*/
