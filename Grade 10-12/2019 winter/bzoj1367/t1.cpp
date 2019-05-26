#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
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
int n,a[1000010],root[1000010],le[1000010],ri[1000010],top;
namespace h{
	int ch[1000010][2],dis[1000010],w[1000010],siz[1000010],cnt;
	inline int newnode(int val){
		int cur=++cnt;
		assert(cur<=1000000);
		ch[cur][0]=ch[cur][1]=0;dis[cur]=1;siz[cur]=1;
		w[cur]=val;return cur;
	}
	int merge(int x,int y){
		if(!x||!y) return x^y;
		if(w[x]<w[y]) swap(x,y);
		ch[x][1]=merge(ch[x][1],y);
		siz[x]=siz[ch[x][0]]+siz[ch[x][1]]+1;
		if(dis[ch[x][1]]>dis[ch[x][0]]) swap(ch[x][0],ch[x][1]);
		dis[x]=dis[ch[x][1]]+1;
		return x;
	}
}
int main(){
	n=read();int i,cur,j;
	for(i=1;i<=n;i++) a[i]=read()-i;
	for(i=1;i<=n;i++){
		top++;
		root[top]=h::newnode(a[i]);
		le[top]=ri[top]=i;
//		cout<<"add new seg "<<i<<' '<<i<<' '<<a[i]<<'\n';
		while(top>1&&h::w[root[top]]<h::w[root[top-1]]){
			top--;
			root[top]=h::merge(root[top],root[top+1]);
//			cout<<"merged "<<top<<' '<<top+1<<' '<<le[top]<<' '<<ri[top]<<' '<<h::w[root[top]]<<'\n';
			ri[top]=ri[top+1];
			while(h::siz[root[top]]*2>(ri[top]-le[top]+2)) root[top]=h::merge(h::ch[root[top]][0],h::ch[root[top]][1]);
		}
	}
//	cout<<"finish for"<<endl;
	ll ans=0;
	for(i=1;i<=top;i++){
		for(j=le[i];j<=ri[i];j++) ans+=(ll)abs(a[j]-h::w[root[i]]);
//		cout<<"seg "<<i<<' '<<le[i]<<' '<<ri[i]<<' '<<h::w[root[i]]<<' '<<ans<<'\n';
	}
	cout<<ans<<'\n';
}
