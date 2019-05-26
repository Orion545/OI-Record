#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <stack>
using namespace std;

const int maxn = 1000;

struct Edge   //ջ�бߵĽṹ
{
    int u,v;
    Edge(int uu,int vv)
    {
        u = uu;
        v = vv;
    }
};
stack<Edge> s;

struct edge  //��ʽǰ���ǽ�ͼ�ı߽ṹ
{
    int v,next;
}edges[maxn];

int n,m;        //�ڵ����Ŀ������ߵ���Ŀ
int e,head[maxn];
int pre[maxn];           //��һ�η��ʵ�ʱ���
int dfs_clock;           //ʱ���
int iscut[maxn];         //��ǽڵ��Ƿ�Ϊ�
int bcc_cnt;             //��_˫��ͨ��������Ŀ
int bccno[maxn];         //�ڵ����ڵĵ�_˫��ͨ�����ı��
vector<int> bcc[maxn];   //��_˫��ͨ����

void addedges(int u,int v)  //�ӱ�
{
    edges[e].v = v;
    edges[e].next = head[u];
    head[u] = e++;
    edges[e].v = u;
    edges[e].next = head[v];
    head[v] = e++;
}

int dfs(int u,int fa)
{
    int lowu = pre[u] = ++dfs_clock;
    int child = 0;
    for(int i=head[u];i!=-1;i=edges[i].next)
    {
        int v = edges[i].v;
        Edge e = (Edge){u,v};
        if(!pre[v])
        {
            s.push(e);
            child++;
            int lowv = dfs(v,u);
            lowu = min(lowu,lowv); //�ú������lowu
            if(lowv >= pre[u])     //�ҵ���һ����������������
            {
                iscut[u] = 1;
                bcc_cnt++;
                bcc[bcc_cnt].clear();
                for(;;)            //����bcc��Ϣ
                {
                    Edge x = s.top(); s.pop();
                    if(bccno[x.u] != bcc_cnt) {bcc[bcc_cnt].push_back(x.u); bccno[x.u] = bcc_cnt;}
                    if(bccno[x.v] != bcc_cnt) {bcc[bcc_cnt].push_back(x.v); bccno[x.v] = bcc_cnt;}
                    if(x.u == u && x.v == v) break;
                }
            }
        }
        else if(pre[v] < pre[u] && v != fa)   //�÷���߸���lowu
        {
            s.push(e);
            lowu = min(lowu,pre[v]);
        }
    }
    if(fa < 0 && child == 1) iscut[u] = 0;    //���ڸ��ڵ���ֻ��һ���������Ǹ
    return lowu;
}

void init()
{
    memset(pre,0,sizeof(pre));
    memset(iscut,0,sizeof(iscut));
    memset(head,-1,sizeof(head));
    memset(bccno,0,sizeof(bccno));
    e = 0; dfs_clock = 0; bcc_cnt = 0;
}

int vis[maxn];

bool loop(int u,int t,int fa,int begin){
	int i,v,flag,re=1;vis[u]=1;
	for(i=head[u];~i;i=edges[i].next){
		v=edges[i].v;if(v==fa) continue;
		if(bccno[v]==t){
			if(vis[v]&&v!=begin) return 0;
			if(!vis[v]) re=re&&loop(v,t,u,begin);
		}
	}
	return re;
}

int main()
{
    int u,v;
	scanf("%d%d",&n,&m); 
    init();
    for(int i=0;i<m;i++)
    {
       scanf("%d%d",&u,&v);
       addedges(u,v);
    }
    dfs(1,-1);
    for(int i=1;i<=bcc_cnt;i++)
    {
       	for(int j=0;j<bcc[i].size();j++)
           cout<<bcc[i][j]<<" ";
       	cout<<endl;
    }
    for(int i=1;i<=bcc_cnt;i++){
    	if(bcc[i].size()<=2) continue;
    	if(loop(bcc[i][0],i,edges[head[bcc[i][0]]].v,bcc[i][0])){
    		
		}
	} 
}
