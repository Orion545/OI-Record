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
int main(){
	freopen("1.in","w",stdout);
	int n=100,m=100,i,j;
	cout<<n<<' '<<m<<'\n';
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(i==50&&j==50) putchar('E');
			else putchar('o');
		}
		putchar('\n');
	}
}
