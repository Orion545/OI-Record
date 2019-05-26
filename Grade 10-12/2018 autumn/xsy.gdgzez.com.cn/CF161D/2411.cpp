/*

宣告——
汝身在我之下，托付吾之命运于汝之剑，
遵从圣杯之名，若汝遵从此意志此理，回应吧。
在此起誓，吾是成就世间一切行善之人，吾是肃清世间一切罪恶之人，
被狂乱之槛所囚的囚徒。吾是此锁链的操纵者，
汝为身缠三大言灵之七天，从抑止之轮显现吧，天秤之守护者！

*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
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
int n,m,cnt,root,sum,ans=0,first[50010];
int d[510],tmp[510],cntd,cnttmp,dis[50010],siz[50010],son[50010];
bool vis[50010];
struct edge{
    int to,next,w;
}a[100010];
inline void add(int u,int v,int w){
    a[++cnt]=(edge){v,first[u],w};first[u]=cnt;
    a[++cnt]=(edge){u,first[v],w};first[v]=cnt;
}
void init(){
    cnt=0;ans=0;memset(first,-1,sizeof(first));
    memset(siz,0,sizeof(siz));memset(son,0,sizeof(son));
    memset(dis,0,sizeof(dis));memset(vis,0,sizeof(vis));
}
void getroot(int u,int f){
	int i,v;siz[u]=1;son[u]=0;
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(v==f||vis[v]) continue;
		getroot(v,u);
		siz[u]+=siz[v];son[u]=max(son[u],siz[v]);
	}
	son[u]=max(son[u],sum-siz[u]);
	if(son[u]<son[root]) root=u;
}
void get(int u,int f,int w){
	int i,v;
	dis[u]=dis[f]+w;
//	cout<<"	get "<<u<<' '<<f<<' '<<dis[u]<<'\n';
	if(dis[u]>m) return;
	tmp[dis[u]]++;cnttmp=max(cnttmp,dis[u]);
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(v==f||vis[v]) continue;
		get(v,u,a[i].w);
	}
}
void dfs(int u,int cursum){
	int i,j,v;vis[u]=1;
	cntd=0;d[0]=1;dis[u]=0;
	for(j=first[u];~j;j=a[j].next){
		v=a[j].to;if(vis[v]) continue;
		get(v,u,a[j].w);
		for(i=0;i<=m;i++) ans+=d[i]*tmp[m-i];
		for(i=0;i<=cnttmp;i++) d[i]+=tmp[i];	
//		cout<<"	tmpfin "<<v<<' '<<ans<<'\n';
		cntd=max(cntd,cnttmp);
		for(i=0;i<=cnttmp;i++) tmp[i]=0;
		cnttmp=0;
	}
	for(i=0;i<=cntd;i++) d[i]=0;
	cntd=0;
//	cout<<"finish getans "<<u<<' '<<ans<<'\n';
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(vis[v]) continue;
		sum=(siz[v]>siz[u])?(cursum-siz[u]):siz[v];
		root=0;son[0]=sum;
		getroot(v,0);
		dfs(root,sum);
	}
}
		
int main(){
    //freopen("tree.in","r",stdin);
    int i,t1,t2,t3;
    n=read();m=read();
    init();
    for(i=1;i<n;i++){
        t1=read();t2=read();t3=1;
        add(t1,t2,t3);
    }
    sum=n;root=0;son[0]=n;
    getroot(1,0);
    dfs(root,n);
    printf("%d\n",ans);
}

