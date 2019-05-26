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
int n,a[210],fin[110];
int main(){
	n=read();int i,j,k,ans=0;
	for(i=1;i<=n*2;i++){
		a[i]=read();
	}
	for(i=1;i<=n*2;i+=2){
//		cout<<i<<' '<<a[i]<<' '<<a[i+1]<<'\n';
		if(a[i]==a[i+1]) continue;
		for(j=i+2;j<=n*2;j++)
			if(a[j]==a[i]) break;
		for(k=j-1;k>i;k--) a[k+1]=a[k];
		a[i+1]=a[i];ans+=j-i-1;
	}
	printf("%d\n",ans);
}
