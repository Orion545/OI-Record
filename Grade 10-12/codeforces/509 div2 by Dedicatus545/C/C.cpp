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
struct node{
	int val,num,vis;
}a[200010];
bool cmp(node l,node r){
	return l.val<r.val;
}
bool bk(node l,node r){
	return l.num<r.num;
}
int n,m,d,c[200010];
int main(){
	n=read();m=read();d=read();int i,st=1,ans=0;
	for(i=1;i<=n;i++) a[i].val=read(),a[i].num=i;
	sort(a+1,a+n+1,cmp);
	for(i=1;i<=n;i++) c[i]=a[i].val;
	while(st<=n){
		i=st;
		ans++;
		while(i<=n){
//			cout<<i<<'\n';
			a[i].vis=ans;
			i=upper_bound(c+i+1,c+n+1,c[i]+d)-c;
			while(a[i].vis) i++;
		}
		while(a[st].vis) st++;
	}
	sort(a+1,a+n+1,bk);
	printf("%d\n",ans);
	for(i=1;i<=n;i++) printf("%d ",a[i].vis);
}
