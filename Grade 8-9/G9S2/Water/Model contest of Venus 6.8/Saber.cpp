#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
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
int n,sum,t1,maxn,a[60];
int main(){
	freopen("Saber.in","r",stdin);
	freopen("Saber.out","w",stdout);
	n=read();maxn=sum=0;int i;
	for(i=1;i<=n;i++) a[i]=read();
	for(i=n;i>=1;i--){
		sum+=a[i];
		maxn=max(maxn,sum);
	}
	printf("%d\n",maxn);
}

