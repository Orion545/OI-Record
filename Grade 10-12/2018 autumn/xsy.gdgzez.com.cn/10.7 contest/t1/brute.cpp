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
ll n,k,cur,cnt,tmp;
int calc(ll x){
	ll re=0;
	while(x){
		if(x%10==4||x%10==7) re++;
		x/=10;
	}
	return re;
}
int main(){
	int T=read();
	while(T--){
		n=read();k=read();
		cur=n+1;cnt=1;
			while(cnt>=1&&cnt<=k+1){
				cout<<cnt<<' '<<cur<<'\n';
				if(calc(cur)==calc(n+cnt-1)){
					cnt++;
					if(cnt==k+1) break;
				}
				else{
					cur=cur-cnt+2;cnt=1;
				}
			}
		cout<<cur-cnt+1<<'\n';
	}
}
