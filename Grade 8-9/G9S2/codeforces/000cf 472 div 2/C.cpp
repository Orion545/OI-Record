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
int n,m,a[100010];
int main(){
	n=read();m=read();int i,j;
	for(i=1;i<=n;i++) a[i]=read();
	double ans=-1.0;
	for(i=1;i<=n-2;i++){
		j=upper_bound(a+i+2,a+n+1,a[i]+m)-a;
//		cout<<j<<endl;
		j--;
//		cout<<i<<ends<<j<<ends<<a[i]<<ends<<a[i+1]<<ends<<a[j]<<endl;
		if(j<=i+1) continue;
		ans=max(ans,((double)(a[j]-a[i+1]))/((double)(a[j]-a[i])));
	}
	printf("%.12lf",ans);
}
