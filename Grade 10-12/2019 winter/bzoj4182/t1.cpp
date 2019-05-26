#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
#define hash DEEP_DARK_FANTASY
#define ll long long
using namespace std;
inline ll read(){
	ll re=0,flag=1;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(isdigit(ch)) re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
ll MOD,n,num[1010];
struct mat{
	ll n,m,a[71][71];
	mat(){n=m=0;memset(a,0,sizeof(a));}
}a,b,c,hash[1010];
inline mat mul(mat l,mat r){
	mat re;ll i,j,k,tmp;
//	cout<<"mul "<<l.n<<' '<<l.m<<' '<<r.n<<' '<<r.m<<'\n';
	assert(l.m==r.n);
	re.n=l.n;re.m=r.m;
	for(i=1;i<=l.n;i++){
		for(j=1;j<=r.m;j++){
			tmp=0;
			for(k=1;k<=l.m;k++) tmp=(tmp+l.a[i][k]*r.a[k][j])%MOD;
			re.a[i][j]=tmp;
		}
	}
	return re;
}
inline mat qpow(mat a,ll b){
	mat re;ll i;
	for(i=1;i<=a.n;i++) re.a[i][i]=1;
	re.n=re.m=a.n;
	while(b){
		if(b&1) re=mul(re,a);
		a=mul(a,a);b>>=1;
	}
	return re;
}
inline bool cmp(mat l,mat r){
	if(l.n!=r.n||l.m!=r.m) return 0;
	for(ll i=1;i<=n;i++) if(l.a[i][1]!=r.a[i][1]) return 0;
	return 1;
}
int main(){
	srand(19260817);
	n=read();MOD=read();ll i,j,m=ceil(sqrt(double(MOD)));
	for(i=1;i<=n;i++) for(j=1;j<=n;j++) a.a[i][j]=read();
	a.n=a.m=n;
	for(i=1;i<=n;i++) for(j=1;j<=n;j++) b.a[i][j]=read();
	b.n=b.m=n;
	for(i=1;i<=n;i++) c.a[i][1]=num[i]=rand()%MOD;
	c.n=n;c.m=1;
	for(j=0;j<m;j++){
		hash[j]=mul(b,c);c=mul(a,c);
	}
	a=qpow(a,m);
	for(i=1;i<=n;i++) c.a[i][1]=num[i];
	for(i=m;i<=MOD+m;i+=m){
		c=mul(a,c);
		for(j=m-1;j>=0;j--){
			if(cmp(c,hash[j])){cout<<i-j<<'\n';return 0;}
		}
	}
	return 0;
}
