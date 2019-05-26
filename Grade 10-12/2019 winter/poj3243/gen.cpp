#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<ctime>
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
int random(int l,int r){
	return rand()%(r-l+1)+l;
}
int main(){
	int a,b,p,T=200;
	srand(time(NULL));
	while(T--){
		a=random(1,1e9);
		b=random(1,1e9);
		p=random(1,100);
		cout<<a<<' '<<p<<' '<<b<<'\n';
	}
	puts("0 0 0");
}
