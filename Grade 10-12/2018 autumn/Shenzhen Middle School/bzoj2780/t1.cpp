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
	int ch[200010][26],fa[200010],siz[200010],val[200010],vis[200010],root,cnt,last;
	void init(){root=cnt=last=1;val[1]=0;}
	inline int newnode(int w){val[++cnt]=w;return cnt;}
	void insert(int c,int num){
		int p=last,np=newnode(val[p]+1);
//		cout<<"insert "<<c<<' '<<p<<' '<<np<<'\n';
		for(;p&&!ch[p][c];p=fa[p]) ch[p][c]=np;
		if(!p) fa[np]=root;
		else{
			int q=ch[p][c];
			if(val[q]==val[p]+1) fa[np]=q;
			else{
				int nq=newnode(val[p]+1);
				memcpy(ch[nq],ch[q],sizeof(ch[q]));
				fa[nq]=fa[q];vis[nq]=vis[q];siz[nq]=siz[q];
				fa[q]=fa[np]=nq;
				for(;p&&ch[p][c]==q;p=fa[p]) ch[p][c]=nq;
			}
		}
		for(p=np;p;p=fa[p]){
			if(vis[p]<num) vis[p]=num,siz[p]++;
		}
		last=np;
	}
	int query(char *s,int len){
		int i,cur=root,c;
		for(i=0;i<len;i++){
			c=s[i]-'a';
			cur=ch[cur][c];
//			cout<<"query "<<s[i]<<' '<<cur<<' '<<siz[cur]<<'\n';
		}
		return siz[cur];
	}
}
int n,q,len;char s[400010];
int main(){
	n=read();q=read();int i,j;
	sam::init();
	for(i=1;i<=n;i++){
		scanf("%s",s);len=strlen(s);sam::last=1;
		for(j=0;j<len;j++) sam::insert(s[j]-'a',i);
	}
	for(i=1;i<=q;i++){
		scanf("%s",s);len=strlen(s);
		printf("%d\n",sam::query(s,len));
	}
}
