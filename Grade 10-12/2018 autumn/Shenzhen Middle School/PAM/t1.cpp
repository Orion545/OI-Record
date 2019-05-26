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
char s[300010];
int n;ll ans=0;
namespace pam{
	int fail[300010],num[300010],len[300010],ch[300010][26],last,cnt;
	inline int newnode(int w){len[++cnt]=w;return cnt;}
	void init(){
		s[0]=-1;cnt=-1;fail[0]=1;last=0;
		newnode(0);newnode(-1);
	}
	inline int getfail(int cur,int pos){
		while(s[pos-len[cur]-1]!=s[pos]) cur=fail[cur];
		return cur;
	}
	void insert(int x){
		int c=(s[x]-='a'),cur=getfail(last,x);
//		cout<<"insert "<<x<<' '<<c<<' '<<cur<<'\n';
		if(!ch[cur][c]){
			int now=newnode(len[cur]+2);
			fail[now]=ch[getfail(fail[cur],x)][c];
			ch[cur][c]=now;
		}
		num[last=ch[cur][c]]++;
	}
}
int main(){
	using namespace pam;
	scanf("%s",s+1);int i;
	n=strlen(s+1);
	init();
	for(i=1;i<=n;i++) insert(i);
	for(i=cnt;i>=1;i--){
		num[fail[i]]+=num[i];
		ans=max(ans,1ll*num[i]*len[i]);
	}
	cout<<ans<<'\n';
}
