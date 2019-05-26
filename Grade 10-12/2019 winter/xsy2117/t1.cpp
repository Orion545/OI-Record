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
int n,m,c[100010],p[100010],tim[100010];
struct plan{
	int dis,pos;
	plan(){dis=1e9;pos=0;}
	plan(int aa,int bb){dis=aa;pos=bb;}
}a[100010];
inline plan operator +(plan x,int b){
	return plan(x.dis+b,x.pos);
}
inline plan min(plan x,plan y){
	return (x.dis<y.dis)?x:y;
}
void update(int u){
	if(c[u]) a[u]=plan(0,u);
	else a[u]=plan(1e9,0);
	if((u<<1)<=n) a[u]=min(a[u],a[u<<1]+((tim[u<<1]>=0)?1:-1));
	if((u<<1|1)<=n) a[u]=min(a[u],a[u<<1|1]+((tim[u<<1|1]>=0)?1:-1));
//	cout<<"update "<<u<<' '<<a[u].dis<<' '<<a[u].pos<<' '<<c[u]<<' '<<tim[u]<<'\n';
}
int main(){
	n=read();m=read();
	int ans=0,i,cur,tmp,x;
	plan minn;
	for(i=1;i<=n;i++) c[i]=read();
	for(i=1;i<=m;i++) p[i]=read();
	for(i=n;i>=1;i--) update(i);
	for(i=1;i<=m;i++){
		minn=plan(1e9,0);cur=p[i];tmp=0;
		for(x=cur;x;x>>=1) minn=min(minn,a[x]+tmp),tmp+=((tim[x]<=0)?1:-1);

		printf("%d\n",ans+=minn.dis);
//		cout<<"minn "<<minn.dis<<' '<<minn.pos<<'\n';
		c[tmp=minn.pos]--;

		while(cur!=tmp){
			if(cur>tmp){tim[cur]--;update(cur);cur>>=1;}
			if(cur<tmp){tim[tmp]++;update(tmp);tmp>>=1;}
		}
		for(;cur;cur>>=1) update(cur);
	}
}
