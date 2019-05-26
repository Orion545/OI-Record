#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>
#include<stack>
using namespace std;
char ch;
#define ll long long
#define MM 101010
#define N 1110
#define mo 1000000007

ll xxx;ll fff;
inline ll readll(){
	xxx=0;fff=1;ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')fff=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		xxx=(xxx<<1)+(xxx<<3)+ch-'0';
		ch=getchar();
	}
	return xxx*fff;
}
int xx;int ff;
inline int read(){
	xx=0;ff=1;ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')ff=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		xx=(xx<<1)+(xx<<3)+ch-'0';
		ch=getchar();
	}
	return xx*ff;
}
int n;
int d[MM];
struct node{
	int l,r;
};
queue <node> q;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	
	int l=1,r;
	while(!q.empty())q.pop();
	ll ans=0;
	node nn;
	for(int i=1;i<=n;++i){
		d[i]=read();
		if(!d[i]){
			nn.l=l;
			nn.r=i-1;
			q.push(nn);
			l=i+1;
		}
	}
	if(d[n]!=0){
		nn.l=l;
		nn.r=n;
		q.push(nn);
	}
	while(!q.empty()){
		nn=q.front();q.pop();
		l=nn.l;r=nn.r;
		int v=l;
		//cerr<<"QQ"<<l+1<<endl;
		for(int i=l+1;i<=r;++i){
			if(d[v]>d[i])v=i;
		}
		//cerr<<"Q"<<endl;
		ans+=d[v];
		if(l==r)continue;
		//cerr<<"Q"<<l<<" "<<r<<" "<<v<<endl;
		for(int i=l;i<v;++i)d[i]-=d[v];
		for(int i=v+1;i<=r;++i)d[i]-=d[v];
		if(l<=v-1){
			nn.l=l;nn.r=v-1;
			q.push(nn);
		}
		if(v+1<=r){
			nn.l=v+1;nn.r=r;
			q.push(nn);
		}
	}
	printf("%lld\n",ans);
	fclose(stdin);fclose(stdout);
	
	return 0;
}
