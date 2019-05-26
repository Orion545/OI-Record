#pragma GCC optimize (3)
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<queue>
#include<cmath>
#define mymax(A,B) (A>B?A:B)
using namespace std;
namespace IO
{
    const int __S=(1<<20)+5;char __buf[__S],*__H,*__T;
    inline char getc()
    {
        if(__H==__T) __T=(__H=__buf)+fread(__buf,1,__S,stdin);
        if(__H==__T) return -1;
        return *__H++;
    }
    template <class __I>inline void read(__I &__x)
    {
        __x=0;char __c=getc();
        while(!isdigit(__c)) __c=getc();
        while(isdigit(__c)) __x=__x*10+__c-'0',__c=getc();
    }
    inline void reads(char *__s,int __x)
    {
        char __c=getc();int __tot=__x-1;
        while(__c<'A'||__c>'Z') __c=getc();
        while(__c>='A'&&__c<='Z') __s[++__tot]=__c,__c=getc();
        __s[++__tot]='\0';
    }
    char __obuf[__S],*__oS=__obuf,*__oT=__oS+__S-1,__c,__qu[55];int __qr;
    inline void flush(){fwrite(__obuf,1,__oS-__obuf,stdout);__oS=__obuf;}
    inline void putc(char __x){*__oS++ =__x;if(__oS==__oT) flush();}
    template <class __I>inline void print(__I __x)
    {
        if(!__x) putc('0');
        while(__x) __qu[++__qr]=__x%10+'0',__x/=10;
        while(__qr) putc(__qu[__qr--]);
    }
    inline void el(){putc('\n');}inline void sp(){putc(' ');}
}using namespace IO;
 
