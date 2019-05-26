#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
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
int n,a[110];char s[110];
int main(){
	n=read();scanf("%s",s);int i,j;
	for(i=1;i<=n;i++){
		if(s[i-1]=='?') continue;
		if(s[i-1]=='C') a[i]=1;
		if(s[i-1]=='M') a[i]=2;
		if(s[i-1]=='Y') a[i]=3;
		if(i>1&&s[i-1]==s[i-2]){
			printf("No\n");return 0;
		}
	}
	for(i=2;i<n;i++){
		if(!a[i]&&a[i-1]&&a[i+1]&&(a[i-1]!=a[i+1])){
			a[i]=6-a[i-1]-a[i+1];
		}
	}
	for(i=1;i<=n;i++){
		if(a[i]==0){
			printf("Yes\n");return 0;
		}
	}
	printf("No\n");return 0;
}
