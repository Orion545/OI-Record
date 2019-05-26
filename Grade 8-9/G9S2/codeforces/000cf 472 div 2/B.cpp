#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
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
int n,m;ll a[100];
vector<ll>x;
int main(){
	n=read();m=read();ll i,j;char s[110];
	for(i=1;i<=n;i++){
		scanf("%s",s);
		for(j=0;j<m;j++) a[i]+=((ll)(s[j]=='#')<<j);
	}
	x.clear();bool flag;
	for(i=1;i<=n;i++){
		flag=0;
		for(j=0;j<x.size();j++){
			if(a[i]==x[j]){
				flag=1;break;
			}
			if(a[i]&x[j]){
				printf("No\n");return 0;
			}
		}
		if(flag) continue;
		x.push_back(a[i]);
	}
	printf("Yes\n");return 0;
}
