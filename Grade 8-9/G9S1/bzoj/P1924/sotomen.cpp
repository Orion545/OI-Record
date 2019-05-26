#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<vector>
#define mp make_pair
using namespace std;
const int dx[9]={0,1,1,1,0,0,-1,-1,-1},dy[9]={0,-1,0,1,-1,1,-1,0,1};
inline int read(){
    int re=0,flag=1;char ch=getchar();
    while(ch>'9'||ch<'0'){
        if(ch=='-') flag=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9') re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
    return re*flag;
}
int n,r,c,first[2100010],First[2100010],cnt=0,Cnt=0;
int dfn[2100010],low[2100010],num=0;
int s[500010]={0},top=0;
int belong[2100010],tot=0,dp[500010];
vector<int>qlt[500010];
struct edge{
    int from,to,next;
}a[6000010];
struct Edge{
    int to,next;
}e[6000010];
inline void add(int u,int v){
    a[++cnt]=(edge){u,v,first[u]};first[u]=cnt;
}
inline void Add(int u,int v){
    e[++Cnt]=(Edge){v,First[u]};First[u]=Cnt;
}
map<pair<int,int>,int>m;
void tarjan(int u){
    int i,v;
    dfn[u]=low[u]=++num;
    s[++top]=u;
    for(i=first[u];~i;i=a[i].next){
        v=a[i].to;
        if(!dfn[v]){
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else low[u]=min(low[u],dfn[v]);
    }
    if(low[u]==dfn[u]){
        ++tot;
        while(s[top]!=u){
            belong[s[top]]=tot;
            qlt[tot].push_back(s[top]);
            s[top--]=0;
        }
        belong[s[top]]=tot;
        qlt[tot].push_back(s[top]);
         s[top--]=0;
    }
}
int q[500010],head=0,tail=0;
int main(){
    memset(first,-1,sizeof(first));
    memset(First,-1,sizeof(First))
    int i,t1,t2,t3,t4,t5,j;
    map<pair<int,int>,int>::iterator tmp;
    memset(first,-1,sizeof(first));
    n=read();r=read();c=read();
    for(i=1;i<=n;i++){
        t1=read();t2=read();t3=read();
        m[mp(t1,t2)]=i;
        add(t1,r+c+t3);add(t2+r,t3+r+c);
        if(t3==1) add(r+c+t3,t1);
        if(t3==2) add(r+c+t3,r+t2);
        if(t3==3){
            for(j=1;j<=8;j++){
                t4=t2+dx[j];t5=t3+dx[j];tmp=m.find(mp(t4,t5));
                if(tmp==m.end()) continue;
                else add(r+c+t3,r+c+tmp->second);
            }
        }
    }
    for(i=r+c+1;i<=r+c+n;i++) if(!dfn[i]) tarjan(i);
    for(i=1;i<=cnt;i++){
        if(!belong[a[i].from]||!belong[a[i].to]) continue;
        if(belong[a[i].from]==belong[a[i].to]) continue;
        Add(belong[a[i].from],belong[a[i].to]);in[belong[a[i].to]]++;
    }
    for(i=1;i<=tot;i++) if(!in[i]) q[tail++]=i;
    while(head<tail){

    }
}
