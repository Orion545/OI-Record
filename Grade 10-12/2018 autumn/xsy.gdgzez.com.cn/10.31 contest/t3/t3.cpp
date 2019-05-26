/*

宣告——
汝身听吾号令，托付吾之命运于汝之剑，
应圣杯之召，若汝遵从此意志此理，回应吧。
在此起誓，吾愿成就世间一切之善行，吾愿诛尽世间一切之恶行。
汝为身缠三大言灵之七天，从抑止之轮显现吧，天秤之守护者！

*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#define inf 1e15
#define ll long long
using namespace std;
inline ll read(){
	ll re=0,flag=1;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(isdigit(ch)) re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
namespace IO
{
    const ll __S=(1<<20)+5;char __buf[__S],*__H,*__T;
    inline char getc()
    {
        if(__H==__T) __T=(__H=__buf)+fread(__buf,1,__S,stdin);
        if(__H==__T) return -1;return *__H++;
    }
    template <class __I>inline void read(__I &__x)
    {
        __x=0;int __fg=1;char __c=getc();
        while(!isdigit(__c)&&__c!='-') __c=getc();
        if(__c=='-') __fg=-1,__c=getc();
        while(isdigit(__c)) __x=__x*10+__c-'0',__c=getc();
        __x*=__fg;
    }
    char __obuf[__S],*__oS=__obuf,*__oT=__oS+__S-1,__c,__qu[55];ll __qr;
    inline void flush(){fwrite(__obuf,1,__oS-__obuf,stdout);__oS=__obuf;}
    inline void putc(char __x){*__oS++ =__x;if(__oS==__oT) flush();}
    template <class __I>inline void print(__I __x)
    {
        if(!__x) putc('0');
        while(__x) __qu[++__qr]=__x%10+'0',__x/=10;
        while(__qr) putc(__qu[__qr--]);
    }
    inline void el(){putc('\n');}inline void sp(){putc(' ');}
}using namespace IO;
ll n,m,cnt=-1,first[100010],dis[100010],vis[100010],ans;
struct edge{
    ll to,next,w,cap;
}a[2000010];
inline void add(ll u,ll v,ll cap,ll w){
//	cout<<u<<" "<<v<<" "<<cap<<" "<<w<<"\n";
    a[++cnt]=(edge){v,first[u],w,cap};first[u]=cnt;
    a[++cnt]=(edge){u,first[v],-w,0};first[v]=cnt;
}
ll q[200010];
bool spfa(ll s,ll t){
    ll i,u,v,head=0,tail=1;memset(q,0,sizeof(q));
    for(i=1;i<=n+m+2;i++) dis[i]=-1;memset(vis,0,sizeof(vis));
    dis[t]=0;q[0]=t;vis[t]=1;
    while(head<tail){
        u=q[head++];vis[u]=0;
//        cout<<"spfa "<<u<<" "<<dis[u]<<"\n";
        for(i=first[u];~i;i=a[i].next){
            v=a[i].to;
//			cout<<"	trying "<<v<<" from "<<u<<' '<<a[i^1].cap<<' '<<dis[v]<<'\n';
            if(!a[i^1].cap) continue;
            if(~dis[v]&&dis[v]<=dis[u]+a[i^1].w) continue;
            dis[v]=dis[u]+a[i^1].w;
            if(!vis[v]){
                vis[v]=1;
                q[tail++]=v;
            }
        }
    }
    return ~dis[s];
}
ll dfs(ll u,ll t,ll limit){
//    cout<<"dfs "<<u<<" "<<t<<" "<<limit<<"\n";
    if(u==t||!limit) return limit;
    ll i,v,f,flow=0;vis[u]=1;
    for(i=first[u];~i;i=a[i].next){
        v=a[i].to;if(vis[v]) continue;
        if(dis[v]==dis[u]-a[i].w&&(f=dfs(v,t,min(limit,a[i].cap)))){
            flow+=f;limit-=f;
            a[i].cap-=f;a[i^1].cap+=f;
            ans+=f*a[i].w;
            //cout<<"ans added "<<f*a[i].w<<"\n";
            if(!limit){
                vis[u]=0;
                return flow;
            }
        }
    }
    dis[u]=-1;
    return flow;
}
ll mcmf(ll s,ll t){
//	cout<<"begin mcmf\n";
    ll re=0;
    while(spfa(s,t)){
        vis[t]=1;
        while(vis[t]){
            memset(vis,0,sizeof(vis));
            re+=dfs(s,t,inf);
        }
    } 
    return re;
}
struct hole{
	ll pos,siz;
	inline bool operator <(const hole &b)const{
		return pos<b.pos;
	}
}h[100010];
ll mouse[100010];
int main(){
//	freopen("in.in","r",stdin);
    memset(first,-1,sizeof(first));
    ll i,t1,t2,S,T;
    read(n);read(m);
    S=n+m+2;T=n+m+1;
    for(i=1;i<=n;i++){
		read(mouse[i]);
		add(S,i,1,0);
	}
    for(i=1;i<=m;i++){
    	read(t1);read(t2);
    	h[i]=(hole){t1,t2};
    }
    sort(h+1,h+m+1);
    for(i=1;i<=m;i++){
    	add(i+n,T,h[i].siz,0);
    	if(i<m){
    		add(i+n,i+1+n,inf,h[i+1].pos-h[i].pos);
    		add(i+1+n,i+n,inf,h[i+1].pos-h[i].pos);
    	}
    }
    for(i=1;i<=n;i++){
		ll pos=lower_bound(h+1,h+m+1,(hole){mouse[i],0})-h;
		if(pos<=m) add(i,pos+n,inf,h[pos].pos-mouse[i]);
		if(pos>1) add(i,pos+n-1,inf,mouse[i]-h[pos-1].pos);
	}
	ll flow=mcmf(S,T);
    if(flow==n) cout<<ans<<"\n";
    else puts("-1");
}
