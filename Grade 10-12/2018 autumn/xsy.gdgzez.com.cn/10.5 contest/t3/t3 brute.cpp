#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cassert>
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
int n,m,a[1010][1010];
vector<int>x;
void empty(){}
int main(){
	n=read();m=read();int i,s,t1,t2,ans=0;
	for(i=1;i<=m;i++){
		t1=read();t2=read();t1++;t2++;
		a[t1][t2]=a[t2][t1]=1;
	}
	for(s=1;s<(1<<n);s++){
		x.clear();
		for(i=1;i<=n;i++) if(s&(1<<(i-1))) x.push_back(i);
		for(auto u:x){
			for(auto v:x){
				if(a[u][v]) goto b;
			}
		}
		for(i=1;i<=n;i++){
			if(s&(1<<(i-1))) continue;
			bool flag=0;
			for(auto u:x){
				if(a[u][i]) flag=1;
			}
			if(!flag) goto b;
		}
		ans++;
		b:empty();
	}
	cout<<ans<<'\n';
} 
