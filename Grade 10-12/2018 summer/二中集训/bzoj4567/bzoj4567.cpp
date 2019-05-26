#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
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
ll son[510010][26],deep_dark_fantasy[510010],cnt;
struct edge{
	ll to,siz;
};
bool cmp(edge l,edge r){
	return l.siz<r.siz;
}
vector<edge>a[100010];ll siz[100010];
inline void add(ll u,ll v){
	a[u].push_back((edge){v,0});
}
void insert(char s[],ll num){
	ll i,len=strlen(s),cur=0,tmp;
	for(i=len-1;i>=0;i--){
		tmp=s[i]-'a';
		if(!son[cur][tmp]) son[cur][tmp]=++cnt;
		cur=son[cur][tmp];
	}
	deep_dark_fantasy[cur]=num;
}
void rebuild(ll u,ll top){
	ll i;
	if(deep_dark_fantasy[u]!=0) add(deep_dark_fantasy[top],deep_dark_fantasy[u]),top=u;
	for(i=0;i<26;i++){
		if(!son[u][i]) continue;
		rebuild(son[u][i],top);
	}
}
ll getsiz(ll u){
	ll i,re=1,tmp;edge v;
	for(i=0;i<a[u].size();i++){
		v=a[u][i];tmp=getsiz(v.to);
		a[u][i].siz+=tmp;re+=tmp;
	}
	sort(a[u].begin(),a[u].end(),cmp);
	return re;
}
ll dfn[100010],clk,ans=0;
void dfs(ll u){
	dfn[u]=++clk;
	ll i,v;
	for(i=0;i<a[u].size();i++){
		v=a[u][i].to;
		ans+=clk+1-dfn[u];
		dfs(v);
	}
}
char s[1000010];
int main(){
//	freopen("9.in","r",stdin);
	ll n=read();ll i;
	for(i=1;i<=n;i++) scanf("%s",s),insert(s,i);
	rebuild(0,0);getsiz(0);dfs(0);
	printf("%lld",ans);
}
