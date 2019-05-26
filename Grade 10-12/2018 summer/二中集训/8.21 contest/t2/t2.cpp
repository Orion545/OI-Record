#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cassert>
#include<vector>
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
int n,m,l[300010],r[300010],ans[100010],a[100010];
vector<int>q[100010];
int lowbit(int x){
	return x&(-x);
}
void change(int x,int val){
//	cout<<"change "<<x<<' '<<val<<'\n';
	for(;x<=m;x+=lowbit(x)) a[x]+=val;
}
int sum(int x){
	int re=0;
//	cout<<"getsum "<<x<<' ';
	for(;x>0;x-=lowbit(x)) re+=a[x];
//	cout<<re<<'\n';
	return re;
}
int main(){
	n=read();m=read();int i,j,ans,totn=n;
	for(i=1;i<=n;i++){
		l[i]=read();r[i]=read();
		q[r[i]-l[i]+1].push_back(l[i]);
	}
	for(j=1;j<=m;j++){
		for(i=0;i<q[j].size();i++){
			change(q[j][i],1);change(q[j][i]+j,-1);
		}
		ans=0;totn-=q[j].size();
		for(i=j;i<=m;i+=j) ans+=sum(i);
		printf("%d\n",ans+totn);
	}
}
