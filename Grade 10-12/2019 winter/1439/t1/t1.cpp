#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
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
int main(){
	int n=read(),i;long double ans=0,tmp=-1;
	for(i=n+1;i<=20010;i++){
		tmp*=(long double)(-i);
		if(abs(tmp)>=1e8) break;
		ans+=(1.0/tmp);
	}
	printf("%.4lf\n",(double)ans);
}
