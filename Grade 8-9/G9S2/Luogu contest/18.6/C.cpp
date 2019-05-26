#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
inline ll read(){
	ll re=0,flag=1;char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
int n,r[1000010];double a[1000010];
int main(){
	n=read();a[0]=read();int i,j,cur=0;double tmp;
	for(i=1;i<=n;i++){
		a[i]=read();r[i]=read();
		tmp=0;
		for(j=cur;j<=r[i];j++){
			if(a[j]>=(a[i]-tmp)*5){
				a[j]-=(a[i]-tmp)*5;tmp=a[i];break;
			}
			tmp+=a[j]*0.2;a[j]=0;cur=j+1;
		}
		if(tmp!=a[i]){
			puts("-1");return 0;
		}
	}
	double ans=0;
	for(i=0;i<=n;i++){
		ans+=a[i]*0.2;
	}
	printf("%.10lf",ans);
}
