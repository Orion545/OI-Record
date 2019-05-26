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
int n,m,a[1000010],dp[2][2010];char s[1000010];
int main(){
	n=read();m=read();int i,cur=0,pre=1,j,ans[1010];
	scanf("%s",s);
	for(i=0;i<n;i++) a[i+1]=(s[i]!='+');
	dp[0][cur]=1;
	for(i=1;i<=n;i++){
		swap(cur,pre);memset(dp[cur],0,sizeof(dp[cur]));
//		cout<<i<<' '<<a[i]<<'\n';
		for(j=0;j<(1<<m);j++){
			if(dp[pre][j]==0) continue;
//			cout<<"j "<<j<<'\n';
			dp[cur][j]=1;
			if(a[i]==0) dp[cur][(j+1)&((1<<m)-1)]=1;
			else dp[cur][(j<<1)&((1<<m)-1)]=1;
		}
	}
	for(i=(1<<m)-1;i>=0;i--){
		if(dp[cur][i]){
//			cout<<"choose "<<i<<endl;
			j=0;
			while(i){
				ans[++j]=i&1;
				i>>=1;
			}
			if(j==0) puts("0");
			else{
				for(i=j;i>=1;i--) printf("%d",ans[i]);
			}
		}
	}
}
