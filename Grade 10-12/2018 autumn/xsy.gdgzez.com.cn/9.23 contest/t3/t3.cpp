#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
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
int n,m,tote,cnte,first[1010],in[1010];
struct edge{
	int to,next;
}a[5010];
inline void add(int u,int v){
	a[++cnte]=(edge){v,first[u]};first[u]=cnte;in[v]++;
}
int dp[1010][10],ch[1010][10],st;
set<int>s[20];
void DP(){
	int q[1010],head=0,tail=0,i,u,v,j;
	for(i=1;i<=n;i++) if(!in[i]) q[tail++]=i,st=i;
	while(head<tail){
		u=q[head++];
		if(n<=20) s[u].insert(u);
		for(i=1;i<=m;i++) dp[u][i]+=ch[u][i];
		for(i=first[u];~i;i=a[i].next){
			v=a[i].to;
			if(n<=20){
				for(auto kkk:s[u]) s[v].insert(kkk);
			}
			for(j=1;j<=m;j++) dp[v][j]+=dp[u][j];
			in[v]--;
			if(!in[v]) q[tail++]=v;
		}
	}
}
void cmp(int *l,int *r){
	int i;
	for(i=1;i<=m;i++){
		if(l[i]<r[i]){
			memcpy(l,r,sizeof(int)*10);return;
		}
		if(l[i]>r[i]) return;
	}
}
struct node{
	int s[10];
	inline bool operator <(const node &r)const{
		for(int i=1;i<=m;i++){
			if(s[i]!=r.s[i]) return s[i]>r.s[i];
		}
		return 0;
	}
	bool check(){
		int i;
		for(i=1;i<=m;i++) if(s[i]<0) return 0;
		return 1;
	}
}se[1010];
/*
static inline bool cmp(const node &l,const node r){
	for(int i=1;i<=m;i++){
		if(l.s[i]!=r.s[i]) return l.s[i]<r.s[i];
	}
	return 0;
}
*/
int main(){
	n=read();tote=read();m=read();int i,t1,t2,j,k;char str[10];
	memset(first,-1,sizeof(first));
	for(i=1;i<=n;i++){
		scanf("%s",str);
		for(j=1;j<=m;j++){
			if(str[j-1]=='+') ch[i][j]=1;
			if(str[j-1]=='-') ch[i][j]=-1;
			if(str[j-1]=='/') ch[i][j]=0;
		}
	}
	for(i=1;i<=tote;i++){
		t1=read();t2=read();
		add(t2,t1);
	}
	DP();
	if(n<=20){
		int ans[10]={0},tmp[10],vis[30];
		for(j=0;j<(1<<n);j++){
			memset(tmp,0,sizeof(tmp));
			memset(vis,0,sizeof(vis));
			for(i=1;i<=n;i++){
				if((1<<(i-1))&j)
					for(auto u:s[i]) vis[u]=1;
			}
			for(i=1;i<=n;i++) if(vis[i]){
				for(k=1;k<=m;k++) tmp[k]+=ch[i][k];
			}
			cmp(ans,tmp);
		}
		for(i=1;i<=m;i++) printf("%d ",1000+ans[i]);
		return 0;
	}
	if(tote==0){
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++) se[i].s[j]=ch[i][j];
		}
		sort(se+1,se+n+1);
//		for(i=1;i<=n;i++) cout<<i<<' '<<se[i].s[1]<<'\n';
		for(i=n;i>=1;i--){
			if(se[i].check()) break;
		}
		int ans[10]={0};
		for(j=1;j<=i;j++){
			for(k=1;k<=m;k++){
				ans[k]+=se[j].s[k];
			}
		}
		for(i=1;i<=m;i++) printf("%d ",1000+ans[i]);
		return 0;
	}
	if(tote==n-1){
		int ans[10]={0};
		for(i=1;i<=n;i++){
			cmp(ans,dp[i]);
		}
		for(i=1;i<=m;i++) printf("%d ",1000+ans[i]);
	}
}
