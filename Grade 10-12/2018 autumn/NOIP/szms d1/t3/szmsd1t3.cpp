/*

宣告——
汝身听吾号令，托付吾之命运于汝之剑，
应圣杯之召，若汝遵从此意志此理，回应吧。
在此起誓，吾愿成就世间一切之善行，吾愿诛尽世间一切之恶行。
汝为身缠三大言灵之七天，从抑止之轮显现吧，天秤之守护者！

*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
#include<vector>
#include<queue>
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
namespace SEG{
	int seg[800010],lazy[800010];
	void push(int l,int r,int num){
		if(l==r||!lazy[num]) return;
		seg[num<<1]=max(seg[num<<1],lazy[num]);
		seg[num<<1|1]=max(seg[num<<1|1],lazy[num]);
		lazy[num<<1]=max(lazy[num<<1],lazy[num]);
		lazy[num<<1|1]=max(lazy[num<<1|1],lazy[num]);
		lazy[num]=0;
	}
	void change(int l,int r,int ql,int qr,int num,int val){
		if(l>=ql&&r<=qr){
			seg[num]=max(seg[num],val);
			lazy[num]=max(lazy[num],val);
			return;
		}
		push(l,r,num);
		int mid=(l+r)>>1;
		if(mid>=ql) change(l,mid,ql,qr,num<<1,val);
		if(mid<qr) change(mid+1,r,ql,qr,num<<1|1,val);
		seg[num]=max(seg[num<<1],seg[num<<1|1]);
	}
	int query(int l,int r,int num,int pos){
		if(l==r) return seg[num];
		push(l,r,num);
		int mid=(l+r)>>1;
		if(mid>=pos) return query(l,mid,num<<1,pos);
		else return query(mid+1,r,num<<1|1,pos);
	}
}
int n,m,k,q,st[200010][20];
struct query{
	int l,r;
};
vector<query>x[200010];
inline bool cmp(query l,query r){
	if(l.l==r.l) return l.r<r.r;
	else return l.l<r.l;
}
int main(){
//	freopen("in.in","r",stdin);
	n=read(),m=read(),k=read();
	int i,j,curl,curr,t1,t2,t3;
	for(i=1;i<=m;i++){
		t1=read();t2=read();t3=read();
		x[t3].push_back((query){t1,t2});
	}
	for(i=1;i<=k;i++){
		if(!x[i].size()){
			SEG::change(1,n,1,n,1,n);
			break;
		}
		sort(x[i].begin(),x[i].end(),cmp);
		curl=1;curr=x[i][j=0].l;
		while(curl<=n&&curr<=n){
			SEG::change(1,n,curl,curr,1,curr);
			if(curl==n||curr==n) break;
			while(j<x[i].size()-1&&x[i][j+1].l<=x[i][j].r) j++;
			curl=x[i][j].r;
			if(j<x[i].size()-1) curr=x[i][++j].l;
			else curr=n;
		}
	}
	for(i=1;i<=n;i++) st[i][0]=max(SEG::query(1,n,1,i),i);
	for(j=1;j<=18;j++){
		for(i=1;i<=n;i++){
			st[i][j]=st[st[i][j-1]][j-1];
		}
	}
	q=read();
	while(q--){
		t1=read();t2=read();
//		cout<<"input query "<<t1<<' '<<t2<<' '<<st[t1][18]<<'\n';
		i=t1;t3=0;
		if(st[t1][18]<t2) t3=-2;
		else{
			for(j=18;j>=0;j--){
				if(st[i][j]<t2){
					i=st[i][j];
					t3+=(1<<j);
				}
			}
		}
		printf("%d\n",t3+1);
	}
}
