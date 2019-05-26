#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
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
int n,m,l,r,a[210],b[210],sum[210],ans=0;
void dfs(int u,int tot){
	if(u==n+1){ans=max(ans,tot);return;}
	int flag;

	sum[u]=sum[u-1];
	flag=1;
	if(u>=m) flag=((sum[u]-sum[u-m]>=l)&&(sum[u]-sum[u-m]<=r));
	if(flag) dfs(u+1,tot+b[u]);

	sum[u]=sum[u-1]+1;
	flag=1;
	if(u>=m) flag=((sum[u]-sum[u-m]>=l)&&(sum[u]-sum[u-m]<=r));
	if(flag) dfs(u+1,tot+a[u]);

	sum[u]=0;
}
int main(){
	n=read();m=read();l=read();r=m-read();int i;
	for(i=1;i<=n;i++) a[i]=read(),b[i]=read();
	dfs(1,0);
	cout<<ans<<'\n';
}
