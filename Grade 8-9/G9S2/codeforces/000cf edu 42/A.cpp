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
ll n,a[200010],tot=0,tt=0;
int main(){
	n=read();ll i;
	for(i=1;i<=n;i++) a[i]=read(),tot+=a[i];
	for(i=1;i<=n;i++){
		tt+=a[i];
		if(tt>=(tot/2)+(tot%2)){
			cout<<i<<endl;return 0;
		}
	}
}

