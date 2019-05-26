#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
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
int n,m,x[100010],root[100010],cnt,ch[4000010][2];
ll a[4000010];
int insert(int l,int r,int pos,int pre){
	int cur=++cnt;
	a[cur]=a[pre]+(ll)pos;ch[cur][0]=ch[pre][0];ch[cur][1]=ch[pre][1];
//	cout<<"insert "<<l<<' '<<r<<' '<<pos<<' '<<pre<<' '<<cur<<' '<<a[cur]<<'\n';
	if(l==r) return cur;
	int mid=(l+r)>>1;
	if(mid>=pos) ch[cur][0]=insert(l,mid,pos,ch[pre][0]);
	else ch[cur][1]=insert(mid+1,r,pos,ch[pre][1]);
	return cur;
}
ll query(int l,int r,int ql,int qr,int pre,int cur){
	if(l>=ql&&r<=qr) return a[cur]-a[pre];
	int mid=(l+r)>>1;ll re=0;
	if(mid>=ql) re+=query(l,mid,ql,qr,ch[pre][0],ch[cur][0]);
	if(mid<qr) re+=query(mid+1,r,ql,qr,ch[pre][1],ch[cur][1]);
	return re;
}
int main(){
	n=read();int i,t1,t2;root[0]=0;
	ll ans,lim;
	for(i=1;i<=n;i++) x[i]=read(),root[i]=insert(1,1e9,x[i],root[i-1]);
	m=read();
	while(m--){
		t1=read();t2=read();
		lim=1;ans=0;
		ans=query(1,1e9,1,lim,root[t1-1],root[t2]);
		while(ans>=lim&&lim<=1e9){
			lim=min((ll)1e9,ans+1);
			ans=query(1,1e9,1,lim,root[t1-1],root[t2]);
		}
		printf("%lld\n",ans+1);
	}
}
