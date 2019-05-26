#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
inline char _getc(){
	static char buf[1<<14],*p1=buf,*p2=buf;
	return (p1==p2)&&(p2=(p1=buf)+fread(buf,1,1<<14,stdin),p1==p2)?EOF:*p1++;
}
inline ll scan(){
	ll x=0,f=1; char ch=0;
	while(ch<48) ch=='-'&&(f=-1),ch=_getc();
	while(ch>=48) x=x*10+ch-48,ch=_getc();
	return x*f;
}
inline void _read(char*s){
	char ch=0; int o=0;
	while(ch<'A'||ch>'Z') ch=_getc();
	while((ch>='A'&&ch<='Z')||(ch>='0'&&ch<='9'))
	s[++o]=ch,ch=_getc();
}
const ll N=1e5+4,INF=(ll)1e14+7,X=3e3+4;
int n,m,head[N],to[N<<1],nex[N<<1];ll p[N]; 
char type[10];
bool vis[X][X];
inline void add(int u,int v){
	static int ce=0; nex[++ce]=head[u];
	head[u]=ce; to[ce]=v;
}
ll f[N][2][2];
void dfs(int u,int fa){
	bool leaf=1;
	ll sum10=0,sum11=0,sum1m=0,sum0m=0;
	for(int i=head[u];i;i=nex[i]){
		if(to[i]==fa) continue;
		leaf=0; dfs(to[i],u);
		sum10+=f[to[i]][1][0];
		sum11+=f[to[i]][1][1];
		sum0m+=min(f[to[i]][0][0],min(f[to[i]][1][0],f[to[i]][1][1]));
		sum1m+=min(f[to[i]][1][0],f[to[i]][1][1]);
	}
	if(leaf) f[u][0][0]=0,f[u][1][1]=p[u];
	else{
		f[u][0][0]=sum1m; f[u][1][1]=sum0m+p[u];
		for(int i=head[u];i;i=nex[i]){
			if(to[i]==fa) continue;
			ll rm=sum1m-min(f[to[i]][1][0],f[to[i]][1][1]);
			f[u][1][0]=min(f[u][1][0],rm+f[to[i]][1][1]);
		}
	}
}
int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	n=scan(); m=scan(); _read(type);
	for(int i=1;i<=n;i++) p[i]=scan();
	for(int i=1;i<n;i++){
		int a,b; a=scan(); b=scan();
		add(a,b); add(b,a);
		vis[a][b]=vis[b][a]=1;
	}
	while(m--){
		ll a,x,b,y,pa,pb; 
		a=scan(); x=scan(); b=scan(); y=scan();
		if(x==y&&x==0&&vis[a][b]){
			puts("-1"); continue;
		}
		pa=p[a]; pb=p[b];
		if(x==0) p[a]=INF; if(y==0) p[b]=INF;
		memset(f,0x3f,sizeof(f));
		dfs(1,0); printf("%lld\n",min(f[1][1][0],f[1][1][1]));
		p[a]=pa; p[b]=pb;
	}
	fclose(stdin); fclose(stdout);
	return 0;
}
