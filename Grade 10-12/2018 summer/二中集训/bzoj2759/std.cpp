#include <cstdio>
#include <iostream>
#define plu(x,y) (((x)+(y))%MOD)
#define mul(x,y) (1LL*(x)*(y)%MOD)
using namespace std;
const int N=30005,MOD=10007;
int n,a[N],vis[N],tm;
int inv[MOD];
bool flag;
struct Data{
    int k,b;
    Data(){}
    Data(int _k,int _b){k=_k;b=_b;}
    int solve(){
        if(k==1){flag=true;return b==0?-2:-1;}
        flag=false;
        return mul(-b,inv[plu(k-1,MOD)]);   
    }
}one=Data(1,0),b[N];
namespace LCT{/*{{{*/
    int rt,ch[N][2],fa[N],x,t[N][2];
    Data s[N][2];
    int pfa[N];
    inline bool isRoot(int u){return ch[fa[u]][0]!=u&&ch[fa[u]][1]!=u;}
    inline int who(int u){return ch[fa[u]][1]==u;}
    Data merge(Data u,Data v){//v(u(x))
        return Data(mul(v.k,u.k),plu(mul(v.k,u.b),v.b));
    }
    void pushup(int u){
        t[u][0]=ch[u][0]?t[ch[u][0]][0]:u;
        t[u][1]=ch[u][1]?t[ch[u][1]][1]:u;
        s[u][0]=ch[u][0]?s[ch[u][0]][0]:one;
        s[u][1]=ch[u][0]?merge(s[ch[u][0]][1],b[u]):one;
        if(ch[u][1]){
            s[u][1]=merge(s[u][1],b[t[ch[u][1]][0]]);   
            s[u][1]=merge(s[u][1],s[ch[u][1]][1]);
        }
    }
    void rotate(int u){
        int f=fa[u],g=fa[f],c=who(u);
        if(!isRoot(f)) ch[g][who(f)]=u;
        fa[u]=g;
        ch[f][c]=ch[u][c^1];
        if(ch[f][c]) fa[ch[f][c]]=f;
        ch[u][c^1]=f; fa[f]=u;
        pushup(f); pushup(u);
    }
    void splay(int u){
        for(;!isRoot(u);rotate(u))
            if(!isRoot(fa[u]))
                rotate(who(u)==who(fa[u])?fa[u]:u);
    }
    void access(int u){
        for(int v=0;u;v=u,u=fa[u]){
            splay(u);
            ch[u][1]=v;
            pushup(u);
        }
    }
    void cutfa(int a){
        access(a);
        splay(a);
        int f=t[ch[a][0]][1];
        splay(f);
        ch[f][1]=0;
        fa[a]=0;
        pushup(f);
    }
    void linkfa(int a,int f){
        access(a);
        splay(a);
        fa[a]=f;        
    }
    int getRt(int u){
        access(u);
        splay(u);
        return t[u][0];
    }
}/*}}}*/
int getRt(int u){
    for(;!vis[u];u=a[u]) vis[u]=tm;
    return vis[u]==tm?u:0;
}
int solve(int rt){
    int pfa=LCT::pfa[rt];
    LCT::access(pfa);
    LCT::splay(pfa);
    Data tmp=LCT::s[pfa][1];
//    cout<<"now "<<tmp.k<<' '<<tmp.b<<'\n';
    tmp=LCT::merge(tmp,b[rt]);
    int res=tmp.solve();
    return flag?res:plu(res,MOD);
}
int main(){
    inv[0]=inv[1]=1;    
    for(int i=2;i<MOD;i++) inv[i]=mul(-(MOD/i),inv[MOD%i]);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d%d",&b[i].k,&a[i],&b[i].b);
        LCT::fa[i]=a[i];
        LCT::s[i][0]=LCT::s[i][1]=Data(1,0);
    }
    int rt;
    for(int i=1;i<=n;i++)
        if(!vis[i]){
            tm++;
            rt=getRt(i);
            if(!rt) continue;
            LCT::fa[rt]=0; LCT::pfa[rt]=a[rt];
        }
    char str[10];
    int m,a,x,y,z;
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
        scanf("%s",str);
//    	for(int j=1;j<=n;j++) cout<<j<<' '<<LCT::fa[j]<<' '<<LCT::pfa[j]<<' '<<LCT::ch[j][0]<<' '<<LCT::ch[j][1]<<' '<<LCT::s[j][1].k<<' '<<LCT::s[j][1].b<<'\n';
        if(str[0]=='A'){/*{{{*/
            scanf("%d",&a);
            rt=LCT::getRt(a);
//            cout<<"query "<<a<<' '<<rt<<' '<<LCT::pfa[rt]<<'\n';
            int x=solve(rt);
            if(x<0) printf("%d\n",x);
            else{
                LCT::access(a);                 
                LCT::splay(a);      
                int ans=plu(mul(LCT::s[a][1].k,x),LCT::s[a][1].b);
                printf("%d\n",plu(ans,MOD));
            }
        }/*}}}*/
        else{/*{{{*/
            scanf("%d%d%d%d",&a,&x,&z,&y);
            rt=LCT::getRt(a);
            int zrt=LCT::getRt(z);
            int pfa=LCT::pfa[rt];
            LCT::splay(a);
            b[a]=Data(x,y);
            LCT::pushup(a);
            LCT::access(a);
            LCT::splay(a);
            if(!LCT::ch[a][0]){
                if(zrt==rt)
                    LCT::pfa[a]=z;
                else{
                    LCT::linkfa(a,z);
                    LCT::pfa[a]=0;
                }
            }
            else{
                LCT::access(pfa);
                LCT::splay(rt);
                LCT::splay(a);
                if(LCT::fa[rt]){//on the circle
                    LCT::cutfa(a);
                    LCT::linkfa(rt,LCT::pfa[rt]);
                    LCT::pfa[rt]=0;
                    //LCT::fa[a]=0;
                    if(zrt==rt)
                        LCT::pfa[a]=z;
                    else LCT::linkfa(a,z);
                }
                else{//not on circle
                    LCT::cutfa(a);  
                    zrt=LCT::getRt(z);
                    if(zrt==a)
                        LCT::pfa[a]=z;
                    else
                        LCT::linkfa(a,z);
                }
            }
        }/*}}}*/
    }
    return 0;
}
