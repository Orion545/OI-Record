#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
#define MOD 1000000007
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
int n;ll Q,A,B,C;
int vis[10000010],cnt;
ll pri[10000010],sigma[10000010],sqr[10000010],mi[10000010];
ll sq(ll x){
	return x*x%MOD;
}
void init(){
	ll i,j,k;sigma[1]=mi[1]=sqr[1]=1;
	for(i=2;i<=C;i++){
		if(!vis[i]){
			pri[++cnt]=i;
			sigma[i]=2;
			sqr[i]=(i*i+1)%MOD;
			mi[i]=i;
		}
		for(j=1;j<=cnt;j++){
			k=i*pri[j];if(k>C) break;
			vis[k]=1;
			if(i%pri[j]==0){
				mi[k]=mi[i]*pri[j]%MOD;
				sigma[k]=(sigma[i]+sigma[i/mi[i]])%MOD;
				sqr[k]=(sqr[i]+sqr[i/mi[i]]*sq(mi[k])%MOD)%MOD;
				break;
			}
			sigma[k]=sigma[i]*sigma[pri[j]]%MOD;
			sqr[k]=sqr[i]*sqr[pri[j]]%MOD;
			mi[k]=pri[j];
		}
//		cout<<i<<' '<<sigma[i]<<' '<<sqr[i]<<'\n';
	}
}
ll ans1,ans2;
int main(){
	n=read();Q=read();A=read();B=read();C=read();
	init();
	while(n--){
//		cout<<"Q "<<Q<<'\n';
		ans1=(ans1+sigma[Q]+(Q&1))%MOD;
		ans2=(ans2+sqr[Q]+4*(Q&1))%MOD;
		Q=(Q*A+B)%C+1;
	}
	printf("%lld\n%lld\n",ans1,ans2);
}

