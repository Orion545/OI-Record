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
int n=15000,K,i,l,r,p;
int main(){
	srand(time(NULL));
	cout<<n<<'\n';
	for(i=1;i<=n;i++){
		l=random(1,1e9);
		r=random(1,1e9);
		p=random(1,998244352);
		if(l>r) swap(l,r);
		printf("%d %d %d\n",l,r,p);
	}
	cout<<(K=random(1,n))<<'\n';
}
