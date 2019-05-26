#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
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
int n;double a[110][110],b[110]; 
int Gauss(){
	int i,j,k,num;double tmp,tt;
	for(i=1;i<=n;i++){
		num=i;
		for(j=i+1;j<=n;j++) if(fabs(a[j][i])>=fabs(a[num][i])) num=j;
		for(j=1;j<=n;j++) swap(a[i][j],a[num][j]);
		swap(b[i],b[num]);
		tmp=a[i][i];
		for(j=1;j<=n;j++) a[i][j]/=tmp;b[i]/=tmp;
		for(j=1;j<=n;j++){
			if(j==i) continue;
			tt=a[j][i];
			for(k=1;k<=n;k++) a[j][k]-=tt*a[i][k];
			b[j]-=tt*b[i];
		}
	}
}
int main(){
	n=read();int i,j;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++) a[i][j]=read();
		b[i]=read();
	}
	Gauss();
	for(i=1;i<=n;i++) printf("%.2lf\n",b[i]);
}
