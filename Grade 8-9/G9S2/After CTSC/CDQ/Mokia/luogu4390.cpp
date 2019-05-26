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
	while(ch>='0'&&ch<='9') re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
struct node{
	int type,val,x,y,num;
	inline bool operator <(const node &b){
		if(b.x!=x) return x<b.x;
		if(b.y!=y) return y<b.y;
		else return type<b.type;
	}
}a[200010],t[200010];
int limx,limy,n,q,ans[10010];
struct BIT{
	int a[200010];
	int lowbit(int x){
		return x&(-x);
	}
	void add(int x,int val){
//		cout<<"add "<<x<<' '<<val<<'\n';
		for(;x<=limy;x+=lowbit(x)) a[x]+=val;
	} 
	int sum(int x){
//		cout<<"sum "<<x<<'\n';
		int re=0;
		for(;x>=1;x-=lowbit(x)) re+=a[x];
		return re;
	}
}T; 
inline bool cmp1(node l,node r){
	return l.x<r.x;
}
inline bool cmp2(node l,node r){
	return l.y<r.y;
}
inline bool cmp3(node l,node r){
	return l.num<r.num;
}
void cdq(int l,int r){
//	cout<<"cdq "<<l<<' '<<r<<'\n';
	if(l==r) return;
	int mid=(l+r)>>1,i=l,j=mid+1,p=l;
	cdq(l,mid);cdq(mid+1,r);
//	cout<<"begin merge "<<l<<' '<<r<<'\n';
	while(i<=mid&&j<=r){
//		cout<<'	'<<i<<' '<<j<<' '<<a[i].type<<' '<<a[i].x<<' '<<a[i].y<<' '<<a[j].type<<' '<<a[j].x<<' '<<a[j].y<<'\n';
		if(a[i]<a[j]){
//			cout<<"		go i\n";
			if(a[i].type==1) T.add(a[i].y,a[i].val);
			t[p++]=a[i++];
		}
		else{
//			cout<<"		go j\n";
			if(a[j].type==2) ans[a[j].val]+=T.sum(a[j].y);
			if(a[j].type==3) ans[a[j].val]-=T.sum(a[j].y);
			t[p++]=a[j++];
		}
	}
	while(i<=mid){
//		cout<<"	repair i "<<i<<' '<<a[i].type<<' '<<a[i].x<<' '<<a[i].y<<'\n';
		if(a[i].type==1) T.add(a[i].y,a[i].val);
		t[p++]=a[i++];
	}
	while(j<=r){
//		cout<<"	repair j "<<j<<' '<<a[j].type<<' '<<a[j].x<<' '<<a[j].y<<'\n';
		if(a[j].type==2) ans[a[j].val]+=T.sum(a[j].y);
		if(a[j].type==3) ans[a[j].val]-=T.sum(a[j].y);
		t[p++]=a[j++];
	}
	i--;
	while(i>=l){
		if(a[i].type==1) T.add(a[i].y,-a[i].val);
		i--;
	}
	for(i=l;i<=r;i++) a[i]=t[i];
//	cout<<"finish "<<l<<' '<<r<<'\n';
}
int main(){
	int i,j;int t1,t2,t3,t4,t5;
	t1=read();t2=read();
	while((t1=read())&&(t1!=3)){
		if(t1==1){
			t2=read();t3=read();t4=read();
			a[++n]=(node){1,t4,t2,t3,n};
		}
		else{
			t2=read();t3=read();t4=read();t5=read();q++;
			a[++n]=(node){2,q,t2-1,t3-1,n};
			a[++n]=(node){3,q,t2-1,t5,n};
			a[++n]=(node){3,q,t4,t3-1,n};
			a[++n]=(node){2,q,t4,t5,n};
		}
	}
	sort(a+1,a+n+1,cmp1);
	for(i=1;i<=n;){
		limx++;j=a[i].x;
		while(j==a[i].x) a[i].x=limx,i++;
	} 
	sort(a+1,a+n+1,cmp2);
	for(i=1;i<=n;){
		limy++;j=a[i].y;
		while(j==a[i].y) a[i].y=limy,i++;
	} 
	sort(a+1,a+n+1,cmp3);
//	for(i=1;i<=n;i++) cout<<i<<' '<<a[i].type<<' '<<a[i].val<<' '<<a[i].x<<' '<<a[i].y<<'\n';
	cdq(1,n);
	for(i=1;i<=q;i++) printf("%d\n",ans[i]);
}
