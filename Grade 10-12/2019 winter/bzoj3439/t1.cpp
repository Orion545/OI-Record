#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<vector>
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
int n,in[100010],out[100010],clk,root[100010],lis[100010];
char s[100010];int pos[100010];
vector<int>num[100010];
namespace seg{
	int siz[2000010],ch[2000010][2],cnt;
	inline void insert(int &cur,int pre,int l,int r,int pos){
		cur=++cnt;
		ch[cur][0]=ch[pre][0];ch[cur][1]=ch[pre][1];siz[cur]=siz[pre]+1;
//		cout<<"	insert "<<l<<' '<<r<<' '<<pos<<' '<<cur<<' '<<siz[cur]<<'\n';
		if(l==r) return;
		int mid=(l+r)>>1;
		if(mid>=pos) insert(ch[cur][0],ch[pre][0],l,mid,pos);
		else insert(ch[cur][1],ch[pre][1],mid+1,r,pos);
	}
	inline int query(int cur,int pre,int l,int r,int lim){
//		cout<<"	query "<<l<<' '<<r<<' '<<cur<<' '<<pre<<' '<<siz[cur]<<' '<<siz[pre]<<' '<<siz[ch[cur][0]]<<' '<<siz[ch[pre][0]]<<' '<<lim<<'\n';
		if(siz[cur]-siz[pre]<lim) return -1;
		if(l==r) return l;
		int mid=(l+r)>>1;
		if(siz[ch[cur][0]]-siz[ch[pre][0]]>=lim) return query(ch[cur][0],ch[pre][0],l,mid,lim);
		else return query(ch[cur][1],ch[pre][1],mid+1,r,lim-siz[ch[cur][0]]+siz[ch[pre][0]]);
	}
}
namespace t{
	int first[100010],cnte=-1;
	void init(){memset(first,-1,sizeof(first));}
	struct edge{
		int to,next;
	}a[1000010];
	inline void add(int u,int v){
		a[++cnte]=(edge){v,first[u]};first[u]=cnte;
		a[++cnte]=(edge){u,first[v]};first[v]=cnte;
	}
	void dfs(int u,int f){
		int i,v;
		in[u]=++clk;
		lis[clk]=u;
//		cout<<"dfs "<<u<<' '<<f<<' '<<in[u]<<' '<<num[u].size()<<'\n';
		for(i=first[u];~i;i=a[i].next){
			v=a[i].to;if(v==f) continue;
			dfs(v,u);
		}
		out[u]=clk;
	}
}
namespace trie{
	int ch[100010][26],cnt=1;
	inline void insert(int len,int val){
		int i,cur=1,tmp;
		for(i=len-1;i>=0;i--){
			tmp=s[i]-'a';
			if(!ch[cur][tmp]){
				ch[cur][tmp]=++cnt;
				t::add(cur,ch[cur][tmp]);
			}
			cur=ch[cur][tmp];
		}
		num[cur].push_back(val);
		pos[val]=cur;
	}
}
int main(){
	n=read();t::init();int i,t1,l,r,j;
	for(i=1;i<=n;i++){
		scanf("%s",s);
		trie::insert(strlen(s),i);
	}
	t::dfs(1,0);
	for(i=1;i<=trie::cnt;i++){
		t1=lis[i];
//		cout<<"do node "<<i<<' '<<lis[i]<<'\n';
		if(num[t1].size()==0){root[i]=root[i-1];continue;}
		seg::insert(root[i],root[i-1],1,n,num[t1][0]);
		for(j=1;j<num[t1].size();j++)
			seg::insert(root[i],root[i],1,n,num[t1][j]);
	}
	for(i=1;i<=n;i++){
		t1=read();
		l=in[pos[i]]-1;r=out[pos[i]];
//		cout<<"query "<<i<<' '<<pos[i]<<' '<<l<<' '<<r<<'\n';
		printf("%d\n",seg::query(root[r],root[l],1,n,t1));
	}
}
