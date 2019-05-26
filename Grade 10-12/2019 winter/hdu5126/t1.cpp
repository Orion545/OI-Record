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
int n,sta;
struct node{
	int x,y,z,x1,x2,y1,y2,z1,z2,lc,rc,sum;
	node(){}
	node(int xx,int yy,int zz){x=x1=x2=xx;y=y1=y2=yy;z=z1=z2=zz;lc=rc=0;sum=1;}
	inline bool operator <(const node b)const{
		if(sta==0) return x<b.x;
		if(sta==1) return y<b.y;
		if(sta==2) return z<b.z;
	}
}a[100010],in[100010];int cnt;
void update(int cur){
	a[cur].sum=a[a[cur].lc].sum+a[a[cur].rc].sum+1;
	a[cur].x1=a[cur].x2=a[cur].x;
	a[cur].y1=a[cur].y2=a[cur].y;
	a[cur].z1=a[cur].z2=a[cur].z;
	if(a[cur].lc){
		a[cur].x1=min(a[cur].x1,a[a[cur].lc].x1);
		a[cur].x2=max(a[cur].x2,a[a[cur].lc].x2);
		a[cur].y1=min(a[cur].y1,a[a[cur].lc].y1);
		a[cur].y2=max(a[cur].y2,a[a[cur].lc].y2);
		a[cur].z1=min(a[cur].z1,a[a[cur].lc].z1);
		a[cur].z2=max(a[cur].z2,a[a[cur].lc].z2);
	}
	if(a[cur].rc){
		a[cur].x1=min(a[cur].x1,a[a[cur].rc].x1);
		a[cur].x2=max(a[cur].x2,a[a[cur].rc].x2);
		a[cur].y1=min(a[cur].y1,a[a[cur].rc].y1);
		a[cur].y2=max(a[cur].y2,a[a[cur].rc].y2);
		a[cur].z1=min(a[cur].z1,a[a[cur].rc].z1);
		a[cur].z2=max(a[cur].z2,a[a[cur].rc].z2);
	}
//	cout<<"	update "<<cur<<' '<<a[cur].x1<<' '<<a[cur].x2<<' '<<a[cur].y1<<' '<<a[cur].y2<<' '<<a[cur].z1<<' '<<a[cur].z2<<'\n';
}
void insert(int &cur,int flag,node x){
	if(!cur){cur=cnt;a[cur]=x;return;}
	if(flag==0){
		if(x.x<=a[cur].x) insert(a[cur].lc,(flag+1)%3,x);
		else insert(a[cur].rc,(flag+1)%3,x);
	}
	if(flag==1){
		if(x.y<=a[cur].y) insert(a[cur].lc,(flag+1)%3,x);
		else insert(a[cur].rc,(flag+1)%3,x);
	}
	if(flag==2){
		if(x.z<=a[cur].z) insert(a[cur].lc,(flag+1)%3,x);
		else insert(a[cur].rc,(flag+1)%3,x);
	}
	update(cur);
}
void build(int &cur,int flag,int l,int r){
	if(l>r){cur=0;return;}
	sta=flag;int mid=(l+r)>>1;cur=mid;
	nth_element(in+l,in+mid,in+r+1);
	a[cur]=in[mid];
	build(a[cur].lc,(flag+1)%3,l,mid-1);
	build(a[cur].rc,(flag+1)%3,mid+1,r);
	update(cur);
}
int query(int cur,int x1,int x2,int y1,int y2,int z1,int z2){
	if(!cur) return 0;
//	cout<<"query "<<cur<<' '<<a[cur].x1<<' '<<a[cur].x2<<' '<<a[cur].y1<<' '<<a[cur].y2<<' '<<a[cur].z1<<' '<<a[cur].z2<<'\n';
	if(x1>a[cur].x2||x2<a[cur].x1||y1>a[cur].y2||y2<a[cur].y1||z1>a[cur].z2||z2<a[cur].z1) return 0;
	if(x1<=a[cur].x1&&x2>=a[cur].x2&&y1<=a[cur].y1&&y2>=a[cur].y2&&z1<=a[cur].z1&&z2>=a[cur].z2) return a[cur].sum;
	int re=0;
	if(a[cur].x>=x1&&a[cur].x<=x2&&a[cur].y>=y1&&a[cur].y<=y2&&a[cur].z>=z1&&a[cur].z<=z2) re++;
	re+=query(a[cur].lc,x1,x2,y1,y2,z1,z2);
	re+=query(a[cur].rc,x1,x2,y1,y2,z1,z2);
	return re;
}
int main(){
	int T=read(),f,t1,t2,t3,t4,t5,t6;
	int root;
	while(T--){
		f=read();
		if(f==1){
			t1=read();t2=read();t3=read();
			in[++cnt]=node(t1,t2,t3);
			insert(root,0,in[cnt]);
			if(cnt%5000==0) build(root,0,1,cnt);
		}
		else{
			t1=read();t2=read();t3=read();t4=read();t5=read();t6=read();
			printf("%d\n",query(root,t1,t4,t2,t5,t3,t6));
		}
//		build(root,0,1,cnt);
	}
}
