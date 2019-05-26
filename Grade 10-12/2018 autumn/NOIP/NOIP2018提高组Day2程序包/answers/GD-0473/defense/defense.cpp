
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>

using namespace std;
struct node{int to,next;}e[200020];

int n,m,u,v,head[200020],deep[100010],cnt,p[100010],minn,a,x,b,y,lca[100010][30],fa[100010];
string s;
bool vis[100010];
inline void dfs(int rt,int all,int need){
	if(minn<need) return ;
	if(all==n){
		if(need<minn) minn=need;
		return ;
	}
	if(x==0&&rt==a) dfs(rt+1,all,need);
	if(y==0&&rt==b) dfs(rt+1,all,need);
	if((rt-1)==0){
		int su=0;
		if(!vis[rt]) su++,vis[rt]=true;
		if(!vis[rt+1]) su++,vis[rt+1]=true;
		if(su!=0||(x==1&&rt==a)||(y==1&&rt==b)) dfs(rt+1,all+su,need+p[rt]);
		else dfs(rt+1,all,need);
	}
	else if((rt+1)>n){
		int su=0;
		if(!vis[rt]) su++,vis[rt]=true;
		if(!vis[rt-1]) su++,vis[rt-1]=true;
		if(su!=0||(x==1&&rt==a)||(y==1&&rt==b)) dfs(rt-1,all+su,need+p[rt]);
		else dfs(rt-1,all,need);
	}
	else{
		int su=0;
		if(!vis[rt+1]) su++,vis[rt+1]=true;
		if(!vis[rt]) su++,vis[rt]=true;
		if(!vis[rt-1]) su++,vis[rt-1]=true;
		if(su!=0||(x==1&&rt==a)||(y==1&&rt==b)) dfs(rt+1,all+su,need+p[rt]);
		else dfs(rt+1,all,need);
	}
	
	return ;	
	
}

inline void find(int rt,int all,int need){
	if(minn<need) return ;
	if(all==n){
		if(need<minn) minn=need;
		return ;
	}
	for(int i=head[rt];i;i=e[i].next){
		if(!vis[e[i].to]){
			vis[e[i].to]=true;
			int sum=0;
			for(int j=head[e[i].to];j;j=e[j].next){
				if(!vis[e[j].to]){
					vis[e[j].to]=true;sum++;
				}
			}
			dfs(e[i].to,all+sum,need+p[i]);
			vis[e[i].to]=false;
		}
	}
	return ;
}
int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d",&n);scanf("%d",&m);cin >> s;
//	cout << s << endl;
	for(int i=1;i<=n;i++){
		scanf("%d",&p[i]);
	}
	for(int i=1;i<=n-1;i++){
		scanf("%d",&u);scanf("%d",&v);
//		cout << u << endl;
		e[++cnt].to=v;e[cnt].next=head[u];head[u]=cnt;
		e[++cnt].to=u;e[cnt].next=head[v];head[v]=cnt;
	}
	while(m--){
		scanf("%d",&a);scanf("%d",&x);scanf("%d",&b);scanf("%d",&y);
//		if(n<=10&&m<=10){
//			
//			continue;
//		}
		if(s[0]=='A'){
			int ans=0;
//			if(x==1) vis[a-1]=true,vis[a+1]=true,vis[a]=true,ans+=p[a];
//			if(y==1) vis[b-1]=true,vis[b+1]=true,vis[b]=true,ans+=p[b];
			if(s[1]=='1'){
				
			}
			else if(s[1]=='2'){
				
			}
			else if(s[1]=='3'){
				dfs(1,0,0);
				ans+=minn;
				printf("%d\n",ans);
			}
		}
		else if(s[0]=='B'){
			if(s[1]=='1'){
				
			}
			else if(s[1]=='2'){
				
			}
			else if(s[1]=='3'){
				
			}			
		}
		else if(s[0]=='C'){
			if(s[1]=='1'){
				
			}
			else if(s[1]=='2'){
				
			}
			else if(s[1]=='3'){
				if(n<=100&&m<=100){
//					dfs(1);
					vis[1]=true;
					minn=1000000000;
					find(1,0,0);
				}
			}			
		}
	}
	
	
	
	
	fclose(stdin);fclose(stdout);	
	return 0;
}


