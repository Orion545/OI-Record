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
ll n,cnt1[100010],cnt2[100010];
int main(){
	n=read();ll i,t1;
	for(i=1;i<=n;i++){
		t1=read();
		if(i&1) cnt1[t1]++;
		else cnt2[t1]++;
	}
	ll maxn=0,pos;
	for(i=1;i<=100000;i++){
		if(maxn<=cnt1[i]) maxn=cnt1[i],pos=i;
	}
	ll ans=n/2-maxn,ppos=pos,mm=maxn;
	maxn=0;pos=0;
	for(i=1;i<=100000;i++){
		if(maxn<=cnt2[i]) maxn=cnt2[i],pos=i;
	}
	if(pos==ppos){
//			cout<<"c\n";
		ll ans1=0,ans2=0,mmm=maxn;
//		if(mm>maxn){
			//change 2
//			cout<<"c2\n";
			maxn=0;pos=0;
			for(i=1;i<=100000;i++){
				if(i!=ppos&&maxn<cnt2[i]) maxn=cnt2[i];
			}
			ans+=n/2-maxn;
			ans1=ans;
//		}
//		else{
			// change 1
			ans=n/2-mmm;
			maxn=0;pos=0;
			for(i=1;i<=100000;i++){
				if(i!=ppos&&maxn<cnt1[i]) maxn=cnt1[i];
			}
//			cout<<"c1 "<<maxn<<'\n';
			ans+=n/2-maxn; 
			ans2=ans;
//		}
		ans=min(ans1,ans2);
	}
	else ans+=n/2-maxn;
	cout<<ans<<'\n';
} 
