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
int n,cnt[110];char s[110];
int main(){
	n=read();int i,tmp;
	scanf("%s",s);
	for(i=1;i<=n;i++) tmp=(s[i-1]-'0'),cnt[tmp]++;
	if(cnt[8]*11<=n) cout<<cnt[8];
	else cout<<n/11;
} 
