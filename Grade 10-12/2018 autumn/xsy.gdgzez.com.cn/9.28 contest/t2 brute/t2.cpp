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
int n,a[200010],t1,t2;
int lim[200010],top;
int main(){
	n=read();int i,tmp;
	for(i=1;i<=n;i++) a[i]=read();
	for(i=1;i<n;i++) t1=read(),t2=read();
	
	lim[1]=a[1];top=1;
	for(i=2;i<=n;i++){
		tmp=upper_bound(lim+1,lim+top+1,a[i])-lim-1;
//		cout<<i<<' '<<a[i]<<' '<<tmp<<' '<<lim[tmp]<<'\n';
		lim[tmp+1]=a[i];top=max(top,tmp+1);
	}
	
	int ans=top;
	memset(lim,0,sizeof(lim));
	reverse(a+1,a+n+1);
	
	lim[1]=a[1];top=1;
	for(i=2;i<=n;i++){
		tmp=upper_bound(lim+1,lim+top+1,a[i])-lim-1;
//		cout<<i<<' '<<a[i]<<' '<<tmp<<' '<<lim[tmp]<<'\n';
		lim[tmp+1]=a[i];top=max(top,tmp+1);
	}
	ans=max(ans,top);
	
	printf("%d\n",ans);
}
