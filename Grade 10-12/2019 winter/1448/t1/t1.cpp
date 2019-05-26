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
int n;double x[1010],y[1010];
int main(){
	int T=read();
	while(T--){
		n=read();int i,j,k,l;
		for(i=1;i<=n;i++) x[i]=read(),y[i]=read();
		for(i=1;i<=n;i++){
			for(j=i+1;j<=n;j++){
				//take node i and j as signs
