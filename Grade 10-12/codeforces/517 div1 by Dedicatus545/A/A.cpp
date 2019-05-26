#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<vector>
using namespace std;
#define ll long long
inline int read(){
	int re=0,flag=1;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(isdigit(ch)) re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
ll n,m;bool vis[100010];
ll sum(ll i){return i*(i+1)/2;}
vector<int>ans,s;
int main(){
	n=read();m=read();
	ll tot=n+m,i;
	for(i=0;i<=100000;i++){
		if((sum(i)<=tot)&&(sum(i+1)>tot)) break;
	}
	if(i==0){
		cout<<0<<'\n'<<'\n'<<0<<'\n'<<'\n';
		return 0;
	}
//	cout<<"get "<<i<<'\n';
	int x=max(n,m),cur=i,cnt=i;
	while(x>0&&cur>0){
//		cout<<"do "<<cur<<' '<<x<<'\n';
		while(cur>x) cur--;
		if(cur<=0) return 0;
		ans.push_back(cur);x-=cur;vis[cur]=1;
		cur--;
	}
//	cout<<"fin "<<ans.size()<<'\n';
	x=min(n,m),cur=i,cnt=i;
	while(x>0&&cur>0){
//		cout<<"do "<<cur<<' '<<x<<'\n';
		while(cur>x||vis[cur]) cur--;
		if(cur<=0) break;
		s.push_back(cur);x-=cur;
		cur--;
	}
	if(n>m){
		cout<<ans.size()<<'\n';
		for(auto xx:ans) cout<<xx<<' ';
		cout<<'\n';
		cout<<s.size()<<'\n';
		for(auto xx:s) cout<<xx<<' ';
		cout<<'\n';
	}
	else{
		cout<<s.size()<<'\n';
		for(auto xx:s) cout<<xx<<' ';
		cout<<'\n';
		cout<<ans.size()<<'\n';
		for(auto xx:ans) cout<<xx<<' ';
		cout<<'\n';
	}
}

