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
struct segt{
	int a[4000010];
	segt(){memset(a,0,sizeof(a));}
	void update(int p){
		a[p]=(a[p<<1]|a[(p<<1)+1]);
	}
	void insert(int l,int r,int num,int pos){
		if(l==r){ 
			a[num]=1;return;
		}
		int mid=(l+r)>>1,son=num<<1;
		if(mid>=pos) insert(l,mid,son,pos);
		else insert(mid+1,r,son+1,pos);
		update(num);
	}
	int query(int l,int r,int ql,int qr,int num){
		if(l>=ql&&r<=qr) return a[num];
		int mid=(l+r)>>1,son=num<<1,re=0;
		if(mid>=ql) re|=query(l,mid,ql,qr,son);
		if(mid<qr) re|=query(mid+1,r,ql,qr,son+1);
		return re;
	}
}T;
int n,k,d,a[1000010];
int main(){
	n=read();k=read();d=read();int i,l,r,mid;n++;
	for(i=2;i<=n;i++) a[i]=read();
	sort(a+2,a+n+1);
	if(k==1){
		puts("YES");return 0;
	}
	T.insert(1,n,1,1);
	for(i=k+1;i<=n;i++){
		l=2;r=i;
		while(l<r){
			mid=(l+r)>>1;
			if(a[i]-a[mid]>d) l=mid+1;
			else r=mid;
		}
//		if(l==2) l--;
//		cout<<i<<ends<<l<<endl; 
		if(i-l+1<k) continue;
		if(T.query(1,n,l-1,i-k,1)) T.insert(1,n,1,i);
	}
	if(T.query(1,n,n,n,1)) puts("YES");
	else puts("NO");
}
