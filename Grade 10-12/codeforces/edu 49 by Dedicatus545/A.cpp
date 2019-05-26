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
	int T=read(),n,i;char s[1010];
	while(T--){
		cin>>n>>s;bool flag=1;
		
		for(i=0;i<n/2;i++){
			int tmp=abs(s[i]-s[n-i-1]);
			if(tmp!=0&&tmp!=2){
				puts("NO");flag=0;break;
			}
		}
		if(flag) puts("YES");
	}
}
