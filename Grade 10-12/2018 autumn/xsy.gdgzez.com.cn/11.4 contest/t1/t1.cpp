/*

宣告——
汝身听吾号令，托付吾之命运于汝之剑，
应圣杯之召，若汝遵从此意志此理，回应吧。
在此起誓，吾愿成就世间一切之善行，吾愿诛尽世间一切之恶行。
汝为身缠三大言灵之七天，从抑止之轮显现吧，天秤之守护者！

*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
#include<vector>
#include<queue>
#define MOD 2333
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
int a[50][50],w[50][50],tr[50][50],n,m,q;
void mula(){
	int i,j,re[50][50]={0};
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			re[1][i]=(re[1][i]+w[i][j]*a[1][j])%MOD;
		}
	}
	memcpy(a,re,sizeof(re));
}
void mulAT(){
	int i,j,re[50][50]={0};
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			re[1][i]=(re[1][i]+tr[i][j]*a[1][j])%MOD;
		}
	}
	memcpy(a,re,sizeof(re));
}
void mulw(){
	int i,j,k,re[50][50]={0};
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			for(k=1;k<=n;k++){
				re[i][j]=(re[i][j]+w[i][k]*w[k][j])%MOD;
			}
		}
	}
	memcpy(w,re,sizeof(re));
}
void qpow(int b){
	while(b){
		if(b&1) mula();
		mulw();b>>=1;
	}
}
int main(){
	freopen("l.in","r",stdin);
	freopen("l.out","w",stdout);
	n=read();m=read();int i,t1,t2,s,t;
	for(i=1;i<=m;i++){
		t1=read();t2=read();
		tr[t1][t2]++;
		if(t2!=t1) tr[t2][t1]++;
	}
	q=read();
	while(q--){
		s=read();t=read();
		t1=read();t2=read();
		memset(a,0,sizeof(a));
		memcpy(w,tr,sizeof(tr));
		a[1][s]=1;
		qpow(t1);
		i=t1;int ans=0;
		while(i<=t2){
			ans=(ans+a[1][t])%MOD;
			mulAT();i++;
		}
		printf("%d\n",ans);
	}
}
/*
2 1
1 2
3
1 2 1 1
1 2 2 3
1 2 1 3

*/
