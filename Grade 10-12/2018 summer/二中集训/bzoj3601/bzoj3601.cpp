#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
#define ll long long
#define MOD 1000000007
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
ll d,w,p[1010],a[1010],c[110][110],x[110];
ll qpow(ll a,ll b){
	ll re=1;
	while(b){
		if(b&1) re=re*a%MOD;
		a=a*a%MOD;b>>=1;
	}
	return re;
}
void Gauss(){
	ll i,j,k,num;ll tmp,tt;
	for(i=1;i<=d+1;i++){
		num=i;
		for(j=i+1;j<=d+1;j++) if(abs(c[j][i])>abs(c[num][i])) num=j;
		for(j=1;j<=d+2;j++) swap(c[i][j],c[num][j]);
		tmp=qpow(c[i][i],MOD-2);
		for(j=i+1;j<=d+1;j++){
			tt=c[j][i]*tmp%MOD;
			for(k=1;k<=d+2;k++) c[j][k]=(c[j][k]-tt*c[i][k]%MOD+MOD)%MOD;
		}
	}
	for(i=d+1;i>=1;i--){
		x[i]=c[i][d+2]=c[i][d+2]*qpow(c[i][i],MOD-2)%MOD;
		for(j=i-1;j>=1;j--) c[j][d+2]=(c[j][d+2]-c[j][i]*c[i][d+2]%MOD+MOD)%MOD;
//		cout<<i<<' '<<x[i]<<'\n';
//		for(j=1;j<=d+2;j++) cout<<c[i][j]<<' ';cout<<'\n';
	}
}
int main(){
	d=read();w=read();ll i,j,tmp,sum=0;
	for(i=1;i<=w;i++) p[i]=read(),a[i]=read();
	for(i=1;i<=d+1;i++){
		tmp=1;sum+=qpow(i,d);sum%=MOD;
		for(j=1;j<=d+1;j++){
			tmp=tmp*i%MOD;
			c[i][j]=tmp;
		}
		c[i][d+2]=sum;
	}
	Gauss();tmp=0;
	for(i=1;i<=d+1;i++){
		sum=1;
		for(j=1;j<=w;j++) sum*=(qpow(p[j],a[j]*i)-qpow(p[j],d+a[j]*i-i)+MOD),sum%=MOD;
		tmp=(tmp+x[i]*sum)%MOD;
	}
	printf("%lld\n",tmp);
}
/*
3 2
2 1
5 1

1100
*/
