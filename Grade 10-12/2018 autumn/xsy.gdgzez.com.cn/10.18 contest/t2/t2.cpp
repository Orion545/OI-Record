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
int n,ch[100010];ll a[100010];
ll dp0,dp1,dp2;
int main(){
	n=read();int i;char c;
	for(i=1;i<=n;i++){
		a[i]=read();
		if(i==n) break;
		c=getchar();
		while(c!='+'&&c!='-') c=getchar();
		ch[i+1]=(c=='-');
//		cout<<"finish readin "<<i<<' '<<a[i]<<' '<<ch[i+1]<<'\n';
	}
	dp0=0;dp1=dp2=-1e15;
	for(i=1;i<=n;i++){
		if(ch[i]){
			dp0-=a[i];
			dp1+=a[i];
			dp2-=a[i];
			dp2=max(dp2,dp1);
			dp1=max(dp1,dp0);
		}
		else{
			dp0+=a[i];
			dp1-=a[i];
			dp2+=a[i];
		}
		dp1=max(dp2,dp1);
		dp0=max(dp1,dp0);
	}
	cout<<dp0<<'\n';
}
