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
            if(enter[i + 1] <= last[i + 1])//��һ��������ȴ� 
                g[i] = i + 1;//���Ӱ�쵽��һ��
            else //���ȴ� 
                g[i] = g[i + 1];//�������ٺ����ʱ�� 
        }
        for(int i = 1;i < n;++ i){//for���� 
            int tmp = sum[g[i]] - sum[i];//���Ӱ������� 
            if(tmp > maxx && dis[i] > 0){
                maxx = tmp;
                tar = i;//�������������ĵ� 
            }
        }
        ans -= maxx;//����ans 
        dis[tar] --;//����dis 
        cout<<ans<<' '<<maxx<<'\n';
        for(int i = 2;i <= n;++ i){
            enter[i] = max(enter[i - 1],last[i - 1]) + dis[i - 1];//���¸���enter 
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
        last[a[i].start] = max(last[a[i].start],a[i].time);//���һ���˵�a[i].startվ���ʱ�� �͵�������ʱ��ȡmax 
        sum[a[i].end] ++;
    }
    enter[1] = last[1];
    for(int i = 1;i <= n;++ i)
        sum[i] += sum[i - 1];//��iվ��������� ǰ׺�ʹ��� 

    for(int i = 2;i <= n;++ i)
        enter[i] = max(enter[i - 1],last[i - 1]) + dis[i - 1];//������iվ�������ʱ�� ����󵽵�ʱ��ȡmax 
    for(int i = 1;i <= m;++ i)
        ans += enter[a[i].end] - a[i].time;//��������Ӽ�������answer,����Ϳ���ֱ�Ӽ���~
    cout<<ans<<'\n';
	bus(k);
    printf("%d \n",ans);
    return 0;
}
