#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define inf 0x7fffffff
using namespace std;
int n,m;
int fa[10010],ch[10010][2];
bool rt[10010],rev[10010];
inline void _swap(int &x,int &y){x^=y;y^=x;x^=y;}
inline void pushrev(int x){
    if(!x) return;
    swap(ch[x][0],ch[x][1]);
    rev[x]^=1;
}
inline void pushdown(int x){
    if(rev[x]){
        pushrev(ch[x][0]);
        pushrev(ch[x][1]);
        rev[x]=0;
    }
}
void push(int x){
//	cout<<"push "<<x<<endl;
    if(!rt[x]) push(fa[x]);
    pushdown(x);
}
inline int get(int x){
    return x==ch[fa[x]][1];
}
inline void rotate(int x){
    if(rt[x]) return;
    int f=fa[x],ff=fa[f],son=get(x);
    ch[f][son]=ch[x][son^1];
    if(ch[f][son]) fa[ch[f][son]]=f;
    ch[x][son^1]=f;
    fa[f]=x;
    fa[x]=ff;
    if(!rt[f]) ch[ff][ch[ff][1]==f]=x;
    else rt[x]=1,rt[f]=0;
}
inline void splay(int x){
    push(x);
//	cout<<"splay "<<x<<endl;
    for(int f;!rt[x];rotate(x)){
//		cout<<x<<ends<<fa[x]<<endl;
        if(!rt[f=fa[x]]) 
            rotate((get(x)==get(f))?f:x);
    }
        
}
inline void access(int x){
//	cout<<"access "<<x<<endl;
    int y=0;
    do{
        splay(x);
        rt[ch[x][1]]=1;
        rt[ch[x][1]=y]=0;
        x=fa[y=x];
    }while(x);
}
inline bool judge(int u,int v){
    while(fa[u]) u=fa[u];
    while(fa[v]) v=fa[v];
//	cout<<"judge "<<u<<ends<<v<<endl;
    return u==v;
}
inline void mroot(int x){
    access(x);splay(x);pushrev(x);
}
inline void link(int u,int v){
//	cout<<"link "<<u<<ends<<v<<endl;
    mroot(u);fa[u]=v;
}
inline void cut(int u,int v){
    mroot(u);splay(v);
    fa[ch[v][0]]=fa[v];
    rt[ch[v][0]]=1;
    fa[v]=0;ch[v][0]=0;
}
int main(){
    int i,t1,t2;char s[10];
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++) rt[i]=1;
    for(i=1;i<=m;i++){
        scanf("%s%d%d",&s,&t1,&t2);
        if(s[0]=='Q') printf("%s\n",(judge(t1,t2)?"Yes":"No"));
        if(s[0]=='C') link(t1,t2);
        if(s[0]=='D') cut(t1,t2);
    }
//	system("pause");
}
