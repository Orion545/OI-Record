#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
#define rank DEEP_DARK_FANTASY
#define ll long long
using namespace std;
inline int read(){
	int re=0,flag=1;char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
int ch[1000010][26],val[1000010],fa[1000010],siz[1000010],book[1000010],rank[1000010];
int cnt=1,root=1,last=1;
void extend(int c){
	int np=++cnt,p=last;
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
int dp[500010],n;
char s[500010];
void calc(){
	int i,cur;
	for(i=1;i<=cnt;i++) book[val[i]]++;
	for(i=1;i<=cnt;i++) book[i]+=book[i-1];
	for(i=1;i<=cnt;i++) rank[book[val[i]]--]=i;
	for(i=cnt;i>=1;i--){
		cur=rank[i];siz[fa[cur]]+=siz[cur];
//		cout<<i<<' '<<cur<<' '<<fa[cur]<<' '<<siz[cur]<<' '<<val[cur]<<'\n';
		dp[val[cur]]=max(dp[val[cur]],siz[cur]);
	}
	for(i=n-1;i>=1;i--) dp[i]=max(dp[i],dp[i+1]);
	for(i=1;i<=n;i++) printf("%d\n",dp[i]);
}
int main(){
	scanf("%s",s);int i;n=strlen(s);
//	cout<<"finish input "<<s<<'\n';
	for(i=0;i<n;i++) extend(s[i]-'a');
	calc();
}

