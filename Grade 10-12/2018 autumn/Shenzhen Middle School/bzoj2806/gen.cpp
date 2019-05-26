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
char s[1100010];
int main(){
	std::ios::sync_with_stdio(false);
	int n=1000,m=10,len=100,i,j;
	cout<<n<<' '<<m<<'\n';
	for(i=1;i<=m;i++){
		for(j=1;j<=len;j++) cout<<random(0,1);
		cout<<'\n';
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=len;j++) cout<<random(0,1);
		cout<<'\n';
	}
}
