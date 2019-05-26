#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define N 10101
using namespace std;
int head[N],to[N],next[N],tot;
int n,m,p[N],ans[N],bj[N],pre[N];
int test=0;
struct hehe{
	int x,y;
}g[N];
bool cmp(hehe a,hehe b)
{
	return a.y>b.y;
}
void cc(int x,int y)
{
	next[++tot]=head[x];to[tot]=y;head[x]=tot;
}
bool dfs(int x,int fx,int tot)
{
	int k=0;
//	cout<<x<<" "<<fx<<" "<<tot<<endl;
	if(tot==n){
//		int bj=0;
//		for(int i=1;i<=n;i++)
//		if(a[i]>p[i]){bj=i;break;
//		}
//		for(int i=bj;i<=n;i++)
//		a[i]=p[i];
		return true;
	}
	for(int i=head[x];i;i=next[i])
	{//cout<<"ac"<<to[i]<<" "<<bj[to[i]]<<endl;
		int v=to[i];
		if(v==fx||bj[v]==1)continue;
		bj[v]=1;
		pre[v]=x;
		p[tot+1]=v;
		int tmp=ans[tot+1];
		if(dfs(v,x,tot+1)){ans[tot+1]=p[tot+1];k=1;//cout<<p[tot+1]<<endl;
		break;
		}
		else {ans[tot+1]=tmp;p[tot+1]=0;bj[v]=0;pre[v]=0;
		}
	}

	if(k==0)
	{if(pre[x]!=0)
		return dfs(pre[x],x,tot);
	else return false;
	}
	else return true;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
    	scanf("%d%d",&g[i].x,&g[i].y);
    	g[i+m].x=g[i].y;g[i+m].y=g[i].x;
    }
    sort(g+1,g+2*m+1,cmp);
    for(int i=1;i<=2*m;i++)
    {
    	cc(g[i].x,g[i].y);
    }
  //  for(int i=1;i<=n;i++)
  //  {
  //  cout<<i<<endl;
  //  for(int j=head[i];j;j=next[j])
  //  cout<<to[j]<<" ";
  //  cout<<endl;
//    }
    p[1]=1;ans[1]=1;bj[1]=1;pre[1]=0;
    dfs(1,0,1);
    for(int i=1;i<=n;i++)
    printf("%d ",ans[i]);
	return 0;
}
