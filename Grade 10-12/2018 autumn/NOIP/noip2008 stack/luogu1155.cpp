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
#include<cmath>
#include<stack>
#include<queue>
#define ll long long
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
int n,a[1010],suf[1010],w[1010][1010];
queue<int>q;int vis[1010];
int bfs(int i){
	int u,v;
	q.push(i);vis[i]=2;
	while(!q.empty()){
		u=q.front();q.pop();
		for(v=1;v<=n;v++){
			if(!w[u][v]) continue;
			if(vis[u]==vis[v]) return 0;
			if(!vis[v]){
				vis[v]=vis[u]^1;
				q.push(v);
			}
		}
	}
	return 1;
}
stack<int>s1,s2;
int main(){
//	freopen("in.in","r",stdin);
	n=read();int i,j,cur=0;
	for(i=1;i<=n;i++) a[i]=read();
	suf[n+1]=1e9;
	for(i=n;i>=1;i--) suf[i]=min(suf[i+1],a[i]);
	for(i=1;i<=n;i++){
		for(j=i+1;j<=n;j++){
			if(a[i]>a[j]) continue;
			if(suf[j+1]>=a[i]) continue;
//			cout<<"getpair "<<i<<' '<<j<<'\n';
			w[i][j]=w[j][i]=1;
		}
	}
	for(i=1;i<=n;i++){
		if(vis[i]) continue;
		if(!bfs(i)){puts("0");return 0;}
	}
	for(i=1;i<=n;i++){
		if(vis[i]==2){
			if(!s1.empty()&&s1.top()<a[i]){
				while(!s2.empty()&&!s1.empty()&&s2.top()<s1.top()){
					printf("d ");
					cur=s2.top();s2.pop();
				}
			}
			while(!s1.empty()&&s1.top()<a[i]){
				printf("b ");
				cur=s1.top();s1.pop();
			}
			s1.push(a[i]);printf("a ");
		}
		else{
			while(!s2.empty()&&s2.top()==cur+1){
				printf("d ");
				cur++;s2.pop();
			}
			while(!s1.empty()&&s1.top()==cur+1){
				printf("b ");
				cur++;s1.pop();
			}
			s2.push(a[i]);printf("c ");
		}
	}
	while(!(s1.empty()||s2.empty())){
		cur=min(s1.top(),s2.top());
		if(cur==s1.top()){
			printf("b ");
			s1.pop();
		}
		else{
			printf("d ");
			s2.pop();
		}
	}
	while(!s1.empty()) printf("b "),s1.pop();
	while(!s2.empty()) printf("d "),s2.pop();
}
