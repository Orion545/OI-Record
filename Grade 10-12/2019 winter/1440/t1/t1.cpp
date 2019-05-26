#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#define last DEEP_DARK_FANTASY
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
int n,s[500010],pl=250000,pr=250000;
namespace pam{
	int ch[400010][10],len[400010],fail[400010],num[400010],dep[400010],cnt,last[2];
	inline int newnode(int l){len[++cnt]=l;return cnt;}
	inline void init(){
		cnt=-1;fail[0]=1;
		last[0]=last[1]=0;
		dep[0]=dep[1]=0;
		newnode(0);newnode(-1);
	}
	inline int getfail(int cur,int pos,int d){
		if(d==0) d=-1;
		while(s[pos-len[cur]*d-d]!=s[pos]) cur=fail[cur];
//		cout<<"		finish getfail "<<cur<<' '<<len[cur]<<' '<<pos<<' '<<s[pos]<<' '<<s[pos-len[cur]-1]<<'\n';
		return cur;
	}
	inline int insert(int c,int d){
		if(d) s[pr++]=c+1;
		else s[--pl]=c+1;
//		cout<<"insert "<<c<<' '<<d<<' '<<pl<<' '<<pr<<' '<<s[d?(pr-1):pl]<<' '<<last[d]<<'\n';
		int cur=getfail(last[d],d?(pr-1):pl,d);
		if(!ch[cur][c]){
			int now=newnode(len[cur]+2);
			fail[now]=ch[getfail(fail[cur],d?(pr-1):pl,d)][c];
			dep[now]=dep[fail[now]]+1;
//			cout<<"	newnode "<<now<<' '<<len[now]<<' '<<fail[now]<<' '<<dep[now]<<'\n';
			ch[cur][c]=now;
		}
		num[last[d]=ch[cur][c]]++;
		if(len[last[d]]==pr-pl) last[d^1]=last[d];
		return dep[last[d]];
	}
}
int main(){
	n=read();char d[10],v[10];ll ans=0,tmp;
	pam::init();
	while(n--){
		scanf("%s%s",d,v);
		tmp=pam::insert(v[0]-'a',d[0]=='r');
		printf("%lld %d\n",(ans+=tmp),pam::cnt-1);
	}
}
