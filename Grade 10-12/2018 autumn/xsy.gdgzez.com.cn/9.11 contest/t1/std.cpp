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
ll n,m,sumd[210],val[210][210],dis[210],maxn[210][210][210];
int main(){
	n=read();m=read();int i,j,k;ll ans=0;
	for(i=1;i<n;i++) dis[i]=read(),sumd[i+1]=sumd[i]+dis[i];
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++) val[i][j]=read(),maxn[j][i][i]=val[i][j];
	}
	for(i=1;i<=m;i++){
		for(k=1;k<n;k++){
			for(j=1;j<=n-k;j++)
				maxn[i][j][j+k]=max(maxn[i][j][j+k-1],val[j+k][i]);
		}
	}
	for(i=1;i<=n;i++){
		for(j=i;j<=n;j++){
			ll tmp=0;
			for(k=1;k<=m;k++) tmp+=(ll)maxn[k][i][j];
//			cout<<i<<' '<<j<<' '<<tmp<<'\n';
			ans=max(ans,tmp-sumd[j]+sumd[i]);
		}
	}
	printf("%lld\n",ans);
}
