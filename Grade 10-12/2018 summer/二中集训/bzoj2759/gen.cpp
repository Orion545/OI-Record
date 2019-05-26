#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cassert>
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
	ios::sync_with_stdio(false);
	srand(time(NULL));
	int n=30000,i;
	cout<<n<<'\n'; 
	for(i=1;i<=n;i++){
		int tmp=random(1,n);
		while(tmp==i) tmp=random(1,n);
		cout<<random(0,10006)<<' '<<tmp<<' '<<random(0,10006)<<'\n';
	}
	cout<<n<<'\n';
	for(i=1;i<=n;i++){
		if(random(0,1)){
			cout<<"A "<<random(1,n)<<'\n';
		}
		else{
			int j=random(1,n);
			int tmp=random(1,n);
			while(tmp==j) tmp=random(1,n);
			cout<<"C "<<j<<' '<<random(0,10006)<<' '<<tmp<<' '<<random(0,10006)<<'\n';
		}
	}
}
