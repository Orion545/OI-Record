#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cassert>
#define ll long long
#define pb push_back
using namespace std;
int s[105];
int ASDASD[105];
int QWEQWE[105];
int flag=-1;
vector<int>e[105];
vector<int>cnt;
vector<int>fa;
void empty(){}
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
	int n,i,j;n=read();
	for(i=1;i<=n;i++){
		s[i]=read();
		ASDASD[s[i]]++;
		e[s[i]].pb(i);
	}
	for(i=0;i<=100;i++){
		if(!ASDASD[i]) continue;
		if(ASDASD[i]==1) 
			cnt.pb(e[i][0]);
		else fa.pb(i);
	}
	if(cnt.size()%2){
		for(i=0;i<fa.size();i++){
			if(ASDASD[fa[i]]>2){
				for(j=1;j<e[fa[i]].size();j++) QWEQWE[e[fa[i]][j]]=2;
				cnt.pb(e[fa[i]][0]);
				flag=fa[i];
				goto jump;
			}
		} 
		puts("NO");
		return 0;
	}
	jump:empty();
	for(i=0;i<fa.size();i++) 
		if(ASDASD[fa[i]]%2==0&&flag!=fa[i]) 
			for(j=0;j<e[fa[i]].size();j++) 
				QWEQWE[e[fa[i]][j]]=2;
	puts("YES");
	for(i=0;i<(cnt.size()>>1);i++)
		QWEQWE[cnt[i]]=2;
	for(i=(cnt.size()>>1);i<cnt.size();i++) 
		QWEQWE[cnt[i]]=1;
	for(i=1;i<=n;i++){
		if(QWEQWE[i]==1) putchar('A');
		else putchar('B');
	}
	return 0;
}
