#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<queue>
#define mp make_pair
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
struct sam{
	int root,last,cnt,ch[4010][26],val[4010],fa[4010];
	sam(){root=last=cnt=1;val[cnt]=0;}
	inline int newnode(int w){val[++cnt]=w;return cnt;}
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
				fa[nq]=fa[q];
				fa[q]=fa[np]=nq;
				for(;p&&ch[p][c]==q;p=fa[p]) ch[p][c]=nq;
			}
		}
		last=np;
	}
}sa,sb;
struct lam{
	int ch[2010][27],fail[2010],last[27],cnt;
	inline int newnode(){return ++cnt;}
	lam(){cnt=0;last[26]=newnode();}
	void insert(int c){
		int i,p,cur=newnode();
		for(i=0;i<=26;i++){
			for(p=last[i];p&&!ch[p][c];p=fail[p]) ch[p][c]=cur;
		}
		fail[cur]=last[c];last[c]=cur;
	}
}la,lb;
int vis[4010][4010];
queue<pair<int,int> >q;
template<class T1,class T2>inline int bfs(T1 s1,T2 s2){
	memset(vis,0,sizeof(vis));
	while(!q.empty()) q.pop();
	q.push(mp(1,1));
	vis[1][1]=0;
	int i,x,y,tx,ty;
	while(!q.empty()){
		x=q.front().first;
		y=q.front().second;
		q.pop();
//		cout<<"bfs "<<x<<' '<<y<<' '<<vis[x][y]<<'\n';
		for(i=0;i<26;i++){
//			cout<<"	try "<<i<<' '<<s1.ch[x][i]<<' '<<s2.ch[y][i]<<'\n';
			if(!s1.ch[x][i]) continue;
			if(!s2.ch[y][i]) return vis[x][y]+1;
			tx=s1.ch[x][i];ty=s2.ch[y][i];
			if(vis[tx][ty]) continue;
			vis[tx][ty]=vis[x][y]+1;
			q.push(mp(tx,ty));
		}
	}
	return -1;
}
int n,m;char a[2010],b[2010];
int main(){
	int i;
	scanf("%s",a);n=strlen(a);
	for(i=0;i<n;i++) la.insert(a[i]-'a');
	for(i=0;i<n;i++) sa.insert(a[i]-'a');
	scanf("%s",b);m=strlen(b);
	for(i=0;i<m;i++) lb.insert(b[i]-'a');
	for(i=0;i<m;i++) sb.insert(b[i]-'a');
	cout<<bfs(sa,sb)<<'\n';
	cout<<bfs(sa,lb)<<'\n';
	cout<<bfs(la,sb)<<'\n';
	cout<<bfs(la,lb)<<'\n';
}
