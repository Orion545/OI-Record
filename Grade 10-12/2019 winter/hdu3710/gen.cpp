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
inline int random(int l,int r){
	return rand()%(r-l+1)+l;
}
int T=1,n=100,m=200;
int main(){
	srand(time(NULL));
	cout<<T<<'\n'<<n<<' '<<m<<'\n';
	int i;
	for(i=2;i<=n;i++){
		cout<<random(1,i-1)<<' '<<i<<' '<<random(1,1e4)<<' '<<0<<'\n';
	}
	for(i=n;i<=m;i++){
		cout<<random(1,n)<<' '<<random(1,n)<<' '<<random(1,1e4)<<' '<<0<<'\n';
	}
}
