#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=4e5+5;
struct code{
	int l;int r;int z;
}d[maxn];
int f[maxn],a[maxn],ans,num;
int n,i,t,j,k,l,x,y,z;
void make(int l,int r,int v){
	int mid=(l+r)/2;
	if (l==r){
		f[v]=l;return;
	}
	make(l,mid,v*2);make(mid+1,r,v*2+1);
	f[v]=(a[f[v*2]]>a[f[v*2+1]])?f[v*2+1]:f[v*2];
}
void find(int l,int r,int v,int x,int y){
	if (l>=x && r<=y){
		t=(a[t]>a[f[v]])?f[v]:t;
		return;
	}
	int mid=(l+r)/2;
	if (mid>=x) find(l,mid,v*2,x,y);
	if (mid<y) find(mid+1,r,v*2+1,x,y);
}
int main(){
	freopen("road.in","r",stdin);freopen("road.out","w",stdout);
	scanf("%d",&n);
	for (i=1;i<=n;i++)scanf("%d",&a[i]);a[0]=1e9;
	make(1,n,1);d[j=1].l=1;d[1].r=n;i=0;y=0;
	while (i<j){
		i++;t=0;
		find(1,n,1,d[i].l,d[i].r);ans+=a[t]-d[i].z;
		if (t!=d[i].l) d[++j].l=d[i].l,d[j].r=t-1,d[j].z=a[t];
		if (t!=d[i].r) d[++j].l=t+1,d[j].r=d[i].r,d[j].z=a[t];
	}
	printf("%d\n",ans);
	return 0;
}
