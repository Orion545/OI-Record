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
ll n,ch[4000010][2],siz[4000010],cnt1,cnt2,cnt,son[400010][2],val[400010],rt[400010];
void update(ll pos){
	siz[pos]=siz[ch[pos][0]]+siz[ch[pos][1]];
}
ll insert(ll l,ll r,ll pos){
	ll mid=(l+r)>>1,cur=++cnt;
	assert(cnt<=4000000);
	siz[cur]=1;ch[cur][0]=ch[cur][1]=0;
	if(l==r) return cur;
	if(mid>=pos) ch[cur][0]=insert(l,mid,pos);
	else ch[cur][1]=insert(mid+1,r,pos);
	return cur;
}
ll merge(ll cur,ll pre){
	if(!cur) return pre;
	if(!pre) return cur;
	cnt1+=siz[ch[cur][0]]*siz[ch[pre][1]];
	cnt2+=siz[ch[cur][1]]*siz[ch[pre][0]];
	ch[cur][0]=merge(ch[cur][0],ch[pre][0]);
	ch[cur][1]=merge(ch[cur][1],ch[pre][1]);
	update(cur);
	return cur;
}
ll dfs(ll u){
	ll ans=0;
	if(!val[u]){
		ans=dfs(son[u][0])+dfs(son[u][1]);
		cnt1=cnt2=0;
		rt[u]=merge(rt[son[u][0]],rt[son[u][1]]);
		ans+=min(cnt1,cnt2);
	}
	else rt[u]=insert(1,n,val[u]);
	return ans;
}
ll readin(ll u){
	ll t1=read(),t2;
	if(t1) val[u]=t1,t2=u;
	else{
		son[u][0]=u+1;
		t2=readin(son[u][0]);
		son[u][1]=t2+1;
		t2=readin(son[u][1]);
	}
	return t2;
}
int main(){
	n=read();
	readin(1);
	printf("%lld\n",dfs(1));
}
