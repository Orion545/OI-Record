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
int n,m;double p[6010][610],a[6010],pre[6010],suf[6010],dp[610][6010];
int main(){
	n=read();m=read();int i,j,k,len;double t1,t2;
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			p[i][j]=read();
			p[i][j]/=1000.0;
		}
	}
	for(i=1;i<=m;i++){
		memset(a,0,sizeof(a));
		a[0]=1.0;len=0;
//		cout<<"begin "<<i<<'\n';
		for(j=1;j<=n;j++){
			t1=p[j][i];t2=1.0-p[j][i];
			for(k=len+1;k>=1;k--) a[k]=a[k]*t2+a[k-1]*t1;
			a[0]=a[0]*t2;
			if(a[len+1]>1e-12) len++;
		}
		memset(pre,0,sizeof(pre));
		memset(suf,0,sizeof(suf));
		for(j=len;j>=1;j--) suf[j]=suf[j+1]+a[j];
		for(j=1;j<=len;j++) pre[j]=pre[j-1]+a[j]*j;
		for(j=1;j<=len;j++) suf[j]=suf[j]*j+pre[j-1];
//		for(j=0;j<=len;j++) cout<<j<<' '<<a[j]<<' '<<suf[j]<<'\n';
		for(j=0;j<=n;j++){
			for(k=0;k<=len;k++){
				dp[i][j+k]=max(dp[i][j+k],dp[i-1][j]+suf[k]);
			}
//			cout<<"finish "<<i<<' '<<j<<' '<<dp[i][j]<<'\n';
		}
	}
	printf("%.10lf\n",dp[m][n]);
}
