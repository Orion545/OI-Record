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
int n;char t1[500010],t2[500010],s[1000010];
namespace pam{
	int last,cnt,fail[1000010],len[1000010],ch[1000010][26],anc[1000010];
	int val[1000010],pos[1000010],tval[1000010],tpos[1000010];
	inline int newnode(int w){len[++cnt]=w;return cnt;}
	void init(){
		s[0]=-1;last=0;cnt=-1;fail[0]=1;
		newnode(0);newnode(-1);
		anc[0]=0;anc[1]=1;tval[0]=tval[1]=1e9;
	}
	inline int getfail(int cur,int pos){
		while(s[pos-len[cur]-1]!=s[pos]) cur=fail[cur];
		return cur;
	}
	inline void insert(int x){
		int c=s[x]-'a',cur=getfail(last,x);
		val[x]=1e9;
		if(!ch[cur][c]){
			int now=newnode(len[cur]+2);
			fail[now]=ch[getfail(fail[cur],x)][c];
			ch[cur][c]=now;
			anc[now]=((fail[now]>1&&len[now]-len[fail[now]]==len[fail[now]]-len[fail[fail[now]]])?anc[fail[now]]:now);
		}
		last=ch[cur][c];
		for(cur=ch[cur][c];cur>1;cur=fail[anc[cur]]){
			tval[cur]=val[x-len[anc[cur]]];
			tpos[cur]=x-len[anc[cur]];
//			cout<<"doing "<<x<<' '<<cur<<' '<<anc[cur]<<' '<<tval[cur]<<' '<<tpos[cur]<<'\n';
			if(anc[cur]!=cur&&tval[fail[cur]]<tval[cur]) tval[cur]=tval[fail[cur]],tpos[cur]=tpos[fail[cur]];
			if((x%2==0)&&(val[x]>tval[cur]+1)) val[x]=tval[cur]+1,pos[x]=tpos[cur];
		}
		if(x%2==0&&s[x-1]==s[x]&&val[x-2]<val[x]) val[x]=val[x-2],pos[x]=x-2;
//		cout<<"finish insert "<<x<<' '<<c<<' '<<val[x]<<' '<<pos[x]<<'\n';
	}
}
int main(){
	scanf("%s",t1+1);scanf("%s",t2+1);n=strlen(t1+1);int i;
	for(i=1;i<=n;i++){
		s[i*2-1]=t1[i];
		s[i*2]=t2[i];
	}
	using namespace pam;
	n<<=1;init();
	for(i=1;i<=n;i++) insert(i);
	if(val[n]==1e9) puts("-1");
	else{
		printf("%d\n",val[n]);
		for(i=n;i;i=pos[i]){
			if(i-pos[i]>2) printf("%d %d\n",(pos[i]>>1)+1,i>>1);
		}
	}
}
