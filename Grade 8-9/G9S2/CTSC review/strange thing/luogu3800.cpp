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
int r,c,n,T;
struct node{
	int x,y,val;
}a[4010];
bool cmp(node l,node r){
	return l.x<r.x;
} 
int _abs(int x){return (x>0)?x:-x;}
int dp[4010];
int main(){
	r=read();c=read();n=read();T=read();
	int i,j;
	for(i=1;i<=n;i++) a[i].x=read(),a[i].y=read(),a[i].val=read();
	sort(a+1,a+n+1,cmp);
	dp[1]=a[1].val;
	for(i=1;i<=n;i++){
//		dp[i]=dp[i-1];
		for(j=0;j<i;j++){
			if(abs(a[i].y-a[j].y)<=T*(a[i].x-a[j].x)) dp[i]=max(dp[i],dp[j]+a[i].val);
		}
//		cout<<"dp "<<i<<ends<<dp[i]<<endl;
	}
//	printf("%d\n",dp[n]);
	int ans=0;
	for(i=1;i<=n;i++) ans=max(ans,dp[i]);
	printf("%d\n",ans);
}
