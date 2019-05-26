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
	int a,b,c;a=read();b=read();c=read();
	if(a<=b){
		int ta=a+min(b-a,c);c-=ta-a;
		cout<<min(ta,b)*2+(c/2)*2;
	}
	else{
		int tb=b+min(a-b,c);c-=tb-b;
		cout<<min(a,tb)*2+(c/2)*2;
	}
}
