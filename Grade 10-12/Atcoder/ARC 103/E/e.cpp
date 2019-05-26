#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cassert>
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
char ss[100010];
int n,a[100010];
vector<int>s;
vector<int>e[100010]; 
int main(){
	int i;
	scanf("%s",ss);n=strlen(ss);
	for(i=0;i<n;i++) a[i+1]=(ss[i]=='1');
	for(i=1;i<n;i++){
		if(!a[i]) continue;
		if(!a[n-i]){
			puts("-1");return 0;
		}
		if(i<=n-i) s.push_back(i);
	}
	if(a[1]!=1||a[n]==1){
		puts("-1");return 0;
	}
	int top=1,cnt=1;
	for(i=1;i<s.size();i++){
		int num=s[i]-s[i-1]-1;
		cnt++;e[cnt].push_back(top);top=cnt;
		while(num) cnt++,e[top].push_back(cnt),num--;
	}
	cnt++;e[cnt].push_back(top);top=cnt;
	while((++cnt)<=n) e[top].push_back(cnt);
	for(i=1;i<=n;i++){
		for(auto u:e[i]){
			printf("%d %d\n",i,u);
		}
	}
}
