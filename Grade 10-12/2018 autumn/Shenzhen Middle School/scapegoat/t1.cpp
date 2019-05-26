#include<iostream>
#include<cassert>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
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
int ch[200010][2],fa[200010],siz[200010],num[200010],w[200010],cnt;
void update(int cur){
	siz[cur]=siz[ch[cur][0]]+siz[ch[cur][1]]+num[cur];
}
vector<int>s;
void dfs(int u){
	if(!u) return;
	dfs(ch[u][0]);
	if(num[u]) s.push_back(u);
	dfs(ch[u][1]);
}
int build(int l,int r,int f){
	if(l>r) return 0;
//	cout<<"	build "<<l<<' '<<r<<' '<<f<<'\n';
	int mid=(l+r)>>1,cur=s[mid];
	ch[cur][0]=ch[cur][1]=0;fa[cur]=f;siz[cur]=num[cur];
	if(l==r) return cur;
	ch[cur][0]=build(l,mid-1,cur);
	ch[cur][1]=build(mid+1,r,cur);
	update(cur);return cur;
}
int get(int cur){return ch[fa[cur]][1]==cur;}
int	unb,root=0;
void rebuild(int u){
//	cout<<"start rebuild "<<u<<'\n';
	s.clear();
	dfs(u);
	int f=fa[u],son=get(u),tmp=build(0,s.size()-1,f);
	if(f) ch[f][son]=tmp;
	else root=tmp;
}
double alpha=0.78;
void insert(int cur,int val){
//	cout<<"insert "<<cur<<' '<<w[cur]<<' '<<val<<'\n';
	if(fa[cur]==0) unb=0;
	if(!cur){
		cnt++;ch[cnt][0]=ch[cnt][1]=0;fa[cnt]=0;siz[cnt]=num[cnt]=1;w[cnt]=val;
		root=cnt;return;
	}
	siz[cur]++;
	if(w[cur]==val){
		num[cur]++;return;
	}
	if(val<w[cur]){
		if(!ch[cur][0]){
			cnt++;ch[cnt][0]=ch[cnt][1]=0;fa[cnt]=cur;siz[cnt]=1;num[cnt]=1;w[cnt]=val;
			ch[cur][0]=cnt;return;
		}
		else insert(ch[cur][0],val);
	}
	else{
		if(!ch[cur][1]){
			cnt++;ch[cnt][0]=ch[cnt][1]=0;fa[cnt]=cur;siz[cnt]=1;num[cnt]=1;w[cnt]=val;
			ch[cur][1]=cnt;return;
		}
		else insert(ch[cur][1],val);
	}
//	cout<<"finish insert "<<cur<<' '<<fa[cur]<<' '<<siz[ch[cur][0]]<<' '<<siz[ch[cur][1]]<<' '<<siz[cur]<<'\n';
	double le=siz[ch[cur][0]],ri=siz[ch[cur][1]],ss=siz[cur];
	if((max(le,ri)/ss)>alpha) unb=cur;
//	cout<<"check "<<le<<' '<<ri<<' '<<ss<<' '<<max(le,ri)<<' '<<max(le,ri)/ss<<' '<<unb<<'\n';
	if(fa[cur]==0&&unb) rebuild(unb);
}
int getpos(int cur,int rk){
//	cout<<"getpos "<<cur<<' '<<siz[ch[cur][0]]<<' '<<siz[ch[cur][1]]<<' '<<siz[cur]<<' '<<num[cur]<<' '<<rk<<'\n';
//	assert(cur);
	if(siz[ch[cur][0]]<rk&&siz[ch[cur][0]]+num[cur]>=rk) return cur;
	if(siz[ch[cur][0]]>=rk) return getpos(ch[cur][0],rk);
	else return getpos(ch[cur][1],rk-siz[ch[cur][0]]-num[cur]);
}
int getrank(int cur,int val){
//	cout<<"getrank "<<cur<<' '<<w[cur]<<' '<<val<<'\n';
	if(w[cur]==val) return siz[ch[cur][0]]+1;
	if(w[cur]>val) return getrank(ch[cur][0],val);
	else return getrank(ch[cur][1],val)+siz[ch[cur][0]]+num[cur];
}
void del(int cur,int val){
	siz[cur]--;
	if(w[cur]==val){num[cur]--;return;}
	if(w[cur]>val) del(ch[cur][0],val);
	else del(ch[cur][1],val);
}
int main(){
	int N=read(),op,x,tmp;
	while(N--){
		op=read();x=read();
//		cout<<"read in "<<op<<' '<<x<<'\n';
		if(op==1) insert(root,x);
		if(op==2) del(root,x);
		if(op==3) insert(root,x),printf("%d\n",getrank(root,x)),del(root,x);
		if(op==4) printf("%d\n",w[getpos(root,x)]);
		if(op==5) insert(root,x),printf("%d\n",w[getpos(root,getrank(root,x)-1)]),del(root,x);
		if(op==6){
			insert(root,x);
			tmp=getrank(root,x);
			printf("%d\n",w[getpos(root,tmp+num[getpos(root,tmp)])]);
			del(root,x);
		}
	}
}

