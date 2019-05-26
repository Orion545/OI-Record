#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
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
int b[40];
bool insert(int x){
	for(int i=30;~i;i--){
		if((1<<i)&x){
			if(!b[i]){b[i]=x;break;}
			else x^=b[i];
		}
		if(!x) return 1;
	}
	return 0;
}
int a[100010];
int main(){
	int n=read(),i;ll ans=0;
	for(i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);
	for(i=n;i>=1;i--) if(insert(a[i])) ans+=1ll*a[i];
	cout<<ans<<'\n';
}
