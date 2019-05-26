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
int n,root[2];
int ch[200010][2],dis[200010],tim[200010],w[200010],cnt;
inline int newnode(int val,int pos){
	int cur=++cnt;
	ch[cur][0]=ch[cur][1]=0;dis[cur]=1;
	tim[cur]=pos;w[cur]=val;
	return cur;
}
int merge(int x,int y){
	if(!x||!y) return x^y;
	if(tim[x]<tim[y]) swap(x,y);
	ch[x][1]=merge(ch[x][1],y);
	if(dis[ch[x][1]]>dis[ch[x][0]]) swap(ch[x][1],ch[x][0]);
	dis[x]=dis[ch[x][1]]+1;
	return x;
}
int main(){
	int i,t1,t2,cas=0;char s[20];
	while(n=read()){
		printf("Case #%d:\n",++cas);
		root[0]=root[1]=0;cnt=0;
		for(i=1;i<=n;i++){
			scanf("%s",s);
			if(s[0]=='p'&&s[1]=='u'){
				//push
				scanf("%s",s);t1=(s[0]=='B');
				root[t1]=merge(root[t1],newnode(read(),i));
			}
			if(s[0]=='p'&&s[1]=='o'){
				//pop
				scanf("%s",s);t1=(s[0]=='B');
				printf("%d\n",w[root[t1]]);
				root[t1]=merge(ch[root[t1]][0],ch[root[t1]][1]);
			}
			if(s[0]=='m'){
				scanf("%s",s);t1=(s[0]=='B');
				scanf("%s",s);t2=(s[0]=='B');
				root[t1]=merge(root[t1],root[t2]);
				root[t2]=0;
			}
		}
	}
}
