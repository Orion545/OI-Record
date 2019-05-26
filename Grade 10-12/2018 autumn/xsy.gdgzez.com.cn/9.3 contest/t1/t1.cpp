#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
#define ll long long
inline ll read(){
	ll re=0,flag=1;char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
ll pri[1000010],cntp;bool vis[10000010],sqr[10000010];
void init(){
	ll i,j,k,len=10000000;vis[1]=0;
	for(i=2;i<=len;i++){
		if(!vis[i]) pri[++cntp]=i;
		for(j=1;j<=cntp;j++){
			k=i*pri[j];if(k>len) break;
			vis[k]=1;
			if(sqr[i]) sqr[k]=1;
			if(i%pri[j]==0){sqr[k]=1;break;}
		}
//		if(i<=100) cout<<i<<' '<<vis[i]<<' '<<sqr[i]<<'\n';
	}
}
ll check(ll x){
	if(x==2||x==3||x==4||x==6||x==14) return 1;
	if(x&1||x<14) return 0;
	x>>=1;
	if(x<=10000000) return !vis[x]&&!sqr[x-1];
	ll i;
	for(i=1;i<=cntp&&pri[i]<=sqrt(x);i++) 
		if(x%pri[i]==0||(x-1)%(pri[i]*pri[i])==0) return 0;
	return 1;
}
int main(){
	ll T=read(),x,y;
	init();
	while(T--){
		x=read();y=read();
		
		if(x==1){
			if(y%2) puts("YES");
			else puts("NO");
		}
		if(x==2){
			if(y==1||y==2) puts("YES");
			else puts("NO");
		}
		if(x==3){
			if(check(y)) puts("YES");
			else puts("NO");
		}
	}
}
