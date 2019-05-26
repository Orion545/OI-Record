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
int n,m,a[100010],cnt=0;
int seg[4000010],ch[4000010][2];
void insert(int &cur,int pre,int l,int r,int pos){
	cur=++cnt;
	int mid=(l+r)>>1;
	seg[cur]=seg[pre]+1;
	ch[cur][0]=ch[pre][0];ch[cur][1]=ch[pre][1];
//	cout<<"	insert "<<cur<<' '<<pre<<' '<<l<<' '<<r<<' '<<pos<<' '<<seg[cur]<<' '<<ch[cur][0]<<' '<<ch[cur][1]<<'\n';
	if(l==r) return;
	if(mid>=pos) insert(ch[cur][0],ch[pre][0],l,mid,pos);
	else insert(ch[cur][1],ch[pre][1],mid+1,r,pos);
}
int query(int l,int r,int ql,int qr,int cur,int pre){
//	cout<<"	query "<<l<<' '<<r<<' '<<ql<<' '<<qr<<' '<<seg[cur]<<' '<<seg[pre]<<'\n';
	if(l>=ql&&r<=qr) return seg[cur]-seg[pre];
	int mid=(l+r)>>1,re=0;
	if(mid>=ql) re+=query(l,mid,ql,qr,ch[cur][0],ch[pre][0]);
	if(mid<qr) re+=query(mid+1,r,ql,qr,ch[cur][1],ch[pre][1]);
	return re;
}
int sum[100010],rt[100010];
ll solve(int val,int l,int r){
	ll re=0;int i,tl,tr;
	cnt=0;seg[0]=ch[0][0]=ch[0][1]=0;
	insert(rt[0],0,0,n<<1,n);
	for(i=1;i<=n;i++){
		if(a[i]<=val) sum[i]=sum[i-1]+1;
		else sum[i]=sum[i-1]-1;
		tl=i-r-1;tr=i-l;
		tl=(tl<0)?0:rt[tl];
		tr=(tr<0)?0:rt[tr];
		re+=query(0,n<<1,0,n+sum[i],tr,tl);
//		cout<<"current "<<re<<'\n';
		insert(rt[i],rt[i-1],0,n<<1,sum[i]+n);
	}
	return re;
}
int main(){
	n=read();int i;
	for(i=1;i<=n;i++) a[i]=read();
	m=read();int l1,l2,r1,r2;
	while(m--){
		l1=read();r1=read();l2=read();r2=read();
		printf("%lld\n",solve(r1,l2,r2)-solve(l1-1,l2,r2));
	}
}
/*
5
4 1 2 2 5
5
2 4 2 3
2 4 1 3
2 5 2 5
3 5 2 5
1 5 3 5

*/	
