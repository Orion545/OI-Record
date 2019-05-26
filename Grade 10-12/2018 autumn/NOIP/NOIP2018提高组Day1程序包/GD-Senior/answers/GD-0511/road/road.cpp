#include<iostream>
#include<cstdio>
#define maxn 100005
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
int n;
int a[maxn];
long long d[maxn];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=qread();
	for(int i=1;i<=n;i++) a[i]=qread();
	for(int i=2;i<=n+1;i++){
		d[i]=a[i]-a[i-1];
	}
	long long ans=0;
	for(int i=2;i<=n+1;i++){
		if(d[i]<0) ans+=-d[i];
	}
	printf("%lld\n",ans);
}
