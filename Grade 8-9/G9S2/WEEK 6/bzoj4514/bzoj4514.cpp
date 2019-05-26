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
    while(ch>'9'||ch<'0'){
        if(ch=='-') flag=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9') re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
    return re*flag;
}
ll cnt=-1,ans,flow,first[210],dis[210],vis[210],limit[210],pre[210];
struct edge{
    ll to,next,w,cap;
}a[100010];
inline void add(ll u,ll v,ll w,ll cap){
    //cout<<"add "<<u<<" "<<v<<" "<<w<<" "<<cap<<"\n";
    a[++cnt]=(edge){v,first[u],w,cap};first[u]=cnt;
    a[++cnt]=(edge){u,first[v],-w,0};first[v]=cnt;
}
bool spfa(ll s,ll t){
    //cout<<"*************************begin spfa\n";
    ll q[5010]={0},head=0,tail=1,u,v,w,i;
    for(i=s;i<=t;i++) dis[i]=-inf;
    memset(vis,0,sizeof(vis));
    memset(pre,-1,sizeof(pre));memset(limit,0,sizeof(limit));
    q[0]=s;vis[s]=1;dis[s]=0;limit[s]=inf;
    while(head<tail){
        u=q[head++];vis[u]=0;
        //cout<<"spfa "<<u<<" "<<dis[u]<<" "<<head<<" "<<tail<<"\n";
        for(i=first[u];~i;i=a[i].next){
            v=a[i].to;w=a[i].w;
            //cout<<" to "<<v<<" "<<dis[v]<<" "<<w<<"\n";
            if(a[i].cap&&(dis[v]<dis[u]+w)){
                //cout<<"     renew \n";
                dis[v]=dis[u]+w;
                limit[v]=min(limit[u],a[i].cap);
                pre[v]=i;
                if(!vis[v]) q[tail++]=v,vis[v]=1;
            }
        }
    }
    return dis[t]!=-inf;
}
ll n,A[210],B[210],C[210],col[210];
ll tot=0,pri[100010],v[100010]={0};
void init(){
    ll i,j,k;v[1]=1;
    for(i=2;i<=100000;i++){
        if(!v[i]) pri[++tot]=i;
        for(j=1;j<=tot;j++){
            k=i*pri[j];if(k>100000) break;
            v[k]=1;
            if((i%pri[j])==0) break;
        }
    }
}
ll cntprime(ll x){
	//cout<<"cntprime "<<x<<"\n";
    ll re=0,c=1;
    while(x>1&&c<=tot){
        while((x%pri[c])==0) x/=pri[c],re++;
        c++;
    }
    //cout<<x<<" "<<c<<" "<<re<<"\n";
    if((c==tot+1)&&(x>1)) return 1;
    return re;
}
int main(){
    freopen("menci_pair.in","r",stdin);
    freopen("menci_pair.out","w",stdout);
    memset(first,-1,sizeof(first));
    ll i,j;init();
    n=read();
    //cout<<"begin read in\n";
    for(i=1;i<=n;i++) A[i]=read(),col[i]=cntprime(A[i]);
    //cout<<"finish read A\n";
    for(i=1;i<=n;i++){
        B[i]=read();
        if(col[i]%2) add(0,i,0,B[i]);
        else add(i,n+1,0,B[i]);
    }
    for(i=1;i<=n;i++) C[i]=read();
    //cout<<"finish read in\n";
    for(i=1;i<=n;i++){
        for(j=i+1;j<=n;j++){
        	//cout<<i<<" "<<j<<" "<<A[i]<<" "<<A[j]<<"\n";
            if((((A[i]%A[j])==0)&&(col[i]==col[j]+1))||(((A[j]%A[i])==0)&&(col[j]==col[i]+1))){
                if(col[i]%2) add(i,j,C[i]*C[j],inf);
                else add(j,i,C[i]*C[j],inf);
            }
        }
    }
    //cout<<"finish add edge\n";
    ll tmp,u;
    while(1){
        if(!spfa(0,n+1)) break;
        //cout<<"end1 "<<dis[n+1]<<" "<<ans<<" "<<flow<<"\n";
        if(dis[n+1]+ans<0) break;
        if(dis[n+1]>=0) tmp=limit[n+1];
        else tmp=min(limit[n+1],ans/(-dis[n+1]));
        //cout<<"end2 of spfa "<<dis[n+1]<<" "<<tmp<<"\n";
        ans+=dis[n+1]*tmp;flow+=tmp;
        for(u=n+1;~pre[u];u=a[pre[u]^1].to){
        	//cout<<u<<" "<<pre[u]<<" "<<a[pre[u]^1].to<<"\n";
            a[pre[u]].cap-=tmp;a[pre[u]^1].cap+=tmp;
        }
    }
    printf("%lld\n",flow);
}
