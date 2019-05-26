#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long 
using namespace std;
#define y1 DEEP_DARK_FANTASY
inline int read(){
	int re=0,flag=1;char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
double x1[100010],x2[100010],y1[200010],y2[200010];
int ql[100010],cntl,qr[100010],cntr;
ll r[100010],c[100010];
int n,m;
double slope1(int i,int j){
	return (y1[j]-y1[i])/(x1[j]-x1[i]);
}
double slope2(int i,int j){
	return (y2[j]-y2[i])/(x2[j]-x2[i]);
}
ll calc(ll i1,ll j1,ll i2,ll j2,ll k){
//	cout<<"calc "<<i1<<' '<<j1<<' '<<i2<<' '<<j2<<' '<<k<<'\n';
	if(k==1) return (ll)(r[i1]*(j2-j1)+c[j2]*(i2-i1));
	else return (ll)(c[j1]*(i2-i1)+r[i2]*(j2-j1));
}
int main(){
	n=read();m=read();int i,j;double k1,k2;
	n++;m++;
	for(i=1;i<=n;i++) r[i]=y1[i]=read(),x1[i]=i;
	for(i=1;i<=m;i++) c[i]=y2[i]=read(),x2[i]=i;
	for(i=1;i<=n;i++){
		while(cntl>1&&(slope1(ql[cntl],i)<=slope1(ql[cntl-1],ql[cntl]))) cntl--;
		cntl++;ql[cntl]=i;
	}
	for(i=1;i<=m;i++){
		while(cntr>1&&(slope2(qr[cntr],i)<=slope2(qr[cntr-1],qr[cntr]))) cntr--;
		cntr++;qr[cntr]=i;
	}
//	for(i=1;i<=cntl;i++) cout<<ql[i]<<' ';
//	cout<<'\n';
//	for(i=1;i<=cntr;i++) cout<<qr[i]<<' ';
//	cout<<'\n';
	i=1;j=1;ll ans=0;
	while(i<cntl&&j<cntr){
		k1=slope1(ql[i],ql[i+1]);
		k2=slope2(qr[j],qr[j+1]);
		if(k1<k2) ans+=calc(ql[i],qr[j],ql[i+1],qr[j],2),i++;
		else ans+=calc(ql[i],qr[j],ql[i],qr[j+1],1),j++;
	}
	while(i<cntl) ans+=calc(ql[i],qr[j],ql[i+1],qr[j],1),i++;
	while(j<cntr) ans+=calc(ql[i],qr[j],ql[i],qr[j+1],2),j++;
	printf("%lld\n",ans);
}
