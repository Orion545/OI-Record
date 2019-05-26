#include<cstdio>
#include<queue>
using namespace std;
const int N=5005;
int n,m,fa[N],ans[N],now[N];
int head[N],to[N*2],nxt[N*2],tot;
bool vis[N];
int read()
{
	int rt=0;	char ch=getchar();
	while(ch<'0'||ch>'9'){	ch=getchar();}
	while(ch>='0'&&ch<='9'){rt=rt*10+ch-48;ch=getchar();}
	return rt;
}
void add(int u,int v)
{
	to[++tot]=v;
	nxt[tot]=head[u];
	head[u]=tot;
}
void qinkuangyi(int x)
{
	printf("%d ",x);
	priority_queue<int,vector<int>,greater<int> >q;
	for(int i=head[x];i;i=nxt[i]){
		if(to[i]==fa[x])	continue;
		fa[to[i]]=x;
		q.push(to[i]);
	}
	while(!q.empty()){
		qinkuangyi(q.top());
		q.pop();
	}
}
void qinkuanger()
{
	int now=1,xiao=1000000,da=-1,cnt=2,flag=0;
	vis[1]=1;
	printf("1 ");
	for(int i=head[now];i;i=nxt[i]){
		if(to[i]>da)	da=to[i];
		if(to[i]<xiao)	xiao=to[i];
	}
	now=xiao;
	vis[now]=1;
	printf("%d ",xiao);
	while(cnt<n){
		for(int i=head[now];i;i=nxt[i]){
			if(vis[to[i]]==1)	continue;
			if(flag==1){
				now=to[i];
				vis[now]=1;
				printf("%d ",now);
				cnt++;
				continue;
			}
			if(to[i]<da){
				now=to[i];
				vis[now]=1;
				printf("%d ",now);
				cnt++;
			}
			else{
				flag=1;
				now=da;
				vis[now]=1;
				printf("%d ",now);
				cnt++;		
			}
		}
	}
	
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	n=read();	m=read();
	for(int i=1;i<=m;i++){
		int uu,vv;
		uu=read();	vv=read();
		add(uu,vv);	add(vv,uu);
	}
	if(m==n-1){
		qinkuangyi(1);
		return 0;
	}
	if(m==n){
		qinkuanger();
	}
	return 0;
}

