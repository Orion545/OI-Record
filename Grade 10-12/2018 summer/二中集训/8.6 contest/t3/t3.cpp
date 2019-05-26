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
int n,a[110],now[110];
int main(){
	n=read();int i,maxn=0,cnt=0;
	for(i=1;i<=n;i++) a[i]=read(),maxn=max(maxn,a[i]),now[a[i]]++;
	if(maxn%2){
		for(i=maxn/2+1;i<=maxn;i++){
			if(now[i]<2){
				puts("Impossible");return 0;
			}
		}
		now[maxn/2+1]-=2;
		for(i=0;i<=maxn/2+1;i++){
			if(now[i]){
				puts("Impossible");return 0;
			}
		}
		puts("Possible");
	}
	else{
		if(!now[maxn/2]){
			puts("Impossible");return 0;
		}
		now[maxn/2]--; 
		for(i=maxn/2+1;i<=maxn;i++){
			if(now[i]<2){
				puts("Impossible");return 0;
			}
		}
		for(i=0;i<=maxn/2;i++){
			if(now[i]){
				puts("Impossible");return 0;
			}
		}
		puts("Possible");
	}
}
