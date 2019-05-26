#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#define ll long long
#define MOD 1000000007
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
int n,m,Q,first[100010],cnt,ans[100010];
struct edge{
	int to,next;
}a[200010];
void add(int u,int v){
	a[++cnt]=(edge){v,first[u]};first[u]=cnt;
	a[++cnt]=(edge){u,first[v]};first[v]=cnt;
}
int f[100010];
void init(){
//	cout<<"init"<<endl;
	for(int i=1;i<=n;i++) f[i]=-1;
}
int find(int x){
	return ((f[x]<0)?x:(f[x]=find(f[x])));
}
void join(int x,int y){
//	cout<<"join "<<x<<ends<<y<<endl;
	int fx=find(x),fy=find(y);
//	cout<<"find "<<fx<<ends<<fy<<endl;
	if(fx==fy) return;
	if(f[fx]>f[fy]) swap(x,y),swap(fx,fy);
	f[fx]+=f[fy];f[fy]=fx;
}
struct query{
	int x,y,z;
}q[100010];
struct node{
	int l,r;vector<int>q;
	void clear(){l=r=0;q.clear();}
};
bool check(int x){
//	cout<<"check query "<<x<<endl;
	int tmp=(-f[find(q[x].x)]-f[find(q[x].y)]);
	if(find(q[x].x)==find(q[x].y)) tmp/=2;
	return (q[x].z<=tmp);
}
queue<node>que;
void bfs(){
	int i,j,cur=0,mid;node u,t1,t2;init();
	while(!que.empty()){
		u=que.front();que.pop();t1.clear();t2.clear();
//		cout<<"query "<<u.l<<ends<<u.r<<ends<<cur<<endl;
//		for(i=0;i<u.q.size();i++) cout<<u.q[i]<<ends;cout<<endl;
//		system("pause");
		if(u.r-u.l==1){
			for(i=0;i<u.q.size();i++) ans[u.q[i]]=u.r;
			continue;
		}
		mid=(u.r+u.l)>>1;
		if(cur>mid) init(),cur=0;
		while(cur<mid) cur++,join(a[cur<<1].to,a[(cur<<1)-1].to);
		j=u.q.size();
		t1.l=u.l;t1.r=mid;t2.l=mid;t2.r=u.r;
		for(i=0;i<j;i++){
			if(check(u.q[i])) t1.q.push_back(u.q[i]);
			else t2.q.push_back(u.q[i]);
		}
		que.push(t1);que.push(t2);
	}
}
int main(){
	memset(first,-1,sizeof(first));
	int i,t1,t2;node tmp;
	n=read();m=read();
	for(i=1;i<=m;i++){
		t1=read();t2=read();add(t1,t2);
	}
	Q=read();
	for(i=1;i<=Q;i++){
		q[i].x=read();q[i].y=read();q[i].z=read();
		tmp.q.push_back(i);
	}
	tmp.l=0;tmp.r=m;
	que.push(tmp);
	bfs();
	for(i=1;i<=Q;i++){
		printf("%d\n",ans[i]);
	}
}
/*
5 6
2 3
4 5
1 2
1 3
1 4
1 5
6
2 4 3
2 4 4
2 4 5
1 3 3
1 3 4
1 3 5

*/
