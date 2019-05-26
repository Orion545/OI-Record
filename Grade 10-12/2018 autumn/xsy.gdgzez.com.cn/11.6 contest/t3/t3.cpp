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
#define ull unsigned long long
#define MOD 19260817
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
int n,m;char s[100010];
ull p[100010];
ull seg[4000010];int ch[4000010][2],cnt,root[100010],rk[100010];
void build(int &cur,int l,int r){
	cur=++cnt;
	if(l==r){seg[cur]=(int)s[l-1];return;}
	int mid=(l+r)>>1;
	build(ch[cur][0],l,mid);
	build(ch[cur][1],mid+1,r);
	seg[cur]=seg[ch[cur][0]]*p[r-mid]+seg[ch[cur][1]];
}
void insert(int &cur,int l,int r,int pos,int val,int pre){
	cur=++cnt;
	ch[cur][0]=ch[pre][0];ch[cur][1]=ch[pre][1];
	if(l==r){seg[cur]=val;return;}
	int mid=(l+r)>>1;
	if(mid>=pos) insert(ch[cur][0],l,mid,pos,val,ch[pre][0]);
	else insert(ch[cur][1],mid+1,r,pos,val,ch[pre][1]);
	seg[cur]=seg[ch[cur][0]]*p[r-mid]+seg[ch[cur][1]];
//	cout<<"finish insert "<<cur<<' '<<pre<<' '<<l<<' '<<r<<' '<<seg[cur]<<' '<<seg[pre]<<'\n';
}
int query(int l,int r,int cur,int pre,int ql,int qr){
//	cout<<"query "<<l<<' '<<r<<' '<<cur<<' '<<pre<<' '<<seg[cur]<<' '<<seg[pre]<<'\n';
	if(l==r){
		if(seg[pre]!=seg[cur]) return seg[pre]<seg[cur];
		else return ql<qr;
	}
	int mid=(l+r)>>1;
	if(seg[ch[cur][0]]==seg[ch[pre][0]]) return query(mid+1,r,ch[cur][1],ch[pre][1],ql,qr);
	else return query(l,mid,ch[cur][0],ch[pre][0],ql,qr);
}
bool cmp(int l,int r){
	if(l==r) return 0;
	return query(1,m,root[r],root[l],l,r);
}
int main(){
	freopen("z.in","r",stdin);
	freopen("z.out","w",stdout);
	n=read();m=read();int i,t1,t2;char t3[10];
	scanf("%s",s);
	p[0]=1;
	for(i=1;i<=m;i++) p[i]=p[i-1]*MOD;
	build(root[1],1,m);
	for(i=2;i<=n;i++){
		t1=read();t2=read();scanf("%s",t3);
		insert(root[i],1,m,t2,(int)t3[0],root[t1]);
	}
	for(i=1;i<=n;i++) rk[i]=i;
	sort(rk+1,rk+n+1,cmp);
	for(i=1;i<=n;i++) printf("%d ",rk[i]);
}
/*
4 3
abc
1 1 b
2 1 a
1 3 a

*/
