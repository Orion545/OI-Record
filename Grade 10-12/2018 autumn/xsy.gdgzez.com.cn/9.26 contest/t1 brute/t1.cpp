#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cassert>
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
ll x[10010],y[10010],n,k;
ll sqr(ll x){
	return x*x;
}
int main(){
	ll T=read();
	while(T--){
		n=read();k=read();ll i,j,m,tmp,ans=1e9;
		for(i=0;i<k;i++) x[i]=read(),x[i+k]=x[i];
		for(i=0;i<k;i++) y[i]=read();
		for(m=0;m<k;m++){
			for(i=0;i<n;i++){
				tmp=0;
				for(j=0;j<k;j++){
					tmp+=min(sqr((x[j+m]-(x[m]-i)+n*2)%n-y[j]),sqr(n-abs((x[j+m]-(x[m]-i)+n*2)%n-y[j])));
//					cout<<"start "<<m<<", now "<<j<<' '<<", st position "<<i<<", now pos "<<(x[j+m]-(x[m]-i)+n*2)%n<<' '<<tmp<<'\n'; 
				}
				ans=min(ans,tmp);
			}
		}
		printf("%lld\n",ans);
	}
} 
