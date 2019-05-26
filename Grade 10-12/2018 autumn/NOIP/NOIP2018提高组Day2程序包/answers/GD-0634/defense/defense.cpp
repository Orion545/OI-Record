#include <cstdio>
#include <algorithm>
#define Add(x,y) (nxt[++num]=head[x],V[num]=y,head[x]=num)
#define For(x) for(int h=head[x],o=V[h]; h; o=V[h=nxt[h]])
using namespace std;
int head[100005],nxt[200005],V[200005],num;
int n,m,aa,bb,xx,yy,fa[100005],f[100005][2],tag[100005];
long long ans,p[100005];
char ch[5];


void dfs(int x,int ff){
	fa[x]=ff;
	For(x) if (o!=ff) dfs(o,x);
	f[x][1]=p[x];
	For(x){
		f[x][0]+=f[o][1];
		f[x][1]+=min(f[o][0],f[o][1]);
	}
}

int check(int x,int ff){
	For(x) if (o!=ff){
		if (!tag[x] &&!tag[o]) return 0;
		if (!check(o,x)) return 0;
	}
	return 1;
}

void zzk(int x,long long ss){
	if (x==4)
		int fdasjkldf=1;
	if (x>n){
		if (ss==3)
			int fdsalfkj=1;
		if (check(1,0)) ans=min(ans,ss);
		return;
	}
	if (x==aa){
		if (xx){tag[x]=1; zzk(x+1,ss+p[x]); tag[x]=0; return;}
		zzk(x+1,ss);
		return;
	}
	if (x==bb){
		if (yy){tag[x]=1; zzk(x+1,ss+p[x]); tag[x]=0; return;}
		zzk(x+1,ss);
		return;
	}
	zzk(x+1,ss);
	tag[x]=1;
	zzk(x+1,ss+p[x]);
	tag[x]=0;
}

int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d%s",&n,&m,ch);
	for (int i=1; i<=n; i++) scanf("%lld",&p[i]);
	for (int i=1,uu,vv; i<n; i++) scanf("%d%d",&uu,&vv),Add(uu,vv),Add(vv,uu);
	//dfs(1,0);
	
	if (n<=10 && m<=10){
		while (m--){
			ans=2147483647;
			for (int i=1; i<=n; i++) tag[i]=0;
			scanf("%d%d%d%d",&aa,&xx,&bb,&yy);
			zzk(1,0);
			if (ans==2147483647){puts("-1"); continue;}
			printf("%lld\n",ans);
		}
		return 0;
	}
		
	while (m--){
		scanf("%d%d%d%d",&aa,&bb,&xx,&yy);
	}
}
