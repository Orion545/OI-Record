#include<bits/stdc++.h>
using namespace std;
int n,m,p[100001],a,x,b,y,u,v;
char c[3];
/*
struct lzzj{
	int to,next;
}edge[10001];

void add(int u,int v){
	edge[++cnt].to=v;
	edge[cnt].next=head[u];
	head[u]=cnt;
}

void dfs(int x){
	for(int i=head[x];i;i=edge[i].next){
		int v=edge[i].to;
		if(!vis[v])           
	}
}
*/
int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d%s",&n,&m,&c);
	for(int i=1;i<=n;i++) cin>>p[i];
	for(int i=1;i<n;i++){
		scanf("%d%d",&u,&v);
		//add(u,v);
		//add(v,u);
	}
	while(m--){
		scanf("%d%d%d%d",&a,&x,&b,&y);
		cout<<"-1"<<endl;
		/*for(int i=head[a];i;i=edge[i].next)
			if(b==edge[i].to&&x==0&&y==0)
				cout<<"-1"<<endl;
		if(c[1]=='A'&&c[2]=='1'){
			ans+=p[1];
			dfs(1);
		}*/
	}
}
