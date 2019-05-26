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
int n,K,a[200010];
int main(){
	n=read();K=read();int i,j,cur=0,ans=0,pretot=0,tot;
	for(i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++){
		tot=1;
		while(a[i+1]==a[i]) tot++,i++;
		if(cur<a[i]||cur-K==a[i]) ans+=pretot;
		cur=a[i]+K;pretot=tot;
//		cout<<i<<' '<<ans<<'\n';
	}
	ans+=pretot;
	printf("%d\n",ans);
}
