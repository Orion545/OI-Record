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
int n=10,m=20,k=3;
int main(){
	srand(time(NULL));
	cout<<n<<' '<<m<<' '<<k<<'\n';int i,t1,t2,t3,t4;
	for(i=1;i<n;i++){
		t1=i+1;t2=random(1,i);t3=random(1,1e9);t4=random(0,1);
		cout<<t1<<' '<<t2<<' '<<t3<<' '<<t4<<'\n';
	}
	for(i=n;i<=m;i++){
		t1=random(2,n);t2=random(1,t1-1);t3=random(1,1e9);t4=random(0,1);
		cout<<t1<<' '<<t2<<' '<<t3<<' '<<t4<<'\n';
	}
}
