#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
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
int dp[110][10];
int a,b,t[10],s[10],len;
void init(){
	int i,j,k;
	t[1]=1;
	for(i=1;i<=10;i++) t[i]=t[i-1]*10;
	for(i=0;i<10;i++) dp[1][i]=1;
	for(i=2;i<10;i++){
		for(j=0;j<10;j++){
			for(k=0;k<10;k++){
				if(abs(j-k)<2) continue;
				dp[i][j]+=dp[i-1][k];
			}
		}
	}
}
int solve(int x){
	int re=0,i,j;
	if(!x) return 0;
	len=0;i=x;
	while(i) s[++len]=i%10,i/=10;
	for(i=1;i<len;i++){
		for(j=1;j<10;j++) re+=dp[i][j];
	}
//	cout<<"solve "<<x<<' '<<re<<'\n';
	for(i=1;i<s[len];i++) re+=dp[len][i];
	for(i=len-1;i>=1;i--){
		for(j=0;j<s[i];j++){
			if(abs(j-s[i])<2) break;
			re+=dp[i][j];
		}
		if(abs(s[i]-s[i+1])<2) break;
		if(i==1) re++;
	}
//	cout<<"solve "<<x<<' '<<re<<'\n';
	return re;
}
int main(){
	a=read();b=read();init();
	cout<<solve(b)-solve(a-1)<<'\n';
}
