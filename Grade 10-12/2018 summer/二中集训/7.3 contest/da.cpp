#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define ll long long
#define inf 1e15
using namespace std;
inline ll read(){
	ll re=0,flag=1;char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
int main(){
	freopen("data.in","w",stdout);
	
	int n=50000;
	cout<<n<<' '<<n<<'\n';
	for(int i=1;i<=n;i++) cout<<i-1<<'\n';
	for(int i=1;i<=n;i++){
		cout<<"0 "<<n-1<<' '<<i-1<<'\n';
	}
}
