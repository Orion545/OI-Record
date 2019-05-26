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
//	freopen("in.in","w",stdout);
	srand(time(NULL));
	int n=3000,m=1000,Q=1000,i;
	cout<<n<<' '<<m<<' '<<Q<<'\n';
	for(i=1;i<=m;i++){
		cout<<random(1,1000)<<' '<<random(1,1e9)<<'\n';
	}
	for(i=1;i<=Q;i++) cout<<random(1,3000)<<'\n';
}
