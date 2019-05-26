#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#define LL long long
using namespace std;
const LL maxn=50005;
struct rp{
	LL to,w;
};
vector<rp> v[maxn];
LL n,m,fa[maxn];
LL dis[maxn];
inline void read(LL &x){
	LL w=0,X=0;
	char ch=getchar();
	while(ch>'9'||ch<'0')w^=ch=='-',ch=getchar();
	while(ch<='9'&&ch>='0')X=(((X<<2)+X)<<1)+(ch^48),ch=getchar();
	x=w?-X:X;
	return;
}
inline void write(LL x){
	if(x>9)write(x/10);
	putchar(x%10+'0');
	return;
}
inline void writeln(LL x){
	if(x>9)write(x/10);
	putchar(x%10+'0');
	puts("");
	return;
}
LL max(LL a,LL b){
	return a>b?a:b;
}
LL min(LL a,LL b){
	return a<b?a:b;
}
void dfs(LL x){
	dis[x]=0;
	for(LL i=0;i<v[x].size();i++){
		LL y=v[x][i].to;
		if(y!=fa[x]){
			fa[y]=x;
			dfs(y);
			dis[x]=max(dis[x],dis[y]+v[x][i].w);
		}
	}
	return;
}
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	read(n),read(m);
	LL x,y,w,maxw=0,maxnode;
	rp tmp;
	for(LL i=1;i<=n-1;i++){
		read(x),read(y),read(tmp.w);
		if(tmp.w>maxw)maxnode=min(x,y),maxw=tmp.w;
		tmp.to=y;
		v[x].push_back(tmp);
		tmp.to=x;
		v[y].push_back(tmp);
	}
	dfs(maxnode);
	LL max1=0,max2=0;
	for(LL i=0;i<v[maxnode].size();i++){
		LL y=v[maxnode][i].to;
		if(dis[y]+v[maxnode][i].w>max1){
			max2=max1;
			max1=dis[y]+v[maxnode][i].w;
		}
		else if(dis[y]+v[maxnode][i].w>max2){
			max2=dis[y]+v[maxnode][i].w;
		}
	}
	writeln(max1+max2);
	return 0;
}
