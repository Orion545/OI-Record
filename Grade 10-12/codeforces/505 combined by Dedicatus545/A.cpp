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
int n;char s[100010];int cnt[26]={0};
int main(){
	n=read();scanf("%s",s);int i;
	for(i=0;i<n;i++) cnt[s[i]-'a']++;
	if(n==1){
		puts("Yes");return 0;
	}
	for(i=0;i<26;i++) if(cnt[i]>1){
		puts("Yes");return 0;
	}
	puts("No");
}
