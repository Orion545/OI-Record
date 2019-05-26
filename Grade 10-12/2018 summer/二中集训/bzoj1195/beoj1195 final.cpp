#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
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
int n,son[1010][26],sta[1010],fail[1010],cnt;
void insert(char s[],int num){
    int i,len=strlen(s),cur=0,tmp;
    for(i=0;i<len;i++){
        tmp=s[i]-'A';
        if(!son[cur][tmp]) son[cur][tmp]=++cnt;
        cur=son[cur][tmp];
    }
    sta[cur]|=(1<<(num-1));
}
void AC(){
    int q[1010],head=0,tail=0,i,u,v;
    for(i=0;i<26;i++){
        if(!son[0][i]) continue;
        q[tail++]=son[0][i];fail[son[0][i]]=0;
    }
    while(head<tail){
        u=q[head++];
        for(i=0;i<26;i++){
            v=son[u][i];
            if(!v) son[u][i]=son[fail[u]][i];
            else fail[v]=son[fail[u]][i],q[tail++]=v;
        }
        v=fail[u];
        while(v&&!sta[v]) v=fail[v];
        sta[u]|=sta[v];
    }
}
int qp[1000010],qs[1000010],qf[1000010],head,tail,maxq=1000000,vis[1010][10010],fa[5000010],a[5000010];
void print(int u){
    if(!u) return;
    print(fa[u]);putchar(a[u]+'A');
}
void bfs(){
    int i,u,v,pre,cur,num,cnts=0;
    tail=1;qp[0]=qs[0]=qf[0]=0;vis[0][0]=0;
    while(head!=tail){
        u=qp[head];pre=qs[head];num=qf[head];head=(head+1)%maxq;
        if(pre==(1<<n)-1){
            print(num);return;
        }
        for(i=0;i<26;i++){
            v=son[u][i];cur=pre|sta[v];
            if(vis[v][cur]) continue;
            vis[v][cur]=1;
            fa[++cnts]=num;a[cnts]=i;
            qp[tail]=v;qs[tail]=cur;qf[tail]=cnts;tail=(tail+1)%maxq;
        }
    }
}
char s[110];
int main(){
//	freopen("1.in","r",stdin);
    n=read();int i;
    for(i=1;i<=n;i++) scanf("%s",s),insert(s,i);
    AC();
    bfs();
}
