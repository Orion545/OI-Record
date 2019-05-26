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
double dp[2][110],n,m;
int main(){
	n=read();m=read();int i,cur=1,pre=0,j;
	for(i=n-1;i>=0;i--){
		swap(cur,pre);
		for(j=1;j<=100;j++){
			dp[cur][j]=(1/(double)m)*((dp[pre][j]*(double)j+dp[pre][j+1]+j)/((double)j+1.0)+((double)m-1.0)*dp[pre][j]+(double)j/2.0);
		}
	}
	printf("%.10lf\n",dp[cur][1]*m);
}
