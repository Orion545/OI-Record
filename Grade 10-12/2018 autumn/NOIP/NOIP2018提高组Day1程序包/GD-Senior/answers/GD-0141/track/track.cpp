#include<iostream>
#include<stdio.h>
using namespace std;
int f[1000001],t[1000001],v[1000001];
int p[1000001];
int kp(int l,int r){
	int mid;
	int l1,r1;
	l1=l;
	r1=r;
	mid=(v[l]+v[r])/2;
	while(l<=r){
		while(v[l]<mid) l++;
		while(v[r]>mid) r--;
		if(l<=r){
		int i;
		i=v[l];v[l]=v[r];v[r]=i;
		i=f[l];f[l]=f[r];f[r]=i;
		i=t[l];t[l]=t[r];t[r]=i;
		l++;
		r--;
		}
	}
	if(l<r1) kp(l,r1);
	if(r>l1) kp(l1,r);
	return 0;
}
int find(int f1,int f2){
	int t1,t2;
	t1=f1;
	t2=f1;
	while(p[f1]!=f1) f1=p[f1];
	//while(p[t1]!=t1) t1=p[t1],p[t1]=f1;
	while(p[f2]!=f2) f2=p[f2];
	//while(p[t2]!=t2) t2=p[t2],p[t2]=f2;
	if(f1==f2) return 1;
	else p[f2]=f1;
	return 0;
}
int main(){
	int s=0;
	freopen("track1.in","r",stdin);
	freopen("track.out","w",stdout);
	int n,m;
	cin>>n>>m;
	//cout<<n;
	for(int i=1;i<n;i++) cin>>f[i]>>t[i]>>v[i];
	for(int i=1;i<=n;i++) p[i]=i; 
	kp(1,n-1);
	//for(int i=1;i<n;i++) cout<<v[i]<<" ";
	for(int i=1;i<n;i++){
		if(find(f[i],t[i])==0)
		s+=v[i];
		//for(int i=1;i<=n;i++) cout<<p[i]<<" ";
		//cout<<endl;
	}
	cout<<s;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
