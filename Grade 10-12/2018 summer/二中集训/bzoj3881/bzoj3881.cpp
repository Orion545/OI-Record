#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
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
struct ACAM{
	int son[2000010][26],fail[2000010],siz[2000010],cnt,end[100010],rt;
	ACAM(){
		cnt=rt=1;
	}
	void insert(char s[],int num){
		int i,cur=rt,tmp,len=strlen(s);
		for(i=0;i<len;i++){
			tmp=s[i]-'a';
			if(!son[cur][tmp]) son[cur][tmp]=++cnt;
			cur=son[cur][tmp];
		}
		end[num]=cur;
	}
	void AC(){
		int u,i,v;queue<int>q;
		for(i=0;i<26;i++){
			if(!son[rt][i]) son[rt][i]=rt;
			else q.push(son[rt][i]),fail[son[rt][i]]=rt;
		}
		while(!q.empty()){
			u=q.front();q.pop();
//			cout<<"bfs "<<u<<'\n';
			for(i=0;i<26;i++){
				v=son[u][i];
				if(!v) son[u][i]=son[fail[u]][i];
				else fail[v]=son[fail[u]][i],q.push(v);
			}
		}
	}
}AC;
struct bitree{
	int a[2000010],siz;
	int lowbit(int x){
		return x&(-x);
	}
	void add(int x,int val){
//		cout<<"BIT add "<<x<<' '<<val<<'\n';
		for(;x<=siz;x+=lowbit(x)) a[x]+=val;
	}
	int sum(int x){
		int re=0;
		for(;x>0;x-=lowbit(x)) re+=a[x];
		return re;
	}
}BIT;
struct tree{
	int first[2000010],dfn[2000010],out[2000010],cnt,clk,dep[2000010],st[2000010][22],siz;
	int seg[2000010],point[2000010];
	tree(){
		memset(first,-1,sizeof(first));cnt=clk=0;
	}
	bool cmp(int l,int r){
		return dfn[l]<dfn[r];
	}
	struct edge{
		int to,next;
	}a[4000010];
	void add(int u,int v){
//		cout<<"add "<<u<<' '<<v<<'\n';
		a[++cnt]=(edge){v,first[u]};first[u]=cnt;
		a[++cnt]=(edge){u,first[v]};first[v]=cnt;
	}
	void dfs(int u,int f){
		int i,v;dfn[u]=++clk;dep[u]=dep[f]+1;st[u][0]=f;point[clk]=u;
//		cout<<"T dfs "<<u<<' '<<f<<' '<<dfn[u]<<' '<<dep[u]<<'\n';
		for(i=first[u];~i;i=a[i].next){
			v=a[i].to;if(v==f) continue;
			dfs(v,u);
		}
		out[u]=clk;
	}
	void ST(){
		for(int j=1;j<=21;j++){
			for(int i=1;i<=siz;i++) st[i][j]=st[st[i][j-1]][j-1];
		}
	}
	int lca(int l,int r){
//		cout<<"lca "<<l<<' '<<r<<'\n';
		int i;
		if(dep[l]>dep[r]) swap(l,r);
		for(i=21;i>=0;i--) if(dep[st[r][i]]>=dep[l]) r=st[r][i];
		if(l==r) return l; 
		for(i=21;i>=0;i--){
			if(st[r][i]!=st[l][i]){
				r=st[r][i];
				l=st[l][i];
			}
		}
		return st[l][0];
	}
	void change(char s[]){
		int i,cur=AC.rt,tmp,len=strlen(s);
		for(i=0;i<len;i++){
			tmp=s[i]-'a';cur=AC.son[cur][tmp];
			seg[i]=dfn[cur];
		}
		sort(seg,seg+len);
		BIT.add(seg[0],1);
		for(i=1;i<len;i++){
			if(seg[i]!=seg[i-1]){
				BIT.add(seg[i],1);
				BIT.add(dfn[lca(point[seg[i]],point[seg[i-1]])],-1);
			}
		}
	}
	int ask(int pos){
		int x=AC.end[pos];
		return BIT.sum(out[x])-BIT.sum(dfn[x]-1);
	}
}T;
int n,m;char s[2000010];
int main(){
	n=read();int i,t1,t2;
	for(i=1;i<=n;i++) scanf("%s",s),AC.insert(s,i);
	
	AC.AC();BIT.siz=T.siz=AC.cnt;
//	cout<<"finish AC\n";
	
	for(i=1;i<=BIT.siz;i++) T.add(i,AC.fail[i]);
	T.dfs(1,0);T.ST();
	
	m=read();
	for(i=1;i<=m;i++){
		t1=read();
		if(t1==1){
			scanf("%s",s);
			T.change(s);
		}
		else{
			t2=read();
			printf("%d\n",T.ask(t2));
		}
	}
}
