#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cassert>
#include<set>
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
set<ll>s,ss;
ll x[2000010],y[2000010],cnt1=0,cnt2=0;
int main(){
	ll T=read(),n,i,j,lim,times=0;
	for(j=3;j<=64;j++){
		lim=((ll)pow((long double)1e18,1.0/(long double)(j)));
		if(j==9) lim++;
// 		cout<<j<<' '<<lim<<'\n';
		for(i=2;i<=lim;i++){
			s.insert((ll)((long double)pow((long double)i,(long double)j)));
			if(j%2==0) ss.insert((ll)((long double)pow((long double)i,(long double)j)));
		}
	}
	set<ll>::iterator it;
	for(it=s.begin();it!=s.end();it++) x[++cnt1]=(*it); 
	for(it=ss.begin();it!=ss.end();it++) y[++cnt2]=(*it); 
// 	cout<<cnt1<<' '<<x[cnt1]<<' '<<x[1]<<'\n';
	while(T--){
		n=read();times++;
//		if(times==1059) cout<<n<<'\n';
		ll len3=upper_bound(x+1,x+cnt1+1,n)-x-1;
		ll tmp=sqrt((long double)n);
		ll len2=upper_bound(y+1,y+cnt2+1,n)-y-1;
		len2=tmp-1-len2;
// 		if(times==1059) cout<<len3<<'\n';
//		cout<<len3<<'\n';
		cout<<n-len3-len2-1<<'\n';
	}
}
/*
1
1000000000000000000

1
999999999999999999

*/
