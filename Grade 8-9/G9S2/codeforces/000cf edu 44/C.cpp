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
ll n,m,tot,limit,a[100010];
int main(){
	n=read();m=read();limit=read();tot=n*m;ll i,j,r,tmp,ans=0;
	for(i=1;i<=tot;i++) a[i]=read();
	sort(a+1,a+tot+1);
	for(i=1;i<=tot;i++) if((a[i]-a[1])>limit) break;
	r=i-1;tmp=r-n;
	if(r<n){
		puts("0");return 0;
	}
//	cout<<r<<endl;
	for(i=1;i<=r;i+=j){
		for(j=1;j<=m-1;j++){
			if(!tmp) break;
			tmp--;
		}
		ans+=a[i];
	}
	cout<<ans;
}
