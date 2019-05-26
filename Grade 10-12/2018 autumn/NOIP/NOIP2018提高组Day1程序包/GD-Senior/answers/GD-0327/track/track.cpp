#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#define fo(i,a,b) for(i=a;i<=b;i++)
#define fo1(i,b,a) for(i=b;i>=a;i--)

using namespace std;

const int maxn=50005;

int fi[maxn],ne[maxn*2],dui[maxn*2],dui1[maxn*2],qc[maxn];
int f[maxn],g[maxn],c[maxn];
bool bz[maxn];
int i,j,k,t,l,r,mid,m,n,x,y,z,nc;

int cmp(int x,int y){
	return x<y;
}
void add(int x,int y,int z){
	if (fi[x]==0) fi[x]=++nc; else ne[qc[x]]=++nc;
	qc[x]=nc; dui[nc]=y; dui1[nc]=z;
}

void dfs(int x,int y){
	int i;
	for(i=fi[x];i;i=ne[i])if (dui[i]!=y){
		dfs(dui[i],x);
	}
	int z=0;
	for(i=fi[x];i;i=ne[i])if (dui[i]!=y){
		f[x]=f[x]+f[dui[i]]; c[++z]=g[dui[i]]+dui1[i]; bz[z]=false;
	}
	sort(c+1,c+z+1,cmp);
	int l=1,r=z,midd=0,ft,fx=0,l1,r1;
	while (c[r]>=mid && r>0){
		f[x]++; bz[r]=true; r--; z--;
	}
	c[0]=0;
	while (l<r){
		if (c[l]+c[r]>=mid){
			bz[l]=true; bz[r]=true; f[x]++; fx++; r--;
		}
		l++;
	}
	l=0; r=z;
	while (l<r){
		midd=(l+r)/2;
		fo(i,0,z) bz[i]=false; bz[midd]=true;
		ft=0;
		l1=1; r1=z;
		while (l1<r1){
			if (c[l1]+c[r1]>=mid && bz[l1]==false && bz[r1]==false){
				bz[l1]=true; bz[r1]=true; while (bz[r1]==true && r1>0) r1--; ft++;
			}
			l1++;
		}
		if (ft==fx) l=midd+1; else r=midd;
	}
	fo(i,0,z) bz[i]=false; bz[l]=true;
	ft=0;
	l1=1; r1=z;
	if (bz[r1]==true) r1--;
	while (l1<r1){
		if (c[l1]+c[r1]>=mid && bz[l1]==false && bz[r1]==false){
			bz[l1]=true; bz[r1]=true; while (bz[r1]==true && r1>0) r1--; ft++;
		}
		l1++;
	}
	if (ft!=fx) l--;
	g[x]=c[l];
}
void dp(){
	memset(f,0,sizeof(f));
	memset(g,0,sizeof(g));
	dfs(1,0);
}
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	r=0; nc=0;
	fo(i,1,n-1){
		scanf("%d%d%d",&x,&y,&z);
		r=r+z;
		add(x,y,z);
		add(y,x,z);
	}
	l=1;
	while (l<r){
		mid=(l+r)/2;
		dp();
		if (f[1]>=m) l=mid+1; else r=mid;
	}
	mid=l;
	dp();
	if (f[1]<m) l--;
	printf("%d\n",l);
	return 0;
}
