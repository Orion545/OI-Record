#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cassert>
#define ll long long
#define MOD 998244353
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
ll n,m,cnt=0;
struct node{
	ll x,y,val,num,sum,sqr,dp;
}a[1000010];
inline bool cmp(node l,node r){
	return l.val>r.val;
}
ll sq(ll x){
	return x*x%MOD;
}
ll qpow(ll a,ll b){
	ll re=1;
	while(b){
		if(b&1) re=re*a%MOD;
		a=a*a%MOD;b>>=1;
	}
	return re;
}
ll pres[1000010],preq[1000010],predp[1000010];
int main(){
	n=read();m=read();ll i,j,r,c;
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			cnt++;
			a[cnt].val=read();
			a[cnt].x=i;a[cnt].y=j;
		}
	}
	r=read();c=read();
	sort(a+1,a+cnt+1,cmp);
	for(i=1;i<=cnt;i++){
		if(a[i].x==r&&a[i].y==c) break;
	}
	ll st=i;
	ll ans=0,way=0;
	
	
	a[st].num=0;
	i=j=st;
	for(i=1;i<=cnt;i++) pres[i]=(pres[i-1]+a[i].x)%MOD,preq[i]=(preq[i-1]+sq(a[i].x))%MOD;
	for(i=st+1;i<=cnt;i++){
		a[i].num=a[i-1].num,a[i].sum=a[i-1].sum,a[i].sqr=a[i-1].sqr;a[i].dp=a[j-1].dp;
		if(a[i].val!=a[i-1].val){
			a[i].num=(a[i].num+((j==st)?1:a[j].num)*(i-j))%MOD;
			a[i].sum=(a[i].sum+(pres[i-1]-pres[j-1]+MOD)*((j==st)?1:a[j].num)%MOD)%MOD;
//			(a[i].sum*=a[i].num)%=MOD;
			a[i].sqr=(a[i].sqr+(preq[i-1]-preq[j-1]+MOD)*((j==st)?1:a[j].num)%MOD)%MOD;
//			(a[i].sqr*=a[i].num)%=MOD;
			a[i].dp=(a[i].dp+(predp[i-1]-predp[j-1]+MOD))%MOD;
			j=i;
		}
		(a[i].dp+=(a[i].num*sq(a[i].x)%MOD-2*a[i].x*a[i].sum%MOD+a[i].sqr+MOD))%=MOD;
		cout<<"dp x "<<a[i].num<<' '<<a[i].sum<<' '<<a[i].sqr<<' '<<a[i].dp<<' '<<j<<' '<<i<<'\n';
		predp[i]=(predp[i-1]+a[i].dp)%MOD;
	}
	for(i=cnt;a[i].val==a[cnt].val;i--) (ans+=a[i].dp)%=MOD,(way+=a[i].num)%=MOD;
	
	
	a[st].num=0;
	i=j=st;
	for(i=st;i<=cnt;i++) pres[i]=(pres[i-1]+a[i].y)%MOD,preq[i]=(preq[i-1]+sq(a[i].y))%MOD;
	for(i=st+1;i<=cnt;i++){
		a[i].num=a[i-1].num,a[i].sum=a[i-1].sum,a[i].sqr=a[i-1].sqr;a[i].dp=a[j-1].dp;
		if(a[i].val!=a[i-1].val){
			a[i].num=(a[i].num+((j==st)?1:a[j].num)*(i-j))%MOD;
			a[i].sum=(a[i].sum+(pres[i-1]-pres[j-1]+MOD)*((j==st)?1:a[j].num)%MOD)%MOD;
//			(a[i].sum*=a[i].num)%=MOD;
			a[i].sqr=(a[i].sqr+(preq[i-1]-preq[j-1]+MOD)*((j==st)?1:a[j].num)%MOD)%MOD;
//			(a[i].sqr*=a[i].num)%=MOD;
			a[i].dp=(a[i].dp+(predp[i-1]-predp[j-1]+MOD))%MOD;
			j=i;
		}
		(a[i].dp+=(a[i].num*sq(a[i].y)%MOD-2*a[i].y*a[i].sum%MOD+a[i].sqr+MOD))%=MOD;
		cout<<"dp y "<<a[i].num<<' '<<a[i].sum<<' '<<a[i].sqr<<' '<<a[i].dp<<' '<<j<<' '<<i<<' '<<a[i].x<<' '<<a[i].y<<'\n';
		predp[i]=(predp[i-1]+a[i].dp)%MOD;
	}
	for(i=cnt;a[i].val==a[cnt].val;i--) (ans+=a[i].dp)%=MOD;
	
	
	cout<<ans<<' '<<way<<'\n';
	cout<<665496238ll*8ll%MOD<<'\n';
	cout<<ans*qpow(way,MOD-2)%MOD<<'\n';
}
