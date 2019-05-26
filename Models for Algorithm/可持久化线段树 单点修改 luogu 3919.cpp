#include<iostream> 
#include<cstdio>
#include<cstring>
#include<algorithm>
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
int n,m,cnt,x[1000010],rt[1000010];
int l[20000010],r[20000010],a[20000010];
void build(int &now,int ll,int rr){
	int mid=(ll+rr)>>1;
	now=++cnt;
	if(ll==rr){
		a[now]=x[ll];return;
	}
	build(l[now],ll,mid);build(r[now],mid+1,rr);
	a[now]=a[l[now]]+a[r[now]];
}
void change(int &now,int pre,int ll,int rr,int pos,int w){
	int mid=(ll+rr)>>1;
	now=++cnt;
	if(ll==rr){
		a[now]=w;return;
	}
	l[now]=l[pre];r[cnt]=r[pre];
	if(mid>=pos) change(l[now],l[pre],ll,mid,pos,w);
	else change(r[now],r[pre],mid+1,rr,pos,w);
	a[now]=a[l[now]]+a[r[now]];
}
int query(int now,int ll,int rr,int pos){
	int mid=(ll+rr)>>1;
	if(ll==rr) return a[now];
	if(mid>=pos) return query(l[now],ll,mid,pos);
	else return query(r[now],mid+1,rr,pos);
}
int main(){
	int i,t1,t2,t3,op;
	n=read();m=read();
	for(i=1;i<=n;i++) x[i]=read();
	build(rt[0],1,n);
	for(i=1;i<=m;i++){
		t1=read();op=read();t2=read();
		if(op==1){
			t3=read();
			change(rt[i],rt[t1],1,n,t2,t3);
		}
		else{
			printf("%d\n",query(rt[t1],1,n,t2));rt[i]=rt[t1];
		}
	}
}
