#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
inline int read(){
	int x=0,f=1;
	char s=getchar();
	while (s<'0'or s>'9'){if (s=='-')f=-1;s=getchar();}
	while (s>='0'and s<='9'){x=(x<<3)+(x<<1)+s-'0';s=getchar();	}
	return x*f;
}
const int N=100010;
const int M=200010;
int he[N],to[M],next[M];
int edge;
void add(int u,int v){
	to[++edge]=v,next[edge]=he[u],he[u]=edge;
	to[++edge]=u,next[edge]=he[v],he[v]=edge;
}
bool vis[N];
vector <int>head[N];
int w1[N],w2[N];
void maketree(int u){
	if (vis[u])return;
	vis[u]=1;
	for (int i=he[u];i;i=next[i]){
		if (vis[to[i]])continue;
		head[u].push_back(to[i]);
		maketree(to[i]);
	}
	return;
}
int vis2[N];
int w[N];
void dfs(int u,bool zhu){
	if (head[u].size()==0){
//		cout<<u<<" di"<<endl;
		w1[u]=w[u];
		w2[u]=0;
		return;
	}
	w1[u]=w[u];
	for (int i=0;i<head[u].size();i++){
		if (vis2[u]=1){
			dfs(head[u][i],1);
		}else dfs(head[u][i],0);
		w2[u]+=w1[head[u][i]];
		w1[u]+=min(w1[head[u][i]],w2[head[u][i]]);
	}
//	if (zhu){
//		w2[u]=w1[u];
//	}
//	if (vis2[u]=2)w2[u]=w1[u];
}
int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
//freopen("defense1.in","r",stdin);
	string as;
	int n,m;
	n=read();
	m=read();
	cin>>as;
	int u,v,a,b;
	for (int i=1;i<=n;i++)w[i]=read();
	for (int i=1;i<=n-1;i++){
		u=read(),v=read();
		add(u,v);
	}
	maketree(1);
//	cout<<"finish"<<endl;
//	for (int i=1;i<=n;i++){
//		if (head[i].size()==0)continue;
//		for (int j=0;j<head[i].size();j++){
//			cout<<i<<" "<<head[i][j]<<endl;
//		}
//	}
	int flag=0;
	for (int i=1;i<=m;i++){
		u=read(),a=read(),v=read(),b=read();
		flag=0;
		if (a==b and a==0){
			for (int j=he[u];j;j=next[j]){
				if (to[j]==v){
					printf("-1\n");
					flag=1;
					break;
				}
			}
			if (flag)continue;
		}
		memset(w1,0,sizeof(w1));
		memset(w2,0,sizeof(w2));
//		for (int i2=1;i2<=n;i2++)cout<<w1[i2]<<" ";
//		cout<<endl;
//		for (int i2=1;i2<=n;i2++)cout<<w2[i2]<<" ";
//		cout<<endl;
		vis2[u]=a+1,vis2[v]=b+1;
//		if (a+1=1)
		if (vis2[1]=1)dfs(1,1);
		else dfs(1,0);
//		dfs(1,0);
//		for (int i2=1;i2<=n;i2++)cout<<w1[i2]<<" ";
//		cout<<endl;
//		for (int i2=1;i2<=n;i2++)cout<<w2[i2]<<" ";
		printf ("%d\n",min(w1[1],w2[1]));
		vis2[u]=0,vis2[v]=0;
	}
	return 0;
}

