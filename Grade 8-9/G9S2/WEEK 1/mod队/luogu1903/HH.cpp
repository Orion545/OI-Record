#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
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
int n,m,cnt[1000010],tot=0,x[50010],cur[50010];
int curl,curr,curc,block,ans[200010],cntq,cntc;
struct query{
    int l,r,i,ch;
}a[200010];
struct ch{
    int pos,to,from;
}c[200010];
bool cmp(query l,query r){
    if(l.l/block!=r.l/block) return (l.l/block)<(r.l/block);
    else{
        if(l.r!=r.r) return l.r<r.r;
        else return l.ch<r.ch;
    }
}
void add(int i){
    cnt[x[i]]++;if(cnt[x[i]]==1) tot++;
    //cout<<"add "<<i<<" "<<x[i]<<" "<<cnt[x[i]]<<" "<<tot<<"\n";
}
void erase(int i){
    cnt[x[i]]--;if(!cnt[x[i]]) tot--;
    //cout<<"erase "<<i<<" "<<x[i]<<" "<<cnt[x[i]]<<" "<<tot<<"\n";
}
void change(int l,int r,int i){
    //cout<<"***change "<<l<<" "<<r<<" "<<i<<" "<<x[c[i].pos]<<"\n";
    if(l<=c[i].pos&&c[i].pos<=r) erase(c[i].pos);
    x[c[i].pos]=c[i].to;
    if(l<=c[i].pos&&c[i].pos<=r) add(c[i].pos);
}
void back(int l,int r,int i){
    //cout<<"***back "<<l<<" "<<r<<" "<<i<<"\n";
    if(l<=c[i].pos&&c[i].pos<=r) erase(c[i].pos);
    x[c[i].pos]=c[i].from;
    if(l<=c[i].pos&&c[i].pos<=r) add(c[i].pos);
}
int main(){
    freopen("testdata.in","r",stdin);
    int i,t1,t2;char s[10];
    n=read();m=read();
    for(i=1;i<=n;i++) x[i]=cur[i]=read();
    for(i=1;i<=m;i++){
        scanf("%s",s);t1=read();t2=read();
        if(s[0]=='Q')
            a[++cntq].l=t1,a[cntq].r=t2,a[cntq].i=cntq,a[cntq].ch=cntc;
        else
            c[++cntc].pos=t1,c[cntc].from=cur[t1],cur[t1]=c[cntc].to=t2;
    }
    block=sqrt(n);
    sort(a+1,a+cntq+1,cmp);
    
    curl=a[1].l;curr=a[1].r;
    for(i=a[1].l;i<=a[1].r;i++) add(i);
    while(curc<a[1].ch) change(a[1].l,a[1].r,++curc);
    ans[a[1].i]=tot;

    for(i=2;i<=m;i++){
        while(curl<a[i].l) erase(curl++);
        while(curl>a[i].l) add(--curl);
        while(curr<a[i].r) add(++curr);
        while(curr>a[i].r) erase(curr--);
        while(curc<a[i].ch) change(a[i].l,a[i].r,++curc);
        while(curc>a[i].ch) back(a[i].l,a[i].r,curc--);
        ans[a[i].i]=tot;
        //cout<<"now "<<curl<<" "<<curr<<"\n";
    }
    for(i=1;i<=cntq;i++) printf("%d\n",ans[i]);
}
