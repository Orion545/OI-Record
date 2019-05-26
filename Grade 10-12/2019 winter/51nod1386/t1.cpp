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
int lis[12]={0,2,3,5,7,11,13,17,19,23,29,31};
int n,m,f[1010],st[1010],v[1010],dp[2][3010],pri[1010],cntp,vis[1010];
void init(){
	int i,j,k,len=1000;
	for(i=2;i<=len;i++){
		for(j=1;j<=11;j++){
			if(i%lis[j]==0) st[i]|=(1<<(j-1));
		}
		f[i]=f[i-1];
		if(!vis[i]){
			pri[++cntp]=i;
			v[i]=i;
			f[i]+=(i>31);
		}
		for(j=1;j<=cntp;j++){
			k=i*pri[j];if(k>len) continue;
			vis[k]=1;v[k]=v[i];
			if(i%pri[j]==0) break;
		}
	}
}
int main(){
	int T=read(),i,j,s,tmp,cur,pre,bit,cases=0;
	init();
	while(T--){
		n=read();m=read();
		cur=0;pre=1;
		bit=1;
		while(lis[bit]<=n&&bit<=11) bit++;
		bit--;
		memset(dp,127,sizeof(dp));
		dp[cur][0]=0;
		for(i=2;i<=n;i++){
			swap(cur,pre);
			for(j=0;j<(1<<bit);j++) dp[cur][j]=dp[pre][j];
			if(i==m) continue;
			for(j=0;j<(1<<bit);j++){
				dp[cur][j|st[i]]=min(dp[cur][j|st[i]],dp[pre][j]+1-(v[i]>31));
			}
//			cout<<i<<' '<<bit<<' '<<dp[cur][(1<<bit)-1]<<'\n';
		}
		cout<<"Case #"<<++cases<<": "<<dp[cur][(1<<bit)-1]+(m!=1)+f[n]<<'\n';
	}
}
