#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<stack>
#define maxn 5005
using namespace std;
int n,m;
vector<int>G[maxn];
bool vis[maxn];
int xl[maxn],cnt=0;//序列 
inline void dfs(int x){
	xl[++cnt]=x;
	for(int i=0;i<G[x].size();++i){
		int v=G[x][i];
		if(!vis[v]){
			vis[v]=1;
			dfs(v);
		}
	}
}
stack<int>zh;
bool inzh[maxn],finded;
bool incir[maxn];
int cir[maxn],circnt,fa[maxn];
inline void findcir(int x,int f){
	fa[x]=f;
	zh.push(x);
	inzh[x]=1;
	for(int i=0;i<G[x].size();++i){
		int v=G[x][i];
		if(v!=f){
			if(inzh[v]){
				for(;;){
					int y=zh.top();
					zh.pop();
					incir[y]=1;
					cir[++circnt]=y;
					if(y==v)break;
				}
				finded=1;
				return;
			}
			findcir(v,x);
			if(finded)return;
		}
	}
	zh.pop();
	inzh[x]=0;
}
bool line[maxn];
void inidfs(int x){
	xl[++cnt]=x;
	for(int i=0;i<G[x].size();++i){
		int v=G[x][i];
		if(!vis[v]){
			if(!line[v]&&!incir[v]){
				vis[v]=1;
				inidfs(v);
			}
		}
	}
	if(x==cir[circnt])return;//不能入环 
	for(int i=0;i<G[x].size();++i){
		int v=G[x][i];
		if(!vis[v]){
			vis[v]=1;
			inidfs(v);//v is lined
		}
	}
}
inline void dfss(int x){
	xl[++cnt]=x;
	for(int i=0;i<G[x].size();++i){
		int v=G[x][i];
		if(!vis[v]&&!incir[v]){
			vis[v]=1;
			dfss(v);
		}
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;++i){
		int a,b;
		scanf("%d%d",&a,&b);
		G[a].push_back(b);
		G[b].push_back(a);
	}
	for(int i=1;i<=n;++i)sort(G[i].begin(),G[i].end());
	if(m==n-1){
		vis[1]=1;
		dfs(1);
		for(int i=1;i<=cnt;++i)printf("%d ",xl[i]);
	}else{//jihuanshu
		findcir(1,0);
		//cir[circnt]是点1的接入点
		int x=cir[circnt];
		while(x){
			line[x]=1;//在特殊链上 
			x=fa[x];
		}
		vis[1]=1;
		inidfs(1);
		int l=circnt-1,r=1,last=circnt,fx=0;
		while(l!=r){
			if(cir[l]<cir[r]){
				last=l;
				fx=-1;
				vis[cir[l]]=1;
				dfss(cir[l]);
				l=(l-2+circnt)%circnt+1;
			}else{
				last=r;
				fx=1;
				vis[cir[r]]=1;
				dfss(cir[r]);
				r=r%circnt+1;
			}
			if((l+1)%circnt!=0&&r-1!=0)break;
		}
		while(l!=r){
			if(fx==1){
				vis[cir[r]]=1;
				dfss(cir[r]);
				r++;
			}else{
				vis[cir[l]]=1;
				dfss(cir[l]);
				l=(l-2+circnt)%circnt+1;
			}
		}
		vis[cir[r]]=1;
		dfss(cir[r]);
		for(int i=1;i<=cnt;++i)printf("%d ",xl[i]);
	}
	return 0;
}
