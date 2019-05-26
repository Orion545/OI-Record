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
	int n=10,lim=10,m=10,i,t1,t2,t3;
	cout<<n<<'\n';
	for(i=1;i<=n;i++) cout<<random(1,5)<<' ';
	cout<<'\n'<<m<<'\n';
	for(i=1;i<=m;i++){
		t1=random(1,2);
		if(t1==1){
			t2=random(1,5);t3=random(1,n);
		}
		else{
			t2=random(1,lim);t3=random(1,n);
		}
		cout<<t1<<' '<<t2<<' '<<t3<<'\n';
	}
}
