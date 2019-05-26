#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
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
ll m,fail[1000010];char b[1000010];
int main(){
	m=read();
	scanf("%s",b);ll i,j;
	j=0;fail[0]=fail[1]=0;
	for(i=1;i<m;i++){
		while(j&&b[i]!=b[j]) j=fail[j];
		j+=(b[i]==b[j]);fail[i+1]=j;
	}
	printf("%lld\n",m-fail[m]);
}
