#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<ctime>
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
int random(int l,int r){
	return rand()%(r-l+1)+l;
}
int main(){
	srand(time(NULL));
	int n=999999999,a=random(10000,30000)*random(10000,30000);
	int b=random(10000,30000)*random(10000,30000),K=100000;
	b=a;
	cout<<n<<' '<<a<<' '<<b<<' '<<K<<'\n';
	for(int i=1;i<=K;i++){
		int t=random(0,1);
		if(t) putchar('+');
		else putchar('-');
	}
	puts("");
}

