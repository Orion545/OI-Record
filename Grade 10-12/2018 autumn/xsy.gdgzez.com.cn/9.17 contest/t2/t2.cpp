#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
#define MOD 1000000007
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
const int dx[3]={0,0,1},dy[3]={0,1,0};
int dp[4020][4020];int N=2005;bool vis[4020][4020];
int n,xx[200010],yy[200010],qx[200010],qy[200010],head=0,tail=1,maxq=200000;
ll inv[8010],finv[8010],f[8010];
void init(){
    int i;inv[1]=finv[1]=1;
    for(i=2;i<=8000;i++){
        inv[i]=((MOD-MOD/i)*inv[MOD%i])%MOD;
    }
    f[1]=1;
    for(i=2;i<=8000;i++){
        f[i]=(f[i-1]*i)%MOD;
        finv[i]=(finv[i-1]*inv[i])%MOD;
    }
}
int main(){
    init();
    int i,maxx=0,maxy=0,x,y,tx,ty;ll X=0;
    n=read();
    for(i=1;i<=n;i++){
        xx[i]=read();yy[i]=read();
        dp[N-xx[i]][N-yy[i]]+=1;
        maxx=max(maxx,xx[i]);maxy=max(maxy,yy[i]);
    }
    qx[0]=N-maxx,qy[0]=N-maxy;vis[N-maxx][N-maxy]=1;
    while(head!=tail){
        x=qx[head];y=qy[head];head=(head+1)%maxq;
//        cout<<"dp "<<x<<ends<<y<<ends<<dp[x][y]<<endl;;
        for(i=1;i<=2;i++){
            tx=x+dx[i];ty=y+dy[i];
            if(tx>N+maxx||ty>N+maxy) continue;
            dp[tx][ty]=(dp[tx][ty]+dp[x][y])%MOD;
//            cout<<"    to "<<tx<<ends<<ty<<ends<<dp[tx][ty]<<endl;
            if(!vis[tx][ty]){
                vis[tx][ty]=1;
                qx[tail]=tx;qy[tail]=ty;tail=(tail+1)%maxq;
            }
        }
    }
    for(i=1;i<=n;i++){
        X=X+dp[N+xx[i]][N+yy[i]];X%=MOD;
        X=X-((f[xx[i]*2+yy[i]*2]*finv[xx[i]*2])%MOD*finv[yy[i]*2])%MOD+MOD;
        X%=MOD;
    }
    printf("%lld\n",(X*inv[2])%MOD);
}
