#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
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
int rt[4000010],cnt,ch[40000010][2],lazy[40000010];ll siz[40000010];
int n,m;
int UPPERql,UPPERqr,UPPERqql,UPPERqqr,LOWERql,LOWERqr;
void push(int l,int r,int cur){
	if(l==r||!lazy[cur]) return;
	int mid=(l+r)>>1;
//	assert(cnt<=40000000);
	if(!ch[cur][0]) ch[cur][0]=++cnt;
	siz[ch[cur][0]]+=(mid-l+1)*lazy[cur];lazy[ch[cur][0]]+=lazy[cur];
	if(!ch[cur][1]) ch[cur][1]=++cnt;
	siz[ch[cur][1]]+=(r-mid)*lazy[cur];lazy[ch[cur][1]]+=lazy[cur];
	lazy[cur]=0;
}
void change(int l,int r,int &cur){
//	assert(cnt<=40000000);
	if(!cur) cur=++cnt;
//	cout<<"	lower change "<<l<<' '<<r<<' '<<ql<<' '<<qr<<' '<<cur<<'\n';
	if(l>=LOWERql&&r<=LOWERqr){siz[cur]+=(r-l+1);lazy[cur]++;return;}
	push(l,r,cur);
	int mid=(l+r)>>1;
	if(mid>=LOWERql) change(l,mid,ch[cur][0]);
	if(mid<LOWERqr) change(mid+1,r,ch[cur][1]);
	siz[cur]=siz[ch[cur][0]]+siz[ch[cur][1]];
}
void changert(int l,int r,int num,int pos){
//	cout<<"UPPER CHANGE "<<l<<' '<<r<<' '<<num<<' '<<pos<<' '<<ql<<' '<<qr<<'\n';
	LOWERql=UPPERql;LOWERqr=UPPERqr;
	change(1,n,rt[num]);
	if(l==r) return;
	int mid=(l+r)>>1;
	if(mid>=pos) changert(l,mid,num<<1,pos);
	if(mid<pos) changert(mid+1,r,num<<1|1,pos);
}
ll query(int l,int r,int cur){
	if(!cur) return 0;
//	cout<<"	lower query "<<l<<' '<<r<<' '<<ql<<' '<<qr<<' '<<cur<<'\n';
	if(l>=LOWERql&&r<=LOWERqr) return siz[cur];
	push(l,r,cur);
	int mid=(l+r)>>1;ll re=0;
	if(mid>=LOWERql) re+=query(l,mid,ch[cur][0]);
	if(mid<LOWERqr) re+=query(mid+1,r,ch[cur][1]);
	return re;
}
int getans(int l,int r,int num,ll lim){
	if(l==r) return l;
	LOWERql=UPPERql;LOWERqr=UPPERqr;
	ll tmp=query(1,n,rt[num<<1|1]);int mid=(l+r)>>1;
//	cout<<"BINARY SEARCHING "<<l<<' '<<r<<' '<<num<<' '<<ql<<' '<<qr<<' '<<lim<<' '<<tmp<<'\n';
	if(tmp>lim) return getans(mid+1,r,num<<1|1,lim);
	else return getans(l,mid,num<<1,lim-tmp);
}
ll get(int l,int r,int num){
	if(!rt[num]) return 0;
//	cout<<"UPPER QUERY "<<l<<' '<<r<<' '<<num<<' '<<ql<<' '<<qr<<' '<<qql<<' '<<qqr<<'\n';
	if(l>=UPPERql&&r<=UPPERqr){LOWERql=UPPERqql;LOWERqr=UPPERqqr;return query(1,n,rt[num]);}
	int mid=(l+r)>>1;ll re=0;
	if(mid>=UPPERql) re+=get(l,mid,num<<1);
	if(mid<UPPERqr) re+=get(mid+1,r,num<<1|1);
	return re;
}
int main(){
	n=read();m=read();ll i,t1,t2,t3,t4,lastp=0,tmp;
	for(i=1;i<=n;i++){
		t1=read();
	}
	while(m--){
		t4=read();t1=read();t2=read();t3=read();
		if(t4){
			UPPERql=t1;UPPERqr=t2;
			tmp=getans(1,1000001,1,t3);
			lastp=tmp;
			UPPERql=tmp+1;UPPERqr=1000001;UPPERqql=t1;UPPERqqr=t2;
			printf("%lld %lld\n",tmp,get(1,1000001,1));
		}
		else{
			t3^=lastp;UPPERql=t1;UPPERqr=t2;
			changert(1,1000001,1,t3+1);
		}
	}
}
