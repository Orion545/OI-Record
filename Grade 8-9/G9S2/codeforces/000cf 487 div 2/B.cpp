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
int n,p;char s[2010];
int main(){
	n=read();p=read();scanf("%s",s);int i,flag=0;
	if(n==p){
//		for(i=0;i<n;i++) if(s[i]=='.') s[i]='0';
//		for(i=0;i<n;i++) cout<<s[i];
		puts("No"); 
		return 0;
	}
	for(i=0;i<n-p;i++){
//		cout<<i<<' '<<s[i]<<' '<<s[i+p]<<'\n';
		if(s[i]==s[i+p]&&(s[i]=='0'||s[i]=='1')) continue;
		flag=1;
		if(s[i]==s[i+p]&&s[i]=='.'){
			s[i]='0';s[i+p]='1';
		}
		if(s[i]!=s[i+p]){
			if(s[i]=='.') s[i]=(s[i+p]=='0')+'0';
			if(s[i+p]=='.') s[i+p]=(s[i]=='0')+'0';
		}
	}
	if(!flag){
		puts("No");return 0;
	}
	for(i=n-p;i<p;i++) if(s[i]=='.') s[i]='0';
	for(i=0;i<n;i++) cout<<s[i];
}
