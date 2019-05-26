#include<iostream>
#include<cstdio>
#include<cstring>
#define ll unsigned long long
#define inf 0x7fffffff
using namespace std;
struct erickin{
    int data,to;ll next;
}a[1000010],b[1000010];
struct Queue{
    int aa[100010],head,tail;
    Queue(){
        memset(aa,0,sizeof(aa));
        head=1;tail=1;
    }
    void push(int k){
        aa[tail++]=k;
    }
    void pop(){
        aa[head++]=0;
    }
    bool empty(){
        if(head==tail) return 1;
        else return 0;
    }
    int h(){
        return aa[head];
    }
};
Queue q,qq;
ll n,m,x,first1[1000010],first2[1000010];
ll ans1[1000010],ans2[1000010];
bool vis[1000010]={0};
void spfa1(){
    for(int i=1;i<=n;i++) ans1[i]=inf;
    q.push(x);vis[x]=1;ans1[x]=0;
    while(!q.empty()){
        int h=q.h();
        int p=first1[h];
//        cout<<"doing "<<q.h()<<ends<<q.head<<ends<<q.tail<<ends<<ans1[h]<<endl;
        while(p!=-1){
            int t=ans1[h]+a[p].data;
//            cout<<"    in edge NO."<<p<<" to "<<a[p].to<<" on "<<a[p].data<<endl;
            if(ans1[a[p].to]>t){
//                cout<<"        success as "<<ans1[a[p].to]<<" && "<<t<<endl;
                ans1[a[p].to]=t;
                if(!vis[a[p].to]){
//                    cout<<"        new in queue:pt NO."<<a[p].to<<endl;
                    q.push(a[p].to);vis[a[p].to]=1;
                }
            }
            p=a[p].next;
        }
        q.pop();vis[h]=0;
    }
}
void spfa2(){
    for(int i=1;i<=n;i++) ans2[i]=inf;
    qq.push(x);vis[x]=1;ans2[x]=0;
    while(!qq.empty()){
        int h=qq.h();
        int p=first2[h];
//        cout<<"doing "<<qq.h()<<ends<<qq.head<<ends<<qq.tail<<ends<<ans2[h]<<endl;
        while(p!=-1){
            int t=ans2[h]+b[p].data;
//            cout<<"    in edge NO."<<p<<" to "<<b[p].to<<" on "<<b[p].data<<endl;
            if(ans2[b[p].to]>t){
//                cout<<"        success as "<<ans2[b[p].to]<<" && "<<t<<endl;
                ans2[b[p].to]=t;
                if(!vis[b[p].to]){
//                    cout<<"        new in queue:pt NO."<<b[p].to<<endl;
                    qq.push(b[p].to);vis[b[p].to]=1;
                }
            }
            p=b[p].next;
        }
        qq.pop();vis[h]=0;
    }
}
int tt1[1000010],tt2[1000010];
int main(){
    std::ios::sync_with_stdio(false);
    cin>>n>>m>>x;
    int ta,tb,tc;
    for(int i=0;i<=n;i++) first1[i]=tt1[i]=first2[i]=tt2[i]=-1;
    for(int i=1;i<=m;i++){
        cin>>ta>>tb>>tc;
        a[i].data=tc;a[i].to=tb;a[i].next=tt1[ta];
        first1[ta]=tt1[ta]=i;
        b[i].data=tc;b[i].to=ta;b[i].next=tt2[tb];
        first2[tb]=tt2[tb]=i;
    }
    spfa1();
    memset(vis,0,sizeof(vis));
    spfa2();
    ll minn=0;
    for(int i=1;i<=n;i++){
//        cout<<ans1[i]<<ends<<ans2[i]<<endl;
        if(i!=x) minn=max(minn,ans1[i]+ans2[i]);
    }
    cout<<minn;
}
