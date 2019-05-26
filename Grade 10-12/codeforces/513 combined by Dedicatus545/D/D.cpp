#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
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
int n,m,FRIST[1000020],SECOND[1000020];

void init(){
	
	sort(FRIST+1,FRIST+n+1);
	sort(SECOND+1,SECOND+n+1);
}
ll ans;
int main(){
	n=read();ans=n;int i;
	for(i=1;i<=n;i++){
		FRIST[i]=read();
		SECOND[i]=read();
	}
	init();
	for(i=1;i<=n;i++) 
		ans=ans+(ll)max(FRIST[i],SECOND[i]);
	cout<<ans;
}
