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
int main(){
	string s;cin>>s;int n=s.length(),i=0;
	int a=0,b=0,c=0;
	while(s[i]=='a') a++,i++;
	if(!a){
		printf("NO");return 0;
	}
	while(s[i]=='b') b++,i++;
	if(!b){
		printf("NO");return 0;
	}
	while(s[i]=='c') c++,i++;
	if(c!=a&&c!=b){
		printf("NO");return 0;
	}
	printf("YES");
}
