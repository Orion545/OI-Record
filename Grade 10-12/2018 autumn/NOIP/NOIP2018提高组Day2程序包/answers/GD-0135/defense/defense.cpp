#include<cstdio>
#include<cstring>
#include<algorithm>
#define INF 1152921504606846976
#define LL long long
using namespace std;
const LL N=1E5+5;
struct Edge{
	LL from,to,nxt,w;
}p[N*2],q[N];
LL lst[N],Lst[N],val[N],len=0;
LL dep[N],tyChar,tyNum;
LL f[N][2],Tag[N],bz[N];
LL fa[N],g[N][2],Ans[N];
LL n,m,x,y,u,v,tot=0;
void Add(LL x,LL y){
	p[++len].to=y;
	p[len].from=x;
	p[len].nxt=lst[x];
	lst[x]=len;
}
void Put(LL x,LL y,LL z){
	q[++tot].to=y;
	q[tot].from=x;
	q[tot].w=z;
	q[tot].nxt=Lst[x];
	Lst[x]=tot;
}
void dfs(LL x,LL pre){
	f[x][1]=val[x];
	for(LL j=lst[x];j;j=p[j].nxt){
		LL that=p[j].to;
		if (that!=pre){
			fa[that]=x;
			dep[that]=dep[x]+1;
			dfs(that,x);
			f[x][1]+=min(f[that][0],f[that][1]);
			f[x][0]+=f[that][1];
		}
	}
}
void change(LL x){
	if (!x) return;
	g[x][0]=0;g[x][1]=val[x];
	for(LL j=lst[x];j;j=p[j].nxt){
		LL that=p[j].to;
		if (that!=fa[x]){
			g[x][1]+=min(g[that][0],g[that][1]);
			g[x][0]+=g[that][1];
		}
	}if (bz[x])
		g[x][!Tag[x]]=INF;
	change(fa[x]);
}
void rechange(LL x){
	if (!x) return;
	g[x][0]=f[x][0];
	g[x][1]=f[x][1];
	rechange(fa[x]);
}
void solve(LL x,LL pre){
	for(LL j=Lst[x];j;j=q[j].nxt){
		LL that=q[j].to;
		if (that==1){
			LL tmp=val[x];
			for(LL k=lst[x];k;k=p[k].nxt){
				LL t=p[k].to;
				tmp=tmp+min(f[t][0],f[t][1]);
			}Ans[q[j].w]=tmp;
		}else{
			LL tmp=0;
			for(LL k=lst[x];k;k=p[k].nxt){
				LL t=p[k].to;
				tmp=tmp+f[t][1];
			}Ans[q[j].w]=tmp;
		}
	}for(LL j=lst[x];j;j=p[j].nxt){
		LL that=p[j].to;
		if (that!=pre){
			LL t1=f[x][0],t2=f[x][1];
			LL t3=f[that][0],t4=f[that][1];
			f[x][0]-=f[that][1];
			f[x][1]-=min(f[that][0],f[that][1]);
			f[that][0]+=f[x][1];
			f[that][1]+=min(f[x][0],f[x][1]);
			solve(that,x);
			f[x][0]=t1;f[x][1]=t2;
			f[that][0]=t3;f[that][1]=t4;
		}
	}
}
int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%lld%lld ",&n,&m);
	tyChar=getchar();
	scanf("%lld",&tyNum);
	for(LL i=1;i<=n;i++)
		scanf("%lld",&val[i]);
	for(LL i=1;i<=n-1;i++){
		scanf("%lld%lld",&x,&y);
		Add(x,y);Add(y,x);
	}dep[1]=1;dfs(1,0);
	if (tyNum==1){
		f[1][0]=INF;
		for(LL i=1;i<=m;i++){
			scanf("%lld%lld%lld%lld",&x,&y,&u,&v);
			Put(u,v,i);
		}solve(1,0);
		for(LL i=1;i<=m;i++)
			if (Ans[i]>=INF)
				printf("-1\n");
			else
				printf("%lld\n",Ans[i]);
		return 0;
	}memcpy(g,f,sizeof(g));
	for(LL i=1;i<=m;i++){
		scanf("%lld%lld%lld%lld",&x,&y,&u,&v);
		bz[x]=bz[u]=1;
		Tag[x]=y;Tag[u]=v;
		if (dep[x]<dep[u])
			swap(x,u);
		change(x);change(u);
		LL Ans=min(g[1][0],g[1][1]);
		if (Ans>=INF)
			printf("-1\n");
		else
			printf("%lld\n",Ans);
		bz[x]=bz[u]=0;
		rechange(x);rechange(u);
	}
	return 0;
}
