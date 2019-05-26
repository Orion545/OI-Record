#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#define end DEEP_DARK_FANTASY
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
int ch[2000010][26],cnt,siz[2000010],end[2000010];
int n,first[200010],dep[200010],st[200010][20],cnte,root[200010];
char str[200010][20];
struct edge{
	int to,next;
}a[400010];
inline void add(int u,int v){
	a[++cnte]=(edge){v,first[u]};first[u]=cnte;
	a[++cnte]=(edge){u,first[v]};first[v]=cnte;
}
void insert(int &cur,char s[],int pos,int pre){
	cur=++cnt;
//	cout<<"insert "<<cur<<' '<<s[pos]<<' '<<pre<<'\n';
	memcpy(ch[cur],ch[pre],sizeof(ch[pre]));
	siz[cur]=siz[pre]+1;end[cur]=end[pre];
	if(pos==strlen(s)){end[cur]++;return;}
	insert(ch[cur][s[pos]-'a'],s,pos+1,ch[pre][s[pos]-'a']);
}
void dfs(int u,int f){
	int i,v;dep[u]=dep[f]+1;st[u][0]=f;
	insert(root[u],str[u],0,root[f]);
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(v==f) continue;
		dfs(v,u);
	}
}
void ST(){
	int i,j;
	for(j=1;j<=19;j++){
		for(i=1;i<=n;i++)
			st[i][j]=st[st[i][j-1]][j-1];
	}
}
int lca(int l,int r){
	int i;
	if(dep[l]>dep[r]) swap(l,r);
	for(i=19;i>=0;i--) if(dep[st[r][i]]>=dep[l]) r=st[r][i];
	if(l==r) return l;
	for(i=19;i>=0;i--){
		if(st[r][i]!=st[l][i]){
			r=st[r][i];
			l=st[l][i];
		}
	}
	return st[l][0];
}
char s[100010];int lastans=0;
void query(int pos,int l,int r,int f,int ff,int len){
	if(end[l]+end[r]-end[f]-end[ff]) lastans=max(lastans,len);
	if(s[pos]<'a'||s[pos]>'z') return;
	int c=s[pos]-'a',tmp=siz[ch[l][c]]+siz[ch[r][c]]-siz[ch[f][c]]-siz[ch[ff][c]];
//	cout<<"query "<<l<<' '<<r<<' '<<f<<' '<<ff<<' '<<len<<' '<<c<<' '<<tmp<<' '<<end[l]+end[r]-end[f]-end[ff]<<' '<<lastans<<'\n';
	if(!tmp) return;
	query(pos+1,ch[l][c],ch[r][c],ch[f][c],ch[ff][c],len+1);
}
int main(){
	memset(first,-1,sizeof(first));
	n=read();int q,online=read(),t1,t2,i,len,t3;
	for(i=1;i<=n;i++) scanf("%s",str[i]);
	for(i=2;i<=n;i++) t1=read(),add(t1,i);
	dfs(1,0);ST();
	q=read();
	while(q--){
		t1=read();t2=read();
		if(online) t1^=lastans,t2^=lastans;
		
		scanf("%s",s);len=strlen(s);s[len]=' ';
		t3=lca(t1,t2);lastans=0;
//		cout<<"query "<<t1<<' '<<t2<<' '<<t3<<'\n';
		for(i=0;i<len;i++)
			query(i,root[t1],root[t2],root[t3],root[st[t3][0]],0);
		printf("%d\n",lastans);
	}
}
