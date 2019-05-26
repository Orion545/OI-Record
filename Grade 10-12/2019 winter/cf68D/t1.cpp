#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<unordered_map>
#define ll long long
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
unordered_map<int,double>mp;
double dfs(int u,double lim){
	if(mp[u]<=lim) return lim;
	return (dfs(u<<1,max(lim,mp[u]-mp[u<<1]))+dfs(u<<1|1,max(lim,mp[u]-mp[u<<1|1])))*0.5;
}
int h,q;
int main(){
	h=read();q=read();char s[10];int i,t1,t2;
	while(q--){
		scanf("%s",s);
		if(s[0]=='d') printf("%.6lf\n",dfs(1,0));
		else{
			t1=read();t2=read();
			for(;t1;t1/=2) mp[t1]+=t2;
		}
	}
}
