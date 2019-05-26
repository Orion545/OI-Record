#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<map>
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
ll n,vis[200010],pri[100010],cntp,mark;
map<ll,ll>big;
void init(){
	ll i,j,k;vis[1]=1;
	for(i=2;i<=100000;i++){
		if(!vis[i]){pri[++cntp]=i;big[(ll)i*(ll)i]=i;}
		for(j=1;j<=cntp;j++){
			k=i*pri[j];if(k>100000) break;
			vis[k]=1;
			if(i%pri[j]==0) break;
		}
		if(i==3000) mark=cntp;
	}
}
vector<ll>f1,f2;bool cb=0;
ll cur[100010],inv[100010];
map<ll,ll>s;
void F(ll x,ll num){
	if(x==1){cur[num]=inv[num]=1e15;cb=1;return;}
	ll i,cnt,flag=0;
	f1.clear();f2.clear();
	for(i=1;i<=mark;i++){
		if(x%pri[i]) continue;
		cnt=0;
		while(x%pri[i]==0) cnt++,x/=pri[i];
		if(cnt%3==1) f1.push_back(pri[i]),flag=1;
		if(cnt%3==2) f2.push_back(pri[i]),flag=1;
	}
//	cout<<"mid "<<x<<' '<<num<<'\n';
	if(x!=1){
		flag=1;
		if(big.count(x)) f2.push_back(big[x]);
		else f1.push_back(x);
	}
//	cout<<"kkk "<<flag<<' '<<f1.size()<<' '<<f2.size()<<'\n';
	if(!flag){cur[num]=inv[num]=1e15;cb=1;return;}
	ll rer=1,rel=1;
	for(auto i:f1) rer*=(i*i),rel*=i;
	for(auto i:f2) rer*=i,rel*=(i*i);
	if(s.count(rel)) s[rel]++;
	else s[rel]=1;
	cur[num]=rel;inv[num]=rer;
//	cout<<"final "<<num<<' '<<cur[num]<<' '<<inv[num]<<'\n';
}
ll rk[100010];
inline bool cmp(ll l,ll r){
	return cur[l]<cur[r];
}
int main(){
	init();
	n=read();ll i,tmp,j,de=0,tot=0;
	for(i=1;i<=n;i++){
		tmp=read();
		F(tmp,i);rk[i]=i;
	}
	sort(rk+1,rk+n+1,cmp);
	for(j=1;j<=n;j++){
//		cout<<j<<' '<<rk[j]<<' '<<cur[rk[j]]<<' '<<inv[rk[j]]<<'\n';
		if(cur[rk[j]]==1e15) continue;
		tot++;
		if(cur[rk[j]]==cur[rk[j-1]]) continue;
		if(inv[rk[j]]>=cur[rk[j]]&&s.count(inv[rk[j]])){
//			cout<<"add de "<<'\n';
			de+=min(s[cur[rk[j]]],s[inv[rk[j]]]);
		}
	}
	cout<<tot-de+(cb!=0)<<'\n';
}
	
