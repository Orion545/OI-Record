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
	srand(time(NULL));
	int n=13,S=random(1,2000),i;
	int T=5;
	cout<<T<<'\n';
	while(T--){
		cout<<n<<' '<<(S=random(1,2000))<<'\n';
		for(i=1;i<=n;i++) cout<<random(1,100)<<' '<<random(1,100)<<'\n';
	}
}
