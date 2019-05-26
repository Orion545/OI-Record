#include <iostream>
#include <cstdio>
using namespace std;
const int N=1e5+10;
int n,a[N],b[N],t[4*N],list[N],ans;

void Build(int x,int l,int r) {
	if (l==r) {
		t[x]=a[l];
		return;
	}
	int mid=l+r>>1;
	Build(x<<1,l,mid);
	Build((x<<1)+1,mid+1,r);
	t[x]=min(t[x<<1],t[(x<<1)+1]);
}

int Query(int x,int l,int r,int ll,int rr) {
	if (l>rr||ll>r) return 2147483647;
	if (ll<=l&&r<=rr) return t[x];
	int mid=l+r>>1,x1=2147483647,x2=2147483647;
	if (ll<=mid) x1=Query(x<<1,l,mid,ll,rr);
	if (mid<rr) x2=Query((x<<1)+1,mid+1,r,ll,rr);
	return min(x1,x2);
}

void Solve(int l,int r,int delta) {
	if (l>r) return;
	int mx=Query(1,1,n,l,r),j=list[mx];
	ans+=mx-delta;
	if (l==r) return;
	for (;b[j]&&b[j]>r&&b[j]>=l;j=b[j]);if (b[j]>=l) j=b[j];
	Solve(j+1,r,mx);
	for (;b[j]&&b[j]>=l;j=b[j]) Solve(b[j]+1,j-1,mx);
	Solve(l,j-1,mx);
}

int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;++i) scanf("%d",&a[i]),b[i]=list[a[i]],list[a[i]]=i;
	Build(1,1,n);
	Solve(1,n,0);
	printf("%d",ans);
	fclose(stdin);fclose(stdout);
	return 0;
}
