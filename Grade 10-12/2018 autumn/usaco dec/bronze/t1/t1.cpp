#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#define ll long long
using namespace std;
inline ll read(){
	ll re=0,flag=1;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(isdigit(ch)) re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
ll l[10],a[10];
int main(){
	freopen("mixmilk.in","r",stdin);
	freopen("mixmilk.out","w",stdout);
	l[0]=read();
	a[0]=read();
	l[1]=read();
	a[1]=read();
	l[2]=read();
	a[2]=read();
	ll i,cur=2,nex=0;
	for(i=1;i<=100;i++){
		cur=(cur+1)%3;nex=(nex+1)%3;
		a[nex]+=a[cur];a[cur]=0;
		if(a[nex]>l[nex]) a[cur]+=a[nex]-l[nex],a[nex]=l[nex];
	}
	cout<<a[0]<<'\n'<<a[1]<<'\n'<<a[2]<<'\n';
}
