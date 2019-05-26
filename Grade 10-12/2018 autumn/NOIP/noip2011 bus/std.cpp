#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>

#define N 30001

using namespace std;

int n,m,k;
int dis[N],last[N],g[N],enter[N];
int ans,sum[N],maxx = -1;

struct node{
    int time,start,end;
}a[N];

inline void bus(int x){
    while(x){
        --x;
        g[n] = g[n - 1] = n;
        int tar;
        maxx = -1;
        for(int i = n - 2;i >= 1;-- i){
            if(enter[i + 1] <= last[i + 1])//下一个点如果等待 
                g[i] = i + 1;//最多影响到下一个
            else //不等待 
                g[i] = g[i + 1];//继续减少后面的时间 
        }
        for(int i = 1;i < n;++ i){//for边数 
            int tmp = sum[g[i]] - sum[i];//最多影响的人数 
            if(tmp > maxx && dis[i] > 0){
                maxx = tmp;
                tar = i;//标记最优情况减的点 
            }
        }
        ans -= maxx;//更新ans 
        dis[tar] --;//减掉dis 
        cout<<ans<<' '<<maxx<<'\n';
        for(int i = 2;i <= n;++ i){
            enter[i] = max(enter[i - 1],last[i - 1]) + dis[i - 1];//重新更新enter 
        }
    }
    return;
}
int main(){
	freopen("in.in","r",stdin);
    scanf("%d%d%d",&n,&m,&k);
    for(int i = 1;i < n;++ i)
        scanf("%d",&dis[i]);
    for(int i = 1;i <= m;++ i)
        scanf("%d%d%d",&a[i].time,&a[i].start,&a[i].end);
    for(int i = 1;i <= m;++ i){
        last[a[i].start] = max(last[a[i].start],a[i].time);//最后一个人到a[i].start站点的时间 和到这个点的时间取max 
        sum[a[i].end] ++;
    }
    enter[1] = last[1];
    for(int i = 1;i <= n;++ i)
        sum[i] += sum[i - 1];//到i站点的总人数 前缀和处理 

    for(int i = 2;i <= n;++ i)
        enter[i] = max(enter[i - 1],last[i - 1]) + dis[i - 1];//公车到i站点的最少时间 和最后到的时间取max 
    for(int i = 1;i <= m;++ i)
        ans += enter[a[i].end] - a[i].time;//处理出不加加速器的answer,后面就可以直接减啦~
    cout<<ans<<'\n';
	bus(k);
    printf("%d \n",ans);
    return 0;
}
