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

const int N=100100;
const long long INF=50000000000LL;

int n,m;
char ty[10];
int p[N];
struct edge
{
    int v;
    edge *next;
}pool[N*2],*head[N],*tp=pool;
long long f[N][2];
int a,b,ax,by;

void addedge(int u,int v)
{
    *tp=(edge){v,head[u]},head[u]=tp++;
    *tp=(edge){u,head[v]},head[v]=tp++;
}

void init()
{
    n=getint(),m=getint();
    scanf("%s",ty);
    for(int i=1; i<=n; i++) p[i]=getint();
    for(int i=1; i<n; i++){
        int u=getint(),v=getint();
        addedge(u,v);
    }
}

void dfs(int x,int fa)
{
    /*
    long long tmp0=0;
    long long negsum=0,mn2=INF;
    f[x][0]=f[x][1]=INF;
    f[x][2]=p[x];
    for(edge *i=head[x]; i; i=i->next){
        if(i->v==fa) continue;
        dfs(i->v,x);
        tmp0+=f[i->v][1];
        if(f[i->v][2]<f[i->v][1]){
            negsum+=f[i->v][2]-f[i->v][1];
        }
        mn2=min(mn2,f[i->v][2]-f[i->v][1]);
        f[x][2]+=min(f[i->v][0],min(f[i->v][1],f[i->v][2]));
    }
    f[x][0]=min(f[x][0],tmp0);
    if(negsum<0){
        f[x][1]=tmp0+negsum;
    }else{
        f[x][1]=f[x][0]+mn2;
    }
    if(x==a){
        if(ax){
            f[x][0]=f[x][1]=INF;
        }else{
            f[x][2]=INF;
        }
    }else if(x==b){
        if(by){
            f[x][0]=f[x][1]=INF;
        }else{
            f[x][2]=INF;
        }
    }
    */
    f[x][0]=INF;
    f[x][1]=p[x];
    long long tmp0=0;
    for(edge *i=head[x]; i; i=i->next){
        if(i->v==fa) continue;
        dfs(i->v,x);
        f[x][1]+=min(f[i->v][0],f[i->v][1]);
        tmp0+=f[i->v][1];
    }
    f[x][0]=min(f[x][0],tmp0);
    if(x==a){
        f[x][!ax]=INF;
    }else if(x==b){
        f[x][!by]=INF;
    }
}

int main()
{
    freopen("defense.in","r",stdin);
    freopen("defense.out","w",stdout);
    init();
    //dfs(1,1);
    //printf("%I64d\n",min(f[1][1],f[1][2]));
    while(m--){
        a=getint(),ax=getint();
        b=getint(),by=getint();
        dfs(1,1);
        long long ans=min(f[1][0],f[1][1]);
        if(ans>=INF){
            puts("-1");
        }else{
            printf("%lld\n",ans);
        }
    }
    return 0;
}
