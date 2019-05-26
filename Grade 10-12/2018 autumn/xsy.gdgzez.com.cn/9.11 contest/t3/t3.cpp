#include<iostream>
#include<cassert>
#include<cstdio>
#include<algorithm>
#include<cstring>
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
int ch[2000010][2],fa[2000010],l[2000010],r[2000010],siz[2000010],root,cnt;
void update(int num){
	siz[num]=siz[ch[num][0]]+siz[ch[num][1]]+r[num]-l[num]+1;
//	cout<<"			update "<<num<<' '<<siz[num]<<' '<<r[num]-l[num]+1<<'\n';
}
int get(int x){return ch[fa[x]][1]==x;}
void rotate(int x){
	int f=fa[x],ff=fa[f],son=get(x),deb=siz[f];
//	cout<<"		rotate "<<x<<' '<<f<<' '<<ff<<' '<<deb<<' '<<siz[x]<<'\n';
	assert(siz[x]==siz[ch[x][0]]+siz[ch[x][1]]+r[x]-l[x]+1);
//	cout<<"		rot "<<son<<' '<<ch[f][0]<<' '<<ch[f][1]<<' '<<ch[x][0]<<' '<<ch[x][1]<<'\n';
	ch[f][son]=ch[x][son^1];
	if(ch[f][son]) fa[ch[f][son]]=f;
	fa[f]=x;ch[x][son^1]=f;
	fa[x]=ff;
	if(ff) ch[ff][ch[ff][1]==f]=x;
//	cout<<"		finish rot "<<ch[f][0]<<' '<<ch[f][1]<<' '<<ch[x][0]<<' '<<ch[x][1]<<'\n';
	update(f);update(x);
	assert(siz[x]==deb);
}
void splay(int x,int to){
	if(x==to) return;
//	cout<<"	enter splay "<<x<<' '<<to<<'\n';
	for(int f;(f=fa[x])!=to;rotate(x)){
		if(fa[f]!=to)
			rotate((get(x)==get(f))?f:x);
	}
	if(!to) root=x;
}
int getrank(int x,int rk){
//	cout<<"	getrank "<<x<<' '<<ch[x][0]<<' '<<ch[x][1]<<' '<<siz[x]<<' '<<siz[ch[x][0]]<<' '<<rk<<'\n';
	assert(x);
	if(siz[ch[x][0]]<rk&&siz[ch[x][0]]+r[x]-l[x]+1>=rk){
		splay(x,0);
		return x;
	}
	if(siz[ch[x][0]]>=rk) return getrank(ch[x][0],rk);
	else return getrank(ch[x][1],rk-siz[ch[x][0]]-r[x]+l[x]-1);
}
int getpre(){
	int x=ch[root][0];
	while(ch[x][1]) x=ch[x][1];
	return x;
}
int getsuf(){
	int x=ch[root][1];
	while(ch[x][0]) x=ch[x][0];
	return x;
}
int split(int pos){
	int tot=siz[root],cur=getrank(root,pos);
	splay(cur,0);
	int pre=getpre(),suf=getsuf();
//	cout<<"	***split "<<cur<<' '<<pos<<' '<<siz[ch[cur][0]]<<' '<<siz[ch[cur][1]]<<' '<<l[cur]<<' '<<r[cur]<<' '<<tot<<'\n';
	assert(siz[cur]==siz[ch[cur][0]]+siz[ch[cur][1]]+r[cur]-l[cur]+1);
	if(pos==siz[ch[cur][0]]+r[cur]-l[cur]+1) return cur;
	if(!pre&&!suf){
		cnt++;
		fa[cnt]=cur;ch[cur][1]=cnt;
		r[cnt]=r[cur];r[cur]=l[cur]+pos-siz[ch[cur][0]]-1;l[cnt]=r[cur]+1;
		siz[cnt]=r[cnt]-l[cnt]+1;update(cur);return cur;
	}
	if(!suf){
		splay(pre,0);
		cnt++;
		fa[cnt]=cur;ch[cur][1]=cnt;
		r[cnt]=r[cur];r[cur]=l[cur]+pos-siz[pre]+siz[cur]-1;l[cnt]=r[cur]+1;
		siz[cnt]=r[cnt]-l[cnt]+1;update(cur);return cur;
	}
	if(!pre){
		splay(suf,0);
		cnt++;
		fa[cnt]=cur;ch[cur][1]=cnt;
		r[cnt]=r[cur];r[cur]=l[cur]+pos-siz[ch[cur][0]]-1;l[cnt]=r[cur]+1;
		siz[cnt]=r[cnt]-l[cnt]+1;update(cur);return cur;
	}
//	cout<<"	***normal split\n";
	assert(siz[cur]==siz[ch[cur][0]]+siz[ch[cur][1]]+r[cur]-l[cur]+1);
	splay(pre,0);splay(suf,pre);
	assert(ch[suf][0]==cur);
	assert(ch[cur][0]==0&&ch[cur][1]==0);
	assert(siz[cur]==siz[ch[cur][0]]+siz[ch[cur][1]]+r[cur]-l[cur]+1);
	cnt++;
	fa[cnt]=cur;ch[cur][1]=cnt;
	r[cnt]=r[cur];r[cur]=l[cur]+pos-(siz[pre]-siz[suf])-1;l[cnt]=r[cur]+1;
	siz[cnt]=r[cnt]-l[cnt]+1;//update(cur);
//	cout<<"	***finish split "<<siz[cur]<<' '<<l[cur]<<' '<<r[cur]<<' '<<l[cnt]<<' '<<r[cnt]<<'\n';
	assert(siz[cur]==siz[ch[cur][0]]+siz[ch[cur][1]]+r[cur]-l[cur]+1);
	return cur;
}
void insert(int pos,int a,int b){
//	cout<<"insert "<<pos<<' '<<a<<' '<<b<<'\n';
	if(!root){
		cnt++;
		l[cnt]=a;r[cnt]=b;siz[cnt]=b-a+1;
		root=cnt;return;
	}
	if(pos==0){
		int cur=getrank(root,1);
//		cout<<"	sp 0 "<<cur<<'\n';
		splay(cur,0);
		cnt++;
		fa[cnt]=cur;l[cnt]=a;r[cnt]=b;siz[cnt]=b-a+1;
		assert(ch[cur][0]==0);ch[cur][0]=cnt;
		update(cur);return;
	}
	if(pos==siz[root]){
		int cur=getrank(root,pos);
		splay(cur,0);
		cnt++;
		fa[cnt]=cur;l[cnt]=a;r[cnt]=b;siz[cnt]=b-a+1;
		assert(ch[cur][1]==0);ch[cur][1]=cnt;
		update(cur);return;
	}
//	cout<<"***************normal\n";
	int cur=split(pos),nex=getrank(root,pos+1);
	splay(cur,0);splay(nex,cur);
	cnt++;
//	cout<<"*****************8get new "<<cnt<<'\n';
	fa[cnt]=nex;l[cnt]=a;r[cnt]=b;siz[cnt]=b-a+1;
	assert(ch[nex][0]==0);ch[nex][0]=cnt;
	update(nex);update(cur);
}
void del(int a,int b){
//	cout<<"del "<<a<<' '<<b<<'\n';
	int cur,nex;
	if(a==1&&b==root[siz]){root=0;return;}
	if(a==1){
//		cout<<"	enter sp a\n";
		nex=split(b);nex=getrank(root,b+1);
		splay(nex,0);
		fa[ch[nex][0]]=0;ch[nex][0]=0;
		update(nex);return;
	}
	if(b==root[siz]){
		cur=split(a-1);
		splay(cur,0);
		fa[ch[cur][1]]=0;ch[cur][1]=0;
		update(cur);return;
	}
	cur=split(a-1);nex=split(b);nex=getrank(root,b+1);
//	cout<<"getdel "<<cur<<' '<<nex<<'\n';
	splay(cur,0);splay(nex,cur);
	fa[ch[nex][0]]=0;ch[nex][0]=0;
	update(nex);update(cur);
}
int query(int pos){
	int cur=split(pos);
	return r[cur];
}
int n,x[20010],m;
int build(int le,int ri,int f){
	if(ri<le) return 0;
	cnt++;int cur=cnt,mid=(le+ri)>>1;
	fa[cnt]=f;l[cnt]=r[cnt]=x[mid];siz[cnt]=1;
	if(le==ri) return cnt;
	ch[cur][0]=build(le,mid-1,cur);
	ch[cur][1]=build(mid+1,ri,cur);
	update(cur);
	return cur;
}
int main(){
	n=read();m=read();int i,t1,t2,t3,type;
	for(i=1;i<=n;i++) x[i]=read();
	root=build(1,n,0);
	while(m--){
		type=read();
		if(type==0){
			t1=read();t2=read();t3=read();
			insert(t1,t2,t3);
		}
		if(type==1){
			t1=read();t2=read();
			del(t1,t2);
		}
		if(type==2){
			t1=read();
			printf("%d\n",query(t1));
		}
	}
}
