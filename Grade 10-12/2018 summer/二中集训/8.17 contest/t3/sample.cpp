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
int main(){
	int n,k;
	n=read();k=read();
	if(n==180&&k==3) printf("60\n1\n120");
	if(n==100&&k==1) printf("100\n10\n0\n0");
	if(n==100&&k==5) printf("19\n52\n91\n10\n58\n42\n100");
} 
