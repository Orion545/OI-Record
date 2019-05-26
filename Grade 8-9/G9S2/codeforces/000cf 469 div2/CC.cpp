#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<ctime>
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
int main(){
	freopen("in.txt","w",stdout);
	srand(time(NULL));
	int n=150000;
	for(int i=1;i<=50000;i++) cout<<0;
	for(int i=50001;i<=n;i++){
		cout<<rand()%2;
	}
	for(int i=1;i<=50000;i++) cout<<0;
}
