#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
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
int n;char s[5000010];
namespace pam{
	int last,cnt,fail[5000010],len[5000010],trans[5000010],ch[5000010][26];ll num[5000010],dp[5000010],ans[5000010];
	inline int newnode(int w){len[++cnt]=w;return cnt;}
	void init(){
		s[0]=-1;last=0;cnt=-1;fail[0]=1;
		newnode(0);newnode(-1);
	}
	inline int getfail(int cur,int pos){
		while(s[pos-len[cur]-1]!=s[pos]) cur=fail[cur];
		return cur;
	}
	inline void insert(int x){
		int c=s[x]-'a',cur=getfail(last,x);
		if(!ch[cur][c]){
			int now=newnode(len[cur]+2),tmp=trans[cur];
//			cout<<"newnode "<<now<<' '<<tmp<<' '<<len[now]<<'\n';
			fail[now]=ch[getfail(fail[cur],x)][c];
			ch[cur][c]=now;
			if(len[fail[now]]<=len[now]/2) trans[now]=fail[now];
			else{
				while(len[tmp]+2>len[now]/2||s[x-len[tmp]-1]!=s[x]) tmp=fail[tmp];
				trans[now]=ch[tmp][c];
			}
//			cout<<"gettrans "<<trans[now]<<'\n';
		}
		num[last=ch[cur][c]]++;
	}
	void solve(){
		int i;
		dp[0]=dp[1]=0;
		for(i=2;i<=cnt;i++){
			if(len[trans[i]]==len[i]/2) dp[i]=dp[trans[i]]+1;
			else dp[i]=1;
//			cout<<"dp "<<i<<' '<<len[i]<<' '<<dp[i]<<'\n';
		}
		for(i=cnt;i>=2;i--) num[fail[i]]+=num[i];
		for(i=2;i<=cnt;i++) ans[dp[i]]+=num[i];
		for(i=n-1;i>=1;i--) ans[i]+=ans[i+1];
		for(i=1;i<=n;i++) printf("%lld\n",ans[i]);
	}
}
int main(){
	scanf("%s",s+1);n=strlen(s+1);int i;
	pam::init();
	for(i=1;i<=n;i++) pam::insert(i);
	pam::solve();
}
