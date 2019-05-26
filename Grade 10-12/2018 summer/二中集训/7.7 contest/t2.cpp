#include<iostream>
#include<cstdio>
#include<cstring>
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
int n,m;
int fa[300010],ch[300010][2],w[300010],a[300010];
bool rev[300010],rt[300010];
inline void _swap(int &x,int &y){x^=y;y^=x;x^=y;}
inline void update(int x){a[x]=w[x]+a[ch[x][0]]+a[ch[x][1]];}
inline void reverse(int x){_swap(ch[x][0],ch[x][1]);rev[x]^=1;}
inline void pushdown(int x){
    if(rev[x]){
        if(ch[x][0]) reverse(ch[x][0]);
        if(ch[x][1]) reverse(ch[x][1]);
        rev[x]=0;
    } 
}
inline void push(int x){if(!rt[x]) push(fa[x]);pushdown(x);}
inline bool get(int x){return x==ch[fa[x]][1];}
inline void rotate(int x){
    int f=fa[x],ff=fa[f],son=get(x);
    ch[f][son]=ch[x][son^1];
    if(ch[f][son]) fa[ch[f][son]]=f;
    fa[f]=x;ch[x][son^1]=f;
    fa[x]=ff;
    if(rt[f]) rt[x]=1,rt[f]=0;
    else ch[ff][f==ch[ff][1]]=x;
    update(f);update(x);
}
inline void splay(int x){
//	cout<<"splay "<<x<<endl;
    push(x);
    for(int f;!rt[x];rotate(x)){
//		cout<<x<<ends<<fa[x]<<endl;
        if(!rt[f=fa[x]]) rotate((get(x)==get(f))?f:x); 
    }
        
    update(x);
}
inline void access(int x){
//	cout<<"access "<<x<<endl;
    int y=0;
    do{
        splay(x);
        rt[ch[x][1]]=1;
        rt[ch[x][1]=y]=0;
        x=fa[y=x];
        update(x);
    }while(x);
}
inline void mroot(int x){
    access(x);splay(x);reverse(x);
}
inline bool judge(int x,int y){
    while(fa[x]) x=fa[x];
    while(fa[y]) y=fa[y];
    return x==y;
}
inline void link(int x,int y){
    if(judge(x,y)){
    	puts("no");
    	return;
	}
	puts("yes");
//	cout<<"link "<<x<<ends<<y<<endl;
    mroot(x);fa[x]=y; 
}
inline void cut(int x,int y){
    if(!judge(x,y)) return;
//	cout<<"cut "<<x<<ends<<y<<endl;
    mroot(x);splay(y);
    fa[ch[y][0]]=fa[y];
    rt[ch[y][0]]=1;
    fa[y]=0;ch[y][0]=0;
}
inline void split(int x,int y){
    mroot(x);access(y);splay(y);
}
int main(){
    int i,t2,t3;char t1[20];
    n=read();
    for(i=1;i<=n;i++) w[i]=read(),a[i]=w[i],rt[i]=1;
	m=read();
//	for(i=1;i<=n;i++) cout<<i<<ends<<w[i]<<endl;
    for(i=1;i<=m;i++){
        scanf("%s",t1);t2=read();t3=read();
        if(t1[0]=='e'){
        	if(!judge(t2,t3)) puts("impossible");
            else split(t2,t3),printf("%d\n",a[t3]);
        }
        if(t1[0]=='b') link(t2,t3);
        if(t1[0]=='p'){
            access(t2);splay(t2);w[t2]=t3;update(t2);
        }
    }
//	system("pause");
}
