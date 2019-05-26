#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
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
int n,m;
bool a[510][510],b[510][510];
int main(){
	int i,j;char s[510];
	n=read();m=read();
	for(i=1;i<=n;i++){
		scanf("%s",s);
		for(j=1;j<=m;j++){
			if(s[j-1]=='#') a[i][j]=b[i][j]=1;
		}
	}
	for(i=1;i<=n;i++) a[i][1]=1,b[i][m]=1;
	for(i=1;i<=n;i++){
		for(j=2;j<m;j++){
			if(i%2) a[i][j]=1;
			else b[i][j]=1;
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(a[i][j]) putchar('#');
			else putchar('.');
		}
		putchar('\n');
	}
	putchar('\n');
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(b[i][j]) putchar('#');
			else putchar('.');
		}
		putchar('\n');
	}
}
