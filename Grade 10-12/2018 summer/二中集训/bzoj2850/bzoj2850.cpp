#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define lld long long
using namespace std;
inline lld read(){
    lld re=0,flag=1;char ch=getchar();
    while(ch>'9'||ch<'0'){
        if(ch=='-') flag=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9') re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
    return re*flag;
}
lld n,m,cnt=0,L,A,B,C;
struct node{
    lld ll,lr,rl,rr,vall,valr,sum,lc,rc,val;
}x[200010],a[200010];
inline bool operator <(const node p,const node o){
    if(L) return p.vall<o.vall;
    else return p.valr<o.valr;
}
bool AC(lld x,lld y){
//	cout<<"		AC "<<x<<' '<<y<<' '<<(A*x+B*y)<<' '<<C<<'\n';
    return (A*x+B*y)<C;
}
lld check(lld pos){
    lld re=0;
    re+=AC(a[pos].ll,a[pos].rl);
    re+=AC(a[pos].ll,a[pos].rr);
    re+=AC(a[pos].lr,a[pos].rl);
    re+=AC(a[pos].lr,a[pos].rr);
//    cout<<"check "<<pos<<' '<<re<<'\n';
    return re;
}
void update(lld pos){
    a[pos].ll=a[pos].lr=a[pos].vall;
    if(a[pos].lc) a[pos].ll=min(a[pos].ll,a[a[pos].lc].ll);
    if(a[pos].rc) a[pos].ll=min(a[pos].ll,a[a[pos].rc].ll);
    if(a[pos].lc) a[pos].lr=max(a[pos].lr,a[a[pos].lc].lr);
    if(a[pos].rc) a[pos].lr=max(a[pos].lr,a[a[pos].rc].lr);
    a[pos].rl=a[pos].rr=a[pos].valr;
    if(a[pos].lc) a[pos].rl=min(a[pos].rl,a[a[pos].lc].rl);
    if(a[pos].rc) a[pos].rl=min(a[pos].rl,a[a[pos].rc].rl);
    if(a[pos].lc) a[pos].rr=max(a[pos].rr,a[a[pos].lc].rr);
    if(a[pos].rc) a[pos].rr=max(a[pos].rr,a[a[pos].rc].rr);
    a[pos].sum=a[a[pos].lc].sum+a[a[pos].rc].sum+a[pos].val;
}
lld build(lld l,lld r,lld now){
//	cout<<"build "<<l<<' '<<r<<' '<<now<<'\n';
    lld mid=(l+r)>>1;L=now;
    nth_element(x+l,x+mid,x+r+1);
    a[mid]=x[mid];
    if(mid>l) a[mid].lc=build(l,mid-1,now^1);
    if(mid<r) a[mid].rc=build(mid+1,r,now^1);
    update(mid);
    return mid;
}
lld query(lld pos){
    lld val=check(pos),re=a[pos].val*AC(a[pos].vall,a[pos].valr);
    if(val==4) return (re=a[pos].sum);
    if(val==0) return re;
    if(a[pos].lc) re+=query(a[pos].lc);
    if(a[pos].rc) re+=query(a[pos].rc);
    return re;
}
int main(){
    n=read();m=read();lld i;
    for(i=1;i<=n;i++){
        x[i].vall=read();x[i].valr=read();x[i].val=read();
    }
    lld root=build(1,n,0);
    for(i=1;i<=m;i++){
    	A=read();B=read();C=read();
    	printf("%lld\n",query(root));
	}
}
/*
3 3
1 2 5
3 1 4
2 2 1
2 1 6
1 3 5
1 3 7

*/
