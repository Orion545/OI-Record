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
int n,a[100010];
int main(){
	n=read();
	int i,maxn=0,minn=n;
	for(i=1;i<=n;i++){
		a[i]=read();
		maxn=max(maxn,a[i]);
		minn=min(minn,a[i]);
	}
//	cout<<maxn<<' '<<minn<<' '<<a[1]<<' '<<a[2]<<' '<<a[3]<<'\n';
	if(maxn-minn>=2){
		puts("No");return 0;
	}
	if(maxn-minn==1){
		int cnt=0;
		for(i=1;i<=n;i++) if(a[i]==minn) cnt++;
		if(cnt<maxn&&(n-cnt)>=(maxn-cnt)*2) puts("Yes");
		else puts("No");
	}
	else{
		if(maxn*2<=n||maxn==n-1) puts("Yes");
		else puts("No");
	}
}
