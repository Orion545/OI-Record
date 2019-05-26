#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#define ll long long
using namespace std;
inline ll read(){
	ll re=0,flag=1;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(isdigit(ch)) re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
ll n,q;
struct BIT{
	ll a[1010][1010];
	void add(ll x,ll y,ll val){
		ll i,j;
		for(i=x;i<=n+1;i+=(i&(-i))){
			for(j=y;j<=n+1;j+=(j&(-j))){
				a[i][j]^=val;
			}
		}
	}
	ll sum(ll x,ll y){
		ll i,j,re=0;
		for(i=x;i;i^=(i&(-i))){
			for(j=y;j;j^=(j&(-j))){
				re^=a[i][j];
			}
		}
		return re;
	}
}T[2][2];
inline void add(ll x,ll y,ll val){
	T[x&1][y&1].add((x+1)>>1,(y+1)>>1,val);
}
inline ll sum(ll x,ll y){
	return T[x&1][y&1].sum((x+1)>>1,(y+1)>>1);
}
int main(){
	n=read();q=read();ll t1,t2,t3,t4,t5,t6;
	while(q--){
		t6=read();
		if(t6==1){
			t1=read();t2=read();t3=read();t4=read();t5=0;
			t5^=sum(t1-1,t2-1);
			t5^=sum(t1-1,t4);
			t5^=sum(t3,t2-1);
			t5^=sum(t3,t4);
			printf("%lld\n",t5);
		}
		else{
			t1=read();t2=read();t3=read();t4=read();t5=read();
			add(t1,t2,t5);
			add(t1,t4+1,t5);
			add(t3+1,t2,t5);
			add(t3+1,t4+1,t5);
		}
	}
}