int s[20000010],ls=0,rs=0;
namespace ctrl{
    int cnt=0;
    inline int get(){
        int re;
        if(ls^rs){
            re=s[ls];
            ls++;if(ls==20000000) ls=0;
        }
        else re=(++cnt);
        return re;
    }
    inline void rec(int x){
        s[rs++]=x;
        if(rs==20000000) rs=0;
    }
}
int st[150010],sttop;
namespace seg{
    int ch[20000010][2],sum[20000010];
    inline void insert(int &cur,int l,int r,int pos,int val){
        if(!cur){
            cur=ctrl::get();
            ch[cur][0]=ch[cur][1]=0;
        }
        if(l==r){sum[cur]+=val;return;}
        int mid=(l+r)>>1;
        if(mid>=pos) insert(ch[cur][0],l,mid,pos,val);
        else insert(ch[cur][1],mid+1,r,pos,val);
        sum[cur]=sum[ch[cur][0]]+sum[ch[cur][1]];
    }
    int s[10010],ss[10010],stop,sstop;
    inline int query(int l,int r,int k){
        if(l==r) return l;
        int mid=(l+r)>>1,re=0,i;
        for(i=0;i<stop;i++){
            re+=sum[ch[s[i]][0]];
//          cout<<"query "<<l<<' '<<r<<' '<<k<<' '<<' '<<s[i]<<' '<<sum[ch[s[i]][0]]<<'\n';
        }
        for(i=0;i<sstop;i++){
            re+=(ss[i]>=l&&ss[i]<=mid);
//          cout<<"query "<<l<<' '<<r<<' '<<k<<' '<<' '<<ss[i]<<' '<<mid<<'\n';
        }
        if(re>=k){
            for(i=0;i<stop;i++) s[i]=ch[s[i]][0];
            return query(l,mid,k);
        }
        else{
            for(i=0;i<stop;i++) s[i]=ch[s[i]][1];
            return query(mid+1,r,k-re);
        }
    }
    inline void dump(int cur){
        if(!cur) return;
        dump(ch[cur][0]);dump(ch[cur][1]);
        ch[cur][0]=ch[cur][1]=sum[cur]=0;ctrl::rec(cur);
    }
}
int root,unb;
double alpha=0.82;
namespace scp{
    int ch[150010][2],siz[150010],rt[150010],v[150010],cnt;
    inline void update(int cur){
        siz[cur]=siz[ch[cur][0]]+siz[ch[cur][1]]+1;
    }
    inline void dfs(int u){
        if(!u) return;
        seg::dump(rt[u]);
        dfs(ch[u][0]);
        st[sttop++]=u;
        dfs(ch[u][1]);
    }
    inline void build(int l,int r,int &cur){
        if(l>r) return;
        int mid=(l+r)>>1;
        cur=st[mid];
        ch[cur][0]=ch[cur][1]=0;siz[cur]=1;rt[cur]=0;
        build(l,mid-1,ch[cur][0]);build(mid+1,r,ch[cur][1]);
        update(cur);
        for(int i=l;i<=r;i++)
            seg::insert(rt[cur],0,70000,v[st[i]],1);
    }
    inline void rebuild(int &cur){
        sttop=0;dfs(cur);
        build(0,sttop-1,cur);
    }
    inline void insert(int &cur,int rk,int val){
//      cout<<"insert "<<cur<<' '<<rk<<' '<<val<<' '<<siz[cur]<<' '<<siz[ch[cur][0]]<<' '<<siz[ch[cur][1]]<<'\n';
        if(!cur){
            cur=++cnt;
            ch[cur][0]=ch[cur][1]=0;siz[cur]=1;v[cur]=val;rt[cur]=0;
            seg::insert(rt[cur],0,70000,val,1);return;
        }
        seg::insert(rt[cur],0,70000,val,1);
        int L=siz[ch[cur][0]];
        if(L>=rk) insert(ch[cur][0],rk,val);
        else insert(ch[cur][1],rk-L-1,val);
        update(cur);
        if((double)(siz[cur])*alpha>(double)(mymax(siz[ch[cur][0]],siz[ch[cur][1]]))){
            if(unb){
                if(ch[cur][0]==unb) rebuild(ch[cur][0]);
                else rebuild(ch[cur][1]);
                unb=0;
            }
        }
        else unb=cur;
    }
    int ori;
    inline void change(int cur,int rk,int val){
//      cout<<"change "<<cur<<' '<<rk<<' '<<val<<'\n';
//      assert(rk>0);assert(cur);
        seg::insert(rt[cur],0,70000,val,1);
        if(siz[ch[cur][0]]+1==rk){ori=v[cur];v[cur]=val;}
        else if(siz[ch[cur][0]]>=rk) change(ch[cur][0],rk,val);
        else change(ch[cur][1],rk-siz[ch[cur][0]]-1,val);
        seg::insert(rt[cur],0,70000,ori,-1);
    }
    inline void query(int cur,int l,int r){
//      cout<<"query "<<cur<<' '<<l<<' '<<r<<' '<<siz[ch[cur][0]]<<' '<<siz[cur]<<'\n';
//		assert(cur);
        if(l==1&&r==siz[cur]){
//          cout<<"   added seg "<<cur<<' '<<rt[cur]<<'\n';
            seg::s[seg::stop++]=rt[cur];return;
        }
        if(siz[ch[cur][0]]+1>=l&&siz[ch[cur][0]]+1<=r) seg::ss[seg::sstop++]=v[cur];
        if(r<=siz[ch[cur][0]]) query(ch[cur][0],l,r);
        else if(l>siz[ch[cur][0]]+1) query(ch[cur][1],l-siz[ch[cur][0]]-1,r-siz[ch[cur][0]]-1);
        else{
            if(l<=siz[ch[cur][0]]) query(ch[cur][0],l,siz[ch[cur][0]]);
            if(r>siz[ch[cur][0]]+1) query(ch[cur][1],1,r-siz[ch[cur][0]]-1);
        }
    }
}
int n,Q;
int main(){
    read(n);int i,t1,t2,t3;char ss[10];int lastans=0;
    for(i=1;i<=n;i++){
        read(t1);
        scp::insert(root,i,t1);
        if(unb){
            unb=0;
            scp::rebuild(root);
        }
    }
//  assert(0);
//  puts("finish input");
    read(Q);
    while(Q--){
        reads(ss,1);
//      cout<<"finish read query "<<ss[1]<<"\n";
        if(ss[1]=='Q'){
            read(t1);read(t2);read(t3);
            t1^=lastans;t2^=lastans;t3^=lastans;
            seg::stop=0;seg::sstop=0;
            scp::query(root,t1,t2);
            lastans=seg::query(0,70000,t3);
            print(lastans);el();
        }
        if(ss[1]=='M'){
            read(t1);read(t2);
            t1^=lastans;t2^=lastans;
            scp::change(root,t1,t2);
        }
        if(ss[1]=='I'){
            read(t1);read(t2);
            unb=0;
            t1^=lastans;t2^=lastans;
            scp::insert(root,t1-1,t2);
            if(unb){
                unb=0;
                scp::rebuild(root);
            }
        }
    }
	flush();
}
