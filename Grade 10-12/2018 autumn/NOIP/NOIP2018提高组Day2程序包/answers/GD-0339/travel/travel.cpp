#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>
#include<stack>
#define N 6010
#define inf 99999999
using namespace std;
inline int read(){
	int x=0,flag=1;
	char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') flag=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+(ch^'0');
	return x*flag;
}
int head[N],to[N*2],nxt[N*2],idx[N*2],E[N][2],in[N];
int eCnt,n,m,tag[N],p[N],ans[N],tot;
bool vis[N],del[N],r[N],h[N];
queue <int> q;
inline void add(int u,int v,int i){
	eCnt++;
	nxt[eCnt]=head[u];
	idx[eCnt]=i;
	to[eCnt]=v;
	head[u]=eCnt;
}
void DFS(int x){
	vis[x]=true;
	tag[x]=++tot;
	vector<int> s;
	for(int i=head[x];i;i=nxt[i]){
		int y=to[i];
		if(vis[y]||h[idx[i]])
			continue;
		s.push_back(y);
	}
	sort(s.begin(),s.end());
	for(int i=0;i<s.size();i++)
		DFS(s[i]);
	vis[x]=false;
}
void Topo(){
	for(int i=1;i<=n;i++){
		if(in[i]==1)
			q.push(i);
	}
	while(!q.empty()){
		int x=q.front();
		del[x]=true;
		q.pop();
		for(int i=head[x];i;i=nxt[i]){
			int y=to[i];
			if(del[y])
				continue;
			in[x]--,in[y]--;
			if(in[y]==1)
				q.push(y);
		}
	}
}
inline void cmp(){
	for(int i=1;i<=n;i++){
		if(p[i]>ans[i])
			return;
		if(p[i]<ans[i])
			break;
	}
	for(int i=1;i<=n;i++)
		ans[i]=p[i];
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=m;i++){
		int u,v;
		u=read(),v=read();
		add(u,v,i);
		add(v,u,i);
		E[i][0]=u;
		E[i][1]=v;
		in[u]++;
		in[v]++;
	}
	if(m==n-1){
		DFS(1);
		for(int i=1;i<=n;i++)
			p[tag[i]]=i;
		for(int i=1;i<=n;i++){
			printf("%d ",p[i]);
		}
	}
	else{
		for(int i=1;i<=n;i++)
			ans[i]=n;
		Topo();
		for(int i=1;i<=n;i++){
			if(in[i])
				r[i]=true;
		}
		for(int i=1;i<=m;i++){
			tot=0;
			if(r[E[i][0]]&&r[E[i][1]]){
				for(int j=1;j<=n;j++)
					tag[j]=0;
				h[i]=true;
				DFS(1);
				h[i]=false;
				bool b=true;
				for(int j=1;j<=n;j++){
					if(tag[j]==0)
						b=false;
					p[tag[j]]=j;
				}
				if(b)
					cmp();
			}
		}
		for(int i=1;i<=n;i++)
			printf("%d ",ans[i]);
	}
	return 0;
}
