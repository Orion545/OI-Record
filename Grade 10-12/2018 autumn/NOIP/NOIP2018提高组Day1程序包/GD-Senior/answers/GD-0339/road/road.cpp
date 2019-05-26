#include<cstdio>
#include<algorithm>
#define N 100010
#define ll long long
using namespace std;
int read(){
	int x=0,flag=1;
	char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') flag=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+(ch^'0');
	return x*flag;
}
struct D{
	int x,idx;
};
int L[N*4],R[N*4],val[N*4],idx[N*4],d[N];
int n;
void build(int x,int l,int r){
	if(l==r)
		idx[x]=l,val[x]=d[l];
	L[x]=l,R[x]=r;
	if(l<r){
		int mid=(l+r)>>1;
		build(x<<1,l,mid);
		build(x<<1|1,mid+1,r);
		if(val[x<<1]<val[x<<1|1])
			val[x]=val[x<<1],idx[x]=idx[x<<1];
		else
			val[x]=val[x<<1|1],idx[x]=idx[x<<1|1];
	}
}
D query(int x,int l,int r){
	D t;
	if(l<=L[x]&&R[x]<=r){
		t.idx=idx[x];
		t.x=val[x];
		return t;
	}
	int inf=99999999;
	D a,b;
	a.idx=0,a.x=inf;
	b.idx=0,b.x=inf;
	int mid=(L[x]+R[x])>>1;
	if(l<=mid)
		a=query(x<<1,l,r);
	if(r>mid)
		b=query(x<<1|1,l,r);
	if(a.x<b.x){
		return a;
	}
	else
		return b;
}
ll Solve(int l,int r,int k){
	if(l==r)
		return d[l]-k;
	D t=query(1,l,r);
	ll res=0;
	res+=d[t.idx]-k;
	if(t.idx-1>=l)
		res+=Solve(l,t.idx-1,d[t.idx]);
	if(t.idx+1<=r)
		res+=Solve(t.idx+1,r,d[t.idx]);
	return res;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)
		d[i]=read();
	build(1,1,n);
	printf("%lld",Solve(1,n,0));
	return 0;
}
