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
int n,m,Q,a[2010][2010],pos[2010];
struct node{
	int tr[2010];
	inline void merge(node l,node r){for(int i=1;i<=n;i++) tr[i]=r.tr[l.tr[i]];}
}seg[10010];
inline void change(int l,int r,int ql,int qr,int num){
//	cout<<"change "<<l<<' '<<r<<' '<<ql<<' '<<qr<<' '<<num<<'\n';
	if(l==r){
		int i,t1,t2,t3;
		for(i=1;i<=n;i++){
			t1=i-1;t2=i;t3=i+1;
			if(t1<1) t1+=n;
			if(t3>n) t3-=n;
			seg[num].tr[i]=t1;
			if(a[t2][l+1]>a[seg[num].tr[i]][l+1]) seg[num].tr[i]=t2;
			if(a[t3][l+1]>a[seg[num].tr[i]][l+1]) seg[num].tr[i]=t3;
//			cout<<"		try "<<i<<' '<<t1<<' '<<t2<<' '<<t3<<'\n';
		}
//		cout<<"	bottom "<<l<<' '<<r<<' '<<seg[num].tr[1]<<' '<<seg[num].tr[2]<<' '<<seg[num].tr[3]<<' '<<seg[num].tr[4]<<'\n';
		pos[l]=num;return;
	}
	int mid=(l+r)>>1;
	if(mid>=ql) change(l,mid,ql,qr,num<<1);
	if(mid<qr) change(mid+1,r,ql,qr,num<<1|1);
	seg[num].merge(seg[num<<1],seg[num<<1|1]);
}
inline int qpow(node x,int b,int pos){
	node tmp;
	while(b){
		if(b&1) pos=x.tr[pos];
		tmp=x;x.merge(tmp,tmp);b>>=1;
	}
	return pos;
}
int main(){
	n=read();m=read();int i,j,k,tmp,t1,t2,t3;char s[10];
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			a[i][j]=read();
		}
		a[i][m+1]=a[i][1];
	}
	change(1,m,1,m,1);
	Q=read();t2=1;t3=1;
	while(Q--){
		scanf("%s",s);
		if(s[0]=='m'){
			t1=read();
			while(t1&&t2<=m){
				t3=seg[pos[t2]].tr[t3];
				t2++;t1--;
			}
			if(t2==m+1){
				if(t1>=m) t3=qpow(seg[1],t1/m,t3),t1%=m;
				t2=1;
				while(t1){
					t3=seg[pos[t2]].tr[t3];
					t2++;t1--;
				}
			}
			printf("%d %d\n",t3,t2);
		}
		else{
			i=read();j=read();k=read();
			a[i][j]=k;
			if(j==1) j=m+1,a[i][j]=k;
			j--;
			change(1,m,j,j,1);
		}
	}
}
