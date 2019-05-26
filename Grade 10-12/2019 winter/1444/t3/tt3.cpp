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
int n,m,d,a[410][410];
int main(){
	int T=read();
	while(T--){
		int i,j,k=0,l,ans;
		n=read();m=read();d=read();
		ans=n*m/d+(n*m%d!=0);
		l=1;
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				if(k==d) l++,k=0;
				k++;
				a[i][j]=l;
			}
		}
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++) printf("%d ",a[i][j]);
			putchar('\n');
		}
	}
}
