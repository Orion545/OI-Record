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
int n,m;
int init[100010],qt[100010],qx[100010],qy[100010];
namespace brute{
	int a[100010][1010],pre[1010],cur[10010];
	void modify(int pos,int val,int lim){
//		cout<<"modify "<<pos<<' '<<val<<' '<<lim<<'\n';
		int i,j;
		a[1][pos]=val;
		for(i=1;i<=n;i++){
			pre[i]=cur[a[1][i]];
			cur[a[1][i]]=i;
		}
		for(j=1;j<=n;j++) cur[a[1][j]]=0;
		for(i=2;i<=lim;i++){
			for(j=0;j<=n;j++) a[i][j]=0;
			for(j=1;j<=n;j++) a[i][j]=a[i][pre[j]]+1;
			for(j=1;j<=n;j++){
				pre[j]=cur[a[i][j]];
				cur[a[i][j]]=j;
			}
			for(j=1;j<=n;j++) cur[a[i][j]]=0;
//			cout<<"i=="<<i<<'\n';
//			for(j=1;j<=n;j++) cout<<a[i][j]<<' '<<pre[j]<<' ';
//			cout<<'\n';
		}
	}
	void solve(){
		int i,j,maxn;
		for(i=1;i<=n;i++) a[1][i]=init[i];
		qt[0]=1;qx[0]=init[1];qy[0]=1;
		for(i=0;i<=m;){
			maxn=0;j=i;
			while(j<m&&qt[j+1]==2) j++,maxn=max(maxn,qx[j]);
			modify(qy[i],qx[i],maxn);
			for(i++;i<=j;i++)
				printf("%d\n",a[qx[i]][qy[i]]);
		}
	}
}
namespace sec{
	int ch[100010][2],fa[100010],w[100010],siz[100010],root[100010];
	inline void update(int cur){
		siz[cur]=siz[ch[cur][0]]+siz[ch[cur][1]]+1;
	}
	inline bool get(int x){return ch[fa[x]][1]==x;}
	void rotate(int x){
		assert(x);
		int f=fa[x],ff=fa[f],son=get(x);
//		cout<<"													rotate "<<x<<' '<<f<<' '<<ff<<'\n';
		ch[f][son]=ch[x][son^1];
		if(ch[f][son]) fa[ch[f][son]]=f;
		fa[f]=x;ch[x][son^1]=f;
		fa[x]=ff;
		if(ff) ch[ff][ch[ff][1]==f]=x;
		update(f);update(x);
	}
	void splay(int x,int type){
//		cout<<"			splay "<<x<<' '<<type<<'\n';
		for(int f;(f=fa[x]);rotate(x)){
			if(fa[f])
				rotate((get(f)==get(x))?f:x);
		}
		root[type]=x;
	}
	int getrank(int cur,int val,int added){
//		cout<<"getrank "<<cur<<' '<<siz[cur]<<' '<<siz[ch[cur][0]]<<' '<<added<<' '<<val<<' '<<w[cur]<<'\n';
		if(w[cur]==val){return siz[ch[cur][0]]+added+1;}
		if(w[cur]>val) return getrank(ch[cur][0],val,added);
		else return getrank(ch[cur][1],val,added+siz[ch[cur][0]]+1);
	}
	int getpos(int cur,int val){
		assert(cur);
//		cout<<"getpos "<<cur<<' '<<val<<' '<<w[cur]<<' '<<ch[cur][0]<<' '<<ch[cur][1]<<'\n';
		if(w[cur]==val) return cur;
		if(w[cur]>val) return getpos(ch[cur][0],val);
		else return getpos(ch[cur][1],val);
	}
	void insert(int &cur,int f,int val,int num,int type){
//		cout<<"insert "<<cur<<' '<<f<<' '<<val<<' '<<num<<' '<<type<<'\n';
		if(!cur){
			cur=num;
			w[num]=val;siz[num]=1;fa[num]=f;
			if(!f) root[type]=num;
			ch[num][0]=ch[num][1]=0;
			return;
		}
		if(w[cur]>val) insert(ch[cur][0],cur,val,num,type);
		else insert(ch[cur][1],cur,val,num,type);
		update(cur);
//		cout<<"finish insert "<<cur<<' '<<ch[cur][0]<<' '<<ch[cur][1]<<' '<<siz[cur]<<'\n';
	}
	int del(int type,int val){
//		cout<<"del "<<type<<' '<<val<<' '<<root[type]<<' '<<siz[root[type]]<<'\n';
		int cur=getpos(root[type],val);
		splay(cur,type);
		if(ch[cur][0]==0&&ch[cur][1]==0){root[type]=0;return cur;}
		if(ch[cur][0]==0&&ch[cur][1]!=0){
			fa[ch[cur][1]]=0;root[type]=ch[cur][1];
			return cur;
		}
		if(ch[cur][0]!=0&&ch[cur][1]==0){
			fa[ch[cur][0]]=0;root[type]=ch[cur][0];
			return cur;
		}
		int pre=ch[cur][0];
		while(ch[pre][1]) pre=ch[pre][1];
		splay(pre,type);
		fa[ch[cur][1]]=pre;ch[pre][1]=ch[cur][1];
		update(pre);
		return cur;
	}
	void solve(){
		int i,tmp;
		for(i=1;i<=n;i++){
			insert(root[init[i]],0,i,i,init[i]);
		}
		for(i=1;i<=m;i++){
//			cout<<"begin new query***************************************************\n";
			if(qt[i]==1){
				tmp=del(init[qy[i]],qy[i]);
				init[qy[i]]=qx[i];
				insert(root[init[qy[i]]],0,qy[i],tmp,init[qy[i]]);
			}
			else{
				if(qx[i]==1) printf("%d\n",init[qy[i]]);
				else{
					printf("%d\n",tmp=getrank(root[init[qy[i]]],qy[i],0));
					splay(tmp,init[qy[i]]);
				}
			}
		}
	}
}
int main(){
	n=read();int i,maxn=0;
	for(i=1;i<=n;i++) init[i]=read();
	m=read();
	for(i=1;i<=m;i++){
		qt[i]=read();qx[i]=read();qy[i]=read();
		if(qt[i]==2) maxn=max(maxn,qx[i]);
	}
	brute::solve();
}
