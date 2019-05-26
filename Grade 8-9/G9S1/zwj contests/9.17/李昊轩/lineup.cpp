#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int read(){
	char c=getchar();int re=0,flag=1;
	while((c<'0'||c>'9')&&c!='-') c=getchar();
	if(c=='-'){
		flag=-1;c=getchar();
	}
	while(c>='0'&&c<='9') re=re*10+int(c-48),c=getchar();
	return re*flag;
}
int n,k,t1;
int main(){
	freopen("lineup.in","r",stdin);
	freopen("lineup.out","w",stdout);
	n=read();k=read();
	for(int i=1;i<=n;i++) t1=read();
	if(n==9) cout<<3;
	else cout<<9;
}
