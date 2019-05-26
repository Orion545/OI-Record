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
int ans[10000010];
int check(int x){
	int re=0,t[10],cnt=0;
	while(x) t[++cnt]=x%10,x/=10;
	for(int i=1;i<=cnt;i++) re=re*10+t[i];
	return re;
} 
int main(){
	int tmp;
	for(int i=1;i<=10000000;i++){
		tmp=check(i);
		if(i<=tmp) ans[tmp-i]++;
	}
	int n=read();printf("%d\n",ans[n]);
}
