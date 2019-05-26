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
inline int qpow(int a,int b,int m){
	int re=1;
	while(b){
		if(b&1) re=1ll*re*a%m;
		a=1ll*a*a%m;b>>=1;
	}
	return re;
}
int MOD,n,m;char s[1000010];
int main(){
	srand(20030316);
	int T=read(),i,j,k,flag,re,cur,tmp;
	while(T--){
		scanf("%s",s+1);
		n=strlen(s+1);
		m=read();re=1;
		for(k=1;k<=10;k++){
			flag=0;
			MOD=rand()%200000+1;
			cur=0;
			for(i=1;i<=n;i++){
				cur=(cur*10+s[i]-'0');
				if(cur>=MOD) cur%=MOD;
			}
			for(i=0;i<MOD;i++){
				if(qpow(i,m,MOD)==cur){
					flag=1;
					break;
				}
			}
			if(!flag){
				puts("N");
				re=0;
				break;
			}
		}
		if(re) puts("Y");
	}
}
