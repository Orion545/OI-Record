#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#define ll long long
#define rank DEEP_DARK_FANTASY
using namespace std;
int ch[1200010][26],val[1200010],fa[1200010],cnt=1;
int last=1,root=1;
struct LCT{
	
}T;
void extend(int c){
	int p=last,np=++cnt;
//	cout<<"extend "<<c<<' '<<last<<'\n';
	val[np]=val[p]+1;siz[np]=1;
	while(p&&!ch[p][c]) ch[p][c]=np,p=fa[p];
	if(!p) fa[np]=root;
	else{
		int q=ch[p][c];
		if(val[q]==val[p]+1) fa[np]=q;
		else{
			int nq=++cnt;
			memcpy(ch[nq],ch[q],sizeof(ch[q]));val[nq]=val[p]+1;fa[nq]=fa[q];
			fa[q]=fa[np]=nq;
			while(p&&ch[p][c]==q) ch[p][c]=nq,p=fa[p];
		}
	}
	last=np;
}
int n;char s[3000010],q[10];
void decode(char s[],int mask){
	int len=strlen(s);
	for(int i=0;i<len;i++){
		mask=(mask*131+i)%len;
		swap(s[i],s[mask]);
	}
}
int main(){
	int Q;scanf("%d",&Q);
	scanf("%s",s);n=strlen(s);int i,mask=0;
	for(i=0;i<n;i++) extend(s[i]-'a'); 
	while(Q--){
		scanf("%s%s",q,s);
		decode(s,mask);
		if(q[0]=='A'){
			
		}
	}
}

