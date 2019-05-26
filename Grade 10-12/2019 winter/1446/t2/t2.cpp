#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<queue>
#define MOD 998244353
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
int n,m;char s[110];
namespace AC{
	int ch[100010][2],st[100010],cnt=0,fa[100010],fail[100010],num[100010];
	inline void insert(int sta){
//		cout<<"insert "<<sta<<' '<<s<<'\n';
		int i,cur=0,len=strlen(s),tmp;
		for(i=0;i<len;i++){
			tmp=s[i]-'0';
			if(!ch[cur][tmp]){
				ch[cur][tmp]=++cnt;
				fa[cnt]=cur;
				num[cnt]=tmp;
			}
			cur=ch[cur][tmp];
		}
		st[cur]|=sta;
	}
	queue<int>q;
	inline void bfs(){
		int i,u;
		for(i=0;i<2;i++){
			if(ch[0][i]) fail[ch[0][i]]=0,q.push(ch[0][i]);
		}
		while(!q.empty()){
			u=q.front();q.pop();
			st[u]|=st[fail[u]];
//			cout<<"bfs "<<u<<' '<<fail[u]<<' '<<st[u]<<' '<<cnt<<'\n';
			for(i=0;i<2;i++){
				if(!ch[u][i]) ch[u][i]=ch[fail[u]][i];
				else fail[ch[u][i]]=ch[fail[u]][i],q.push(ch[u][i]);
			}
		}
	}
	inline int query(int u){
		int re=0;
		for(int v=u;v;v=fa[v]){
			u=ch[u][num[v]^1];
			re|=st[u];
		}
		return re;
	}
}
int dp[2][2110][110];
inline void add(int &a,int b){
	a+=b;
	if(a>=MOD) a-=MOD;
}
int main(){
	n=read();m=read();int i,j,k,st,l;
	for(i=0;i<n;i++){
		scanf("%s",s);
//		cout<<"read in "<<i<<' '<<n<<' '<<s<<'\n';
		AC::insert(1<<i);
		l=strlen(s);
		reverse(s,s+l);
		for(j=0;j<l;j++) s[j]=((s[j]-'0')^1)+'0';
		AC::insert(1<<i);
	}
	AC::bfs();int cur=0,pre=1;dp[cur][0][0]=1;
	for(i=1;i<=m;i++){
		swap(cur,pre);
		memset(dp[cur],0,sizeof(dp[cur]));
		for(j=0;j<=AC::cnt;j++){
			for(st=0;st<(1<<n);st++){
				for(k=0;k<2;k++){
					add(dp[cur][AC::ch[j][k]][st|AC::st[j]],dp[pre][j][st]);
//					cout<<"dp "<<AC::ch[j][k]<<' '<<(st|AC::st[j])<<' '<<dp[cur][AC::ch[j][k]][st|AC::st[j]]<<'\n';
				}
			}
		}
	}
	int ans=0;
	for(i=0;i<=AC::cnt;i++){
		j=AC::query(i);
		for(st=0;st<(1<<n);st++){
			if((st|j)==(1<<n)-1) add(ans,dp[cur][i][st]);
		}
//		cout<<"query "<<i<<' '<<j<<' '<<ans<<'\n';
	}
	cout<<ans<<'\n';
}
