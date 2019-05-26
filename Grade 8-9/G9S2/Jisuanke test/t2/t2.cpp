#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
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
	freopen("flag.in","r",stdin);
	freopen("flag.out","w",stdout);
	int n=read(),i,j;
	for(i=1;i<=n;i++){
		for(j=1;j<=i;j++) putchar('*');
		putchar('\n');
	}
	n<<=1;
	for(i=1;i<=n;i++){
		for(j=1;j<=i;j++) putchar('*');
		putchar('\n');
	}
}
