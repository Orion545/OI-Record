#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
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
ll MOD=1e9+7;
struct query{
	ll pos,type;
}q[100010];
bool cmp(query l,query r){
	if(l.pos!=r.pos) return l.pos<r.pos;
	else return l.type<r.type;
}
ll n,m,Q,ans=1;
ll qpow(ll a,ll b){
	ll re=1;
	while(b){
		if(b&1) re=re*a%MOD;
		a=a*a%MOD;b>>=1;
	}
	return re;
}
vector<ll>s;
int main(){
	n=read();m=read();Q=read();ll i,j,tmp,inv2=qpow(2,MOD-2);
	ll S=(n*(n+1))%MOD*inv2%MOD;
	for(i=1;i<=Q;i++) q[i].pos=read(),q[i].type=read();
	sort(q+1,q+Q+1,cmp);
	for(i=1;i<=Q;i=j){
		j=i;s.push_back(0);
		tmp=s.size()-1;
		while(q[j].pos==q[i].pos){
			if(i==j||q[j].type!=q[j-1].type) s[tmp]+=q[j].type;
			j++;
		}
	}
	ans=qpow(S,m-s.size());
//	cout<<ans<<'\n';
	for(i=0;i<s.size();i++){
		tmp=S-(s[i]%MOD)+MOD;tmp%=MOD;
		ans=ans*tmp%MOD;
//		cout<<ans<<' '<<tmp<<' '<<s[i]<<'\n';
	}
	printf("%lld\n",ans);
}
