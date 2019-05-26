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
int n,m,l[100010],r[100010],s[510][510],ok[510];
int main(){
	n=read();m=read();int i,j,flag=0,k,ans=0;
	for(i=1;i<=m;i++) l[i]=read(),r[i]=read();
	for(i=1;i<=n;i++){
		ok[i]=1;
		s[i][i]=1;
		for(j=m;j>=1;j--){
			if(!s[i][l[j]]&&!s[i][r[j]]) continue;
			if(s[i][l[j]]&&s[i][r[j]]){
				ok[i]=0;break;
			}
			s[i][l[j]]=s[i][r[j]]=1;
		}
	}
	for(i=1;i<n;i++){
		if(!ok[i]) continue; 
		for(j=i+1;j<=n;j++){
			if(!ok[j]) continue;
			flag=0;
			for(k=1;k<=n;k++) flag|=s[i][k]&s[j][k];
			ans+=(flag==0);
		}
	}
	cout<<ans;
} 
