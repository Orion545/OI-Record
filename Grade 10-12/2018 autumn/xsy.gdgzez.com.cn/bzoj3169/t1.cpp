#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<queue>
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
namespace spl{
	int ch[6000010][2],w[6000010],siz[6000010],fa[6000010],cnt;
	void update(int cur){
		siz[cur]=siz[ch[cur][0]]+siz[ch[cur][1]]+1;
//		cout<<"			update "<<cur<<' '<<siz[cur]<<' '<<ch[cur][0]<<' '<<siz[ch[cur][0]]<<' '<<ch[cur][1]<<' '<<siz[ch[cur][1]]<<'\n';
	}
	int newnode(int f,int val){
		cnt++;
//		if(cnt==2599140) cout<<"newnode "<<f<<' '<<val<<' '<<cnt<<'\n';
		fa[cnt]=f;siz[cnt]=1;ch[cnt][0]=ch[cnt][1]=0;w[cnt]=val;
		return cnt;
	}
	bool get(int cur){return ch[fa[cur]][1]==cur;}
	void rotate(int x){
		int f=fa[x],ff=fa[f],son=get(x);
		ch[f][son]=ch[x][son^1];
		if(ch[f][son]) fa[ch[f][son]]=f;
		fa[f]=x;ch[x][son^1]=f;
		fa[x]=ff;
		if(ff) ch[ff][ch[ff][1]==f]=x;
		update(f);update(x);
	}
	void splay(int x,int to,int &root){
//		cout<<"		SPLAY "<<x<<' '<<to<<' '<<root<<'\n';
		for(int f;(f=fa[x])!=to;rotate(x)){
			if(fa[f]!=to)
				rotate((get(x)==get(f))?f:x);
		}
		if(!to) root=x;
	}
	void insert(int &cur,int val,int f,int &root){
//		if(val==4675||val==1000000||val==-1000000) cout<<"	splay insert "<<cur<<' '<<val<<' '<<f<<' '<<root<<' '<<siz[cur]<<'\n';
//		fflush(stdout);
		if(!cur){
			cur=newnode(f,val);
			splay(cur,0,root);
			return;
		}
		siz[cur]++;
		if(w[cur]>=val) insert(ch[cur][0],val,cur,root);
		else insert(ch[cur][1],val,cur,root);
	}
	int getpos(int cur,int val){
		if(w[cur]==val) return cur;
		if(w[cur]>val) return getpos(ch[cur][0],val);
		else return getpos(ch[cur][1],val);
	}
	int pre(int root){
		int u=ch[root][0];
		while(ch[u][1]) u=ch[u][1];
		return u;
	}
	void del(int val,int &root){
		int cur=getpos(root,val);splay(cur,0,root);
//		cout<<"	splay del "<<val<<' '<<cur<<' '<<ch[cur][0]<<' '<<ch[cur][1]<<' '<<siz[cur]<<'\n';
		if(!ch[cur][0]&&!ch[cur][1]){root=0;return;}
		if(!ch[cur][0]&&ch[cur][1]){
			fa[ch[cur][1]]=0;root=ch[cur][1];
			siz[cur]=ch[cur][0]=ch[cur][1]=fa[cur]=0;
			return;
		}
		if(ch[cur][0]&&!ch[cur][1]){
			fa[ch[cur][0]]=0;root=ch[cur][0];
			siz[cur]=ch[cur][0]=ch[cur][1]=fa[cur]=0;
			return;
		}
		int p=pre(cur),suf=ch[cur][1];
		splay(p,0,root);
		assert(fa[cur]==p);
		assert(ch[cur][0]==0);
		ch[p][1]=suf;fa[suf]=p;update(p);
		siz[cur]=ch[cur][0]=ch[cur][1]=fa[cur]=0;
	}
	int pre(int val,int &root){
		int u=root,re=0,minn=1e9;
		while(u){
			if(w[u]>=val) u=ch[u][0];
			else{
				if(val-w[u]<minn){minn=val-w[u];re=u;}
				u=ch[u][1];
			}
		}
//		cout<<"	splay pre "<<val<<' '<<root<<' '<<re<<' '<<w[root]<<' '<<w[ch[root][0]]<<' '<<w[ch[root][1]]<<'\n';
//		fflush(stdout);
		splay(re,0,root);
		return re;
	}
	int suf(int val,int &root){
		int u=root,re=0,minn=1e9;
		while(u){
			if(w[u]<=val) u=ch[u][1];
			else{
				if(w[u]-val<minn){minn=w[u]-val;re=u;}
				u=ch[u][0];
			}
		}
//		cout<<"	splay suf "<<val<<' '<<root<<' '<<re<<' '<<w[root]<<' '<<w[ch[root][0]]<<' '<<w[ch[root][1]]<<'\n';
//		fflush(stdout);
		splay(re,0,root);
		return re;
	}
	int query(int &root,int l,int r){
		int x=pre(l,root),y=suf(r,root);
		splay(x,0,root);splay(y,x,root);
//		cout<<"	splay query "<<root<<' '<<siz[root]<<' '<<l<<' '<<r<<' '<<x<<' '<<w[x]<<' '<<y<<' '<<w[y]<<' '<<ch[y][0]<<' '<<w[ch[y][0]]<<' '<<siz[ch[y][0]]<<'\n';
		return siz[ch[y][0]];
	}
}
namespace ct{
	int cnt,re;queue<int>q;
	int newnode(){
		if(!q.empty()){re=q.front();q.pop();return re;}
		else return ++cnt;
	}
	void del(int num){
		q.push(num);
	}
}
namespace seg{
	int root[1000010],ch[1000010][2];
	void insert(int &cur,int l,int r,int pos,int val){//pos is value in original list, val is position
		if(!cur){
			cur=ct::newnode();
			spl::insert(root[cur],-1e6,0,root[cur]);
			spl::insert(root[cur],1e6,0,root[cur]);
		}
//		if(val==4675) cout<<"seg insert "<<cur<<' '<<l<<' '<<r<<' '<<pos<<' '<<val<<'\n';
		spl::insert(root[cur],val,0,root[cur]);
		if(l==r) return;
		int mid=(l+r)>>1;
		if(mid>=pos) insert(ch[cur][0],l,mid,pos,val);
		else insert(ch[cur][1],mid+1,r,pos,val);
	}
	void del(int &cur,int l,int r,int pos,int val){
//		cout<<"seg del "<<cur<<' '<<l<<' '<<r<<' '<<pos<<' '<<val<<'\n';
		spl::del(val,root[cur]);
//		cout<<"	finish splay del "<<root[cur]<<' '<<spl::siz[root[cur]]<<'\n';
		if(l^r){
			int mid=(l+r)>>1;
			if(mid>=pos) del(ch[cur][0],l,mid,pos,val);
			else del(ch[cur][1],mid+1,r,pos,val);
		}
		if(spl::siz[root[cur]]==2){
			ct::del(cur);
			spl::del(-1e6,root[cur]);
			spl::del(1e6,root[cur]);
			ch[cur][0]=ch[cur][1]=root[cur]=0;
			cur=0;
		}
//		cout<<"finish seg del "<<cur<<' '<<l<<' '<<r<<'\n';
	}
	int getk(int &cur,int l,int r,int qx,int qy,int ql,int qr){
//		cout<<"seg getk "<<l<<' '<<r<<' '<<cur<<' '<<qx<<' '<<qy<<' '<<ql<<' '<<qr<<'\n';
//		fflush(stdout);
		if(!cur) return 0;
		if(l>=ql&&r<=qr) return spl::query(root[cur],qx,qy);
		int mid=(l+r)>>1,re=0;
		if(mid>=ql) re+=getk(ch[cur][0],l,mid,qx,qy,ql,qr);
		if(mid<qr) re+=getk(ch[cur][1],mid+1,r,qx,qy,ql,qr);
		return re;
	}
	int query(int cur,int l,int r,int pos,int qx,int qy){
//		cout<<"seg query "<<l<<' '<<r<<' '<<pos<<' '<<qx<<' '<<qy<<' '<<cur<<' '<<root[cur]<<' '<<spl::ch[root[cur]][0]<<'\n';
		if(l==r) return l;
		int tmp=0;
		if(ch[cur][0]) tmp=spl::query(root[ch[cur][0]],qx,qy);
		int mid=(l+r)>>1;
		if(tmp>=pos) return query(ch[cur][0],l,mid,pos,qx,qy);
		else return query(ch[cur][1],mid+1,r,pos-tmp,qx,qy);
	}
}
int a[50010],n,m,rt=0;
int main(){
	using namespace seg;
	n=read();m=read();
	int i,t1,t2,t3,t4,tmp;
	for(i=1;i<=n;i++){
		a[i]=read();
		insert(rt,0,1e8,a[i],i);
//		if(a[i]==2080098) cout<<"check "<<a[i]<<' '<<i<<'\n';
//		if(a[i]==2080147) cout<<"check "<<a[i]<<' '<<i<<'\n';
//		if(i==4675) cout<<"check "<<i<<' '<<a[i]<<'\n';
	}
	while(m--){
		t1=read();
		if(t1==1){
			t2=read();t3=read();t4=read();
//			cout<<"readin "<<t1<<' '<<t2<<' '<<t3<<' '<<t4<<'\n';
			if(t4==0) puts("1");
			else printf("%d\n",getk(rt,0,1e8,t2,t3,0,t4-1)+1);
		}
		if(t1==2){
			t2=read();t3=read();t4=read();
//			cout<<"readin "<<t1<<' '<<t2<<' '<<t3<<' '<<t4<<'\n';
			printf("%d\n",query(rt,0,1e8,t4,t2,t3));
		}
		if(t1==3){
			t2=read();t3=read();
			del(rt,0,1e8,a[t2],t2);
			insert(rt,0,1e8,a[t2]=t3,t2);
		}
		if(t1==4){
			t2=read();t3=read();t4=read();
//			cout<<"readin "<<t1<<' '<<t2<<' '<<t3<<' '<<t4<<'\n';
			tmp=getk(rt,0,1e8,t2,t3,0,t4-1);
			if(tmp==0) puts("-2147483647");
			else printf("%d\n",query(rt,0,1e8,tmp,t2,t3));
		}
		if(t1==5){
			t2=read();t3=read();t4=read();
//			cout<<"readin "<<t1<<' '<<t2<<' '<<t3<<' '<<t4<<'\n';
			tmp=getk(rt,0,1e8,t2,t3,0,t4);
			if(tmp==t3-t2+1) puts("2147483647");
			else printf("%d\n",query(rt,0,1e8,tmp+1,t2,t3));
		}
	}
}
