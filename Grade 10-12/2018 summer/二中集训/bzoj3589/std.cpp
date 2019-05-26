#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
const int N=2*(1e5)+10,TOP=20;
struct xxx{
    int y,nxt;
}a[N*2];
struct L{
    int x,y;
    L(){}
    L(int _x,int _y){x=_x; y=_y;}
}rec[6],tmp;
int h[N],lis[N*2],st[N],dep[N],pre[N];
int mn[N*2][TOP+1];
int dfn[N],dfned[N];
int n,m,tot,dfn_t,dfn_t1;
namespace BIT{/*{{{*/
    int c[N*2],rt[2];
    int n;
    void init(int _n){n=_n;rt[0]=0; rt[1]=n;}
    void _add(int St,int x,int delta){
        for (;x<=n;x+=x&-x) c[St+x]+=delta;
    }
    void add(int which,int x,int delta){_add(rt[which],dfn[x],delta);_add(rt[which],dfned[x]+1,-delta);}
    int _query(int St,int x){
        int ret=0;
        for (;x;x-=x&-x) ret+=c[St+x];
        return ret;
    }
    int query(int x){
        if (!x) return 0;
        return _query(rt[1],dfn[x])*dep[x]-_query(rt[0],dfn[x]);
    }
}/*}}}*/
void add(int x,int y){a[++tot].y=y; a[tot].nxt=h[x]; h[x]=tot;}
void dfs(int fa,int x,int d){
    int u;
    st[x]=++dfn_t; lis[dfn_t]=x; dep[x]=d; pre[x]=fa;
    dfn[x]=++dfn_t1;
    for (int i=h[x];i!=-1;i=a[i].nxt){
        u=a[i].y;
        if (u==fa) continue;
        dfs(x,u,d+1);
        lis[++dfn_t]=x;
    }
    dfned[x]=dfn_t1;
}
void prework(){
    BIT::init(n);
    lis[0]=dfn_t;
    for (int i=1;i<=lis[0];++i) mn[i][0]=lis[i];
    for (int j=1;j<=TOP;++j)
        for (int i=lis[0]-(1<<j)+1;i>=1;--i)
            if (dep[mn[i][j-1]]<dep[mn[i+(1<<j-1)][j-1]])
                mn[i][j]=mn[i][j-1];
            else 
                mn[i][j]=mn[i+(1<<j-1)][j-1];
}
int get_lca(int x,int y){
//	cout<<"	get_lca "<<x<<' '<<y<<' '<<st[x]<<' '<<st[y]<<' ';
    x=st[x]; y=st[y];
    if (x>y) swap(x,y);
    int len=y-x+1,lg=(int)(log(1.0*len)/log(2.0));
//    cout<<lg<<' '<<mn[x][lg]<<' '<<mn[y-(1<<lg)+1][lg]<<' '<<dep[mn[x][lg]]<<' '<<dep[mn[y-(1<<lg)+1][lg]]<<'\n';
    if (dep[mn[x][lg]]<dep[mn[y-(1<<lg)+1][lg]]) return mn[x][lg];
    else return mn[y-(1<<lg)+1][lg];
}
void merge(L &x,L y){
    if (x.x==0&&x.y==0) return;
    int lca;
    if (dep[x.x]<dep[y.x]){
        lca=get_lca(x.y,y.x);
        if (lca!=y.x){x=L(0,0); return;}
        lca=get_lca(x.y,y.y);
        x=L(y.x,lca);
    }
    else{
        lca=get_lca(y.y,x.x);
        if (lca!=x.x){x=L(0,0); return;}
        lca=get_lca(y.y,x.y);
        x=L(x.x,lca);
    }
}
int get_val(L x){
    return BIT::query(x.y)-BIT::query(pre[x.x]);
}
void solve(int num){
    int all=1<<num,mark,ans=0;
    for (int i=1;i<all;++i){
        mark=-1;
        tmp=L(-1,-1);
        for (int j=1;j<=num;++j)
            if (i>>(j-1)&1){
                mark*=-1;
                if (tmp.x==-1&&tmp.y==-1) 
                    tmp.x=rec[j].x,tmp.y=rec[j].y;
                else
                    merge(tmp,rec[j]);
            }
        ans+=mark*get_val(tmp);
//        cout<<"solving "<<i<<' '<<tmp.x<<' '<<tmp.y<<' '<<ans<<'\n';
    }
    printf("%d\n",ans&2147483647);
}
void debug(){
    for (int i=1;i<=n;++i) printf("%d ",BIT::query(i));
    printf("\n");
}

int main(){
	freopen("8.in","r",stdin);
	freopen("std.out","w",stdout);
    int x,y,delta,num,op;
    scanf("%d",&n);
    memset(h,-1,sizeof(h));
    tot=0;
    for (int i=1;i<n;++i){
        scanf("%d%d",&x,&y);
        add(x,y); add(y,x);
    }
    dfn_t=0; dfn_t1=0;
    dfs(0,1,1);
    prework();
    scanf("%d",&m);
    for (int i=1;i<=m;++i){
        scanf("%d",&op);
        if (op==0){
            scanf("%d%d",&x,&delta);
            BIT::add(0,x,(dep[x]-1)*delta);
            BIT::add(1,x,delta);
        }
        else{
            scanf("%d",&num);
            for (int j=1;j<=num;++j){
                scanf("%d%d",&rec[j].x,&rec[j].y);
                if (dep[rec[j].x]>dep[rec[j].y]) swap(rec[j].x,rec[j].y);
            }
            solve(num);
        }
        //debug();
    }
}
