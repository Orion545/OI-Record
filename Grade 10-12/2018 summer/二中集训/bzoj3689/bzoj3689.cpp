#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define inf 0x7fffffff
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
	int a,rk,val;
};
inline bool operator <(node a,node b){
	return a.val>b.val;
}
priority_queue<node>q;
int n,m,a[100010],son[3200010][2],siz[3200010],cnt;
void insert(int num){
	int i,cur=0;bool tmp;
	for(i=30;i>=0;i--){
		tmp=(num&(1<<i));
		if(!son[cur][tmp]) son[cur][tmp]=++cnt;
		cur=son[cur][tmp];siz[cur]++;
	}
}
int query(int num,int rk){
//	cout<<"query "<<num<<' '<<rk<<'\n';
	if(rk>n) return inf;
	int i,cur=0,re=0;bool tmp;
	for(i=30;i>=0;i--){
		tmp=(num&(1<<i));
//		cout<<"	do "<<i<<' '<<tmp<<' '<<cur<<' '<<rk<<' '<<siz[son[cur][tmp]]<<'\n';
		if(rk<=siz[son[cur][tmp]]) cur=son[cur][tmp];
		else re+=(1<<i),rk-=siz[son[cur][tmp]],cur=son[cur][tmp^1];
	}
//	cout<<"ret "<<re<<' '<<cur<<'\n';
	return re;
}
int main(){
	n=read();m=read();int i;node t;
	for(i=1;i<=n;i++){
		a[i]=read();insert(a[i]);
	}
	for(i=1;i<=n;i++){
		t.val=query(a[i],2);t.rk=2;t.a=a[i];
		q.push(t);
	}
	for(i=1;i<=(m<<1);i++){
		t=q.top();q.pop();
		if(i&1) printf("%d ",t.val);
		t.rk++;t.val=query(t.a,t.rk);
		q.push(t);
	}
}
