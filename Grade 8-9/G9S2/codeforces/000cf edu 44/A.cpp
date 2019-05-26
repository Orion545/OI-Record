#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
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
int n,a[110];
int main(){
	n=read();int i,c1=0,c2=0,m=n/2;
	for(i=1;i<=m;i++) a[i]=read();
	sort(a+1,a+m+1);
	for(i=1;i<=m;i++){
		c1+=abs(i*2-a[i]);
	}
	for(i=1;i<=m;i++){
		c2+=abs(i*2-1-a[i]);
	}
	cout<<min(c1,c2);
} 
