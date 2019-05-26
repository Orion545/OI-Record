#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cassert>
#define ll long long
#define MOD 10007
using namespace std;
inline int read(){
	int re=0,flag=1;char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
int fa[30010],ch[30010][2],sp[30010],k[30010],b[30010],sumk[30010],sumb[30010],rev[30010];
int op[30010],ed[30010],inv[10010];
void update(int num){
	if(!num) return;
	op[num]=(ch[num][0]?op[ch[num][0]]:num);
	ed[num]=(ch[num][1]?ed[ch[num][1]]:num);
	if(ch[num][0]){
		sumk[num]=sumk[ch[num][0]]*k[num]%MOD;
		sumb[num]=(sumb[ch[num][0]]*k[num]+b[num])%MOD;
	}
	else sumk[num]=1,sumb[num]=0;
	if(ch[num][1]){
		sumk[num]=sumk[num]*k[op[ch[num][1]]]%MOD*sumk[ch[num][1]]%MOD;
		sumb[num]=(sumk[ch[num][1]]*((sumb[num]*k[op[ch[num][1]]]+b[op[ch[num][1]]])%MOD)+sumb[ch[num][1]])%MOD;
	}
}
bool nroot(int num){return ((ch[fa[num]][0]==num)||(ch[fa[num]][1]==num));}
bool get(int x){return ch[fa[x]][1]==x;}
void rotate(int x){
	int f=fa[x],ff=fa[f],son=get(x),nr=nroot(f);
//	cout<<"		rotate "<<x<<' '<<f<<' '<<ff<<'\n';
	ch[f][son]=ch[x][son^1];
	if(ch[f][son]) fa[ch[f][son]]=f;
	fa[f]=x;ch[x][son^1]=f;
	fa[x]=ff;
	if(nr) ch[ff][ch[ff][1]==f]=x;
	update(f);update(x);
}
void splay(int x){
	if(!x) return ;
//	cout<<"	splay "<<x<<'\n';
	for(int f;nroot(x);rotate(x)){
		f=fa[x];
		if(nroot(f))
			rotate((get(x)==get(f))?f:x);
	}
//	cout<<"	finish splay\n";
}
void access(int x){
//	cout<<"access "<<x<<'\n';
	for(int y=0;x;y=x,x=fa[x]){
		splay(x);ch[x][1]=y;update(x);
	}
//	cout<<"finish access\n";
}
void link(int x,int y){
	access(x);splay(x);
	fa[x]=y;
}
void cut(int x){
	access(x);splay(x);
	int f=ed[ch[x][0]];
//	cout<<"		cut "<<x<<' '<<f<<'\n';
	splay(f);
	ch[f][1]=fa[x]=0;
	update(f);
}
int findrt(int u){
	access(u);splay(u);
	return op[u];
}
int n,vis[30010],clk,inif[30010];
int findr(int u){
	for(;!vis[u];u=inif[u]) vis[u]=clk;
	return (vis[u]==clk)?u:0;
}
int main(){
//	freopen("in.in","r",stdin);
//	freopen("my.out","w",stdout);
	n=read();int i,u,v,t1,t2,q,rtu,rtv,spfa,ans;char s[10];
	inv[1]=1;
	for(i=2;i<MOD;i++) inv[i]=(MOD-MOD/i)*inv[MOD%i]%MOD;
	for(i=1;i<=n;i++){
		k[i]=read();inif[i]=read();b[i]=read();
		sumk[i]=1;fa[i]=inif[i];
	}
	for(i=1;i<=n;i++){
		if(!vis[i]){
			clk++;
			u=findr(i);if(!u) continue;
			fa[u]=0;sp[u]=inif[u];
		}
	}
	q=read();
	while(q--){
		scanf("%s",s);
//		for(i=1;i<=n;i++) cout<<i<<' '<<fa[i]<<' '<<sp[i]<<' '<<ch[i][0]<<' '<<ch[i][1]<<' '<<sumk[i]<<' '<<sumb[i]<<'\n';
		if(s[0]=='A'){
			u=read();rtu=findrt(u);spfa=sp[rtu];
//			cout<<"query "<<u<<' '<<rtu<<' '<<spfa<<'\n';
			access(spfa);
			splay(spfa);
			t1=sumk[spfa];t2=sumb[spfa];
//			cout<<"now "<<t1<<' '<<t2<<'\n';
			t1=(t1*k[rtu])%MOD;
			t2=(t2*k[rtu]+b[rtu])%MOD;
			if(t1==1) ans=-1-(t2==0);
			else ans=(-t2*inv[(MOD+t1-1)%MOD]%MOD+MOD)%MOD;
			if(ans<0) printf("%d\n",ans);
			else{
				access(u);splay(u);
				ans=((ans*sumk[u])%MOD+sumb[u])%MOD;
				printf("%d\n",ans);
			}
		}
		else{
			u=read();t1=read();v=read();t2=read();
			rtu=findrt(u);rtv=findrt(v);
			spfa=sp[rtu];
			splay(u);
			k[u]=t1;b[u]=t2;update(u);
			access(u);
			splay(u);
//			cout<<"change "<<u<<' '<<ch[u][0]<<' '<<spfa<<' '<<rtu<<' '<<v<<' '<<rtv<<'\n';
			if(!ch[u][0]){
				if(rtu==rtv) sp[u]=v;
				else link(u,v),sp[u]=0;
			}
			else{
				access(spfa);
				splay(rtu);
				splay(u);
				if(fa[rtu]){// on circle
//					cout<<"	on circle\n";
					cut(u);
					link(rtu,sp[rtu]);
					sp[rtu]=0;
					if(rtu==rtv) sp[u]=v;
					else link(u,v);
				}
				else{// not on circle
//					cout<<" not on circle\n";
					cut(u);
					rtv=findrt(v);
					if(rtv==u) sp[u]=v;
					else link(u,v);
				}
			}
		}
	}
}
