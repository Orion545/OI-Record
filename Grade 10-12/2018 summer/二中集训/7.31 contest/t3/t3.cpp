#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
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
int n,q,ch[4000010][2],siz[4000010],cur,root[200010],a[200010],cnt;
int insert(int l,int r,int pos,int pre){
	int cur=++cnt,mid=(l+r)>>1;
	siz[cur]=siz[pre]+1;ch[cur][0]=ch[pre][0];ch[cur][1]=ch[pre][1];
	if(l==r) return cur;
	if(mid>=pos) ch[cur][0]=insert(l,mid,pos,ch[pre][0]);
	else ch[cur][1]=insert(mid+1,r,pos,ch[pre][1]);
	return cur;
}
int query(int l,int r,int ql,int qr,int cur,int pre){
	int mid=(l+r)>>1,re=0;
//	cout<<"query "<<l<<' '<<r<<' '<<ql<<' '<<qr<<' '<<siz[cur]-siz[pre]<<'\n';
	if(l>=ql&&r<=qr) return siz[cur]-siz[pre];
	if(mid>=ql) re+=query(l,mid,ql,qr,ch[cur][0],ch[pre][0]);
	if(mid<qr) re+=query(mid+1,r,ql,qr,ch[cur][1],ch[pre][1]);
	return re;
}
int main(){
	n=read();q=read();int i,b,x,l,r,lim=200000,ans,j;
	for(i=1;i<=n;i++) a[i]=read();
	for(i=1;i<=n;i++) root[i]=insert(0,lim,a[i],root[i-1]);
	for(i=1;i<=q;i++){
		b=read();x=read();l=read();r=read();
		ans=0;
		for(j=17;j>=0;j--){
//			cout<<j<<' '<<ans<<' '<<(b&(1<<j))<<' '<<ans-x<<' '<<(ans+(1<<j))-x<<' '<<(ans+(1<<(j+1)))-x<<'\n';
			if(b&(1<<j)){
				if(!query(0,lim,max(0,ans-x),min((ans+(1<<j))-1-x,lim),root[r],root[l-1])) ans|=(1<<j);
			}
			else{
				if(query(0,lim,max(0,(ans+(1<<j))-x),min((ans+(1<<(j+1)))-1-x,lim),root[r],root[l-1])) ans|=(1<<j);
			}
		}
		printf("%d\n",ans^b);
	}
}
