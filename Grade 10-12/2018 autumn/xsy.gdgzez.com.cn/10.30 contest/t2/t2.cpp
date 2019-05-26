/*

宣告——
汝身听吾号令，托付吾之命运于汝之剑，
应圣杯之召，若汝遵从此意志此理，回应吧。
在此起誓，吾愿成就世间一切之善行，吾愿诛尽世间一切之恶行。
汝为身缠三大言灵之七天，从抑止之轮显现吧，天秤之守护者！

*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<vector>
using namespace std;
inline int read(){
	int re=0,flag=1;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(isdigit(ch)) re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
int n,m,spd,first[50010],cnte,ans=0;
struct edge{
	int to,next;
}a[100010];
int x[50010],vis[50010],dep[50010],pr[50010],fa[50010];
inline void add(int u,int v){
	a[++cnte]=(edge){v,first[u]};first[u]=cnte;
	a[++cnte]=(edge){u,first[v]};first[v]=cnte;
}
int dfs(int u,int f){
	int i,v,cur=(x[u]?u:0),tmp;vis[u]=1;
	dep[u]=dep[f]+1;fa[u]=f;
//	cout<<"begin dfs "<<u<<' '<<f<<' '<<cur<<'\n';
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(vis[v]) continue;
		tmp=dfs(v,u);
		if(!tmp) continue;
		if(!cur) cur=tmp;
		else{
//			cout<<"getpair "<<tmp<<' '<<cur<<'\n';
			pr[tmp]=cur;pr[cur]=tmp;
			cur=0;ans++;
		}
	}
//	cout<<"end dfs "<<u<<' '<<f<<' '<<cur<<'\n';
	return cur;
}
vector<int>le,ri;
int main(){
	memset(first,-1,sizeof(first));
	n=read();m=read();spd=read();int i,j,t1,t2;
	for(i=1;i<=m;i++){
		t1=read();t2=read();
		add(t1,t2);
	}
	for(i=1;i<=spd;i++) t1=read(),x[t1]=1;
	for(i=1;i<=n;i++) if(!vis[i]) dfs(i,0);
	printf("%d\n",ans);
	for(i=1;i<=n;i++){
//		cout<<i<<' '<<pr[i]<<'\n';
		if(!pr[i]||pr[i]<i) continue;
		t1=i;t2=pr[i];
		while(t1!=t2){
//			cout<<"	check "<<t1<<' '<<t2<<'\n';
			if(dep[t1]<dep[t2]) ri.push_back(t2),t2=fa[t2];
			else le.push_back(t1),t1=fa[t1];
		}
		le.push_back(t1);
		for(j=ri.size()-1;j>=0;j--) le.push_back(ri[j]);
		printf("%d",(int)le.size()-1);
		for(j=0;j<le.size();j++) printf(" %d",le[j]);
		puts("");
		le.clear();ri.clear();
	}		
}

