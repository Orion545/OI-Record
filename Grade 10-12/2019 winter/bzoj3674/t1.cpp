#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#define last DEEP_DARK_FANTASY
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
int n,m,root[200010];
namespace seg{
	int ch[10000010][2],fa[10000010],dep[10000010],cnt;
	void insert(int &cur,int pre,int l,int r,int pos,int f){
		cur=++cnt;
		ch[cur][0]=ch[pre][0];ch[cur][1]=ch[pre][1];
		if(l==r){fa[cur]=f;dep[cur]=dep[pre];return;}
		int mid=(l+r)>>1;
		if(mid>=pos) insert(ch[cur][0],ch[pre][0],l,mid,pos,f);
		else insert(ch[cur][1],ch[pre][1],mid+1,r,pos,f);
	}
	inline int query(int cur,int pos){
		int l=1,r=n,mid;
		while(1){
			if(l==r) return cur;
			mid=(l+r)>>1;
			if(mid>=pos) cur=ch[cur][0],r=mid;
			else cur=ch[cur][1],l=mid+1;
		}
	}
	void build(int &cur,int l,int r){
		cur=++cnt;int mid=(l+r)>>1;
		if(l==r){fa[cur]=l;dep[cur]=1;return;}
		build(ch[cur][0],l,mid);build(ch[cur][1],mid+1,r);
	}
	void add(int &cur,int pre,int l,int r,int pos){
		cur=++cnt;
		ch[cur][0]=ch[pre][0];ch[cur][1]=ch[pre][1];
		if(l==r){fa[cur]=fa[pre];dep[cur]=dep[pre]+1;return;}
		int mid=(l+r)>>1;
		if(mid>=pos) add(ch[cur][0],ch[pre][0],l,mid,pos);
		else add(ch[cur][1],ch[pre][1],mid+1,r,pos);
	}
	int find(int rt,int x){
		int cur=query(rt,x);
		if(fa[cur]==x) return cur;
		return find(rt,fa[cur]);
	}
}
int main(){
	using namespace seg;
	n=read();m=read();int t3,t1,t2,tl,tr,cur=0,last=0;
	build(root[0],1,n);
	while(m--){
		t3=read();
		if(t3==1){
			t1=read()^last;t2=read()^last;
			tl=find(root[cur],t1);
			tr=find(root[cur],t2);
			if(fa[tl]==fa[tr]){root[cur+1]=root[cur];cur++;continue;}
			if(dep[tl]<dep[tr]) swap(tl,tr),swap(t1,t2);
			insert(root[cur+1],root[cur],1,n,fa[tr],fa[tl]);
			if(dep[tl]==dep[tr]) add(root[cur+1],root[cur+1],1,n,fa[tl]);
			cur++;
		}
		if(t3==2){
			t1=read()^last;
			root[++cur]=root[t1];
		}
		if(t3==3){
			t1=read()^last;t2=read()^last;
			tl=find(root[cur],t1);
			tr=find(root[cur],t2);
//			cout<<"query "<<t1<<' '<<tl<<' '<<fa[tl]<<' '<<t2<<' '<<tr<<' '<<fa[tr]<<'\n';
			printf("%d\n",last=(tl==tr));
			root[cur+1]=root[cur];cur++;
		}
	}
}

