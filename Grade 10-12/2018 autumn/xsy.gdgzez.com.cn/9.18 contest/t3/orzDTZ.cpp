#include <cstdio>
using namespace std;
typedef long long ll;
const int N=200010,M=20010,V=1000010;
int n,m;
int maxa=1000000;
namespace SEG2{/*{{{*/
    const int S=V*2*18;
    int sz,rt[V*2];
    int ch[S][2],sum[S],tag[S];
    inline void pushup(int u){
        sum[u]=sum[ch[u][0]]+sum[ch[u][1]];
    }
    inline void makeTag(int u,int l,int r,int x){
        sum[u]+=(r-l+1)*x;
        tag[u]+=x;
    }
    inline void pushdown(int u,int l,int r){
        if(tag[u]){
            int mid=(l+r)>>1;
            if(!ch[u][0]) 
                ch[u][0]=++sz;
            if(!ch[u][1])
                ch[u][1]=++sz;
            makeTag(ch[u][0],l,mid,tag[u]);
            makeTag(ch[u][1],mid+1,r,tag[u]);
            tag[u]=0;
        }
    }
    void modify(int &u,int l,int r,int L,int R){
        if(!u){
            u=++sz;
            sum[u]=tag[u]=0;
        }
        if(L<=l&&r<=R){
            makeTag(u,l,r,1);
            return;
        }
        pushdown(u,l,r);
        int mid=(l+r)>>1;
        if(R<=mid)
            modify(ch[u][0],l,mid,L,R);
        else if(mid<L)
            modify(ch[u][1],mid+1,r,L,R);
        else{
            modify(ch[u][0],l,mid,L,mid);
            modify(ch[u][1],mid+1,r,mid+1,R);
        }
        pushup(u);
    }
    int query(int &u,int l,int r,int L,int R){
        if(!u)
            return 0;
        if(L<=l&&r<=R)
            return sum[u];
        pushdown(u,l,r);
        int mid=(l+r)>>1;
        if(R<=mid)
            return query(ch[u][0],l,mid,L,R);
        else if(mid<L)
            return query(ch[u][1],mid+1,r,L,R);
        else
            return query(ch[u][0],l,mid,L,mid)+
                   query(ch[u][1],mid+1,r,mid+1,R);
    }
}/*}}}*/
namespace SEG1{/*{{{*/
    const int S=V*2;
    int rt,sz;
    int ch[S][2],val[S];
    int nl,nr;
    ll limit,ans,sum;
    void build(int &u,int l,int r){
        u=++sz;
        if(l==r)
            return;
        int mid=(l+r)>>1;
        build(ch[u][0],l,mid);
        build(ch[u][1],mid+1,r);
    }
    void modify(int u,int l,int r,int pos){
        SEG2::modify(SEG2::rt[u],1,n,nl,nr);
        if(l==r)
            return;
        int mid=(l+r)>>1;
        if(pos<=mid)
            modify(ch[u][0],l,mid,pos);
        else
            modify(ch[u][1],mid+1,r,pos);
    }
    void setCurrent(int _l,int _r){
        nl=_l;
        nr=_r;
    }
    void query(int u,int l,int r){
        ll rsum=SEG2::query(SEG2::rt[ch[u][1]],1,n,nl,nr);
        if(l==r){
            ll cur=SEG2::query(SEG2::rt[u],1,n,nl,nr);
            if(cur<=limit){
                ans=l;
                sum+=cur;
            }
            else
                ans=l+1;
            return;
        }
        int mid=(l+r)>>1;
        if(limit>=rsum){
            limit-=rsum;
            sum+=rsum;
            query(ch[u][0],l,mid);
        }
        else
            query(ch[u][1],mid+1,r);
    }
    void queryD(ll _limit,ll &_ans,ll &_sum){
        limit=_limit;
        ans=sum=0;
        query(rt,1,maxa);
        _ans=ans; _sum=sum;
    }
}/*}}}*/
void readData(){
    scanf("%d%d",&n,&m);
    int useless;
    for(int i=1;i<=n;i++)
        scanf("%d",&useless);
}
void answerQuery(){
    int opt,l,r;
    ll a,ans=0,val;
    for(int i=1;i<=m;i++){
        scanf("%d%d%d%lld",&opt,&l,&r,&a);
        SEG1::setCurrent(l,r);
        if(opt==0){
            a^=ans;
            SEG1::modify(SEG1::rt,1,maxa,a);
        }
        else{
            SEG1::queryD(a,ans,val);
            printf("%lld %lld\n",ans,val);
        }
    }
}
int main(){
    readData();
	cout<<"ckpt\n";
    SEG1::build(SEG1::rt,1,maxa);
    answerQuery();
	printf("%d\n",SEG2::sz);
    return 0;
}
