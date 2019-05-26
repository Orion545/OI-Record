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
int n,m,v,e;
double dis[310][310];
void floyd(){
	int i,j,k;
	for(k=1;k<=v;k++){
		for(i=1;i<=v;i++){
			for(j=1;j<=v;j++){
				if(i==j) continue;
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
}
double dp[2010][2010][2],k[2010];int c[2010],d[2010];
int main(){
	n=read();m=read();v=read();e=read();
	int i,j,t1,t2,t3;
	for(i=1;i<=n;i++) c[i]=read();
	for(i=1;i<=n;i++) d[i]=read();
	for(i=1;i<=n;i++) scanf("%lf",&k[i]);
	
	for(i=1;i<=v;i++){
		for(j=1;j<=v;j++){
			if(i==j) dis[i][j]=0;
			else dis[i][j]=1e15;
		}
	}
	
	for(i=1;i<=e;i++){
		t1=read();t2=read();t3=read();
		dis[t1][t2]=min(dis[t1][t2],(double)t3);
		dis[t2][t1]=min(dis[t2][t1],(double)t3);
	}
	floyd();
	
//	for(i=1;i<=n;i++) for(j=1;j<=n;j++) cout<<i<<' '<<j<<' '<<dis[i][j]<<'\n';
	
	for(i=1;i<=n;i++){
		for(j=0;j<=n;j++){
			dp[i][j][0]=dp[i][j][1]=1e15;
		}
	}
	
	dp[1][0][0]=dp[1][1][1]=0;
	for(i=2;i<=n;i++){
		for(j=0;j<=i;j++){
			if(j>0){
				dp[i][j][1]=min(
				dp[i-1][j-1][0]
				+dis[c[i-1]][d[i]]*k[i]
				+dis[c[i-1]][c[i]]*(1.0-k[i]),
				
				dp[i-1][j-1][1]
				+dis[c[i-1]][c[i]]*(1.0-k[i-1])*(1.0-k[i])
				+dis[d[i-1]][c[i]]*k[i-1]*(1.0-k[i])
				+dis[c[i-1]][d[i]]*(1.0-k[i-1])*k[i]
				+dis[d[i-1]][d[i]]*k[i-1]*k[i]);
			}
			if(j<i){
				dp[i][j][0]=min(
				dp[i-1][j][0]+dis[c[i-1]][c[i]],
				
				dp[i-1][j][1]
				+dis[c[i-1]][c[i]]*(1.0-k[i-1])
				+dis[d[i-1]][c[i]]*k[i-1]);
			}
//			cout<<i<<' '<<j<<' '<<dp[i][j][0]<<' '<<dp[i][j][1]<<'\n';
//			cout<<c[i-1]<<' '<<d[i-1]<<' '<<c[i]<<' '<<dis[c[i-1]][c[i]]<<' '<<dis[d[i-1]][c[i]]<<'\n';
		}
	}
	if(n==1){puts("0.00");return 0;}
	double ans=1e15;
	for(i=0;i<=m;i++){
		if(i>0) ans=min(ans,dp[n][i][1]);
		if(i<n) ans=min(ans,dp[n][i][0]);
	}
	printf("%.2lf\n",ans);
}
