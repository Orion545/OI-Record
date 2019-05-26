/*

宣告——
汝身听吾号令，托付吾之命运于汝之剑，
应圣杯之召，若汝遵从此意志此理，回应吧。
在此起誓，吾愿成就世间一切之善行，吾愿诛尽世间一切之恶行。
汝为身缠三大言灵之七天，从抑止之轮显现吧，天秤之守护者！

*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
#include<vector>
#include<queue>
#define inf 1e9
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
int n,m;
int w[20][20];
int dp[200010][20],g[200010],dis[200010][20];
int main(){
	n=read();m=read();int i,j,k,h,s,t1,t2,t3,tot=(1<<n),tmp;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(j!=i) w[i][j]=inf;
			else w[i][j]=0;
		}
	}
	for(i=1;i<=m;i++){
		t1=read();t2=read();t3=read();
		t1--;t2--;
		w[t1][t2]=min(w[t1][t2],t3);
		w[t2][t1]=min(w[t2][t1],t3);
	}
	for(s=1;s<tot;s++){
		for(i=0;i<n;i++){
			if((s&(1<<i))==0) continue;
			g[s]|=(1<<i);
			for(j=0;j<n;j++){
				if(w[i][j]==inf) continue;
				g[s]|=(1<<j);
				dis[s][j]=inf;
				for(k=0;k<n;k++){
					if((s&(1<<k))==0) continue;
					dis[s][j]=min(dis[s][j],w[k][j]);
				}
			}
		}
//		cout<<"finish g[s] "<<s<<' '<<g[s]<<'\n';
	}
	for(s=1;s<tot;s++){
		for(i=0;i<n;i++) dp[s][i]=inf;
	}
	for(i=0;i<n;i++) dp[1<<i][0]=0;
	for(s=3;s<tot;s++){
		for(h=1;h<n;h++){
			for(i=s;i;i=(i-1)&s){
				if((g[i]&s)!=s) continue;
				tmp=dp[i][h-1];
				for(j=0;j<n;j++){
					if(((s^i)&(1<<j))==0) continue;
					tmp+=dis[i][j]*h;
				}
				dp[s][h]=min(dp[s][h],tmp);
			}
//			cout<<"getdp "<<s<<' '<<h<<' '<<dp[s][h]<<'\n';
		}
	}
	int ans=inf;
	for(i=0;i<n;i++) ans=min(ans,dp[tot-1][i]);
	cout<<ans<<'\n';
}
