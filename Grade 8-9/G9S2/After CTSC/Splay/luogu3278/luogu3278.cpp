#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#define ll long long
using namespace std;
inline ll read(){
	ll re=0,flag=1;char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
ll fa[300010],ch[300010][2],w[300010],siz[300010];
ll add[300010],mul[300010];ll root=0,cnt=0;
ll MOD=20130426;
void clear(ll pos){
	fa[pos]=ch[pos][0]=ch[pos][1]=w[pos]=add[pos]=0;mul[pos]=1;siz[pos]=1;
}
void push(ll pos){
	if(add[pos]==0&&mul[pos]==1) return;
	if(ch[pos][0]) w[ch[pos][0]]*=mul[pos];w[ch[pos][0]]+=add[pos];w[ch[pos][0]]%=MOD;
	if(ch[pos][1]) w[ch[pos][1]]*=mul[pos];w[ch[pos][1]]+=add[pos];w[ch[pos][1]]%=MOD;
	if(ch[pos][0]) mul[ch[pos][0]]*=mul[pos];mul[ch[pos][0]]%=MOD;
	if(ch[pos][1]) mul[ch[pos][1]]*=mul[pos];mul[ch[pos][1]]%=MOD;
	if(ch[pos][0]) add[ch[pos][0]]*=mul[pos];add[ch[pos][0]]+=add[pos];add[ch[pos][0]]%=MOD;
	if(ch[pos][1]) add[ch[pos][1]]*=mul[pos];add[ch[pos][1]]+=add[pos];add[ch[pos][1]]%=MOD;
	add[pos]=0;mul[pos]=1;
}
void update(ll pos){
	siz[pos]=siz[ch[pos][0]]+siz[ch[pos][1]]+1;
}
ll get(ll pos){
	return pos==ch[fa[pos]][1];
}
void rotate(ll pos){
	ll f=fa[pos],ff=fa[f],son=get(pos);
	push(f);push(pos);
	ch[f][son]=ch[pos][son^1];
	if(ch[f][son]) fa[ch[f][son]]=f;
	fa[f]=pos;ch[pos][son^1]=f;
	fa[pos]=ff;
	if(ff) ch[ff][ch[ff][1]==f]=pos;
	update(f);update(pos);
}
void splay(ll pos,ll to){
	if(pos==to||fa[pos]==to) return;
	for(ll f;(f=fa[pos])!=to;rotate(pos))
		if(fa[f]!=to)
			rotate((get(pos)==get(f))?f:pos);
	update(pos);
	if(to==0) root=pos;
}
ll getrank(ll pos,ll x){
	push(pos);
	if(x==(siz[ch[pos][0]]+1)) return pos;
	if(x<(siz[ch[pos][0]]+1)) return getrank(ch[pos][0],x);
	else return getrank(ch[pos][1],x-siz[ch[pos][0]]-1);
}
ll build(ll l,ll r,ll f){
	if(l>r) return 0;
	cnt++;fa[cnt]=f;
	add[cnt]=0;mul[cnt]=1;w[cnt]=0;siz[cnt]=1;
	if(l==r) return cnt;
	ll mid=(l+r)>>1,cur=cnt;
	ch[cur][0]=build(l,mid-1,cur);
	ch[cur][1]=build(mid+1,r,cur);
	update(cur);
	return cur;
}
void addseg(ll l,ll r,ll val){
	ll x=getrank(root,l+1),y=getrank(root,r+3);
	splay(x,0);splay(y,x);
	push(ch[y][0]);
	add[ch[y][0]]+=val;add[ch[y][0]]%=MOD;
	w[ch[y][0]]+=val;w[ch[y][0]]%=MOD;
	push(ch[y][0]);update(ch[y][0]);
}
void mulseg(ll l,ll r,ll val){
	ll x=getrank(root,l+1),y=getrank(root,r+3);
	splay(x,0);splay(y,x);
	push(ch[y][0]);
	mul[ch[y][0]]*=val;mul[ch[y][0]]%=MOD;
	w[ch[y][0]]*=val;w[ch[y][0]]%=MOD;
	push(ch[y][0]);update(ch[y][0]);
}
void mulx(ll l,ll r){
	ll x=getrank(root,l+1),y=getrank(root,r+3);
	splay(x,0);splay(y,x);
	push(x);push(y);
	ll cur=ch[y][0];
	while(ch[cur][0]){
		push(cur);
		cur=ch[cur][0];
	}
	push(cur);
	ch[cur][0]=++cnt;clear(cnt);
	fa[cnt]=cur;
	while(cur){
		update(cur);cur=fa[cur];
	}
	cur=ch[y][0];
	while(ch[cur][1]){
		push(cur);
		cur=ch[cur][1];
	}
	push(cur);
	w[y]=(w[y]+w[cur])%MOD;
	int f=fa[cur],son=get(cur);
	if(ch[cur][0]){
		ch[f][son]=ch[cur][0];
		fa[ch[f][son]]=f;
	} 
	else ch[f][son]=0;
	clear(cur);
	while(f){
		update(f);f=fa[f];
	}
}
ll lis[200010],dfsclock;
void dfs(ll u){
	if(!u) return;
	push(u);
	dfs(ch[u][0]);
	dfsclock++;
	if(dfsclock>=2) lis[dfsclock-2]=w[u];
//	if(w[u]) cout<<"dfs "<<dfsclock<<' '<<w[u]<<'\n'; 
	dfs(ch[u][1]);
	update(u);
}
int main(){
	ll n=read(),i,t1,t2,t3,ans=0,cur;char s[10];
	root=build(1,200002,0);
	while(n--){
		scanf("%s",s);
		if(s[0]=='a'){
			t1=read(),t2=read(),t3=read();t3%=MOD;
			addseg(t1,t2,t3);
		}
		if(s[0]=='m'&&strlen(s)==3){
			t1=read(),t2=read(),t3=read();t3%=MOD;
			mulseg(t1,t2,t3); 
		}
		if(s[0]=='m'&&strlen(s)==4){
			t1=read(),t2=read();
			mulx(t1,t2);
		}
		if(s[0]=='q'){
			t1=read();
			memset(lis,0,sizeof(lis));dfsclock=0;
			dfs(root);
			ans=lis[0];cur=1;
//			for(i=0;i<=3;i++) cout<<lis[i]<<' ';cout<<'\n';
			for(i=1;i<=200000;i++){
				cur=cur*t1%MOD;ans=(ans+lis[i]*cur%MOD)%MOD;
			}
			printf("%lld\n",ans);
		}
	}
}
