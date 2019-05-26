#include <iostream>
#include <string>
#include <sstream>
#include <cstdio>
using namespace std;
int n,m,a[21000][2],h[21000],h1=0;
string lc[11000];
void sr(){
	scanf("%d%d",&n,&m);
	int i,j,p=n+1,x,y;
	for(i=1;i<=n;i++){
		a[i][0]=0;
	}
	for(i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		a[p][0]=a[x][0];
		a[p][1]=a[x][1];
		a[x][0]=y;
		a[x][1]=p;
		p++;
		a[p][0]=a[y][0];
		a[p][1]=a[y][1];
		a[y][0]=x;
		a[y][1]=p;
		p++;
	}
	return;
}
int bj[1000],lb[1000],lb1,te=0;
void cg(int s){
	int i,j,k,w;
	for(i=s;a[i][0]!=0;i=a[i][1]){
		k=i;
		for(j=a[i][1];a[j][0]!=0;j=a[j][1])
		if(a[k][0]>a[j][0])k=j;
		w=a[i][0];a[i][0]=a[k][0];a[k][0]=w;
	}
	return;
}
int zh(int s,int l){
	if(bj[s]==1) return s;
	if(bj[s]==2) return 0;
	bj[s]=1;int w;
	for(int k=s;a[k][0]!=0;k=a[k][1])
	if(a[k][0]!=l){
		w=zh(a[k][0],s);
		if(w>0){
			h1++;h[h1]=s;
			if(w==s)return 0;return w;
		}
	}
	bj[s]=2;
	return 0;
}
void tx(int s,int l){
	lb1++;lb[lb1]=s;
	for(int k=s;a[k][0]!=0;k=a[k][1])
	if(a[k][0]!=l&&bj[a[k][0]]==0) tx(a[k][0],s);
	return;
}
void cl(){
	int i,j,k,w,s,l,r;
	for(i=1;i<=n;i++) cg(i);
	for(i=1;i<=n;i++)bj[i]=0;
	if(n==m){
	zh(1,0); 
	for(i=1;i<=n;i++)bj[i]=0;
	for(i=1;i<=h1;i++)bj[h[i]]=i;
	}
	tx(1,0);
	for(i=1;i<=lb1;i++)printf("%d ",lb[i]);
	return;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	sr();
	cl();
	return 0;
}
