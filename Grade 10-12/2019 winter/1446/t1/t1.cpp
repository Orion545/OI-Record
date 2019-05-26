#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#define MOD 1000000007
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
int n,a,b,x[100010];
ll p2[100010];
int main(){
	n=read();a=read();b=read();int i,fl=0;
	if(a>b) swap(a,b),fl=1;
	for(i=1;i<=n;i++) x[i]=read();
	p2[0]=1;
	for(i=1;i<=n;i++){
		p2[i]=p2[i-1]*2;
		if(p2[i]>=MOD) p2[i]-=MOD;
	}
	int a1=0,a2=0,a3=0,a4=0,c1=0,c2=0,c3=0,c4=0;
	for(i=1;i<=n;i++){
		x[i]%=(a+b);
		c1+=(x[i]<a);
		c2+=(a<=x[i])&&(x[i]<b);
		c3+=(b<=x[i])&&(x[i]<2*a);
		c4+=(2*a<=x[i])&&(b<=x[i]);
	}
	if(c3) a3=a4=p2[c1+c3-1];
	else a4=p2[c1];
	a3=(a3+1ll*c4*a4)%MOD;
	a1=p2[n]-a3-a4;
	while(a1<0) a1+=MOD;
	if(fl) swap(a1,a2);
	printf("%d %d %d %d\n",a1,a2,a3,a4);
}
