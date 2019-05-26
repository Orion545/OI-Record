#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
struct edge{
	int to,w,next;
}e[400100];
struct new_edge{
	int from,to,w;
}x[400100];
struct node{
	int num,fa;
	vector<int>son;
}a[100100];
int n,m,first[100100],pre[100100],dis[100100],f[100100],ans[100100];
bool vis[100100];
void spfa(){
	int i,u,v,w;
	queue<int>q;memset(dis,127,sizeof(dis));
	q.push(1);pre[1]=1;dis[1]=0;
	while(!q.empty()){
		u=q.front();q.pop();vis[u]=0;
		for(i=first[u];~i;i=e[i].next){
			v=e[i].to;w=e[i].w;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;pre[v]=u;
				if(!vis[v]){
					vis[v]=1;q.push(v);
				}
			}
		}
	}
}
bool cmp(new_edge l,new_edge r){
	return l.w<r.w;
}
int find(int x){
	return ((f[x]==x)?x:f[x]=find(f[x]));
}
int aa[200100],bb[200100],cc[200100];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	memset(first,-1,sizeof(first));
	memset(ans,-1,sizeof(ans));
	int i,j,t1,t2,t3,l,r;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++){
		scanf("%d%d%d",&t1,&t2,&t3);
		e[i*2-1].to=t2;e[i*2-1].next=first[t1];e[i*2-1].w=t3;first[t1]=i*2-1;
		e[i*2].to=t1;e[i*2].next=first[t2];e[i*2].w=t3;first[t2]=i*2;
		aa[i]=t1;bb[i]=t2;cc[i]=t3;
	}
	spfa();
//	for(i=1;i<=n;i++) cout<<pre[i]<<ends<<dis[i]<<endl;
//	for(i=1;i<=m;i++) cout<<aa[i]<<ends<<bb[i]<<ends<<cc[i]<<endl;
//	cout<<"end of spfa"<<endl;
	for(i=1;i<=n;i++){
		a[i].num=i;f[i]=i;
		a[i].fa=pre[i];
		if(i!=1) a[pre[i]].son.push_back(i);
	}
	int cnt=0;
	for(i=1;i<=m;i++){
		if(pre[aa[i]]==bb[i]||pre[bb[i]]==aa[i]) continue;
//		cout<<aa[i]<<ends<<bb[i]<<ends<<cc[i]<<endl;
		x[++cnt].from=aa[i];x[cnt].to=bb[i];x[cnt].w=dis[aa[i]]+dis[bb[i]]+cc[i];
	}
//	cout<<"end2"<<endl;
	sort(x+1,x+cnt+1,cmp);
	for(i=1;i<=cnt;i++){
		l=find(x[i].from);r=find(x[i].to);
		while(l!=r){
			if(dis[l]<dis[r]) swap(l,r);
			ans[l]=x[i].w-dis[l];
			f[l]=pre[l];l=find(l);
		}
	}
	for(i=2;i<=n;i++) printf("%d\n",ans[i]);
}
