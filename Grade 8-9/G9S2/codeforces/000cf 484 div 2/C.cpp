#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
inline int read(){
	int re=0,flag=1;char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
int first[100010],cnt;
struct edge{
	int to,next;
}a[500010];
inline void add(int u,int v){
	a[++cnt]=(edge){v,first[u]};first[u]=cnt;
	a[++cnt]=(edge){u,first[v]};first[v]=cnt;
}
int ans[100010],re[100010],siz[100010];
void dfs(int u,int f){
//	cout<<"dfs "<<u<<ends<<f<<endl;
	int i,v,tmp=0,cnt=0;re[u]=siz[u]=1;
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(v==f) continue;
		dfs(v,u);
		tmp+=re[v];siz[u]+=siz[v];cnt++;ans[u]+=ans[v];
	}
	re[u]=siz[u]%2;
	ans[u]+=cnt-tmp;
//	cout<<"return dfs "<<u<<ends<<ans[u]<<ends<<re[u]<<ends<<siz[u]<<endl;
	return;
}
int main(){
	memset(first,-1,sizeof(first));
	int n=read();int i,t1,t2;
	for(i=1;i<n;i++){
		t1=read();t2=read();
		add(t1,t2);
	}
	if(n%2){
		puts("-1");return 0;
	}
	dfs(1,0);
	printf("%d\n",ans[1]);
}
