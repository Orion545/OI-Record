/*
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
int n,m,k,p;
long double dp[110][110][2],C[210][210];
void dfs(int r,int b,int f){
//	cout<<"dfs "<<r<<' '<<b<<' '<<f<<' '<<dp[r][b][f]<<'\n';
	if(dp[r][b][f]!=-1) return;
	if(!r){dp[r][b][f]=(f==0);return;}
	int i,ch;long double tmp;
	if(f) dp[r][b][f]=1;
	else dp[r][b][f]=0;
	for(ch=1;ch<=min(r+b,k);ch++){
		tmp=0;
		for(i=0;i<=ch;i++){
			//i means this time we randomly choose i red balls
			if(r<i||b<ch-i) continue;
			dfs(r-i,b-ch+i,f^1);
			tmp+=C[i][r]*C[ch-i][b]/C[ch][r+b]*dp[r-i][b-ch+i][f^1];
//			cout<<"	get prob "<<r<<' '<<b<<' '<<f<<' '<<i<<' '<<ch<<' '<<C[i][r]<<' '<<C[ch-i][b]<<' '<<C[ch][r+b]<<' '<<dp[r-i][b-ch+i][f^1]<<'\n';
			
		}
		if(!f) dp[r][b][f]=max(dp[r][b][f],tmp);
		else dp[r][b][f]=min(dp[r][b][f],tmp);
	}
//	cout<<"finish dfs "<<r<<' '<<b<<' '<<f<<' '<<dp[r][b][f]<<'\n';
}
void init(){
	int i,j;
	C[0][0]=1;
	C[0][1]=C[1][1]=1;
	for(i=2;i<=200;i++){
		for(j=0;j<=i;j++){
			C[j][i]=0;
			if(j>0) C[j][i]+=C[j-1][i-1];
			if(j<i) C[j][i]+=C[j][i-1];
		}
	}
	for(i=0;i<=n;i++){
		for(j=0;j<=m;j++){
			dp[i][j][0]=-1;
			dp[i][j][1]=-1;
		}
	}
	cout<<C[85][170]<<'\n';
}
int main(){
	n=read();m=read();k=read();p=read();int i;long double ans=0;
	init();
	for(i=0;i<=p;i++){
		dfs(n-i,m-p+i,0);
		ans+=C[i][n]*C[p-i][m]/C[p][n+m]*dp[n-i][m-p+i][0];
	}
	printf("%.10lf\n",(double)ans);
}

