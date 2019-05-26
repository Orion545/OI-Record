#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<queue>
#include<vector>
#define ll long long
#define log DDEP_DARK_FANTASY
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
int n,m,q;char s[1000010],tt[1000010];
vector<int>q1[500010],q2[500010];
int sl[500010],sr[500010],ql[500010],qr[500010],st[500010][20],log[500010];
namespace sam{
	int ch[400010][26],fa[400010],val[400010],root,cnt,last;
	void init(){root=cnt=1;val[1]=0;}
	inline int newnode(int w){val[++cnt]=w;return cnt;}
	void insert(int c){
		int p=last,np=newnode(val[p]+1);
		for(;p&&!ch[p][c];p=fa[p]) ch[p][c]=np;
		if(!p) fa[np]=root;
		else{
			int q=ch[p][c];
			if(val[q]==val[p]+1) fa[np]=q;
			else{
				int nq=newnode(val[p]+1);
				memcpy(ch[nq],ch[q],sizeof(ch[q]));
				fa[nq]=fa[q];
				fa[q]=fa[np]=nq;
				for(;p&&ch[p][c]==q;p=fa[p]) ch[p][c]=nq;
			}
		}
		last=np;
	}
}
namespace seg{
	struct ele{
		int pos,num;
		ele(int aaa=1e8,int bbb=0){num=bbb;pos=aaa;}
		inline bool operator <(const ele &b)const{
			return (num==b.num)?pos>b.pos:num<b.num;
		}
		friend inline ele max(ele a,ele b){return (a<b)?b:a;}
	}seg[800010],ans[800010];
	int ch[800010][2],cnt;
	void insert(int &cur,int l,int r,int pos){
		if(!cur) cur=++cnt;
//		cout<<"insert "<<cur<<' '<<l<<' '<<r<<' '<<pos<<'\n';
		if(l==r){seg[cur].num++;seg[cur].pos=pos;return;}
		int mid=(l+r)>>1;
		if(mid>=pos) insert(ch[cur][0],l,mid,pos);
		else insert(ch[cur][1],mid+1,r,pos);
		seg[cur]=max(seg[ch[cur][0]],seg[ch[cur][1]]);
	}
	int merge(int x,int y){
		if(!x||!y) return x^y;
		if(!ch[x][0]&&!ch[x][1]){seg[x].num+=seg[y].num;return x;}
		ch[x][0]=merge(ch[x][0],ch[y][0]);
		ch[x][1]=merge(ch[x][1],ch[y][1]);
		seg[x]=max(seg[ch[x][0]],seg[ch[x][1]]);
		return x;
	}
	ele query(int cur,int l,int r,int ql,int qr){
//		cout<<"seg query "<<cur<<' '<<l<<' '<<r<<' '<<ql<<' '<<qr<<'\n';
		if(l>=ql&&r<=qr) return seg[cur];
		int mid=(l+r)>>1;ele re;
		if(mid>=ql) re=max(re,query(ch[cur][0],l,mid,ql,qr));
		if(mid<qr) re=max(re,query(ch[cur][1],mid+1,r,ql,qr));
		return re;
	}
}
namespace g{
	int first[400010],cnte=-1,root[400010];
	void init(){memset(first,-1,sizeof(first));}
	struct edge{
		int to,next;
	}a[800010];
	inline void add(int u,int v){
		a[++cnte]=(edge){v,first[u]};first[u]=cnte;
		a[++cnte]=(edge){u,first[v]};first[v]=cnte;
	}
	void dfs(int u,int f){
		int i,v;
//		cout<<"dfs "<<u<<' '<<f<<' '<<root[u]<<'\n';
		for(i=first[u];~i;i=a[i].next){
			v=a[i].to;if(v==f) continue;
			dfs(v,u);root[u]=seg::merge(root[u],root[v]);
		}
		assert(root[u]);
		for(i=0;i<q2[u].size();i++){
			v=q2[u][i];
			seg::ans[v]=seg::query(root[u],1,m,ql[v],qr[v]);
//			cout<<"	query "<<v<<' '<<seg::ans[v].pos<<' '<<seg::ans[v].num<<'\n';
		}
	}
}
int main(){
	g::init();sam::init();int i,j,k,len,u,dep,v,cur;
	scanf("%s",s);n=strlen(s);
	m=read();
	for(i=1;i<=m;i++){
		scanf("%s",tt);len=strlen(tt);
		sam::last=1;
		for(j=0;j<len;j++){
			sam::insert(tt[j]-'a');
//			cout<<"main inserted char "<<tt[j]<<", get last "<<sam::last<<'\n';
			seg::insert(g::root[sam::last],1,m,i);
		}
	}
	q=read();
	for(i=1;i<=q;i++){
		ql[i]=read();qr[i]=read();sl[i]=read()-1;sr[i]=read()-1;
		q1[sr[i]].push_back(i);
	}
	log[1]=0;
	for(i=2;i<=sam::cnt;i++){
		g::add(sam::fa[i],i);
		st[i][0]=sam::fa[i];
		log[i]=log[i>>1]+1;
	}
	for(j=1;j<=19;j++){
		for(i=1;i<=sam::cnt;i++){
			st[i][j]=st[st[i][j-1]][j-1];
		}
	}
	for(u=1,dep=0,i=0;i<n;i++){
		while(u&&!sam::ch[u][s[i]-'a']) u=sam::fa[u],dep=sam::val[u];
		if(!u) u=1,dep=0;
		u=sam::ch[u][s[i]-'a'];dep++;
//		cout<<"main goths "<<i<<' '<<s[i]<<' '<<u<<' '<<dep<<'\n';
		for(j=0;j<q1[i].size();j++){
			v=q1[i][j];cur=u;
//			cout<<"try query "<<v<<' '<<cur<<' '<<dep<<' '<<sl[v]<<' '<<sr[v]<<'\n';
			if(dep<sr[v]-sl[v]+1) continue;
			for(k=19;k>=0;k--) if(sam::val[st[cur][k]]>=sr[v]-sl[v]+1) cur=st[cur][k];
			q2[cur].push_back(v);
		}
	}
	g::dfs(1,0);
	for(i=1;i<=q;i++){
		if(seg::ans[i].num==0) printf("%d 0\n",ql[i]);
		else printf("%d %d\n",seg::ans[i].pos,seg::ans[i].num);
	}
}
