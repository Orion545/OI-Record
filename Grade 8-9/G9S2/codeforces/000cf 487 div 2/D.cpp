#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
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
int n,L,maxw,l[100010],r[100010],cntl,cntr;
int main(){
	n=read();L=read();maxw=read();int i,t1,t2;
	for(i=1;i<=n;i++){
		t1=read();t2=read();
		if(t2==1) r[++cntr]=t1;
		else l[++cntl]=t1;
	}
	sort(l+1,l+cntl+1);sort(r+1,r+cntr+1);
} 
