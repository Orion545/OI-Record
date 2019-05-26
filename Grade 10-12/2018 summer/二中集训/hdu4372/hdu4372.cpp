#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
#define ll long long
#define MOD 1000000007
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
ll s[2010][2010],c[2010][2010];
void init(){
	int i,j;
	s[0][0]=1;
	for(i=1;i<=2000;i++){
		for(j=0;j<=i;j++){
			s[i][j]=s[i-1][j-1]+(i-1)*s[i-1][j];s[i][j]%=MOD;
		}
	}
	c[0][0]=1;
	for(i=1;i<=2000;i++){
		for(j=0;j<=i;j++){
			c[i][j]=c[i-1][j-1]+c[i-1][j];c[i][j]%=MOD;
		}
	}
}
int main(){
	init();int T=read(),n,a,b;
	while(T--){
		n=read();a=read();b=read();
		printf("%lld\n",s[n-1][a+b-2]*c[a+b-2][a-1]%MOD);
	}
}

