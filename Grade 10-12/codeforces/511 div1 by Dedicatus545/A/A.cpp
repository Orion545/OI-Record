#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cassert>
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
int vis[15000010],pri[6000010],cntp,minn[15000010],cnt[6000010]={0};
void init(){
	int i,j,k,len=15000000;
	for(i=2;i<=len;i++){
		if(!vis[i]) pri[++cntp]=i,minn[i]=cntp;
		for(j=1;j<=cntp;j++){
			k=i*pri[j];if(k>len) break;
			vis[k]=1;
			minn[k]=j;
			if(i%pri[j]==0) break;
		}
	}
}
int n,a[600010],g;
int gcd(int x,int y){
	if(y==0) return x;
	return gcd(y,x%y);
}
int main(){
	n=read();int i,j,cnt1=0;
	init();
	for(i=1;i<=n;i++){
		a[i]=read();
	}
	g=a[1];
	for(i=2;i<=n;i++){
		if(a[i]==1) continue;
		g=gcd(a[i],g);
	}
	for(i=1;i<=n;i++){
		a[i]/=g;
	}
	for(i=1;i<=n;i++){
		if(a[i]==1){cnt1++;continue;}
		j=minn[a[i]];
//		cout<<"do "<<i<<' '<<a[i]<<' '<<minn[a[i]]<<'\n';
		while(a[i]!=1){
			while(a[i]%pri[j]==0) a[i]/=pri[j];
			cnt[j]++;j=minn[a[i]];
		}
	}
	int ans=n+1;
	if(cnt1==n){
		puts("-1");return 0;
	}
	for(i=1;i<=cntp;i++) ans=min(ans,n-cnt[i]-cnt1);
	ans+=cnt1;
	cout<<ans<<'\n';
}
