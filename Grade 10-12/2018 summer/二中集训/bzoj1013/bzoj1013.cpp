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
int n;double a[110][110],b[110],ori[110]; 
int Gauss(){
	int i,j,k,num;double tmp;
	for(i=1;i<n;i++){//process deals with the ith UKE, using row No.i
		num=i;
		for(j=i+1;j<=n;j++){
			if(fabs(a[j][i])>fabs(a[num][i])) num=j;
		}
		for(j=1;j<=n;j++) swap(a[i][j],a[num][j]);//to swap row i with maximum row num
		swap(b[i],b[num]);
//		cout<<"gauss "<<i<<' '<<num<<'\n';
		for(j=i+1;j<=n;j++){
			if(fabs(a[j][i])<=1e-6) continue;
			tmp=a[j][i]/a[i][i];
//			cout<<"	do row "<<j<<' '<<tmp<<' '<<a[j][i]<<' '<<a[i][i]<<'\n';
			for(k=1;k<=n;k++) a[j][k]-=a[i][k]*tmp;
			b[j]-=b[i]*tmp;
		}
	}
//	for(i=1;i<=n;i++){
//		for(j=1;j<=n;j++) cout<<a[i][j]<<' ';
//		cout<<b[i]<<'\n';
//	}
	if(a[n][n]==0) return -1;
	for(i=n;i>=1;i--){//process deals with row i, element i, and clears former elements i
		b[i]/=a[i][i];
//		cout<<b[i]<<' '<<a[i][i]<<'\n';
		for(j=i-1;j>=1;j--) b[j]-=a[j][i]*b[i];
	}return 0;
}
int main(){
	n=read();int i,j;double t1;
	for(i=1;i<=n;i++) scanf("%lf",&ori[i]);
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			scanf("%lf",&t1);
			a[i][j]=2*(t1-ori[j]);b[i]-=ori[j]*ori[j]-t1*t1;
		}
	}
	Gauss();
	for(i=1;i<=n;i++) printf("%.3lf ",b[i]);
}

