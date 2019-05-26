#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define inf 0x7fffffff
using namespace std;
int read(){
	int re=0,flag=1;char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
	if(ch=='-') flag=-1,ch=getchar();
	while(ch>='0'&&ch<='9') re=re*10+(ch-'0'),ch=getchar();
	return re*flag;
}
int n,m,t,first[110],vis[110],dis[110],cnt[110];
int e[110][110];
bool can[110],go[110][110];
struct edge{
	int to,next,w;
}a[10010];
void check(){
	int i,j,k;
	for(k=1;k<=n;k++){
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				if(i!=j&&i!=k&&j!=k){
					go[i][j]=(go[i][j]||(go[i][k]&&go[k][j]));
				}
			}
		}
	}
	for(i=1;i<=n;i++) if(go[i][n]) can[i]=1;
}
int spfa(int k){
	int q[10010],head=1,tail=1,i,u,v,w;
	memset(vis,0,sizeof(vis));memset(cnt,0,sizeof(cnt));
	for(i=1;i<=n;i++) dis[i]=inf;
	q[tail++]=1;
	vis[1]=1;dis[1]=0;
	while(head<tail){
		u=q[head++];vis[u]=0;
//		cout<<"from "<<u<<endl;
		for(i=first[u];~i;i=a[i].next){
			v=a[i].to;w=a[i].w;
			if(!can[v]) continue;
//			cout<<"	to "<<v<<ends<<dis[v]<<ends<<dis[u]+w+k<<endl;
			if(dis[v]>dis[u]+w+k){
//				cout<<"	renew "<<endl;
				dis[v]=dis[u]+w+k;
				if(!vis[v]){
//					cout<<"		in queue"<<endl;
					if(++cnt[v]>n){
//						cout<<"********minus loop"<<endl;
						return 0;
					} 
					q[tail++]=v;vis[v]=1;
				}
			}
		}
	}
	if(dis[n]==inf) dis[n]=-1;
	return 1;
}
int main(){
	freopen("tstrip.in","r",stdin);
	freopen("tstrip.out","w",stdout);
//	cout<<(0>>1)<<endl;
	int i,j,t1,t2,t3;
	t=read();
	while(t--){
		memset(first,-1,sizeof(first));
		memset(a,0,sizeof(a));
		memset(go,0,sizeof(go));
		memset(can,0,sizeof(can));
		memset(e,0,sizeof(e));
		n=read();m=read();
		for(i=1;i<=n;i++) go[i][i]=1;
		for(i=1;i<=m;i++){
			t1=read();t2=read();t3=read();
			a[i].w=t3;a[i].to=t2;a[i].next=first[t1];first[t1]=i;
			e[t1][t2]=t3;go[t1][t2]=1;
		}
		int l=-100000,r=100000,mid;
		check(); 
//		for(i=1;i<=n;i++) cout<<can[i]<<ends;cout<<endl;
		if(!can[1]){
			printf("-1\n");continue;
		}
		while(l<r){
//			cout<<l<<ends<<r<<endl;
			mid=(l+r)>>1;
			if(spfa(mid)&&dis[n]>=0) r=mid;
			else l=mid+1;
		}
		spfa(l);
		printf("%d\n",dis[n]);
	}
}
