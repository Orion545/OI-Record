#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#define ll long long
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
struct complex{
    long double x,y;
    complex(long double xx=0,long double yy=0){x=xx;y=yy;}
    complex operator +(const complex &b){return complex(x+b.x,y+b.y);}
    complex operator -(const complex &b){return complex(x-b.x,y-b.y);}
    complex operator *(const complex &b){return complex(x*b.x-y*b.y,x*b.y+y*b.x);}
}A[2000010],B[2000010];
const long double pi=acos(-1.0);
int n,m,limit=1,cnt=0,r[2000010];
void fft(complex *a,long double type){
    int i,j,k,mid;complex x,y,w,wn;
    for(i=0;i<limit;i++) if(i<r[i]) swap(a[i],a[r[i]]);
    for(mid=1;mid<limit;mid<<=1){
        wn=complex(cos(pi/mid),type*sin(pi/mid));
        for(j=0;j<limit;j+=(mid<<1)){
            w=complex(1,0);
            for(k=0;k<mid;k++,w=w*wn){
                x=a[j+k];y=w*a[j+k+mid];
                a[j+k]=x+y;a[j+k+mid]=x-y;
            }
        }
    }
}
vector<int>ans;
char s[300010];
int main(){
    m=read();n=read();int i;ll tmp;
    scanf("%s",s);
    for(i=0;i<m;i++){
        if(s[i]=='*') B[m-i].x=0;
        else B[m-i].x=(1.0/(100001.0+(long double)(s[i]-'a')));
    }
    scanf("%s",s);
    for(i=0;i<n;i++){
        if(s[i]=='*') A[i+1].x=0;
        else A[i+1].x=(100001.0+(long double)(s[i]-'a'));
    }
    while(limit<=(n+m)) limit<<=1,cnt++;
    for(i=0;i<limit;i++) r[i]=((r[i>>1]>>1)|((i&1)<<(cnt-1)));
    fft(A,1);fft(B,1);
    for(i=0;i<=limit;i++) A[i]=A[i]*B[i];
    fft(A,-1);
    for(i=m+1;i<=n+1;i++){
        A[i].x/=(long double)limit;tmp=(ll)(A[i].x+0.1);
        if(abs(A[i].x-((long double)(tmp)))<=5e-10) ans.push_back(i-m);
    }
    printf("%d\n",ans.size());
    for(i=0;i<ans.size();i++) printf("%d ",ans[i]);
}
