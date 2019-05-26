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
struct SplayTree{
	int n,ch[100010][2],siz[100010],num[100010],w[100010],fa[100010],root,cnt;
	SplayTree(){n=root=cnt=0;}
	
	int newnode(int f,int val){
//		cout<<"new node "<<f<<ends<<val<<endl;
		cnt++;ch[cnt][0]=ch[cnt][1]=0;num[cnt]=siz[cnt]=1;
		w[cnt]=val;fa[cnt]=f;return cnt;
	}
	void delnode(int pos){//!!!!!!!!!!!!!!!!!
		ch[pos][0]=ch[pos][1]=num[pos]=siz[pos]=w[pos]=fa[pos]=0;
	}
	void update(int pos){siz[pos]=siz[ch[pos][0]]+siz[ch[pos][1]]+num[pos];}
	bool get(int pos){return ch[fa[pos]][1]==pos;}
	
	void rotate(int pos){
		//push down here ***
		int f=fa[pos],ff=fa[f],son=get(pos);
//		cout<<"rotate "<<pos<<ends<<f<<ends<<ff<<ends<<son<<ends<<ch[pos][son^1]<<ends<<ch[pos][son]<<endl;
		ch[f][son]=ch[pos][son^1];
		if(ch[f][son]) fa[ch[f][son]]=f;
		fa[f]=pos;ch[pos][son^1]=f;
		fa[pos]=ff;
		if(ff) ch[ff][ch[ff][1]==f]=pos;
//		cout<<"finish rotate "<<ch[pos][son^1]<<ends<<ch[f][son]<<ends<<ch[f][son^1]<<ends<<fa[f]<<endl;
		update(f);update(pos);
	}
	void splay(int pos,int to){
		if((!pos)||(pos==to)) return;
//		cout<<"splay "<<pos<<ends<<fa[pos]<<ends<<to<<endl;
		for(int f;(f=fa[pos])!=to;rotate(pos))
			if(fa[f]!=to)
				rotate((get(f)==get(pos))?f:pos);
		if(!to) root=pos;
	}
	int getpos(int pos,int rank){
		//push down here
		if(rank>siz[ch[pos][0]]&&rank<=(siz[ch[pos][0]]+num[pos])){
			splay(pos,0);
			return w[pos];
		}
		if(rank<=siz[ch[pos][0]]) return getpos(ch[pos][0],rank);
		else return getpos(ch[pos][1],rank-siz[ch[pos][0]]-num[pos]);
	}
	int getrank(int pos,int val,int buff){
		if(w[pos]==val){
			splay(pos,0);
			return siz[ch[pos][0]]+buff+1;
		}
		if(w[pos]>val) return getrank(ch[pos][0],val,buff);
		else return getrank(ch[pos][1],val,buff+siz[ch[pos][0]]+num[pos]);
	}
	int getvalpos(int pos,int val){
		if(w[pos]==val) return pos;
		if(w[pos]>val) return getvalpos(ch[pos][0],val);
		else return getvalpos(ch[pos][1],val);
	}
	int pre(){
		int pos=ch[root][0];
		while(ch[pos][1]) pos=ch[pos][1];
		return pos;
	}
	int suf(){
		int pos=ch[root][1];
		while(ch[pos][0]) pos=ch[pos][0];
		return pos;
	}
	void insert(int pos,int val){
//		cout<<"insert "<<pos<<ends<<w[pos]<<ends<<val<<ends<<ch[pos][0]<<ends<<ch[pos][1]<<endl;
		if(!pos){root=newnode(0,val);return;}
		if(w[pos]==val){num[pos]++;splay(pos,0);return;}
		if(w[pos]>val){
			if(!ch[pos][0]){ 
				ch[pos][0]=newnode(pos,val);
				update(pos);splay(ch[pos][0],0);
			}
			else siz[pos]++,insert(ch[pos][0],val);
		}
		else{
			if(!ch[pos][1]){
				ch[pos][1]=newnode(pos,val);
				update(pos);splay(ch[pos][1],0);
			}
			else siz[pos]++,insert(ch[pos][1],val);
		}
	}
	void del(int val){
//		cout<<"del "<<val<<endl;
		int pos=getvalpos(root,val);splay(pos,0);
		if(num[pos]>1){num[pos]--;return;}
		if(!ch[pos][0]){
			root=ch[pos][1];fa[root]=0;
			delnode(pos);
		}
		else{
			int sec=pre();splay(sec,root);
			root=ch[pos][0];fa[root]=0;
			ch[root][1]=ch[pos][1];fa[ch[pos][1]]=root;
			update(root);delnode(pos);
		}
	}
}T;
int main(){
	int i,t1,t2,Q=read();
	for(i=1;i<=Q;i++){
//		cout<<"**************************query i "<<i<<endl;
		t1=read();t2=read();
		switch(t1){
			case 1:T.insert(T.root,t2);break;
			case 2:T.del(t2);break;
			case 3:T.insert(T.root,t2);printf("%d\n",T.getrank(T.root,t2,0));T.del(t2);break;
			case 4:printf("%d\n",T.getpos(T.root,t2));break;
			case 5:T.insert(T.root,t2);printf("%d\n",T.w[T.pre()]);T.del(t2);break;
			case 6:T.insert(T.root,t2);printf("%d\n",T.w[T.suf()]);T.del(t2);break;
		}
	}
}
/*
10
1 106465
4 1
1 317721
1 460929
1 644985
1 84185
1 89851
6 81968
1 492737
5 493598

*/
