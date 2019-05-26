#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int max_n=1e5+5;

int n,m,x,y,z,sz,ans;
int val[max_n],p[max_n],num[max_n],root[max_n];
int sum[max_n*20],ls[max_n*20],rs[max_n*20];

inline int cmp(int a,int b){return val[a]<val[b];}
inline void build(int &now,int l,int r,int x){
    int mid=(l+r)>>1;
	cout<<"build "<<l<<ends<<r<<ends<<x<<endl;
    sum[++sz]=sum[now]; ls[sz]=ls[now]; rs[sz]=rs[now];
    now=sz;
    ++sum[now];
    if (l==r) return;
    if (x<=mid) build(ls[now],l,mid,x);
    else build(rs[now],mid+1,r,x);
}
inline int query(int i,int j,int l,int r,int k){
	cout<<"query "<<i<<ends<<j<<ends<<l<<ends<<r<<ends<<k<<endl;
    int mid=(l+r)>>1;
    if (l==r) return l;
    int t=sum[ls[j]]-sum[ls[i]];
    if (t>=k) return query(ls[i],ls[j],l,mid,k);
    else return query(rs[i],rs[j],mid+1,r,k-t); 
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i) scanf("%d",&val[i]),p[i]=i;
    sort(p+1,p+n+1,cmp);
    for(int i=1;i<=n;++i) num[p[i]]=i;
    sz=0;root[0]=0;
    for(int i=1;i<=n;++i){
        root[i]=root[i-1];
        build(root[i],1,n,num[i]);
    }
    for(int i=1;i<=m;++i){
        scanf("%d%d%d",&x,&y,&z);
        ans=query(root[x-1],root[y],1,n,z);
        cout<<ans<<endl;
        printf("%d\n",val[p[ans]]);
    }
}
