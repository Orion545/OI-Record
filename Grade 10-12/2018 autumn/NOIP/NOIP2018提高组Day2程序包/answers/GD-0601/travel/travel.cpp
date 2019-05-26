#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>
#include<vector>
#define maxn 5005
//我相信暴力出奇迹！！！ 
using namespace std;
inline void read(int &x){
	x=0;int f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
int N,M;
struct node{
	int nex,to;
}edge[maxn<<1];
int head[maxn],tot;
inline void insert(int from,int to){
	edge[++tot].nex=head[from];
	head[from]=tot;
	edge[tot].to=to;
}
int dfn[maxn],id;
bool vis[maxn];
void dfs(int x,int u){
	vis[x]=1;
	int arr[maxn],tp;
	dfn[++id]=x;
	tp=0;
	for(int i=head[x];i;i=edge[i].nex)
		if(edge[i].to^u)
			arr[++tp]=edge[i].to;
	
	sort(arr+1,arr+tp+1);
	for(int i=1;i<=tp;i++){
		if(!vis[arr[i]])
			dfs(arr[i],x);
	}	
}

int dept[maxn],fa[maxn];
int du,dv;
int nu,nv;
int s[maxn];
int mas[maxn];
void dfs2(int x,int u){
	//cout<<"dfs 2 note:"<<x<<" "<<u<<endl;
	dept[x]=u+1;
	fa[x]=u;
	for(int i=head[x];i;i=edge[i].nex){
		if(edge[i].to!=u){
			if(dept[edge[i].to]){
				du=edge[i].to;
				dv=x;
				return ;
			}
			dfs2(edge[i].to,x);
		}
	}
}
void dfs3(int x,int u){
	int arr[maxn],tp;
	s[id++]=x;
	tp=0;
	for(int i=head[x];i;i=edge[i].nex)
		if(edge[i].to^u)
			arr[++tp]=edge[i].to;
	sort(arr+1,arr+tp+1);
	//for(int i=1;i<=tp;i++)
	//	cout<<arr[i]<<" ";
	//cout<<endl;
	//cout<<"dfs :"<<x<<" "<<u<<endl;
	for(int i=1;i<=tp;i++){
		if((!(x==nv&&arr[i]==nu))&&(!(x==nu&&arr[i]==nv)))
			dfs3(arr[i],x);
	//	else
			//cout<<"error"<<x<<" "<<arr[i]<<endl;
	}	
}
bool check(){
	for(int i=0;i<N;i++){
		if(s[i]<mas[i])
			return true;
		if(s[i]>mas[i])
			return false;
	}
	return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	read(N);read(M);
	int u,v;
	for(int i=1;i<=M;i++){
		read(u);read(v);
		insert(u,v);
		insert(v,u);
	}
	if(N==M+1){
		dfs(1,1);
		for(int i=1;i<=N;i++)
			printf("%d ",dfn[i]);
	}
	else{
		dfs2(1,1);
		nu=du;nv=dv;
		//cout<<du<<" "<<dv<<endl;
		dfs3(1,1);
		for(int i=0;i<N;i++){
			mas[i]=s[i];
			//cout<<mas[i]<<" ";
		}
		//cout<<endl;
		while(du!=dv){
			if(dept[du]<dept[dv])
				swap(du,dv);
			nu=du,nv=fa[du];
			//cout<<du<<" "<<dv<<" "<<nu<<" "<<nv<<endl;
			id=0;
			dfs3(1,1);
			if(check())
				for(int i=0;i<N;i++){
				mas[i]=s[i];
				//cout<<mas[i]<<" ";
			}
			du=fa[du];
		}
		for(int i=0;i<N;i++)
			printf("%d ",mas[i]);
	}
	
	
}
/*
6 5
1 3
2 3
2 5
3 4
4 6

6 6
1 3
2 3
2 5
3 4
4 5
4 6
*/
