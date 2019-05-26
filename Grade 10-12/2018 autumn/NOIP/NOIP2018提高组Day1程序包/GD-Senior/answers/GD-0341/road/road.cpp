#include<iostream>
#include<cstdio>
#include<cstring>
#include<cctype>
#include<algorithm>
#include<cstdlib>
#define go(i,a,b) for(register int i=(a);i<=(b);++i)
using namespace std;
typedef long long ll;
const int N=1e5+3;
inline int min(int a,int b) {return a<b?a:b;}
inline int read(int& x) {
	bool f=0;char c;
	for(;!isdigit(c=getchar());f|=(c=='-'));
	for(x=0;isdigit(c);c=getchar()) x=x*10+(c^48);
	return x=(f?-x:x);
}
int n,a[N];
ll ans=0;
ll solve(int l,int r) {
	if(l>r) return 0;
	if(l==r) {int tmp=a[l];a[l]=0;return tmp;}
	ll res=0;int mn=10001;
	go(i,l,r) mn=min(mn,a[i]);
	res+=mn;
	go(i,l,r) a[i]-=mn;
	int p1=l,p2=l,pos=l;
	for(;p1<=p2 && p2<=r;++p2) {
		if(!a[p2]) {
			res+=solve(p1,p2-1);
			pos=p2;p1=p2=p2+1;
		}
	}
	res+=solve(pos+1,r);
	return res;
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read(n);
	go(i,1,n) read(a[i]);
	ans=solve(1,n);
	cout<<ans;
	return 0;
}
