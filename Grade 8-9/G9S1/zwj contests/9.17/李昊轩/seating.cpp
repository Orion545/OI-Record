#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
struct node{
	int ll,rr,l,r,m,lazy;
}a[1001000];
int read(){
	char c=getchar();int re=0;
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') re=re*10+int(c-48),c=getchar();
	return re;
}
void build(int l,int r,int num){
	a[num].ll=l;a[num].rr=r;a[num].l=a[num].r=a[num].m=(r-l+1);a[num].lazy=0;
	if(l==r) return;
	build(l,(l+r)>>1,num<<1);build(((l+r)>>1)+1,r,(num<<1)+1);
}
void clear(int num){
	if(a[num].ll==a[num].rr||(!a[num].lazy)) return;
	int son=num<<1;
	if(a[num].lazy==1){
		a[son].l=a[son].r=a[son+1].l=a[son+1].r=a[son].m=a[son+1].m=0;
	}
	else{
		a[son].l=a[son].r=a[son].m=(a[son].rr-a[son].ll+1);
		a[son+1].l=a[son+1].r=a[son+1].m=(a[son+1].rr-a[son+1].ll+1);
	}
	a[num<<1].lazy=a[(num<<1)+1].lazy=a[num].lazy;a[num].lazy=0;
}
int find(int x,int num){
	clear(num);
//	cout<<x<<ends<<num<<ends<<a[num].ll<<ends<<a[num].rr<<ends<<a[num].l<<ends<<a[num].r<<ends<<a[num].m<<endl;
	if(a[num].m<x) return 0;
	if(a[num].l>=x) return a[num].ll;
	if(a[num<<1].m>=x) return find(x,num<<1);
	if(a[num<<1].r+a[(num<<1)+1].l>=x) return a[num<<1].rr-a[num<<1].r+1;
	return find(x,(num<<1)+1);
}
void change(int num){
	int son=num<<1;
	clear(num);clear(son);clear(son+1);
//	cout<<"son l: "<<son<<ends<<a[son].l<<ends<<a[son].r<<ends<<a[son].m<<endl;
//	cout<<"son r: "<<son+1<<ends<<a[son+1].l<<ends<<a[son+1].r<<ends<<a[son+1].m<<endl;
	a[num].l=a[son].l;
	if(a[son].l==a[son].rr-a[son].ll+1) a[num].l=a[son].m+a[son+1].l;
	a[num].r=a[son+1].r;
	if(a[son+1].r==a[son+1].rr-a[son+1].ll+1) a[num].r=a[son+1].m+a[son].r;
	a[num].m=max(a[son].m,a[son+1].m);
	a[num].m=max(a[num].m,a[son].r+a[son+1].l);
//	cout<<"changed "<<num<<ends<<a[num].l<<ends<<a[num].r<<ends<<a[num].m<<endl;
}
void checkin(int ql,int qr,int num){
//	cout<<"checkin "<<a[num].ll<<ends<<a[num].rr<<ends<<ql<<ends<<qr<<ends<<num<<endl;
	if(a[num].ll>=ql&&a[num].rr<=qr){
//		cout<<"	suc"<<endl;
		a[num].l=a[num].r=a[num].m=0;
		a[num].lazy=1;return;
	}
	int mid=(a[num].ll+a[num].rr)>>1,son=num<<1;
	clear(num);clear(son);clear(son+1);
	if(mid>=ql) checkin(ql,qr,son);
	if(mid<qr) checkin(ql,qr,son+1);
	change(num);return;
}
void checkout(int ql,int qr,int num){
//	cout<<"checkout "<<a[num].ll<<ends<<a[num].rr<<ends<<ql<<ends<<qr<<ends<<num<<endl;
	if(a[num].ll>=ql&&a[num].rr<=qr){
//		cout<<"	suc"<<endl;
		a[num].l=a[num].r=a[num].m=(a[num].rr-a[num].ll+1);
		a[num].lazy=2;return;
	}
	int mid=(a[num].ll+a[num].rr)>>1,son=num<<1;
	clear(num);clear(son);clear(son+1);
	if(mid>=ql) checkout(ql,qr,son);
	if(mid<qr) checkout(ql,qr,son+1);
	change(num);
	return;
}
int n,q;
int main(){
	freopen("seating.in","r",stdin);
	freopen("seating.out","w",stdout);
	int i,t2,t3,ans=0,tmp;char t1;
	std::ios::sync_with_stdio(false);
	n=read();q=read();
	build(1,n,1);
	for(i=1;i<=q;i++){
		t1=getchar();
		while(t1!='A'&&t1!='L') t1=getchar();
		if(t1=='A'){
//			cout<<"type 1"<<endl;
			t2=read();
			if(a[1].m<t2){
				ans++;continue;
			}
			tmp=find(t2,1);
			checkin(tmp,tmp+t2-1,1);
//			cout<<tmp<<endl;
		}
		else{
//			cout<<"type 2"<<endl;
			t2=read();t3=read();
			checkout(t2,t3,1);
		}
	}
	cout<<ans;
}
