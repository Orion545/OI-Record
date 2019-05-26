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
int q,mask;char s[3000010];
namespace sam{
	int ch[3000010][10],val[3000010],fa[3000010],siz[3000010],root,last,cnt;
	void init(){root=last=cnt=1;val[1]=0;}
	int newnode(int w){val[++cnt]=w;return cnt;}
	void insert(int c){
		int p=last,np=newnode(val[p]+1);
		for(;p&&!ch[p][c];p=fa[p]) ch[p][c]=np;
		if(!p) fa[np]=root;
		else{
			int q=ch[p][c];
			if(val[q]==val[p]+1) fa[np]=q;
			else{
				int nq=newnode(val[p]+1);
				memcpy(ch[nq],ch[q],sizeof(ch[q]));
				fa[nq]=fa[q];siz[nq]=siz[q];
				fa[q]=fa[np]=nq;
				for(;p&&ch[p][c]==q;p=fa[p]) ch[p][c]=nq;
			}
		}
		last=np;
		for(p=np;p;p=fa[p]) siz[p]++;
	}
	int query(char *s){
		int i,cur=root,len=strlen(s);
		for(i=0;i<len;i++) cur=ch[cur][s[i]-'A'];
		return siz[cur];
	}
}
void decode(){
	int len=strlen(s),i,tmp=mask;
//	cout<<"before decode "<<s<<'\n';
	for(i=0;i<len;i++){
		tmp=(tmp*131+i)%len;
		swap(s[i],s[tmp]);
	}
//	cout<<"after decode "<<s<<'\n';
}
bool biao=1;int ccnt;
int main(){
	q=read();char ss[10];int i;
	sam::init();
	scanf("%s",s);
	for(i=0;i<strlen(s);i++){
		if(s[i]!='A'){biao=0;break;}
		else ccnt++;
	}
	if(!biao) for(i=0;i<strlen(s);i++) sam::insert(s[i]-'A');
	while(q--){
		scanf("%s",ss);
		scanf("%s",s);
		decode();
		if(biao){
			if(ss[0]=='A'){
				ccnt+=strlen(s);
			}
			else{
				printf("%d\n",(int)(ccnt-strlen(s)+1));
			}
		}
		else{
			if(ss[0]=='A'){
				for(i=0;i<strlen(s);i++) sam::insert(s[i]-'A');
			}
			else printf("%d\n",i=sam::query(s)),mask^=i;
		}
	}
}
