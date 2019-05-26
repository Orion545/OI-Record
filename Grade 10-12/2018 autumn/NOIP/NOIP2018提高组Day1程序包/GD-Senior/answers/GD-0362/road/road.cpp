#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
const int N=100010;
int a[N];
int fa[N],sum[N];

struct node {
	int x,y,d;
}e[N*2];
bool cmp(node n1,node n2) {
	return n1.d>n2.d;
}
int findfa(int x) {
	if(fa[x]!=x) fa[x]=findfa(fa[x]);
	return fa[x];
}
int main() {
	freopen("road.in","r",stdin); freopen("road.out","w",stdout);
	int n; scanf("%d",&n); memset(a,0,sizeof(a));
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	int len=0;
	for(int i=1;i<n;i++) {
		e[++len]=(node){i,i+1,min(a[i],a[i+1])};
	}
	sort(e+1,e+1+len,cmp); int ans=0;
	for(int i=1;i<=n;i++) { 
		fa[i]=i; sum[i]=a[i];
	}
	for(int i=1;i<=len;i++) {
		int xx=findfa(e[i].x),yy=findfa(e[i].y);
		if(xx!=yy) {
			ans+=abs(sum[xx]-sum[yy]);
			fa[xx]=yy; sum[yy]=min(sum[yy],sum[xx]);
		}
	}
	printf("%d\n",ans+sum[findfa(1)]);
	return 0;
}
