#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,l,s,a[210],b[210],le[210],ri[210];
double p[210],dp[2][210][410];
int main(){
//	freopen("guard.in","r",stdin);
//	freopen("guard.out","w",stdout);
	int i,j,k,kk;
	scanf("%d%d%d",&n,&l,&s);
	for(i=1;i<=n;i++) scanf("%lf",&p[i]),p[i]/=100.0;
	le[0]=-s;
	ri[0]=s;
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[i]=((a[i]==-1)?1:0);
		le[i]=le[i-1]+((a[i]==-1)?1:0);
		ri[i]=ri[i-1]+((a[i]==-1)?0:a[i]);
	}
	int cur=0,nex=1;
	dp[nex][0][min(400,s+200)]=1;
	for(i=0;i<n;i++){
		swap(cur,nex);
		for(j=0;j<=i+1;j++) for(k=0;k<=400;k++) dp[nex][j][k]=0;
		for(j=0;j<=i;j++){
			for(k=0;k<=400;k++){
				kk=min(400,k+a[i+1]);
				dp[nex][j+1][kk]+=dp[cur][j][k]*p[i+1];
				dp[nex][j][k]+=dp[cur][j][k]*(1.0-p[i+1]);
//				if(dp[cur][j][k]) cout<<i<<' '<<j<<' '<<k<<' '<<kk<<' '<<dp[nex][j+1][kk]<<' '<<dp[nex][j][k]<<' '<<dp[cur][j][k]<<'\n'; 
			}
		}
	}
	double ans=0;
	for(i=l;i<=n;i++){
		for(j=200;j<=400;j++) ans+=dp[nex][i][j];
	}
	printf("%.6lf",ans);
} 
