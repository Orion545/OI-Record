#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
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
int pre[100010][26],n,q; 
char s[100010];
int main(){
	int T=read(),i,t1,t2,cnt=0;
	while(T--){
		printf("Case #%d:\n",++cnt);
		n=read();q=read();
		scanf("%s",s);memset(pre,0,sizeof(pre));
		for(i=0;i<n;i++){
			memcpy(pre[i+1],pre[i],sizeof(pre[i]));
			pre[i+1][s[i]-'A']++;
		}
		while(q--){
			t1=read();t2=read();
			for(i=0;i<26;i++){
				if(pre[t2][i]-pre[t1-1][i]){
					printf("%d\n",pre[t2][i]-pre[t1-1][i]);
					break; 
				}
			}
		}
	}
}

