#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
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
int n,m,cnt,first[300010],val[300010],in[300010],inn[300010];
int dp[300010][30];
struct edge{
    int to,next;
}a[300010];
inline void add(int u,int v){
    a[++cnt]=(edge){v,first[u]};first[u]=cnt;
}
char s[300010];int q[300010],head=0,tail=0;
int _max(int l,int r){return (l>r)?l:r;}
int main(){
    //freopen("D.in","r",stdin);
    memset(first,-1,sizeof(first));
    int i,t1,t2,j,num=0,u,v;
    n=read();m=read();
    scanf("%s",s);
    for(i=1;i<=n;i++) val[i]=(s[i-1]-'a')+1;
    for(i=1;i<=m;i++){
        //cout<<"edge "<<i<<"\n";
        t1=read();t2=read();
        in[t2]++;inn[t2]++;
        add(t1,t2);
    }
    //cout<<"finish read in\n";
    for(i=1;i<=n;i++) if(!in[i]) q[tail++]=i;
    while(head<tail){
        u=q[head++];num++;
        for(i=first[u];~i;i=a[i].next){
            v=a[i].to;
            in[v]--;
            if(!in[v]) q[tail++]=v;
        }
    }
    if(num<n){
        printf("-1");return 0;
    }
    memset(q,0,sizeof(q));head=0,tail=0;int ans=1;
    for(i=1;i<=n;i++) if(!inn[i]) q[tail++]=i,ans=max(ans,++dp[i][val[i]]);
    while(head<tail){
        u=q[head++];
        for(i=first[u];~i;i=a[i].next){
            v=a[i].to;
            inn[v]--;
            for(j=1;j<=26;j++)
                dp[v][j]=_max(dp[v][j],dp[u][j]+(j==val[v]));
            //dp[v][val[v]]=_max(dp[v][val[v]],dp[u][val[v]]+1);
            ans=_max(ans,dp[v][val[v]]);
            if(!inn[v]) q[tail++]=v;
        }
    }
    printf("%d",ans);
}
