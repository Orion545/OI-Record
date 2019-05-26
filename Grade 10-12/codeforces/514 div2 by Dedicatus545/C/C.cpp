#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<algorithm>
#define ll long long
using namespace std;
inline ll read(){
	ll re=0,flag=1;char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
using namespace std;
void dfs(int n,int v){
	if(!n) return;
	if(n==1){cout<<v<<' ';return;}
	else if(n==2){cout<<v<<' '<<2*v<<' ';return;}
	else if(n==3){cout<<v<<' '<<v<<' '<<(v+(v<<1))<<' ';return;}
	else{
		int JJJ;
		for(JJJ=1;JJJ<=((n+1)>>1);JJJ++) cout<<v<<' ';
		dfs(n/2,v*2);
	}
}
int main(){
	int n=read();
	dfs(n,1);
}
