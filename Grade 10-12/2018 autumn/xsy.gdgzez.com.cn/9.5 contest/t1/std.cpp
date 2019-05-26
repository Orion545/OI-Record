#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
namespace IO{
    const int S=10000005;
    char buf[S];
    int pos;
    void load(){
        fread(buf,1,S,stdin);
        pos=0;
    }
    char getChar(){
        return buf[pos++];
    }
    int getInt(){
        int x=0,f=1;
        char c=getChar();
        while(c<'0'||c>'9'){if(c=='-')f=-1;c=getChar();}
        while('0'<=c&&c<='9'){x=x*10+c-'0';c=getChar();}
        return x*f;
    }
}
using IO::getInt;
const int N=1000010;
int n,m;
int deadMark[N];
struct Array{
    int reala[N*2],*a;
    void init(){
        a=reala+N;
        for(int i=1;i<=n;i++)
            a[i]=i;
    }
    int closeSeg(int pos){
        a[pos-2]=a[pos];
        return a[pos];
    }
    void nextStep(){
        a--;
        closeSeg(n+1);
    }
    void fetchData(int *res){
        for(int i=n;i>=1;i--)
            for(int j=a[i];j>a[i-2];j-=2)
                res[j]=i;
    }
};
Array l,r;
void simulate(){
    n=getInt(); m=getInt();
    l.init();
    r.init();
    int x;
    for(int i=1;i<=m;i++){
        x=getInt();
        cout<<"process "<<i<<' '<<x<<' '<<n-l.a[n-x+1]+1<<' '<<r.a[x]<<'\n';
        for(int j=1;j<=n;j++) cout<<j<<' '<<l.a[j]<<' '<<r.a[j]<<'\n';
        int le=n-l.closeSeg(n-x+1)+1;
        int ri=r.closeSeg(x);
		cout<<"check "<<le<<' '<<ri<<'\n';
        if(le<=ri){  
            deadMark[le]++;
            deadMark[ri+2]--;
        }
        l.nextStep();
        r.nextStep();
    }
}
void solve(){
    static int pre[N],nex[N];
    l.fetchData(pre);
    r.fetchData(nex);
    for(int i=1;i<=n;i++)
        pre[i]=n-pre[i]+1;      
    reverse(pre+1,pre+1+n);
    int sum[2]={0,0};
    for(int i=1;i<=n;i++){
        sum[i&1]+=deadMark[i];
        if(sum[i&1]==0&&pre[i]<=nex[i])
            printf("%d ",(nex[i]-pre[i]+2)>>1);
        else
            printf("0 ");
    }
    puts("");
}
int main(){
    IO::load();
    simulate();
    solve();
    return 0;
}
