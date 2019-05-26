#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define ll long long
using namespace std;
inline int read(){
	int re=0,flag=1;char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag; 
}
int n,m;
ll a[1200010],cnt=0,x[300010];
bool lazy[1200010]={0};
//vector<int>pri;
//void init(){
//    int i,j;p[1]=1;
//    for(i=2;i<=1000000;i++){
//        if(!p[i]) pri.push_back(i),cnt++;
//        for(j=0;j<pri.size()&&i*pri[j]<=1000000;j++){
//            p[i*pri[j]]=1;
//            if(!i%pri[j]) break; 
//        }
//    }
//}
//int Cnt(int x){
//	int re=1,i,j;
//	if(x==1) return 1;
//	if(!p[x]) return 2;
//	for(i=0;pri[i]<=x&&i<cnt;i++){
//		j=1;
//		while(x%pri[i]==0) j++,x/=pri[i];
//		re*=j;
////		cout<<"cnt "<<pri[i]<<ends<<j<<endl;
//	}
//	return re;
//}
int c[1000010];
void build(int l,int r,int num){
	int mid=(l+r)>>1,son=num<<1;
	if(l==r){
		a[num]=x[l];lazy[num]=(a[num]==1);
		return;
	}
	build(l,mid,son);build(mid+1,r,son+1);
	a[num]=a[son]+a[son+1];lazy[num]=(a[num]==(r-l+1));
	return;
}
ll query(int l,int r,int ql,int qr,int num){
//	cout<<"query "<<l<<ends<<r<<ends<<ql<<ends<<qr<<ends<<a[num]<<endl;
	int mid=(l+r)>>1,son=num<<1,re=0;
	if(l>=ql&&r<=qr) return a[num];
	if(mid>=ql) re+=query(l,mid,ql,qr,son);
	if(mid<qr) re+=query(mid+1,r,ql,qr,son+1);
	return re;
}
void change(int l,int r,int ql,int qr,int num){
//	cout<<"change "<<l<<ends<<r<<ends<<ql<<ends<<qr<<ends<<a[num]<<endl;
	int mid=(l+r)>>1,son=num<<1;
	if(lazy[num]) return;
	if(l==r){
		a[num]=c[a[num]];lazy[num]=(a[num]==1);
		return;
	} 
	if(mid>=ql) change(l,mid,ql,qr,son);
	if(mid<qr) change(mid+1,r,ql,qr,son+1);
	a[num]=a[son]+a[son+1];lazy[num]=(a[num]==(r-l+1));
}
int main(){
	int i,t1=0,t2,t3,j;
//	init();//cout<<cnt<<endl;
////	for(i=1;i<=20;i++) cout<<p[i];cout<<endl;
////	for(i=1;i<=20;i++) cout<<i<<ends<<Cnt(i)<<endl;
//	for(i=1;i<=1000000;i++){
//		c[i]=Cnt(i);
//		if(i%100000==0) cout<<i<<endl;
//	}
//	cout<<"init"<<endl;
	for(i=1;i<=1000000;i++){
		for(j=i;j<=1000000;j+=i) c[j]++;
	}
//	cout<<"init"<<endl;
	n=read();m=read();
	for(i=1;i<=n;i++) x[i]=read();
	build(1,n,1);
	for(i=1;i<=m;i++){
		t1=read();t2=read();t3=read();
		if(t1==1) change(1,n,t2,t3,1);
		else printf("%I64d\n",query(1,n,t2,t3,1));
	}
} 
