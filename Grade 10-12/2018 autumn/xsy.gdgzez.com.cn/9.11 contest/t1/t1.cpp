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
int n,m,dis[5010],l[5010],r[5010];ll sumd[5010],val[5010][210],sum[5010][5010];
int s[5010],top=0;
int main(){
	n=read();m=read();int i,j;ll ans=0;
	for(i=1;i<n;i++) dis[i]=read(),sumd[i+1]=sumd[i]+dis[i];
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++) val[i][j]=read();
	}
	for(j=1;j<=m;j++){
		for(i=1;i<=n;i++){
			while(top&&val[s[top]][j]<=val[i][j]) r[s[top]]=i,s[top--]=0;
			s[++top]=i;
		}
		while(top) r[s[top]]=n+1,s[top--]=0;
		for(i=n;i>=1;i--){
			while(top&&val[s[top]][j]<val[i][j]) l[s[top]]=i,s[top--]=0;
			s[++top]=i;
		}
		while(top) l[s[top]]=0,s[top--]=0;
//		for(i=1;i<=n;i++) cout<<i<<' '<<j<<' '<<l[i]<<' '<<r[i]<<'\n';
		for(i=1;i<=n;i++){
			//matrix([l+1,i],[i,r-1])
//			cout<<"add matirx "<<l[i]+1<<' '<<i<<' '<<i<<' '<<r[i]-1<<'\n';
			sum[l[i]+1][i]+=val[i][j];
			sum[i+1][i]-=val[i][j];
			sum[l[i]+1][r[i]]-=val[i][j];
			sum[i+1][r[i]]+=val[i][j];
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
//			cout<<i<<' '<<j<<' '<<sum[i][j]<<'\n';
			sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+sum[i][j];
//			if(i<=j) cout<<i<<' '<<j<<' '<<sum[i][j]<<'\n';
		}
	}
	for(i=1;i<=n;i++){
		for(j=i;j<=n;j++){
			ans=max(ans,sum[i][j]-sumd[j]+sumd[i]);
		}
	}
	printf("%lld\n",ans);
}
