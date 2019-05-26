#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
inline ll read(){
	ll re=0,flag=1;char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
int main(){
	freopen("balance.in","r",stdin);
	freopen("balance.out","w",stdout); 
	ll T=read(),n,i,cur;
	while(T--){
		n=read();
		cur=1;
		for(i=1;i<=64;i++){
			if(cur>n) break;
			cur<<=1;
		}
		printf("%lld\n",i-1);
	}
}
