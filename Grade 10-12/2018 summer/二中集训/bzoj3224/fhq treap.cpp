#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<ctime>
#define ll long long
using namespace std;
inline ll read(){
	ll re=0,flag=1;char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
int n,ch[200010][2],siz[200010],key[200010],w[200010],cnt,root;
int newnode(int val){
	int cur=++cnt;ch[cur][0]=ch[cur][1]=0;
	siz[cur]=1;w[cur]=val;key[cur]=rand();return cur;
}
void update(int pos){
	siz[pos]=siz[ch[pos][0]]+siz[ch[pos][1]]+1;
}
void split(int cur,int &l,int &r,int val){
//	cout<<"	split "<<cur<<' '<<l<<' '<<r<<' '<<val<<' '<<w[cur]<<' '<<ch[cur][0]<<' '<<ch[cur][1]<<'\n';
	if(!cur){l=r=0;return;}
	if(w[cur]<=val) l=cur,split(ch[cur][1],ch[l][1],r,val);
	else r=cur,split(ch[cur][0],l,ch[r][0],val);
	update(cur);
}
void merge(int &cur,int l,int r){
//	cout<<"	merge "<<cur<<' '<<l<<' '<<r<<'\n';
	if(!l||!r){cur=l+r;return;}
	if(key[l]<key[r]) cur=l,merge(ch[cur][1],ch[l][1],r);
	else cur=r,merge(ch[cur][0],l,ch[r][0]);
	update(cur);
}
void insert(int val){
	int x=0,y=0,z=newnode(val);
	split(root,x,y,val);
	merge(x,x,z);merge(root,x,y);
}
void del(int val){
	int x=0,y=0,z=0;
	split(root,x,y,val);
	split(x,x,z,val-1);
	merge(z,ch[z][0],ch[z][1]);
	merge(x,x,z);merge(root,x,y);
}
int getrank(int val){
	int x=0,y=0,re;
	split(root,x,y,val-1);
	re=siz[x];merge(root,x,y);
	return re+1;
}
int getval(int pos,int rk){
//	cout<<"	getval "<<pos<<' '<<rk<<' '<<siz[pos]<<' '<<siz[ch[pos][0]]<<'\n';
	assert(pos);
	if(siz[ch[pos][0]]+1==rk) return w[pos];
	if(siz[ch[pos][0]]>=rk) return getval(ch[pos][0],rk);
	else return getval(ch[pos][1],rk-siz[ch[pos][0]]-1);
}
int pre(int val){
	int x=0,y=0,re;
	split(root,x,y,val-1);
	re=getval(x,siz[x]);merge(root,x,y);
	return re;
}
int suf(int val){
	int x=0,y=0,re;
	split(root,x,y,val);
	re=getval(y,1);merge(root,x,y);
	return re;
}
int main(){
	n=read();int i,t1,t2;
	for(i=1;i<=n;i++){
		t1=read();t2=read();
		switch(t1){
			case 1:insert(t2);break;
			case 2:del(t2);break;
			case 3:printf("%d\n",getrank(t2));break;
			case 4:printf("%d\n",getval(root,t2));break;
			case 5:printf("%d\n",pre(t2));break;
			case 6:printf("%d\n",suf(t2));break;
			default:break;
		}
	}
}
