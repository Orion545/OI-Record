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
int n,p[1010],m1,m2,m3,m4,m5,m6,m7;char s[10];
int main(){
	n=read();int i;
	m1=m2=m3=m4=m5=m6=m7=1e8;
	for(i=1;i<=n;i++){
		p[i]=read();scanf("%s",s);
		sort(s,s+strlen(s));
		if(!strcmp(s,"A")) m1=min(m1,p[i]);
		if(!strcmp(s,"B")) m2=min(m2,p[i]);
		if(!strcmp(s,"C")) m3=min(m3,p[i]);
		if(!strcmp(s,"AB")) m4=min(m4,p[i]),m1=min(m1,p[i]),m2=min(m2,p[i]);
		if(!strcmp(s,"AC")) m5=min(m5,p[i]),m1=min(m1,p[i]),m3=min(m3,p[i]);
		if(!strcmp(s,"BC")) m6=min(m6,p[i]),m2=min(m2,p[i]),m3=min(m3,p[i]);
		if(!strcmp(s,"ABC")) m7=min(m7,p[i]),m1=min(m1,p[i]),m2=min(m2,p[i]),m3=min(m3,p[i]);
	}
	int ans=min(m1+m2+m3,min(m1+m6,min(m2+m5,min(m3+m4,m7))));
	if(ans>=1e7) cout<<-1<<'\n';
	else cout<<ans<<'\n';
}
