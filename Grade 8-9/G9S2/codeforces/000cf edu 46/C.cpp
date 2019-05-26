#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
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
struct node{
	ll pos,t;
}a[500010];
bool cmp(node l,node r){
	return l.pos<r.pos;
}
ll n,cnt;
ll ans[200010];
int main(){
	n=read();ll i,t1,t2;
	for(i=1;i<=n;i++){
		t1=read();t2=read();
		a[++cnt]=(node){t1,1};
		a[++cnt]=(node){t2+1,-1};
	}
	sort(a+1,a+cnt+1,cmp);
//	for(i=1;i<=cnt;i++) cout<<i<<' '<<a[i].pos<<' '<<a[i].t<<'\n';
	ll tmp=0;i=1;ll j=i,pre;
	while(a[i].pos==a[j].pos) tmp+=a[j].t,j++;
	pre=1;
	for(i=j;i<=cnt;i=j){
//		cout<<i<<' '<<pre<<' '<<tmp<<'\n';
		ans[tmp]+=(a[i].pos-a[pre].pos);pre=i;
		j=i;
		while(a[i].pos==a[j].pos) tmp+=a[j].t,j++;
	}
	for(i=1;i<=n;i++){
		printf("%I64d ",ans[i]);
	}
}
