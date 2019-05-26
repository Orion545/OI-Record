#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cassert>
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
int n,Q;
namespace brute{
	int seg[1010][4010],lazy[1010][4010];
	void push(int l,int r,int num,int pos){
		if(l==r||!lazy[pos][num]) return;
		int mid=(l+r)>>1;
		seg[pos][num<<1]+=lazy[pos][num]*(mid-l+1);lazy[pos][num<<1]+=lazy[pos][num];
		seg[pos][num<<1|1]+=lazy[pos][num]*(r-mid);lazy[pos][num<<1|1]+=lazy[pos][num];
		lazy[pos][num]=0;
	}
	void change(int l,int r,int ql,int qr,int num,int pos){
//		cout<<"change "<<l<<' '<<r<<' '<<ql<<' '<<qr<<' '<<seg[pos][num]<<endl;
		push(l,r,num,pos);
		if(l>=ql&&r<=qr){
			seg[pos][num]+=(r-l+1);lazy[pos][num]++;return;
		}
		int mid=(l+r)>>1;
		if(mid>=ql) change(l,mid,ql,qr,num<<1,pos);
		if(mid<qr) change(mid+1,r,ql,qr,num<<1|1,pos);
		seg[pos][num]=seg[pos][num<<1]+seg[pos][num<<1|1];
	}
	int query(int l,int r,int ql,int qr,int num,int pos){
//		cout<<"query "<<l<<' '<<r<<' '<<ql<<' '<<qr<<' '<<seg[pos][num]<<endl;
		push(l,r,num,pos);
		if(l>=ql&&r<=qr) return seg[pos][num];
		int mid=(l+r)>>1,re=0;
		if(mid>=ql) re+=query(l,mid,ql,qr,num<<1,pos);
		if(mid<qr) re+=query(mid+1,r,ql,qr,num<<1|1,pos);
		return re;
	}
	void solve(){
		int t1,t2,t3,t4,i;
//		cout<<"BRUTESOLVE"<<endl;
		while(Q--){
			t4=read();t1=read();t2=read();t3=read();
			if(t4==1){
				for(i=0;i<t3;i++) change(1,n,t2,t2+i,1,t1+i);
			}
			else{
				ll re=0;
				for(i=0;i<t3;i++) re+=(ll)query(1,n,t2,t2+i,1,t1+i);
				printf("%lld\n",re);
			}
		}
	}
}
namespace pref{
	int pre[1010][1010];
	void solve(){
		int t1,t2,t3,t4,i,j,flag=0;
		while(Q--){
			t4=read();t1=read();t2=read();t3=read();
			if(t4==2&&!flag){
				flag=1;
				for(i=1;i<=n;i++){
					for(j=1;j<=n;j++){
						pre[i][j]+=pre[i][j-1];
//						cout<<i<<' '<<j<<' '<<pre[i][j]<<'\n'; 
					}
				}
				for(i=1;i<=n;i++){
					for(j=1;j<=n;j++){
						pre[i][j]+=pre[i][j-1];
//						cout<<i<<' '<<j<<' '<<pre[i][j]<<'\n'; 
					}
				}
			}
			if(t4==1){
				for(i=0;i<t3;i++) pre[t1+i][t2]++,pre[t1+i][t2+i+1]--;
			}
			else{
				ll re=0;
				for(i=0;i<t3;i++) re+=pre[t1+i][t2+i]-pre[t1+i][t2-1];
				printf("%lld\n",re);
			}
		}
	}
}
int main(){
	n=read();Q=read();
	if(n<=1000) brute::solve();
	else pref::solve();
}
/*
3 9
2 1 1 2
1 1 1 2
2 1 1 2
1 2 1 2
2 1 1 2
2 2 2 2
1 2 2 2
2 1 1 2
2 1 1 3

3 10
1 1 1 1
1 2 2 1
1 3 3 1
1 3 1 1
1 2 1 1
1 3 2 1
2 1 1 3
2 1 1 2
2 1 1 1
2 2 2 2

*/
