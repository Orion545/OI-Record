#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#define ll long long
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
int n,m,a[100010],pre[100010],root[100010];
int ch[2000010][2],minn[2000010],maxn[2000010],cnt;
inline void insert(int &cur,int pre,int l,int r,int pos,int ql,int qr){
	cur=++cnt;
	ch[cur][0]=ch[pre][0],ch[cur][1]=ch[pre][1];
	minn[cur]=minn[pre];maxn[cur]=maxn[pre];
	if(l==r){minn[cur]=ql;maxn[cur]=qr;return;}
	int mid=(l+r)>>1;
	if(mid>=pos) insert(ch[cur][0],ch[pre][0],l,mid,pos,ql,qr);
	else insert(ch[cur][1],ch[pre][1],mid+1,r,pos,ql,qr);
	minn[cur]=min(minn[ch[cur][0]],minn[ch[cur][1]]);
	maxn[cur]=max(maxn[ch[cur][0]],maxn[ch[cur][1]]);
//	cout<<"finish insert "<<cur<<' '<<minn[cur]<<' '<<maxn[cur]<<' '<<l<<' '<<r<<' '<<ql<<' '<<qr<<' '<<ch[cur][0]<<' '<<ch[cur][1]<<'\n';
}
inline int query(int cur,int l,int r,int lim){
//	cout<<"query "<<l<<' '<<r<<' '<<cur<<' '<<lim<<' '<<minn[cur]<<' '<<maxn[cur]<<'\n';
	if(l==r) return (minn[cur]<=lim&&maxn[cur]>=lim)?l:0;
	int mid=(l+r)>>1,re;
	if(minn[ch[cur][1]]<=lim&&maxn[ch[cur][1]]>=lim){
		re=query(ch[cur][1],mid+1,r,lim);
		if(re) return re;
	}
	return query(ch[cur][0],l,mid,lim);
}
int main(){
	n=read();m=read();int i,t1,t2,lastans=0;
	minn[0]=1e9;maxn[0]=0;
	for(i=1;i<=n;i++){
		a[i]=read();
		insert(root[i],root[i-1],1,n,a[i],pre[a[i]]+1,i);
		pre[a[i]]=i;
	}
	while(m--){
		t1=read();t2=read();
		t1=(lastans+t1)%n+1;
		t2=(lastans+t2)%n+1;
		if(t1>t2) swap(t1,t2);
//		cout<<"*********************input "<<t1<<' '<<t2<<'\n';
		printf("%d\n",lastans=query(root[t2],1,n,t1));
	}
}
