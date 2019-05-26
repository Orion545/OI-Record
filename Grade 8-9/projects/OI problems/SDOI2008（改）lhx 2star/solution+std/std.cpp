#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
#define inf 1e9
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
int a[1010][1010],b[1010];int N,n,m[1010],fail[1010],ans=0,tans=inf,tmp;
int main(){
	freopen("bath.in","r",stdin);
	freopen("bath.out","w",stdout);
    N=read();int i,j,t1,t2,k,l;
    n=read();t1=read();for(i=0;i<n-1;i++) t2=read(),b[i]=t2-t1,t1=t2;
    b[n-1]=b[n]=b[n+1]=-inf;
    for(j=1;j<N;j++){
        m[j]=read();t1=read();
        for(i=0;i<m[j]-1;i++) t2=read(),a[j][i]=t2-t1,t1=t2;
        a[j][m[j]-1]=a[j][m[j]]=inf;
    }
    for(k=n-1;k>=1;k--){
        memset(fail,0,sizeof(fail));
        j=0;tans=inf; 
        for(i=1;i<k;i++){
            while(j&&(b[i]!=b[j])) j=fail[j];
            j+=(b[i]==b[j]);fail[i+1]=j;
        }
        for(l=1;l<N;l++){
            j=0;tmp=0;
            for(i=0;i<m[l]-1;i++){
                while(j&&a[l][i]!=b[j]) j=fail[j];
                j+=(a[l][i]==b[j]);
                tmp=max(tmp,j);
                if(j==k) break;
            }
            tans=min(tans,tmp);
        }
        for(i=0;i<k-1;i++) b[i]=b[i+1];b[k]=-inf;
        ans=max(ans,tans);
    }
    printf("%d",ans+1);
}
