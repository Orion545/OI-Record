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
double dp[1010][1010];int n,m,x,y;
int main(){
	n=read();m=read();int i,j,k;
	x=read();y=read();
	if(m==1){
		cout<<(n-x)*2<<'\n';
		return 0;
	}
	for(i=n-1;i>=x;i--){
		for(k=1;k<=60;k++){
			for(j=1;j<=m;j++){
				if(j>1&&j<m) dp[i][j]=1.0+(dp[i][j]+dp[i+1][j]+dp[i][j-1]+dp[i][j+1])/4.0;
				if(j==1) dp[i][j]=1.0+(dp[i][j]+dp[i+1][j]+dp[i][j+1])/3.0;
				if(j==m) dp[i][j]=1.0+(dp[i][j]+dp[i+1][j]+dp[i][j-1])/3.0;
			}
		}
	}
	printf("%.5lf\n",dp[x][y]);
}
