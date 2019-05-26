#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
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
struct pt{
	double x,y;
};
inline bool operator <(pt x,pt y){
	return (x.x==y.x)?(x.y<y.y):(x.x<y.x);
}
inline bool operator ==(pt x,pt y){
	return (x.x==y.x&&x.y==y.y);
}
double slope(pt l,pt r){
//	cout<<"slope "<<((l.x==r.x)?1e50:(r.y-l.y)/(r.x-l.x))<<'\n';
	return ((l.x==r.x)?1e50:(r.y-l.y)/(r.x-l.x));
}
struct edge{
	int to,p,q;
};
set<pt>s[210];
vector<edge>a[210];
bool insert(int u,pt p){
//	cout<<"	insert "<<u<<' '<<p.x<<' '<<p.y<<'\n';
	static pt st[400010];int top=0;
	s[u].insert(p);
	for(auto i:s[u]){
//		cout<<"		check "<<i.x<<' '<<i.y<<'\n';
		while(top>1&&slope(st[top-1],st[top])>slope(st[top],i)) top--;
		while(top>0&&slope(st[top],i)<0) top--;
		if(!top||slope(st[top],i)<=1) st[++top]=i;
	}
	s[u].clear();
	for(int i=1;i<=top;i++) s[u].insert(st[i]);
//	cout<<"	finish insert "<<(s[u].find(p)!=s[u].end())<<'\n';
	return s[u].find(p)!=s[u].end();
}
int S,T;
struct ele{
	int num,p,q;
}q[400010];int head,tail;
void spfa(){
	head=0,tail=1;
	q[0]=(ele){S,0,0};insert(S,(pt){0,0});
	while(head<tail){
		ele u=q[head++];
//		cout<<"spfa "<<u.num<<' '<<u.p<<' '<<u.q<<'\n';
		for(auto i:a[u.num]){
			int v=i.to;
//			cout<<"	going to "<<v<<" from "<<u.num<<'\n';
			if(insert(v,(pt){u.q+i.q-u.p-i.p,u.q+i.q}))
				q[tail++]=(ele){v , u.p+i.p , u.q+i.q};
		}
	}
}
double getans(){
	static pt st[400010];int top=0;
	for(auto cur:s[T]) st[++top]=cur;
	if(top==0) return 0;
	if(top==1) return 0.5*(st[1].y-st[1].x+st[1].y);
	double re=0;
	re+=0.5*(st[1].y-st[1].x*slope(st[1],st[2])+st[1].y)*slope(st[1],st[2]);
	re+=0.5*(st[top].y-st[top].x*slope(st[top-1],st[top])+st[top].y-st[top].x)*(1.0-slope(st[top-1],st[top]));
//	cout<<"***********tmp "<<re<<'\n';
	for(int i=2;i<top;i++)
		re+=0.5*(st[i].y-st[i].x*slope(st[i-1],st[i])+st[i].y-st[i].x*slope(st[i],st[i+1]))*(slope(st[i],st[i+1])-slope(st[i-1],st[i]));
	return re;
}
int n,m;
int main(){
	n=read();m=read();S=read();T=read();int i,t1,t2,t3,t4;
	for(i=1;i<=m;i++){
		t1=read();t2=read();t3=read();t4=read();
		a[t1].push_back((edge){t2,t3,t4});
		a[t2].push_back((edge){t1,t3,t4});
	}
	spfa();
	printf("%.5lf",getans());
}
