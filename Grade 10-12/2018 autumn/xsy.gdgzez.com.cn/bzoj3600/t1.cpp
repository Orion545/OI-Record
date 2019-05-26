#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cassert>
#include<vector>
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
//scapegoat
double f[600010];int root,unb;
struct node{
	int l,r;
	friend bool operator >(node x,node y){
		if(f[x.l]>f[y.l]) return 1;
		if(f[x.l]==f[y.l]&&f[x.r]>f[y.r]) return 1;
		return 0;
	}
	friend bool operator ==(node x,node y){
		return (f[x.l]==f[y.l])&&(f[x.r]==f[y.r]);
	}
};
namespace scp{
	node a[600010];
	int siz[600010],key[600010][2],ch[600010][2],pos[600010],cntn;
	void update(int x){
		siz[x]=siz[ch[x][0]]+siz[ch[x][1]]+1;
	}
	vector<int>str;
	void dfs(int u){
		if(!u) return;
		dfs(ch[u][0]);
		str.push_back(u);
		dfs(ch[u][1]);
	}
	void build(int &cur,int l,int r,double ql,double qr){
		if(l>r){cur=0;return;}
		int mid=(l+r)>>1;double md=(ql+qr)*0.5;
		cur=str[mid];
		f[cur]=md;
		build(ch[cur][0],l,mid-1,ql,md);
		build(ch[cur][1],mid+1,r,md,qr);
		update(cur);
	}
	void rebuild(int &u,double l,double r){
		str.clear();
		dfs(u);
		build(u,0,str.size()-1,l,r);
	}
	double alpha=0.75;int cho;
	int insert(int &cur,node val,double ql,double qr){
		double mid=(ql+qr)*0.5;
		if(!cur){
			cur=++cntn;f[cur]=mid;a[cur]=val;siz[cur]=1;
			return cur;
		}
		int p;
		if(val==a[cur]){p=cur;return p;}
		else{
			siz[cur]++;
			if(val>a[cur]) p=insert(ch[cur][1],val,mid,qr);
			else p=insert(ch[cur][0],val,ql,mid);
		}
		if((double)(siz[cur]*0.75)>(double)(max(siz[ch[cur][0]],siz[ch[cur][1]]))){
			if(unb){
				if(ch[cur][0]==unb) rebuild(ch[cur][0],ql,mid);
				else rebuild(ch[cur][1],mid,qr);
				unb=0;
			}
		}
		else unb=cur;
		return p;
	}
}
int maxn[1000010],pos[1000010];
void change(int l,int r,int p,int cur){
	int mid=(l+r)>>1;
	if(l==r){maxn[p]=l;return;}
	if(mid>=cur) change(l,mid,p<<1,cur);
	else change(mid+1,r,p<<1|1,cur);
	if(f[pos[maxn[p<<1]]]>=f[pos[maxn[p<<1|1]]]) maxn[p]=maxn[p<<1];
	else maxn[p]=maxn[p<<1|1];
}
int query(int l,int r,int ql,int qr,int num){
	if(l>=ql&&r<=qr) return maxn[num];
	int mid=(l+r)>>1,re,re1;
	if(mid>=qr) return query(l,mid,ql,qr,num<<1);
	else if(mid<ql) return query(mid+1,r,ql,qr,num<<1|1);
	else{
		re=query(l,mid,ql,mid,num<<1);
		re1=query(mid+1,r,mid+1,qr,num<<1|1);
		if(f[pos[re]]>=f[pos[re1]]) return re;
		else return re1;
	}
}
int n,Q;
int main(){
	n=read();Q=read();int i,t1,t2,t3;char s[10];
	scp::insert(root,(node){0,0},0,1);f[0]=-1;
	for(i=1;i<=n;i++) pos[i]=1;
	for(i=1;i<=n;i++) change(1,n,1,i);
	while(Q--){
		scanf("%s",s);
		t1=read();t2=read();
		if(s[0]=='C'){
			t3=read();unb=0;
			pos[t3]=scp::insert(root,(node){pos[t1],pos[t2]},0,1);
			if(unb) scp::rebuild(root,0,1);
			change(1,n,1,t3);
		}
		else printf("%d\n",query(1,n,t1,t2,1));
	}
}
