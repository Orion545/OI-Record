#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
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
int n,a[400010],pre[400010],suf[400010],f[400010],g[400010],root[400010];
namespace t{
	int ch[13000010][2],cnt;
	void insert(int &cur,int pre,int dep,int val){
		cur=++cnt;
		ch[cur][0]=ch[pre][0];ch[cur][1]=ch[pre][1];
		if(dep==32) return;
		int pos=(val>>(31-dep))&1;
		insert(ch[cur][pos],ch[pre][pos],dep+1,val);
	}
	int query(int cur,int dep,int val){
		if(dep==32) return 0;
		int pos=(val>>(31-dep))&1;
		if(ch[cur][pos^1]) return ((query(ch[cur][pos^1],dep+1,val))|(1<<(31-dep)));
		else return query(ch[cur][pos],dep+1,val);
	}
}
int main(){
	n=read();int i;
	for(i=1;i<=n;i++) a[i]=read();
	for(i=1;i<=n;i++) pre[i]=pre[i-1]^a[i];
	for(i=n;i>=1;i--) suf[i]=suf[i+1]^a[i];
	t::cnt=0;
	for(i=1;i<=n;i++){
		f[i]=max(max(f[i-1],pre[i]),t::query(root[i-1],0,pre[i]));
		t::insert(root[i],root[i-1],0,pre[i]);
	}
	t::cnt=0;
	for(i=n;i>=1;i--){
		g[i]=max(max(g[i+1],suf[i]),t::query(root[i+1],0,suf[i]));
		t::insert(root[i],root[i+1],0,suf[i]);
	}
	int ans=0;
	for(i=2;i<=n;i++) ans=max(ans,f[i-1]+g[i]);
	cout<<ans<<'\n';
}
