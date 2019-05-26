#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
#include<vector>
#define mp make_pair
#define MOD 1000000007
#define ll long long
using namespace std;
inline int read(){
	int re=0,flag=1;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(isdigit(ch)) re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
inline ll qpow(ll a,ll b){
	ll re=1;
	while(b){
		if(b&1) re=re*a%MOD;
		a=a*a%MOD;b>>=1;
	}
	return re;
}
int n,m,c[100010];
inline ll calc(ll minn,int len){
	if(!len) return 1ll;
	static ll dp[100010];
	int i;ll pw=qpow(minn,m-1);
	dp[0]=1;dp[1]=1;
	for(i=2;i<=len+1;i++){
		if(i-m-1<0) dp[i]=(minn+1)*dp[i-1]%MOD;
		else dp[i]=(dp[i-1]+minn*((dp[i-1]-pw*dp[i-m-1]%MOD+MOD)%MOD))%MOD;
	}
//	cout<<"	calc "<<minn<<' '<<len<<' '<<m<<' '<<pw<<' '<<dp[len+1]<<'\n';
	return dp[len+1];
}
vector<pair<int,int> >lis;
int main(){
	freopen("tracking2.in","r",stdin);
	freopen("tracking2.out","w",stdout); 
	n=read();m=read();int i,t1,t2;
	for(i=1;i<=n-m+1;i++) c[i]=read();
	t1=c[1],t2=1;
	for(i=2;i<=n-m+1;i++){
		if(t1!=c[i]){
			lis.push_back(mp(t1,i-t2));
			t1=c[i];t2=i;
		}
	}
	lis.push_back(mp(t1,n-m+1-t2+1));
	if(lis.size()==1){
		cout<<calc(1e9-lis[0].first,n)<<'\n';
		return 0;
	}
	ll ans=1;
	for(i=0;i<lis.size();i++){
		if(i==0){
			if(lis[0].first<lis[1].first) t1=lis[0].second-1;
			else t1=lis[0].second+m-1;
		}
		else if(i==lis.size()-1){
			if(lis[i].first<lis[i-1].first) t1=lis[i].second-1;
			else t1=lis[i].second+m-1;
		}
		else{
			if(lis[i].first<lis[i-1].first){
				if(lis[i].first<lis[i+1].first) t1=max(0,lis[i].second-m-1);
				else t1=lis[i].second-1;
			}
			else{
				if(lis[i].first>lis[i+1].first) t1=lis[i].second+m-1;
				else t1=lis[i].second-1;
			}
		}
		ans=ans*calc(1e9-lis[i].first,t1)%MOD;
//		cout<<i<<' '<<lis[i].first<<' '<<lis[i].second<<' '<<t1<<' '<<ans<<'\n';
	}
	cout<<ans<<'\n';
}
