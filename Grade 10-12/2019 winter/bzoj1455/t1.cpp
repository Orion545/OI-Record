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
int n,m,a[1000010],dead[1000010],f[1000010];
int ch[1000010][2],dis[1000010],w[1000010],cnt=0;
inline int find(int x){return ((f[x]==x)?x:(f[x]=find(f[x])));}
inline int newnode(int val){
	int cur=++cnt;
	ch[cur][0]=ch[cur][1]=0;dis[cur]=1;
	w[cur]=val;return cur;
}
int merge(int x,int y){
	if(!x||!y) return x^y;
	if(x==y) return x;
	if(w[x]>w[y]) swap(x,y);
	ch[x][1]=merge(ch[x][1],y);
	if(dis[ch[x][1]]>dis[ch[x][0]]) swap(ch[x][0],ch[x][1]);
	dis[x]=dis[ch[x][1]]+1;
	return x;
}
int main(){
	n=read();int i,j,t1,t2;char s[20];
	for(i=1;i<=n;i++){
		a[i]=read();
		newnode(a[i]);
		f[i]=i;dead[i]=0;
	}
	m=read();
	while(m--){
		scanf("%s",s);
		if(s[0]=='M'){
			t1=read();t2=read();
			if(dead[t1]||dead[t2]) continue;
//			cout<<"merge "<<t1<<' '<<t2<<'\n';
			int cur=merge(t1=find(t1),t2=find(t2));
			f[t2]=f[t1]=cur;
		}
		else{
			t1=read();if(dead[t1]){puts("0");continue;}
			t1=find(t1);dead[t1]=1;
			printf("%d\n",w[t1]);
			f[t1]=merge(ch[t1][0],ch[t1][1]);
			f[f[t1]]=f[t1];
		}
//		cout<<m<<endl;
	}
}
