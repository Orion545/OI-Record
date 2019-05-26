#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int m,q,x[100010];long long a[500010],ans;
long long flag[500010],band[500010];
void build(int l,int r,int n){
	int mid=(l+r)/2;flag[n]=0;
	if(l!=r){
		build(l,mid,n*2);build(mid+1,r,n*2+1);
		a[n]=a[n*2]+a[n*2+1];
	}
	else a[n]=x[l];
}
void add(int l,int r,int ql,int qr,int ad,int n){
	int mid=(l+r)/2;
	if(l>qr||r<ql) return;
	if(l>=ql&&r<=qr){
		flag[n]+=ad;a[n]+=ad*(r-l+1);band[n]=ad*(r-l+1);return;
	}
	else{
		add(l,mid,ql,qr,ad,n*2);add(mid+1,r,ql,qr,ad,n*2+1);
		a[n]=a[n*2]+a[n*2+1];band[n]=band[n*2]+band[n*2+1];
	}
}
void check(int l,int r,int ql,int qr,int n){
	int mid=(l+r)/2;
	if(l>qr||r<ql) return;
	if(l>=ql&&r<=qr) ans+=a[n];
	else{
		if(flag[n]){
			flag[n*2]+=flag[n];flag[n*2+1]+=flag[n];
			a[n*2]+=flag[n]*(mid-l+1);a[n*2+1]+=flag[n]*(r-mid);
		}
		check(l,mid,ql,qr,n*2);check(mid+1,r,ql,qr,n*2+1);
	}
}
int main(){
	scanf("%d%d",&m,&q);
	for(int i=1;i<=m;i++) scanf("%d",&x[i]);
	build(1,m,1);
	int x1,x2,x3,x4;
	for(int i=1;i<=q;i++){
		cin>>x1>>x2>>x3;
		if(x1==2){
			ans=0;check(1,m,x2,x3,1);printf("%d\n",ans);
		}
		else{
			cin>>x4;memset(band,0,sizeof(band));add(1,m,x2,x3,x4,1);
		}
	}
}
