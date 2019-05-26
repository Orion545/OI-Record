#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
using namespace std;
#define N 5050
#define ll long long
struct E{int to,nxt;}le[N<<1];
ll n,m,T,u,v,cnt,tot,j;
ll s[N],fst[N],ans[N],used[N];
void rd(ll &x){
	static char ch;ll F=1;
	while(!isdigit(ch=getchar()))if(ch=='-')F=-1;
	for(x=0;isdigit(ch);ch=getchar())x=x*10+ch-'0';
}
void rd(int &x){
	static ll T_T;
	rd(T_T);x=T_T;
}
void dfs(int u,int F){
	int v;
	priority_queue<int,vector<int>,greater<int> > q;
	used[u]=1;
	s[++cnt]=u;
	for(int now=fst[u];now;now=le[now].nxt)if((now+1)/2!=T){
		v=le[now].to;
		if(v==F||used[v])continue;
		q.push(v);
	}
	while(!q.empty()){
		dfs(q.top(),u);
		q.pop();
	}
	used[u]=0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	rd(n),rd(m);
	if(m==n-1){
		T=-1;
		for(int i=1;i<n;++i){
			rd(u),rd(v);
			le[++tot]=(E){v,fst[u]},fst[u]=tot;
			le[++tot]=(E){u,fst[v]},fst[v]=tot;
		}
		dfs(1,0);
		for(int i=1;i<n;++i)printf("%lld ",s[i]);
		printf("%lld\n",s[n]);
	}
	else{
		for(int i=1;i<=n;++i){
			rd(u),rd(v);
			le[++tot]=(E){v,fst[u]},fst[u]=tot;
			le[++tot]=(E){u,fst[v]},fst[v]=tot;
		}
		for(int i=1;i<=n;++i)ans[i]=n;
		for(T=1;T<=n;++T){
			cnt=0;
			dfs(1,0);
			if(cnt==n){
				for(j=1;j<=n;++j){
					if(ans[j]==s[j])continue;
					if(ans[j]<s[j]){j=n+1;break;}
					if(ans[j]>s[j])break;
				}
				while(j<=n)ans[j]=s[j],++j;
			}
		}
		for(int i=1;i<n;++i)printf("%lld ",ans[i]);
		printf("%lld\n",ans[n]);
	}
	fclose(stdin);fclose(stdout);
}
