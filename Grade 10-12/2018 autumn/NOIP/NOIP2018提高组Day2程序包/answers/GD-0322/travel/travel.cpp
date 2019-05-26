#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
const int maxn=50005;
vector<int> a[maxn];
int ans[maxn],vis[maxn],fa[maxn],pos[maxn];
int n,m,flag,en=0;
inline void read(int &x){
	int w=0,X=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')w^=ch=='-',ch=getchar();
	while(ch>='0'&&ch<='9')X=(((X<<2)+X)<<1)+(ch^48),ch=getchar();
	x=w?-X:X;
	return;
}
inline void write(int x){
	if(x>9)write(x/10);
	putchar(x%10+'0');
	return;
}
inline void writeln(int x){
	if(x>9)write(x/10);
	putchar(x%10+'0');
	puts("");
	return;
}
int dfs(int x){
	priority_queue<int> q;
	if(!vis[x])vis[x]=1,ans[++flag]=x;
	pos[x]=flag;
	for(int i=0;i<a[x].size();i++){
		q.push(n-a[x][i]+1);
	}
	int tmp=0;
	for(int i=0;i<a[x].size();i++){
		if(!fa[n-q.top()+1])fa[n-q.top()+1]=x;
		if(!vis[n-q.top()+1])dfs(n-q.top()+1);
		else if(n-q.top()+1<fa[x]&&m==n&&!en){
			en=1;
			int i;
			for(i=pos[x];i>=pos[n-q.top()+1]+2;i--){
				if(ans[i-1]<x)tmp=i;
				if(tmp)continue;
				ans[i]=ans[i-1];
				pos[ans[i-1]]=i;
			}
			ans[tmp]=x;
		}
		q.pop();
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	memset(ans,0,sizeof(ans));
	memset(vis,0,sizeof(vis));
	read(n),read(m);
	int x,y;
	for(int i=1;i<=m;i++){
		read(x),read(y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	flag=0;
	fa[1]=1;
	dfs(1);
	for(int i=1;i<n;i++)write(ans[i]),putchar(' ');
	writeln(ans[n]);
	return 0;
}
