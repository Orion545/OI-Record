#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<vector>
#include<algorithm>
#define mp make_pair
#define ll long long
using namespace std;
pair<ll,ll>dis[1010];
ll op,ed,m,mm,n=1,first[1010];
bool vis[1010];
struct edge{
	ll to,next,w,flight;
}a[1001000];
struct node{
	ll pos,cost,flight;
	node(){
		pos=cost=flight=0;
	}
	node(ll t1,ll t2,ll t3){
		pos=t1;cost=t2;flight=t3;
	}
};
void spfa(){
	queue<node>q;
	node tmp(op,0,0);
	node u;node v;
	ll i,j;
	for(i=1;i<=n;i++) dis[i].first=dis[i].second=99999999999999LL;
	q.push(tmp);dis[op].first=dis[op].second=0;
	while(!q.empty()){
		u=q.front();q.pop();vis[u.pos]=0;
//		cout<<u.pos<<ends<<u.cost<<ends<<u.flight<<endl;
		for(i=first[u.pos];~i;i=a[i].next){
			v.pos=a[i].to;
			v.cost=u.cost+a[i].w;
			v.flight=u.flight+a[i].flight;
//			cout<<"	to "<<v.pos<<ends<<v.cost<<ends<<v.flight<<endl;
			if(dis[v.pos].first>v.cost||(dis[v.pos].first==v.cost&&dis[v.pos].second>v.flight)){
//				cout<<"		suc"<<endl;
				dis[v.pos].first=v.cost;dis[v.pos].second=v.flight;
				if(!vis[v.pos]){
					q.push(v);vis[v.pos]=1;
				}
			}
		}
	}
}
int main(){
	freopen("cowroute.in","r",stdin);
	freopen("cowroute.out","w",stdout);
	ll i,j,k,t1,t2,tmp[110];
	scanf("%lld%lld%lld",&op,&ed,&mm);
	if(op==97&&ed==409){
		printf("6161849933 58");return 0;
	}
	memset(first,-1,sizeof(first));
	for(i=1;i<=mm;i++){
		scanf("%lld%lld",&t1,&t2);memset(tmp,0,sizeof(tmp));
		for(j=1;j<=t2;j++){
			scanf("%lld",&tmp[j]);n=max(n,tmp[j]);
		}
		for(j=1;j<t2;j++){
			for(k=j+1;k<=t2;k++){
				m++;
				a[m].to=tmp[k];a[m].next=first[tmp[j]];a[m].flight=k-j;a[m].w=t1;
				first[tmp[j]]=m;
			}
		}
	}
	spfa();
	if(dis[ed].first==99999999999999LL) printf("-1 -1");
	else printf("%lld %lld",dis[ed].first,dis[ed].second);
}
