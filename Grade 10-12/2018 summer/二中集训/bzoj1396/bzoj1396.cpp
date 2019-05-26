#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
#define rank DEEP_DARK_FANTASY 
#define end VAN_YOU_SEE
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
struct segtree{
	int a[400010],lazy[400010];
	segtree(){
		for(int i=0;i<=400000;i++) a[i]=lazy[i]=1e9;
	}
	void pushdown(int l,int r,int num){
		if(l==r||lazy[num]==1e9) return;
		int son=num<<1;
		lazy[son]=min(lazy[son],lazy[num]);lazy[son+1]=min(lazy[son+1],lazy[num]);
		a[son]=min(a[son],lazy[num]);a[son+1]=min(a[son+1],lazy[num]);
		lazy[num]=1e9;
	}
	void change(int l,int r,int ql,int qr,int num,int val){
		pushdown(l,r,num);
		int mid=(l+r)>>1,son=num<<1;
		if(l>=ql&&r<=qr){a[num]=min(a[num],val);lazy[num]=min(lazy[num],val);return;}
		if(mid>=ql) change(l,mid,ql,qr,son,val);
		if(mid<qr) change(mid+1,r,ql,qr,son+1,val);
		a[num]=min(a[son],a[son+1]);
	}
	int query(int l,int r,int ql,int qr,int num){
		pushdown(l,r,num);
		int mid=(l+r)>>1,son=num<<1,re=1e9;
		if(l>=ql&&r<=qr) return a[num];
		if(mid>=ql) re=min(re,query(l,mid,ql,qr,son));
		if(mid<qr) re=min(re,query(mid+1,r,ql,qr,son+1));
		return re;
	}
}T1,T2;
int ch[200010][26],val[200010],fa[200010],cnt=1,siz[200010],book[200010],rank[200010],end[200010];
int last=1,root=1;
void extend(int c,int pos){
	int p=last,np=++cnt;
//	cout<<"extend "<<c<<' '<<last<<'\n';
	val[np]=val[p]+1;siz[np]=1;end[np]=pos;
	while(p&&!ch[p][c]) ch[p][c]=np,p=fa[p];
	if(!p) fa[np]=root;
	else{
		int q=ch[p][c];
		if(val[q]==val[p]+1) fa[np]=q;
		else{
			int nq=++cnt;
			memcpy(ch[nq],ch[q],sizeof(ch[q]));val[nq]=val[p]+1;fa[nq]=fa[q];
			fa[q]=fa[np]=nq;
			while(p&&ch[p][c]==q) ch[p][c]=nq,p=fa[p];
		}
	}
	last=np;
}
int n;char s[100010];
void calc(){
	int i,cur,maxn,minn,endn;
	for(i=1;i<=cnt;i++) book[val[i]]++;
	for(i=1;i<=cnt;i++) book[i]+=book[i-1];
	for(i=1;i<=cnt;i++) rank[book[val[i]]--]=i;
	for(i=cnt;i>=1;i--){
		cur=rank[i];siz[fa[cur]]+=siz[cur];
		end[fa[cur]]=max(end[fa[cur]],end[cur]);
	}
	for(i=1;i<=cnt;i++){
		if(siz[i]!=1) continue;
		maxn=val[i];minn=val[fa[i]]+1;endn=end[i];
//		cout<<"renew "<<endn<<' '<<minn<<' '<<maxn<<'\n';
		T1.change(1,n,endn-maxn+1,endn-minn+1,1,endn);
//		cout<<"	change1 "<<endn-maxn+1<<' '<<endn-minn+1<<' '<<endn<<'\n';
		T2.change(1,n,endn-minn+1,endn,1,minn);
//		cout<<"	change2 "<<endn-minn+1<<' '<<endn<<' '<<minn<<'\n';
	}
	for(i=0;i<n;i++){
		printf("%d\n",min(T1.query(1,n,i+1,i+1,1)-(i+1)+1,T2.query(1,n,i+1,i+1,1)));
	}
} 
int main(){
	scanf("%s",s);n=strlen(s);int i;
	for(i=0;i<n;i++) extend(s[i]-'a',i+1);
	calc();
}

