#include<bits/stdc++.h>
using namespace std;

struct lzzj{
	int to,next;
}edge[10001];

int head[5001],vis[5001];
int k[5001][5001],tot[5001],t[5001],ans[5001];
int n,m,a,b,cnt,ttot,tmp,tt;

void add(int u,int v){
	edge[++cnt].to=v;
	edge[cnt].next=head[u];
	head[u]=cnt;
}

void dfs(int x){
	//if(vis[x]) return ;
	vis[x]=1;
	//memset(k,0,sizeof(k));
	tmp=0;
	for(int i=head[x];i;i=edge[i].next){
		int v=edge[i].to;
		if(!vis[v]) k[x][++tot[x]]=v;
	}
	//if(!tmp) return;
	//sort(k+1,k+tmp+1);
	for(int i=1;i<=tot[x];i++)
		for(int j=i+1;j<=tot[x];j++)
			if(k[x][i]>k[x][j])
				swap(k[x][i],k[x][j]);
	for(int i=1;i<=tot[x];i++){
		if(!vis[k[x][i]]){
			ans[++ttot]=k[x][i];
			vis[k[x][i]]=1;
			dfs(k[x][i]);
			vis[k[x][i]]=0;
		}
		else return ;
	}
}

void dfs2(int x){
	vis[x]=1;
	for(int i=head[x];i;i=edge[i].next){
		int v=edge[i].to;
		if(!vis[v]){
			vis[v]=1;
			cout<<v<<" ";
			dfs2(v);
		}
	}
}

void dfs3(int x,int dep){
	vis[x]=1;
	if(dep==n-1) exit(0);
	for(int i=head[x];i;i=edge[i].next){
		int v=edge[i].to;
		if(!vis[v]){
			cout<<v<<" ";
			vis[v]=1;
			dfs3(v,dep+1);
		}
	}
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&a,&b);
		add(a,b);
		add(b,a);
		if(a==1) t[++tt]=b;
		if(b==1) t[++tt]=a;
	}
	
	if(m==n-1){
		if(n<1000){
			ans[0]=1;
	        dfs(1);
	        for(int i=0;i<n;i++) cout<<ans[i]<<" ";
		    return 0;
		}
		int t1=t[1],t2=t[2];
		cout<<"1 ";
		if(t1<t2){
			cout<<t1<<" ";
			dfs2(t1);
			cout<<t2<<" ";
			dfs2(t2);
		}
		else{
			cout<<t2<<" ";
			dfs2(t2);
			cout<<t1<<" ";
			dfs2(t1);
		}
	}
	if(m==n){
		int t1=t[1],t2=t[2];
		vis[1]=1;
		cout<<"1 "<<min(t1,t2)<<" ";
		dfs3(min(t1,t2),1);
	}  
	
	
}

