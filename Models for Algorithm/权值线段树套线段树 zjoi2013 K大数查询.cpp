#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
inline int read(){
	int re=0,flag=1;char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') re=re*10+ch-'0',ch=getchar();
	return re*flag;
}
int n,m,cnt;
int root[400010];
int ch[20000010][2];
ll a[20000010],lazy[20000010];
inline void push(int l,int r,int num){
	if(l==r||!lazy[num]) return;
	int mid=(l+r)>>1;
	if(!ch[num][0]) ch[num][0]=++cnt;
	a[ch[num][0]]+=lazy[num]*(ll)(mid-l+1);
	lazy[ch[num][0]]+=lazy[num];
	if(!ch[num][1]) ch[num][1]=++cnt;
	a[ch[num][1]]+=lazy[num]*(ll)(r-mid);
	lazy[ch[num][1]]+=lazy[num];
	lazy[num]=0;
}
inline void change(int l,int r,int ql,int qr,int &num){
//	cout<<"	change "<<l<<ends<<r<<ends<<ql<<ends<<qr<<ends<<num<<endl;
	int mid=(l+r)>>1;
	if(!num) num=++cnt;
	else push(l,r,num);
	if(l>=ql&&r<=qr){
		a[num]+=(ll)(r-l+1);lazy[num]++;
		return;
	}
	if(mid>=ql) change(l,mid,ql,qr,ch[num][0]);
	if(mid<qr) change(mid+1,r,ql,qr,ch[num][1]);
	a[num]=a[ch[num][0]]+a[ch[num][1]];
}
inline void insert(int l,int r,int ql,int qr,int x,int num){
//	cout<<"insert "<<l<<ends<<r<<ends<<ql<<ends<<qr<<ends<<x<<ends<<num<<endl;
	int mid=(l+r)>>1;
	change(1,n,ql,qr,root[num]);
	if(l==r) return;
	if(mid>=x) insert(l,mid,ql,qr,x,num<<1);
	else insert(mid+1,r,ql,qr,x,(num<<1)+1);
}
inline ll check(int l,int r,int ql,int qr,int num){
//	cout<<"	check "<<l<<ends<<r<<ends<<ql<<ends<<qr<<ends<<num<<ends<<a[num]<<endl;
	int mid=(l+r)>>1;ll re=0;
	if(!num) return 0LL;
	push(l,r,num);
	if(l>=ql&&r<=qr) return a[num];
	if(mid>=ql) re+=check(l,mid,ql,qr,ch[num][0]);
	if(mid<qr) re+=check(mid+1,r,ql,qr,ch[num][1]);
//	cout<<"	return "<<l<<ends<<r<<ends<<ql<<ends<<qr<<ends<<re<<endl;
	return re;
}
inline ll query(int l,int r,int ql,int qr,int k,int num){
//	cout<<"query "<<l<<ends<<r<<ends<<ql<<ends<<qr<<ends<<k<<ends<<num<<endl;
	int mid=(l+r)>>1;
	if(l==r) return l;
	ll tt=check(1,n,ql,qr,root[(num<<1)+1]);
	if(tt>=k) return query(mid+1,r,ql,qr,k,(num<<1)+1);
	else return query(l,mid,ql,qr,k-tt,num<<1);
}
int main(){
	int i,t1,t2,t3,t4;
	n=read();m=read();
	for(i=1;i<=m;i++){
		t1=read();t2=read();t3=read();t4=read();
		if(t1==1) insert(1,n<<1,t2,t3,t4+n,1);
		else printf("%lld\n",query(1,n<<1,t2,t3,t4,1)-n);
	}
}
/*
3 5
1 1 3 1
1 1 3 2
1 2 2 3
2 1 3 1
2 1 2 1


*/
