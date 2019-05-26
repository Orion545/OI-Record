#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
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
ll n,K,cnt,a[200010],b[200010],tmp[500010],x[500010],L[200010],R[200010],dp[200010],sum[200010];
void push(ll num){
	if(!x[num]) return;
	x[num<<1]=x[num];
	x[num<<1|1]=x[num];
	x[num]=0;
}
void change(ll l,ll r,ll ql,ll qr,ll num,ll val){
//	cout<<"	change "<<l<<' '<<r<<' '<<ql<<' '<<qr<<' '<<num<<' '<<val<<'\n';
	if(ql>qr) return;
	if(l>=ql&&r<=qr){x[num]=val;return;}
	push(num);
	ll mid=(l+r)>>1;
	if(mid>=ql) change(l,mid,ql,qr,num<<1,val);
	if(mid<qr) change(mid+1,r,ql,qr,num<<1|1,val);
}
ll query(ll l,ll r,ll num,ll pos){
//	cout<<"	query "<<l<<' '<<r<<' '<<num<<' '<<pos<<' '<<x[num]<<'\n';
	if(l==r) return x[num];
	push(num);
	ll mid=(l+r)>>1;
	if(mid>=pos) return query(l,mid,num<<1,pos);
	else return query(mid+1,r,num<<1|1,pos);
}
ll ask(ll pos){
	ll choose=query(1,cnt,1,pos);
//	cout<<"	**** ask "<<pos<<' '<<choose<<'\n';
	if(!choose) return 0;
	return (dp[choose]+(tmp[L[choose]]-tmp[pos]+K)%K);
}
ll erfen(ll val){
	ll l=1,r=cnt,mid;
	while(l<r){
		mid=(l+r)>>1;
		if(tmp[mid]>=val) r=mid;
		else l=mid+1;
	}
//	cout<<"erfen "<<val<<' '<<l<<' '<<tmp[l]<<'\n';
	assert(val==tmp[l]);
	return l;
}
int main(){
	n=read();K=read();ll i;
	for(i=1;i<=n;i++) {
		a[i]=read();b[i]=read();
		sum[i]=(sum[i-1]+a[i]);
//		cout<<"input "<<i<<' '<<a[i]<<' '<<sum[i]<<'\n';
		if(b[i]==2) continue;
		if(2*a[i]>K){
			puts("-1");return 0;
		}
	}
//	cout<<"first input finish\n";
	for(i=n;i>=1;i--){
		if(b[i]==1){
			L[i]=(-2ll*sum[i-1]%K+K)%K;
			R[i]=(-2ll*sum[i]%K+K)%K;
		}
		else L[i]=0,R[i]=K-1;
		tmp[++cnt]=L[i],tmp[++cnt]=R[i];
	}
//	cout<<"second input finish\n";
	sort(tmp+1,tmp+cnt+1);
	cnt=unique(tmp+1,tmp+cnt+1)-tmp-1;
//	for(i=1;i<=cnt;i++) cout<<i<<' '<<tmp[i]<<'\n';
	for(i=n;i>=1;i--){
//		cout<<i<<' '<<L[i]<<' '<<R[i]<<'\n';
		L[i]=erfen(L[i]);
		R[i]=erfen(R[i]);
		dp[i]=ask(L[i]);
//		cout<<"get dp "<<dp[i]<<' '<<L[i]<<' '<<tmp[L[i]]<<' '<<R[i]<<' '<<tmp[R[i]]<<'\n';
		if(L[i]>R[i]) change(1,cnt,R[i]+1,L[i]-1,1,i);
		else change(1,cnt,1,L[i]-1,1,i),change(1,cnt,R[i]+1,cnt,1,i);
	}
	ll ans=dp[1];
	for(i=cnt;i>=1;i--) ans=min(ans,ask(i));
	printf("%lld\n",ans+sum[n]*2ll);
//	cout<<"double check "<<ans<<' '<<sum[n]*2ll<<'\n';
}
