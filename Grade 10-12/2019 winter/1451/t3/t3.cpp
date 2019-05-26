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
int n,a[100010],ans,lim,al[4000010],ar[4000010];
int solve2(int l,int r){
	if(l==r) return a[l]>lim?l:l+1;
	int mid=(l+r)>>1,tl,tr;
	tl=solve2(l,mid);
	tr=solve2(mid+1,r);
	if(tl+1<tr){
		reverse(a+tl,a+tr);
		ans++;
		al[ans]=tl;
		ar[ans]=tr-1;
	}
	return l+(tl-l)+(tr-mid-1);
}
void solve(int l,int r,int L,int R){
	if(l>=r||L>=R) return;
//	cout<<"solve "<<l<<' '<<r<<' '<<L<<' '<<R<<'\n';
	lim=(L+R)>>1;
	int mid=(solve2(l,r)-1);
	solve(l,mid,L,lim);
	solve(mid+1,r,lim+1,R);
}
int main(){
	n=read();int i;
	for(i=1;i<=n;i++) a[i]=read();
	solve(1,n,0,32000);
	printf("%d\n",ans);
	for(i=1;i<=ans;i++) printf("%d %d\n",al[i],ar[i]);
}
