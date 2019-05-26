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
namespace sam{
	int ch[2000010][26],fa[2000010],val[2000010],s[2000010],lis[2000010],book[2000010],root,cnt;
	void init(){root=cnt=1;val[1]=0;}
	inline int newnode(int w){val[++cnt]=w;return cnt;}
	int insert(int c,int last,int ss){
		int p=last,np=newnode(val[p]+1);s[np]=ss;
		for(;p&&!ch[p][c];p=fa[p]) ch[p][c]=np;
		if(!p) fa[np]=root;
		else{
			int q=ch[p][c];
			if(val[q]==val[p]+1) fa[np]=q;
			else{
				int nq=newnode(val[p]+1);
				memcpy(ch[nq],ch[q],sizeof(ch[q]));
				fa[nq]=fa[q];s[nq]=s[q];
				fa[np]=fa[q]=nq;
				for(;p&&ch[p][c]==q;p=fa[p]) ch[p][c]=nq;
			}
		}
		return np;
	}
	void sort(int n){
		int i;
		for(i=1;i<=cnt;i++) book[val[i]]++;
		for(i=1;i<=n;i++) book[i]+=book[i-1];
		for(i=cnt;i>=1;i--) lis[book[val[i]]--]=i;
		for(i=cnt;i>=1;i--){
//			cout<<"sort finish "<<i<<' '<<lis[i]<<' '<<s[lis[i]]<<' '<<val[lis[i]]<<'\n';
			s[fa[lis[i]]]|=s[lis[i]];
		}
	}
}
namespace trie{
	int ch[2000010][26],fa[2000010],s[2000010],cnt;
	void insert(char *str,int len,int ss){
		int i,cur=0,c;
		for(i=0;i<len;i++){
			if(str[i]=='<') cur=fa[cur];
			else{
				c=str[i]-'a';
				if(!ch[cur][c]) ch[cur][c]=++cnt,fa[cnt]=cur;
				cur=ch[cur][c];
			}
			s[cur]|=ss;
//			cout<<"trie insert "<<str[i]<<' '<<cur<<' '<<s[cur]<<'\n';
		}
	}
	int q[2000010],head=0,tail=1,vis[2000010];
	void bfs(){
		int i,u,v;head=0,tail=1;
		vis[0]=1;q[0]=0;
		while(head<tail){
			u=q[head++];
			for(i=0;i<26;i++){
				v=ch[u][i];if(!v) continue;
				vis[v]=sam::insert(i,vis[u],s[v]);
				q[tail++]=v;
			}
		}
	}
}
int n,q,len,ans[1100010];char s[2000010];
void pre(){
	int i,j,maxl=0;
	n=read();
	for(i=1;i<=n;i++){
		scanf("%s",s);len=strlen(s);maxl=max(maxl,len);
		trie::insert(s,len,1<<(i-1));
	}
	sam::init();trie::bfs();sam::sort(maxl);
	for(i=1;i<=sam::cnt;i++) ans[sam::s[i]]=max(ans[sam::s[i]],sam::val[i]);
	for(i=(1<<n)-1;i>0;i--){
		for(j=0;j<n;j++){
			if(i&(1<<j)) ans[i^(1<<j)]=max(ans[i^(1<<j)],ans[i]);
		}
//		cout<<"getans "<<i<<' '<<ans[i]<<'\n';
	}
}
int main(){
	pre();char ss[110];int x,i;q=read();;
	while(q--){
		scanf("%s",ss);x=0;
		for(i=0;i<n;i++) x|=((ss[i]=='1')<<i);
//		cout<<"readin query "<<x<<'\n';
		printf("%d\n",ans[x]);
	}
}
