#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cassert>
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
int n,m;
char s[200010],t[200010];
int main(){
	n=read();m=read();int i,flag=0;
	scanf("%s",s);scanf("%s",t);
	for(i=0;i<n;i++) if(s[i]=='*') flag=1;
	if(!flag){
		if(n!=m){
			 	puts("NO");return 0;
		}
		for(i=0;i<n;i++) if(s[i]!=t[i]){
			puts("NO");return 0;
		}
		puts("YES");
	}
	else{
		if(n>m+1){
			puts("NO");return 0;
		}
		for(i=0;i<n&&s[i]!='*';i++) if(s[i]!=t[i]){
			puts("NO");return 0;
		}
		int j=m-1;
		for(i=n-1;i>=0&&s[i]!='*';i--,j--) if(s[i]!=t[j]){
			puts("NO");return 0;
		}
		puts("YES"); 
	}
}
