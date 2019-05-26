#include <iostream>
#include <cstdio> 
using namespace std;
int n,m,a[51000][3],ans=0,b[51000];
int zj(int s,int l){
	int l1=0,l2=0,w;
	for(int k=s;a[k][0]!=0;k=a[k][2])
	if(a[k][0]!=l){
		w=zj(a[k][0],s)+a[k][1];
		if(w>=l1){
			l2=l1;l1=w;
		}
		else
		if(w>l2)l2=w;	
	}
	ans=max(ans,l1+l2);
	return l1;
}
void sr(){
	scanf("%d%d",&n,&m);
	int i,j,k,x,y,z,p=n+1;
	if(m==1){
	for(i=1;i<=n;i++)a[i][0]=0;
	for(i=1;i<n;i++){
		scanf("%d%d%d",&x,&y,&z);
		for(j=0;j<=2;j++)a[p][j]=a[x][j];
		a[x][0]=y;
		a[x][1]=z;
		a[x][2]=p;p++;
		for(j=0;j<=2;j++)a[p][j]=a[y][j];
		a[y][0]=x;
		a[y][1]=z;
		a[y][2]=p;p++;
	}	
	zj(1,0);
	printf("%d",ans);
	}
	for(i=1;i<n;i++){
	scanf("%d%d%d",&x,&y,&b[i]);ans+=b[i];	
	}
	return;
}
int cx(int s){
	int i,j=0,k=0;
	for(i=1;i<n;i++){
		j+=b[i];
		if(j>=s){
			j=0;k++;
		}
	}
	return k;
}
void cl(){
	int l=1,r=ans,mid,k;
	while(l+1<r){
		mid=(l+r)/2;
		if(cx(mid)>=m)l=mid;
		else r=mid-1;
	}
	if(cx(r)>=m) printf("%d",r);
	else printf("%d",l);
	return;
}
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	sr();
	if(m!=1) cl();
	return 0;
}
