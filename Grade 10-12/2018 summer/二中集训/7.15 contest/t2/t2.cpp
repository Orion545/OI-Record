#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
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
int n,m,tot,val[510][510];
struct BIT{
	int a[510][510];
	void clear(){
		memset(a,0,sizeof(a));
	}
	int lowbit(int x){
		return x&(-x);
	}
	void add(int x,int y){
//		cout<<"		add "<<x<<' '<<y<<'\n';
		for(;x<=n;x+=lowbit(x)){
			int ty=y;
			for(;ty<=n;ty+=lowbit(ty)) a[x][ty]++;
		}
	}
	int sum(int x,int y){
		int re=0;
//		cout<<"		sum "<<x<<' '<<y<<' ';
		for(;x>0;x-=lowbit(x)){
			int ty=y;
			for(;ty>0;ty-=lowbit(ty)) re+=a[x][ty];
		}
//		cout<<re<<'\n';
		return re;
	}
}T;
struct query{
	int l1,l2,r1,r2,k,ans;
}q[60010],tmp;
struct ele{
	int l,r;vector<int>q;
}u,v1,v2;
queue<ele>que;
struct node{
	int i,j,val;
}x[250010];int cntx;
bool cmp(node l,node r){
	return l.val<r.val;
}
void bfs(){
	int l,mid,r,i,cur=0,tt;
	while(!que.empty()){
		u=que.front();que.pop();
		l=u.l;r=u.r;mid=(l+r)>>1;
//		cout<<"bfs "<<l<<' '<<r<<' '<<mid<<'\n';
		if(l==r){
			for(i=0;i<u.q.size();i++){
//				cout<<"	getans "<<u.q[i]<<' '<<x[l].val<<'\n';
				q[u.q[i]].ans=x[l].val;
			}
			continue;
		}
		v1.l=l;v1.r=mid;v2.l=mid+1;v2.r=r;v1.q.clear();v2.q.clear();
		if(cur>mid) T.clear(),cur=0;
		while(cur<mid) cur++,T.add(x[cur].i,x[cur].j);
		for(i=0;i<u.q.size();i++){
			tmp=q[u.q[i]];
			tt=T.sum(tmp.l1-1,tmp.r1-1)-T.sum(tmp.l1-1,tmp.r2)-T.sum(tmp.l2,tmp.r1-1)+T.sum(tmp.l2,tmp.r2);
//			cout<<"	calc "<<u.q[i]<<' '<<tt<<' '<<tmp.k<<'\n';
			if(tt<tmp.k) v2.q.push_back(u.q[i]);
			else v1.q.push_back(u.q[i]);
		}
		que.push(v1);que.push(v2);
	}
}
int main(){
//	freopen("3.in","r",stdin);
//	freopen("my.out","w",stdout);
	n=read();m=read();int i,j;tot=n*n;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			x[++cntx].val=read(),x[cntx].i=i,x[cntx].j=j;
//	cout<<"finish input phase 1\n";
	sort(x+1,x+tot+1,cmp);
	for(i=1;i<=m;i++){
		q[i].l1=read();q[i].r1=read();q[i].l2=read();q[i].r2=read();q[i].k=read();
	}
	u.l=1,u.r=tot;
	for(i=1;i<=m;i++) u.q.push_back(i);
	que.push(u);
	bfs();
	for(i=1;i<=m;i++) printf("%d\n",q[i].ans);
}
