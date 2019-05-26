#include<iostream>
#include<cstdio>
using namespace std;

int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x;
}

int n;
int a[100001];
long long dp[100001];
int main(){
	int i;
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	for(i=1;i<=n;i++){
		a[i]=read();
	}
	for(i=1;i<=n;i++){
		if(a[i]<a[i-1]){
			dp[i]=dp[i-1];
		}
		else{
			dp[i]=dp[i-1]+a[i]-a[i-1];
		}
	}
	printf("%lld\n",dp[n]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
