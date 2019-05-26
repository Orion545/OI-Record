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
int n;char a[1010];
int main(){
	n=read();scanf("%s",a);int i;
	if(n==1){
		if(a[0]=='1') puts("Yes");
		else puts("No");
		return 0;
	}
	if((a[0]=='0'&&a[1]=='0')||(a[n-2]=='0'&&a[n-1]=='0')){
		puts("No");return 0;
	}
	for(i=1;i<n;i++){
		if(a[i]==a[i-1]&&a[i]=='1'){
			printf("No");return 0;
		}
	}
	for(i=2;i<n;i++){
		if(a[i]==a[i-1]&&a[i-1]==a[i-2]&&a[i]=='0'){
			puts("No");return 0;
		}
	}
	puts("Yes");
} 
