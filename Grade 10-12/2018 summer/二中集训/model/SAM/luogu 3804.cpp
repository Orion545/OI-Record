#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#define ll long long
#define rank DEEP_DARK_FANTASY
using namespace std;
int ch[2000010][26],val[2000010],fa[2000010],cnt=1,siz[2000010],book[2000010],rank[2000010];
int last=1,root=1;
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
ll ans;
void calc(){
	int i,cur;
	for(i=1;i<=cnt;i++) book[val[i]]++;
	for(i=1;i<=cnt;i++) book[i]+=book[i-1];
	for(i=1;i<=cnt;i++) rank[book[val[i]]--]=i;
	for(i=cnt;i>=1;i--){
//		cout<<i<<' '<<rank[i]<<' '<<siz[rank[i]]<<'\n';
		cur=rank[i];siz[fa[cur]]+=siz[cur];
		if(siz[cur]>1) ans=max(ans,1ll*siz[cur]*val[cur]);
	}
}
int n;char s[1000010];
int main(){
	scanf("%s",s);n=strlen(s);int i;
	for(i=0;i<n;i++) extend(s[i]-'a'); 
	calc(); 
	printf("%lld\n",ans);
}

