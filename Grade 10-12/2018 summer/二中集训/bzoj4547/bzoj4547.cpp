#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
#define MOD 10000007
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
ll n,k,a[100010],x,y,sum;
ll A[5][5],B[5][5];
void mul(ll x[5][5],ll y[5][5],int lim){
//	cout<<"mul "<<lim<<'\n';
	int i,j,k;ll r[5][5]={0};
	for(i=1;i<=lim;i++){
		for(j=1;j<=3;j++){
			for(k=1;k<=3;k++){
				r[i][j]+=x[i][k]*y[k][j];
			}
			r[i][j]%=MOD;
		}
	}
//	for(i=1;i<=lim;i++){
//		for(j=1;j<=3;j++) cout<<x[i][j]<<' ';
//		cout<<'\n';
//	}
//	for(i=1;i<=3;i++){
//		for(j=1;j<=3;j++) cout<<y[i][j]<<' ';
//		cout<<'\n';
//	}
//	for(i=1;i<=lim;i++){
//		for(j=1;j<=3;j++) cout<<r[i][j]<<' ';
//		cout<<'\n';
//	}
	memcpy(x,r,sizeof(r));
}
int main(){
	n=read();k=read();ll i;
	for(i=1;i<=n;i++) a[i]=read(),sum=(sum+a[i])%MOD;
	sort(a+1,a+n+1);
	x=a[n];y=a[n-1];
	if(x<=0){
		sum=(sum+(x+y)*k%MOD)%MOD;printf("%lld\n",sum);
		return 0; 
	}
	while(y<=0&&k) sum+=(x+y),y=x+y,k--;
	A[1][1]=x;A[1][2]=y;A[1][3]=sum;
	B[1][2]=1;
	B[1][3]=1;B[2][3]=1;B[3][3]=1;
	B[1][1]=1;B[2][1]=1;
	while(k){
//		cout<<k<<' '<<A[1][1]<<' '<<A[1][2]<<' '<<A[1][3]<<' '<<B[1][1]<<' '<<B[1][2]<<'\n';
		if(k&1) mul(A,B,1);
		mul(B,B,3);k>>=1;
	}
	printf("%lld\n",A[1][3]);
}

