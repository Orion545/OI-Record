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
int n;
namespace sam{
	int ch[2000010][26],fa[2000010],val[2000010],siz[2000010],cnt,last,root;
	void init(){cnt=last=root=1;val[1]=0;}
	inline int newnode(int w){val[++cnt]=w;return cnt;}
	void insert(int c){
		int p=last,np=newnode(val[p]+1);siz[np]=1;
		for(;p&&!ch[p][c];p=fa[p]) ch[p][c]=np;
		if(!p) fa[np]=root;
		else{
			int q=ch[p][c];
			if(val[q]==val[p]+1) fa[np]=q;
			else{
				int nq=newnode(val[p]+1);
				memcpy(ch[nq],ch[q],sizeof(ch[q]));
				fa[nq]=fa[q];
				fa[q]=fa[np]=nq;
				for(;p&&ch[p][c]==q;p=fa[p]) ch[p][c]=nq;
			}
		}
		last=np;
	}
	int book[2000010],lis[2000010],vis[2000010];
	void sort(){
		int i;
		for(i=0;i<=n;i++) book[i]=0;
		for(i=1;i<=cnt;i++) book[val[i]]++;
		for(i=1;i<=n;i++) book[i]+=book[i-1];
		for(i=1;i<=cnt;i++) lis[book[val[i]]--]=i;
		for(i=cnt;i>=1;i--) siz[fa[lis[i]]]+=siz[lis[i]];
	}
	int query(char *s,int llen,int curq){
		int i,cur=root,c,len=llen*2-1,curlen=0,ans=0;
//		cout<<"query "<<s<<' '<<len<<' '<<llen<<'\n';
		for(i=0;i<len;i++){
			c=s[i]-'a';
			if(ch[cur][c])
				cur=ch[cur][c],curlen++;
			else{
				while(cur&&!ch[cur][c]) cur=fa[cur];
				if(!cur) cur=root,curlen=0;
				else curlen=val[cur]+1,cur=ch[cur][c];
			}
			if(curlen<llen||i<llen-1) continue;
			for(;val[fa[cur]]>=llen;cur=fa[cur]);
			if(vis[cur]<curq) vis[cur]=curq,ans+=siz[cur];
//			cout<<"	query "<<i<<' '<<s[i]<<' '<<cur<<' '<<siz[cur]<<' '<<ans<<'\n';
		}
		return ans;
	}
}
char s[2000010];
int main(){
	scanf("%s",s);n=strlen(s);
	int i,len,q=read(),j;
	sam::init();
	for(i=0;i<n;i++) sam::insert(s[i]-'a');
	sam::sort();
	memset(s,0,sizeof(s));
	for(j=1;j<=q;j++){
		scanf("%s",s);
		len=strlen(s);
//		cout<<"input "<<s<<' '<<len<<'\n';
		for(i=0;i<len-1;i++) s[i+len]=s[i];
//		cout<<"repeat "<<s<<'\n';
		printf("%d\n",sam::query(s,len,j));
	}
}
