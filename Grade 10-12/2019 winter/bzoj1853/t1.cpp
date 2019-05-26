#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<vector>
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
vector<ll>lis;
ll a[1010],n,L,R,ans=0;
ll gcd(ll a,ll b){
	if(b==0) return a;
	return gcd(b,a%b);
}
ll lcm(ll a,ll b){
	return a/gcd(a,b)*b;
}
void dfs(ll u,ll num,ll val){
	if(val>R) return;
//	cout<<"dfs "<<u<<' '<<num<<' '<<val<<'\n';
	assert(val>=0);
	if(u<1){
		if(!num) return;
		if(num&1) ans+=(R/val)-((L-1)/val);
		else ans-=(R/val)-((L-1)/val);
		return;
	}
	dfs(u-1,num,val);
	ll tmp=val/gcd(val,a[u]);
	if((double)tmp*a[u]<=(double)R) dfs(u-1,num+1,tmp*a[u]);
}
int main(){
	ll i,j,k,flag;ll tmp;
	L=read();R=read();
	for(i=1;i<=10;i++){
		for(j=0;j<(1<<i);j++){
			tmp=0;
			for(k=0;k<i;k++){
				tmp=tmp*10ll;
				if((1<<k)&j) tmp+=8;
				else tmp+=6;
			}
			lis.push_back(tmp);
		}
	}
	sort(lis.begin(),lis.end());
	for(i=0;i<lis.size();i++){
		if(lis[i]>R) break;
//		cout<<"check "<<i<<' '<<lis[i]<<'\n';
		flag=0;
		for(j=1;j<=n;j++) if(lis[i]%a[j]==0) flag=1;
		if(!flag) a[++n]=lis[i];
	}
	dfs(n,0,1);
	cout<<ans<<'\n';
}
