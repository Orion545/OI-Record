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
int n,m,cnt[1000010],tot=0,x[50010],curl,curr,block,ans[200010];
struct query{
    int l,r,i;
}a[200010];
bool cmp(query l,query r){
    if(l.l/block!=r.l/block) return (l.l/block)<(r.l/block);
    else return l.r<r.r;
}
void add(int i){
    cnt[x[i]]++;if(cnt[x[i]]==1) tot++;
    //cout<<"add "<<i<<" "<<x[i]<<" "<<cnt[x[i]]<<"\n";
}
void erase(int i){
    cnt[x[i]]--;if(!cnt[x[i]]) tot--;
    //cout<<"erase "<<i<<" "<<x[i]<<" "<<cnt[x[i]]<<"\n";
}
int main(){
    //freopen("diff.in","r",stdin);
    //freopen("diff.out","w",stdout);
    int i;
    n=read();for(i=1;i<=n;i++) x[i]=read();block=sqrt(n);
    //cout<<"input one complete "<<n<<" "<<i<<"\n";
    m=read();for(i=1;i<=m;i++) a[i].l=read(),a[i].r=read(),a[i].i=i;
    //cout<<"input two complete "<<m<<" "<<i<<"\n";
    sort(a+1,a+m+1,cmp);curl=a[1].l;curr=a[1].r;
    for(i=a[1].l;i<=a[1].r;i++) add(i);
    ans[a[1].i]=tot;
    for(i=2;i<=m;i++){
        while(curl<a[i].l) erase(curl++);
        while(curl>a[i].l) add(--curl);
        while(curr<a[i].r) add(++curr);
        while(curr>a[i].r) erase(curr--);
        ans[a[i].i]=tot;
        //cout<<"now "<<curl<<" "<<curr<<"\n";
    }
    for(i=1;i<=m;i++) printf("%d\n",ans[i]);
}
