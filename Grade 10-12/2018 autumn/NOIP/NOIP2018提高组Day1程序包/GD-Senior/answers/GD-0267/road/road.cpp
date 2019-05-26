#include<bits/stdc++.h>
#define mid ((l+r)>>1)
#define ls (o<<1),l,mid
#define rs (o<<1|1),mid+1,r
using namespace std;
int a[100005],ans,n;
struct pnt{
	int lc,vl;
}tr[600100],inf=(pnt){-1,1000000};

void add(int o,int l,int r,int p,pnt v){
	if(tr[o].vl>v.vl) tr[o]=v;
	if(l==r) return;
	if(p<=mid) add(ls,p,v);
	else add(rs,p,v);
}

pnt qr(int o,int l,int r,int x,int y){
	if(l>=x && r<=y) return tr[o];
	pnt p1=inf,p2=inf;
	if(x<=mid) p1=qr(ls,x,y);
	if(y>mid) p2=qr(rs,x,y);
	if(p1.vl<p2.vl) return p1;
	return p2;
}

void dfs(int l,int r,int lst){
	if(l==r) {
		ans+=a[l]-lst;
		return;
	}
	pnt mn=qr(1,1,n,l,r);
	ans+=mn.vl-lst;
	if(mn.lc>l) dfs(l,mn.lc-1,mn.vl);
	if(mn.lc<r) dfs(mn.lc+1,r,mn.vl);
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	memset(tr,0x3f,sizeof(tr));
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),add(1,1,n,i,(pnt){i,a[i]});
	dfs(1,n,0);
	printf("%d\n",ans);
}
/*
6
4 3 2 5 3 5
*/
