#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#define end DEEP_DARK_FANTASY
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
inline int decode(char c){
	if(c=='r') return 0;
	if(c=='s') return 1;
	if(c=='p') return 2;
}
int n;ll w[100010],d[100010],pre[100010],s[200010];int root,lis[200010];char str[200010];
inline ll get(int r,int ca,int cb){
	if(ca==cb) return d[r];
	if(ca==cb-1||(ca==2&&cb==0)) return w[r];
	return 0;
}
inline ll win(int l,int r){
	return (l<=r)?pre[r]-pre[l-1]:0;
}
namespace sam{
	int ch[400010][3],val[400010],end[400010],fa[400010],last,cnt;
	inline int newnode(int w,int ed){val[++cnt]=w;end[cnt]=ed;return cnt;}
	inline void init(){cnt=last=root=1;val[1]=0;}
	inline void insert(int c){
		int p=last,np=newnode(val[p]+1,val[p]+1);
		lis[end[np]]=c;
		for(;p&&!ch[p][c];p=fa[p]) ch[p][c]=np;
		if(!p) fa[np]=root;
		else{
			int q=ch[p][c];
			if(val[q]==val[p]+1) fa[np]=q;
			else{
				int nq=newnode(val[p]+1,end[q]);
				memcpy(ch[nq],ch[q],sizeof(ch[q]));
				fa[nq]=fa[q];
				fa[q]=fa[np]=nq;
				for(;p&&ch[p][c]==q;p=fa[p]) ch[p][c]=nq;
			}
		}
//		cout<<"insert "<<c<<' '<<last<<' '<<np<<' '<<val[np]<<' '<<end[np]<<'\n';
		last=np;
	}
}
namespace t{
	int son[400010][3];ll ans[400010];
	using namespace sam;
	inline void init(){
		int i;
		memset(ans,-1,sizeof(ans));
		for(i=2;i<=cnt;i++) son[fa[i]][lis[end[i]-val[fa[i]]]]=i;
	}
	inline ll dfs(int u){
		if(~ans[u]) return ans[u];
		ll re=-1e18,c0,c1,v;
//		cout<<"dfs "<<u<<' '<<val[u]<<' '<<son[u][0]<<' '<<son[u][1]<<' '<<son[u][2]<<'\n';
		for(c0=0;c0<3;c0++){
			ll tmp=1e18;
			for(c1=0;c1<3;c1++){
				v=son[u][c1];if(!v) continue;
				if(val[v]<n) tmp=min(tmp,dfs(v)+win(val[u]+2,val[v])+get(val[u]+1,c0,c1));
				else tmp=min(tmp,win(val[u]+2,n)+get(val[u]+1,c0,c1));
//				cout<<"		trying "<<u<<' '<<val[u]+2<<' '<<c0<<' '<<c1<<' '<<v<<' '<<val[v]<<' '<<ans[v]<<' '<<win(val[u]+2,val[v])<<' '<<win(val[u]+2,n)<<' '<<get(val[u]+1,c0,c1)<<'\n';
			}
//			cout<<"	finish c0 "<<c0<<" of "<<u<<' '<<tmp<<'\n';
			if(tmp!=1e18) re=max(re,tmp);
		}
//		cout<<"finish dfs "<<u<<' '<<re<<'\n';
		return ans[u]=re;
	}
}
int main(){
	n=read();int i;
	scanf("%s",str);
	for(i=1;i<=n;i++) s[i]=s[i+n]=decode(str[i-1]);
	for(i=1;i<=n;i++){
		w[i]=read();d[i]=read();
		pre[i]=pre[i-1]+w[i];
//		cout<<"input "<<i<<' '<<pre[i]<<'\n';
	}
	sam::init();
	for(i=1;i<=n+n;i++) sam::insert(s[n+n-i+1]);
	t::init();
	printf("%lld\n",t::dfs(1));
}
