#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
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
int n,col[1010];
string s;
int main(){
	cin>>n;
	int i=1;
	int l=1,r=1e9;
	cout<<1<<' '<<0<<endl;
	cin>>s;
	if(s[0]=='b') col[1]=1;
	else col[1]=0;
	for(i=2;i<=n;i++){
		cout<<(l+r)/2<<' '<<0<<endl;
		cin>>s;
		if(s[0]=='b') col[i]=1;
		else col[i]=0;
		if(col[i]==col[1]) l=(l+r)>>1;
		else r=(l+r)>>1;
	}
	int ans=(l+r)>>1;
	if(col[n]==col[1]){
		cout<<l-1<<' '<<1000000000<<' '<<l<<' '<<1<<endl;
	}
	else{
		cout<<r+1<<' '<<1000000000<<' '<<r<<' '<<1<<endl;
	}
}

