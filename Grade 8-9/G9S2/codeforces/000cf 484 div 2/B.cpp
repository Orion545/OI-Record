#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
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
struct segtree1{
	int a[800010],p[800010];
	void update(int pos){
		a[pos]=min(a[pos<<1],a[(pos<<1)+1]);
		if(a[pos<<1]>a[(pos<<1)+1]) p[pos]=p[(pos<<1)+1];
		else p[pos]=p[(pos<<1)];
	}
	void insert(int l,int r,int num,int pos,int val){
//		cout<<"insert1 "<<l<<ends<<r<<ends<<num<<ends<<pos<<ends<<val<<endl;
		if(l==r){
			a[num]=val;p[num]=pos;return;
		}
		int mid=(l+r)>>1,son=num<<1;
		if(mid>=pos) insert(l,mid,son,pos,val);
		else insert(mid+1,r,son+1,pos,val);
		update(num);
	}
	void clear(int l,int r,int num,int pos){
		if(l==r){
			a[num]=inf;p[num]=pos;return;
		}
		int mid=(l+r)>>1,son=num<<1;
		if(mid>=pos) clear(l,mid,son,pos);
		else clear(mid+1,r,son+1,pos);
		update(num);
	}
	int query(){
		return p[1];
	}
}T1;
struct segtree2{
	int a[800010],p[800010];
	void update(int pos){
		a[pos]=max(a[pos<<1],a[(pos<<1)+1]);
		if(a[pos<<1]>a[(pos<<1)+1]) p[pos]=p[(pos<<1)];
		else p[pos]=p[(pos<<1)+1];
	}
	void insert(int l,int r,int num,int pos,int val){
//		cout<<"insert2 "<<l<<ends<<r<<ends<<num<<ends<<pos<<ends<<val<<endl;
		if(l==r){
			a[num]=val;p[num]=pos;return;
		}
		int mid=(l+r)>>1,son=num<<1;
		if(mid>=pos) insert(l,mid,son,pos,val);
		else insert(mid+1,r,son+1,pos,val);
		update(num);
	}
	void clear(int l,int r,int num,int pos){
		if(l==r){
			a[num]=0;p[num]=pos;return;
		}
		int mid=(l+r)>>1,son=num<<1;
		if(mid>=pos) clear(l,mid,son,pos);
		else clear(mid+1,r,son+1,pos);
		update(num);
	}
	int query(){
		return p[1];
	}
}T2;
int n,w[200010];char x[400010];
int type[200010];
int main(){
	n=read();int i,tmp;
	for(i=1;i<=n;i++) w[i]=read(),type[i]=0,T1.insert(1,n,1,i,w[i]);
	scanf("%s",x);
	for(i=0;i<(n<<1);i++){
		if(x[i]=='0'){
			tmp=T1.query();
			T1.clear(1,n,1,tmp);T2.insert(1,n,1,tmp,w[tmp]);
			printf("%d ",tmp);
		}
		else{
			tmp=T2.query();
			T2.clear(1,n,1,tmp);
			printf("%d ",tmp);
		}
	}	
}
