#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define ll long long
inline int read(){
	int re=0,flag=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='0') flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
} 
int main(){
	freopen("D.in","w",stdout);
	int n=300000;cout<<n<<endl;int i;
	for(i=1;i<=n;i++){
		cout<<rand()*rand()%(1<<30)<<" ";
	}
	cout<<endl;
	for(i=1;i<=n;i++){
		cout<<rand()*rand()%(1<<30)<<" ";
	}
}
