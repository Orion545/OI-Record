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
	int last,cnt,fail[5000010],len[5000010],ch[5000010][2];
	inline int newnode(int w){len[++cnt]=w;return cnt;}
	void init(){
		s[0]=-1;last=0;cnt=-1;fail[0]=1;
		newnode(0);newnode(-1);
	}
	inline int getfail(int cur,int pos){
		while(s[pos-len[cur]-1]!=s[pos]) cur=fail[cur];
		return cur;
	}
	inline int insert(int x){
		int c=s[x]-'a',cur=getfail(last,x);
		if(!ch[cur][c]){
			int now=newnode(len[cur]+2);
			fail[now]=ch[getfail(fail[cur],x)][c];
			ch[cur][c]=now;
			putchar('1');
		}
		else putchar('0');
		last=ch[cur][c];
	}
}
int main(){
	scanf("%s",s+1);n=strlen(s+1);int i;
	pam::init();
	for(i=1;i<=n;i++) pam::insert(i);
	putchar('\n');
}
