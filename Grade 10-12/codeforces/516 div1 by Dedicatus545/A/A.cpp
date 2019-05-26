#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
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
int n;char s[100010];
int cnt[110];
int main(){
	n=read();int i;
	scanf("%s",s);
	sort(s,s+n);
	for(i=0;i<n;i++) cout<<s[i];
	puts("");
}

