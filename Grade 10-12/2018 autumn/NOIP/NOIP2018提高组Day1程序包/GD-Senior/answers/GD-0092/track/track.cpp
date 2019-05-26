#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>

using namespace std;

int getint()
{
	char ch=getchar();
	int f=1,x=0;
	while(!isdigit(ch)){if(ch=='-') f=-1; ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0'; ch=getchar();}
	return f*x;
}

const int N=50500;

int n,m;
//int deg[N];
bool flg1,flg2;
struct edge
{
    int v,w;
    edge *next;
}pool[N*2],*head[N],*tp=pool;

void addedge(int u,int v,int w)
{
    *tp=(edge){v,w,head[u]},head[u]=tp++;
    *tp=(edge){u,w,head[v]},head[v]=tp++;
}

void init()
{
    n=getint(),m=getint();
    flg1=flg2=true;
    for(int i=1; i<n; i++){
        int a=getint(),b=getint(),l=getint();
        addedge(a,b,l);
        //deg[a]++,deg[b]++;
        if(a!=1) flg1=false;
        if(a+1!=b) flg2=false;
    }
}

namespace diamtr
{
    int dis[N];
    
    void dfs(int x,int fa)
    {
        for(edge *i=head[x]; i; i=i->next){
            if(i->v==fa) continue;
            dis[i->v]=dis[x]+i->w;
            dfs(i->v,x);
        }
    }
    
    void work()
    {
        dfs(1,1);
        int mx=0,mxp=1;
        for(int i=2; i<=n; i++){
            if(dis[i]>mx){
                mx=dis[i];
                mxp=i;
            }
        }
        dis[mxp]=0;
        dfs(mxp,mxp);
        mx=0;
        for(int i=1; i<=n; i++){
            mx=max(mx,dis[i]);
        }
        printf("%d\n",mx);
    }
}

namespace ln2
{
    int val[N];
    
    bool chk(int thr)
    {
        int tmp=0,cnt=0;
        for(int i=1; i<n; i++){
            tmp+=val[i];
            if(tmp>=thr){
                cnt++;
                if(cnt>=m) return true;
                tmp=0;
            }
        }
        return false;
    }
    
    void work()
    {
        for(int i=1; i<n; i++){
            for(edge *j=head[i]; j; j=j->next){
                if(j->v==i+1){
                    val[i]=j->w;
                    break;
                }
            }
        }
        int lft=0x3f3f3f3f,rght=0;
        for(int i=1; i<n; i++){
            lft=min(lft,val[i]);
            rght+=val[i];
        }
        int ans=lft;
        while(lft<=rght){
            int mid=(lft+rght)>>1;
            if(chk(mid)){
                ans=mid;
                lft=mid+1;
            }else{
                rght=mid-1;
            }
        }
        printf("%d\n",ans);
    }
}

namespace str2
{
    int val[N];
    
    bool chk(int thr)
    {
        int tot=n-1;
        int cnt=0;
        while(val[tot]>=thr){
            cnt++;
            tot--;
        }
        if(cnt>=m) return true;
        for(int i=1; i<tot; i++){
            if(val[i]+val[tot]>=thr){
                tot--;
                cnt++;
                if(cnt>=m) return true;
            }
        }
        return false;
    }
    
    void work()
    {
        for(edge *i=head[1]; i; i=i->next){
            val[i->v-1]=i->w;
        }
        sort(val+1,val+n);
        int lft=val[1];
        int rght=val[n-1]*2;
        int ans=lft;
        while(lft<=rght){
            int mid=(lft+rght)>>1;
            if(chk(mid)){
                ans=mid;
                lft=mid+1;
            }else{
                rght=mid-1;
            }
        }
        printf("%d\n",ans);
    }
}

namespace fck
{
    int cnt[N],len[N];
    
    void dfs(int x,int fa,int thr)
    {
        int deg=0;
        for(edge *i=head[x]; i; i=i->next){
            if(i->v==fa) continue;
            deg++;
            dfs(i->v,x,thr);
            cnt[x]+=cnt[i->v];
        }
        if(deg==1){
            for(edge *i=head[x]; i; i=i->next){
                if(i->v==fa) continue;
                if(len[i->v]+i->w>=thr){
                    cnt[x]++;
                }else{
                    len[x]=len[i->v]+i->w;
                }
            }
        }
    }
    
    void work()
    {
        int lft=0x3f3f3f3f,rght=0;
        for(int i=1; i<=n; i++){
            for(edge *j=head[i]; j; j=j->next){
                lft=min(lft,j->w);
                rght+=j->w;
            }
        }
        rght>>=1;
        int ans=lft;
        while(lft<=rght){
            int mid=(lft+rght)>>1;
            memset(cnt,0,sizeof(cnt));
            memset(len,0,sizeof(len));
            dfs(1,1,mid);
            if(cnt[1]>=m){
                ans=mid;
                lft=mid+1;
            }else{
                rght=mid-1;
            }
        }
        printf("%d\n",ans);
    }
}

int main()
{
    freopen("track.in","r",stdin);
    freopen("track.out","w",stdout);
    init();
    if(m==1){
        diamtr::work();
    }else if(flg2){
        ln2::work();
    }else if(flg1){
        str2::work();
    }else{
        fck::work();
    }
    return 0;
}
