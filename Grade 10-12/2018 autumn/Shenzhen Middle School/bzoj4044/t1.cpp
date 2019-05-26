#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
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
int n;char s[100010];
namespace pam{
	int last,cnt,dp[100010],fail[100010],len[100010],t[100010],ch[100010][4];
	inline int newnode(int w){
		cnt++;
		fail[cnt]=t[cnt]=ch[cnt][0]=ch[cnt][1]=ch[cnt][2]=ch[cnt][3]=0;
		dp[cnt]=len[cnt]=w;
//		cout<<"****newnode "<<cnt<<' '<<w<<'\n';
		return cnt;
	}
	void init(){
		s[0]=-1;cnt=-1;last=0;
		newnode(0);newnode(-1);fail[0]=1;
	}
	inline int getfail(int cur,int pos){
		while(s[pos-len[cur]-1]!=s[pos]) cur=fail[cur];
		return cur;
	}
	void insert(int x){
		int c,cur=getfail(last,x);
		if(s[x]=='A') c=0;
		if(s[x]=='C') c=1;
		if(s[x]=='G') c=2;
		if(s[x]=='T') c=3;
//		cout<<"insert "<<x<<' '<<c<<' '<<cur<<'\n';
		if(!ch[cur][c]){
			int now=newnode(len[cur]+2),z=cur;
			fail[now]=ch[getfail(fail[cur],x)][c];
			ch[cur][c]=now;
			if(len[now]<=2) t[now]=fail[now];
			else{
				z=t[z];
				while(s[x-len[z]-1]!=s[x]||(len[z]+2)*2>len[now]) z=fail[z];
				t[now]=ch[z][c];
			}
//			cout<<"	get t "<<now<<' '<<t[now]<<'\n';
		}
		last=ch[cur][c];
	}
	int DP(){
		queue<int>q;int i,u,v,ans=n;
//		cout<<"begin dp\n";
		q.push(0);dp[0]=1;
		while(!q.empty()){
			u=q.front();q.pop();
//			cout<<"bfs "<<u<<' '<<dp[u]<<' '<<len[u]<<'\n';
			for(i=0;i<4;i++){
				v=ch[u][i];
				if(!v) continue;
				dp[v]=min(dp[u]+1,dp[t[v]]+1+len[v]/2-len[t[v]]);
				ans=min(ans,dp[v]+n-len[v]);
				q.push(v);
			}
		}
		return ans;
	}
}
int main(){
	int T=read(),i;
	while(T--){
		scanf("%s",s+1);n=strlen(s+1);
		pam::init();
		for(i=1;i<=n;i++) pam::insert(i);
		printf("%d\n",pam::DP());
	}
}
