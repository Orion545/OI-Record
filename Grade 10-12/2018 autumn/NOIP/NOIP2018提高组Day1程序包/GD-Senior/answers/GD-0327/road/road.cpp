#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#define fo(i,a,b) for(i=a;i<=b;i++)

using namespace std;

const int maxn=1e5+5;

int tree[maxn*7];
int a[maxn],i,j,k,l,n,ans,h;

void maketree(int v,int l,int r){
	if (l==r){
		tree[v]=l; return;
	}
	int mid=(l+r)/2;
	maketree(v*2,l,mid);
	maketree(v*2+1,mid+1,r);
	if (a[tree[v*2]]<=a[tree[v*2+1]]) tree[v]=tree[v*2]; else tree[v]=tree[v*2+1];
}

void find(int v,int l,int r,int x,int y){
	if (l==x && r==y){
		if (a[h]>a[tree[v]]) h=tree[v]; return;
	}
	int mid=(l+r)/2;
	if (y<=mid) find(v*2,l,mid,x,y); else
	if (x>mid) find(v*2+1,mid+1,r,x,y); else{
		find(v*2,l,mid,x,mid);
		find(v*2+1,mid+1,r,mid+1,y);
	}
}
void dfs(int l,int r,int x){
	if (l==r){
		ans=ans+a[l]-x; return;
	}
	int p;
	h=0; find(1,1,n,l,r);
	p=h;
	ans=ans+a[p]-x;
	if (p!=l) dfs(l,p-1,a[p]);
	if (p!=r) dfs(p+1,r,a[p]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	fo(i,1,n) scanf("%d",&a[i]);
	a[0]=1000000;
	maketree(1,1,n);
	dfs(1,n,0);
	printf("%d\n",ans);
	return 0;
}
