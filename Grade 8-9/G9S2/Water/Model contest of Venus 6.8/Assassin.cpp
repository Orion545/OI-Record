#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
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
ll n,k,a[1010];
bool check(ll x){
	ll cur=a[1]+x,i,sum=0;
	for(i=2;i<=n;i++){
		if(cur<=a[i]) sum++,cur+=x;
	}
	cout<<"check "<<x<<' '<<sum<<'\n';
	return sum>=k;
}
int main(){
//	freopen("Rider.in","r",stdin);
//	freopen("Rider.out","w",stdout);
	n=read();k=read();k--;ll i;
	for(i=1;i<=n;i++){
		double t1;scanf("%lf",&t1);a[i]=t1*100.0;
	}
	ll l=0,r=1e15,mid;
	while(l<r){
		mid=(l+r)>>1;mid++;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	printf("%.2lf",((double)l)/100.0);
}

