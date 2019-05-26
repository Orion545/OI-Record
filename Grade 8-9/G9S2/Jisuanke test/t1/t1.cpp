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
int main(){
	freopen("add.in","r",stdin);
	freopen("add.out","w",stdout); 
	ll a=read(),b=read(),c=read();
	if(a==(b+c)||b==(a+c)||c==(a+b)) puts("yes");
	else puts("no");
} 
