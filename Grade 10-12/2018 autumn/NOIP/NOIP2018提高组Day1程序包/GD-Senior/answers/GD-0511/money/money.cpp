#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 500005
using namespace std;
inline int qread(){
	int x=0,sign=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*sign;
}

inline int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}
int n,t,sz;
int a[maxn];
int del[maxn];
int tmp[maxn];

int v[maxn];
int c[maxn];
long long dp[maxn];
void backpack(){
	for(int i=1;i<=n;i++){
		c[i]=a[n]/a[i]+1;
	}
	for(int i=1;i<=n;i++){
		for(int j=0;(1<<j)<=c[i];j++){
			v[++sz]=(1<<j)*a[i];
		}
	}
	memset(dp,0,sizeof(dp));
	dp[0]=1;
	for(int i=1;i<=sz;i++){
		for(int j=a[n];j-v[i]>=0;j--){
			dp[j]+=dp[j-v[i]];
			if(dp[j]>=2) dp[j]=2;
		}
	}
//	for(int i=0;i<=a[n];i++){
//		if(dp[i]!=0) printf("dp[%d]=%d\n",i,dp[i]);
//	}
}

int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	t=qread();
	while(t--){
		sz=0;
		n=qread();
		for(int i=1;i<=n;i++){
			a[i]=qread();
			del[i]=0;
			tmp[i]=0;
		}
		sort(a+1,a+1+n);
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]%a[i]==0) del[j]=1;
			}
		}
		sz=0;
		for(int i=1;i<=n;i++){
			if(!del[i]) tmp[++sz]=a[i];
		}
		for(int i=1;i<=sz;i++) a[i]=tmp[i];
		n=sz;
		sz=0;
		backpack();
		int ans=n;
		for(int i=1;i<=n;i++){
			if(dp[a[i]]>1) ans--;
		}
		printf("%d\n",ans);
	}
}
/*
2
4
3 19 10 6
5
11 29 13 19 17
*/
