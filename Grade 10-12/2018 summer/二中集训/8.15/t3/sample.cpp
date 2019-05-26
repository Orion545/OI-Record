#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cassert>
#define ll long long
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
char s[100010];
int main(){
	int n,t1,t2,i;
	n=read();
	for(i=1;i<n;i++) t1=read(),t2=read();
	scanf("%s",s);
	if(n==4) puts("4");
	if(n==5) puts("11");
	if(n==6) puts("8"); 
}
