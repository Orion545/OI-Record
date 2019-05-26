#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
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
int n,m,c,t[100010];
bool check(int lim){
	int i,j,re=1;
	for(i=1,j=1;i<=n;i++){
		if(t[i]-t[j]>lim||(i-j>=c)) j=i,re++;
//		cout<<i<<' '<<j<<' '<<(i-j>=c)<<' '<<re<<'\n';
	}
//	cout<<"finish "<<lim<<' '<<re<<' '<<m<<' '<<c<<'\n';
	return re<=m;
}
int main(){
	freopen("convention.in","r",stdin);
	freopen("convention.out","w",stdout);
	n=read();m=read();c=read();int i,l,r,mid;
	for(i=1;i<=n;i++) t[i]=read();
	sort(t+1,t+n+1);
	l=0,r=1e9;
	while(l<r){
		mid=(l+r)>>1;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	cout<<l<<'\n';
}
