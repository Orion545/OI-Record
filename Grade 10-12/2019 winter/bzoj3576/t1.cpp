#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
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
int f[100010],val[100010],tag,x,y,ans,T,F;
void dfs(int n){
	if(~f[n]) return;
	if(n<F){f[n]=0;return;}
	int i,s,j;
	for(i=2;i<=n;i=j+1){
		j=n/(n/i);
		dfs(n/i);
		if(n!=2) dfs(n/i+1);
	}
	tag++;
	for(i=2;i<=n;i=j+1){
		j=n/(n/i);
		s=0;
		if(n%i&1) s^=f[n/i+1];
		if((i-n%i)&1) s^=f[n/i];
		val[s]=tag;
		if(i!=j){
			s=0;
			if(n%(i+1)&1) s^=f[n/i+1];
			if((i+1-n%(i+1))&1) s^=f[n/i];
			val[s]=tag;
		}
	}
	for(i=0;val[i]==tag;i++);
	f[n]=i;
}
int main(){
	T=read();F=read();
	memset(f,-1,sizeof(f));
	while(T--){
		x=read();ans=0;
		while(x--){
			y=read();dfs(y);
			ans^=f[y];
		}
		if(ans) putchar('1');
		else putchar('0');
		putchar(' ');
	}
}
