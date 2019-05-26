#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<queue>
#define ll long long
#define MOD 1000000007
#define end DEEP_DARK_FANTASY
using namespace std;
inline ll read(){
	ll re=0,flag=1;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(isdigit(ch)) re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
ll ch[2010][10],fail[2010],cnt,end[2010],zero[2010];
char s[2010],t[2010];
void insert(char t[]){
	ll i,cur=0,tmp,len=strlen(t);
	for(i=len-1;i>=0;i--){
		tmp=t[i]-'0';
//		cout<<"insert "<<i<<' '<<tmp<<' '<<cur<<'\n';
		if(!ch[cur][tmp]) ch[cur][tmp]=++cnt;
		cur=ch[cur][tmp];
	}
	end[cur]=1;
	if(t[0]=='0') zero[cur]=1;
}
queue<ll>q;
void AC(){
	ll i,u,v;
	for(i=0;i<10;i++){
		if(!ch[0][i]) continue;
		q.push(ch[0][i]);fail[ch[0][i]]=0;
	}
	while(!q.empty()){
		u=q.front();q.pop();
//		cout<<"AC "<<u<<' '<<fail[u]<<'\n';
		for(i=0;i<10;i++){
			v=ch[u][i];
			if(!v) ch[u][i]=ch[fail[u]][i];
			else{
				fail[v]=ch[fail[u]][i];
				q.push(v);
				zero[v]|=zero[fail[v]];
				end[v]|=end[fail[v]];
			}
		}
	}
}
ll dp[2010][1510][2];
void dfs(ll u,ll re,ll lim){
	ll &cur=dp[u][re][lim],v,i;
//	cout<<"enter "<<u<<' '<<re<<' '<<lim<<' '<<cur<<'\n';
	if(~cur) return;
	if(end[u]){
		if(zero[u]) dp[u][re][0]=dp[u][re][1]=1;
		else dp[u][re][0]=dp[u][re][1]=0;
		if(!re) dp[u][re][1]=0;
//		cout<<"getend "<<u<<' '<<re<<' '<<zero[u]<<'\n';
		return;
	}
	if(!re){
		dp[u][re][0]=1;dp[u][re][1]=0;
//		cout<<"remain 0 "<<u<<' '<<re<<'\n';
		return;
	}
	cur=0;
	for(i=0;i<10;i++){
		v=ch[u][i];
		if(lim){
			if(i>=s[re-1]-'0'){
//				cout<<"to "<<v<<' '<<1<<" from "<<u<<' '<<re<<'\n';
				dfs(v,re-1,1);
				(cur+=dp[v][re-1][1])%=MOD;
			}
			else{
//				cout<<"to "<<v<<' '<<0<<" from "<<u<<' '<<re<<'\n';
				dfs(v,re-1,0);
				(cur+=dp[v][re-1][0])%=MOD;
			}
		}
		else{
			if(i>s[re-1]-'0'){
//				cout<<"to "<<v<<' '<<1<<" from "<<u<<' '<<re<<'\n';
				dfs(v,re-1,1);
				(cur+=dp[v][re-1][1])%=MOD;
			}
			else{
//				cout<<"to "<<v<<' '<<0<<" from "<<u<<' '<<re<<'\n';
				dfs(v,re-1,0);
				(cur+=dp[v][re-1][0])%=MOD;
			}
		}
	}
//	cout<<"dfs "<<u<<' '<<re<<' '<<lim<<' '<<cur<<'\n';
}
ll m,n;
int main(){
//	freopen("4.in","r",stdin);
	scanf("%s",s);n=strlen(s);ll i;
	m=read();
	for(i=1;i<=m;i++){
		scanf("%s",t);
		insert(t);
	}
	memset(dp,-1,sizeof(dp));
	AC();
	dfs(0,n,0);
	cout<<dp[0][n][0]-1<<'\n';
}

