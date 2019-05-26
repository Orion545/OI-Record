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
int main(){
	int T=read();char s[110];
	while(T--){
		scanf("%s",s);int n=strlen(s),i,t1=0,t2=0,t3=0;
		for(i=0;i<n;i++){
			if(s[i]>='a'&&s[i]<='z') t1++;
			if(s[i]>='A'&&s[i]<='Z') t2++;
			if(s[i]>='0'&&s[i]<='9') t3++;
		}
		if(t1&&t2&&!t3){
			if(t1==1){
				i=0;
				while(s[i]>='a'&&s[i]<='z') i++;
				s[i]='0';goto out;
			}
			if(t2==1){
				i=0;
				while(s[i]>='A'&&s[i]<='Z') i++;
				s[i]='0';goto out;
			}
			s[0]='0';
		}
		if(t1&&!t2&&t3){
			if(t1==1){
				i=0;
				while(s[i]>='a'&&s[i]<='z') i++;
				s[i]='A';goto out;
			}
			if(t3==1){
				i=0;
				while(s[i]>='0'&&s[i]<='9') i++;
				s[i]='A';goto out;
			}
			s[0]='A';
		}
		if(!t1&&t2&&t3){
			if(t2==1){
				i=0;
				while(s[i]>='A'&&s[i]<='Z') i++;
				s[i]='a';goto out;
			}
			if(t3==1){
				i=0;
				while(s[i]>='0'&&s[i]<='9') i++;
				s[i]='a';goto out;
			}
			s[0]='a';
		}
		if(t1&&!t2&&!t3){
			s[0]='A';s[1]='0';
		}
		if(!t1&&t2&&!t3){
			s[0]='a';s[1]='0';
		}
		if(!t1&&!t2&&t3){
			s[0]='a';s[1]='A';
		}
		out:
		for(i=0;i<n;i++) putchar(s[i]);
		putchar('\n');
	}
}
