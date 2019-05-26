/*by SilverN*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#define LL long long
using namespace std;
const long double pi=acos(-1.0);
const int mxn=350021;
int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
struct com{
    long double x,y;
    com operator + (const com b){return (com){x+b.x,y+b.y};}
    com operator - (const com b){return (com){x-b.x,y-b.y};}
    com operator * (const com b){return (com){x*b.x-y*b.y,x*b.y+y*b.x};}
}a[mxn],b[mxn],c[mxn];
int N,l,rev[mxn];
void FFT(com *a,int flag){
    int i,j,k;
    for(i=0;i<N;i++)if(rev[i]>i)swap(a[rev[i]],a[i]);
    for(i=1;i<N;i<<=1){
        com wn=(com){cos(pi/i),flag*sin(pi/i)};
        for(j=0;j<N;j+=(i<<1)){
            com w=(com){1,0};
            for(k=0;k<i;k++,w=w*wn){
                com x=a[j+k],y=w*a[j+k+i];
                a[j+k]=x+y;
                a[i+j+k]=x-y;
            }
        }
    }
    if(flag==-1)for(i=0;i<N;i++)a[i].x/=N;
    return;
}
int n,w[mxn];
LL ans[mxn];
int smm[mxn];
void init(){
    n=read();
    LL cnt=0;
    ans[0]=0;
    for(int i=1;i<=n;i++){
        w[i]=read();
        smm[i]=smm[i-1]+w[i];
        if(!w[i]){//0
            cnt++;
            ans[0]+=cnt*(cnt+1)/2;
        }
        else cnt=0;
    }
    return;
}
int main(){
    int i,j;
    int T=read();
    
    while(T--){
        init();
//        for(i=1;i<=n;i++)printf("%d ",smm[i]);
//        printf("\n");
        memset(a,0,sizeof a);
        memset(b,0,sizeof b);
        memset(c,0,sizeof c);
        int ed=smm[n];
        int m=ed<<1;
        for(N=1,l=0;N<=m;N<<=1)l++;
        for(i=0;i<N;i++){
            rev[i]=(rev[i>>1]>>1)|((i&1)<<(l-1));
        }
        //
        for(i=1;i<=n;i++){
            a[smm[i]].x+=i;
            b[ed-smm[i-1]].x+=1;
        }
        /*
        for(i=0;i<=ed;i++)printf("%.2Lf ",a[i].x);
        printf("\n");
        for(i=0;i<=ed;i++)printf("%.2Lf ",b[i].x);
        printf("\n");
        */
        FFT(a,1);FFT(b,1);
        for(i=0;i<=N;i++)
            c[i]=a[i]*b[i];
        FFT(c,-1);
        memset(a,0,sizeof a);
        memset(b,0,sizeof b);
        for(i=1;i<=n;i++){
            a[smm[i]].x+=1;
            b[ed-smm[i-1]].x+=i-1;
        }
        FFT(a,1);FFT(b,1);
        for(i=0;i<=N;i++){
            a[i]=a[i]*b[i];
        }
        FFT(a,-1);
        for(i=0;i<=N;i++)c[i]=c[i]-a[i];
        printf("%lld\n",ans[0]);
        for(i=1;i<=ed;i++){
            printf("%lld\n",(LL)(c[i+ed].x+0.5));
        }
    }
    return 0;
}
/*
1
10
1 2 3 4 5 6 7 8 9 10

*/
