#include <iostream>
#include <cstdio>
using namespace std;
int n,a[101000],x[101000][30];
void ycl(int s,int k){
	int i,w=n-k+1;k/=2;
	for(i=1;i<=w;i++)
	if(a[x[i][s-1]]<a[x[i+k][s-1]]) x[i][s]=x[i][s-1];
	else x[i][s]=x[i+k][s-1];
	return;
}
void sr(){
	int i,j=2;
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d",&a[i]);
	for(i=1;i<=n;i++)x[i][0]=i;
	for(i=1;j<=n;i++){
		ycl(i,j);j*=2;
	}
	return;
}
int cx(int l,int r){
	int i=0,j,k=r-l+1;
	for(j=1;j<=k;j*=2)i++;
	i--;j/=2;
	if(a[x[l][i]]<a[x[r-j+1][i]]) return x[l][i];
	return x[r-j+1][i];
}
int ss(int l,int r,int s){
	if(l>r)return 0;
	int ans,k=cx(l,r);
	ans=a[k]-s+ss(l,k-1,a[k])+ss(k+1,r,a[k]);
	return ans;
}
void cl(){
	printf("%d",ss(1,n,0));
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	sr();
	cl();
	return 0;
}
