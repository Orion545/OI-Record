#include<bits/stdc++.h>
#define N 5001
using namespace std;
template <typename _Tp> _Tp read(){
	register int f=1;
	register _Tp num=0;register char c=0;
	while(!isdigit(c=getchar())) if(c=='-') f=-1;
	while(isdigit(c))
	num=(num<<1)+(num<<3)+(c&15),c=getchar();
	return num*f;
}
template <typename _Tp> void write(_Tp x){
	if(x<0) putchar('-'), write<_Tp> (~x+1);
	else{
		if(x>9) write<_Tp>(x/10);
		putchar(x%10+'0');
	}
}

struct node{
	int op,po;
}road[N];

int n,m,num;
int tot,next[N],head[N],to[N];
int d[N],v[N];

inline bool cmp(const node &x,const node &y){
	if(x.op==y.op) return x.po<y.po;
	return x.op<y.op;
}

inline void add(int x,int y){
	next[++tot]=head[x],head[x]=tot,to[tot]=y;
	next[++tot]=head[y],head[y]=tot,to[tot]=x;
}

void dfs(int ui){
	d[++num]=ui;
	for(register int i=head[ui];i;i=next[i]){
		if(!v[to[i]]){
			v[to[i]]=1;
			dfs(to[i]);
		}
	}
}

void bfs(){
	priority_queue<int> q;
	q.push(-1);
	while(q.size()&&num<n){
		int x=-q.top();q.pop();
		if(v[x]) continue;
		v[x]=1; d[++num]=x;
	    for(register int i=head[x];i;i=next[i]){
		    int y=to[i];
		    q.push(-y);
	    }
    }
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	n=read<int>(),m=read<int>();
	for(register int i=1;i<=m;++i){
		road[i].op=read<int>(),road[i].po=read<int>();
		if(road[i].op>road[i].po) swap(road[i].op,road[i].po);
	}
	sort(road+1,road+m+1,cmp);
	for(register int i=m;i;--i) add(road[i].op,road[i].po);
//	for(register int i=1;i<=n;++i)
//	for(register int j=head[i];j;j=next[j]){
//		cout<<i<<"-->"<<to[j]<<endl;
//	}
//	return 0;
	if(m==n-1){
	    v[1]=1;dfs(1);
	}
	else{
		bfs();
	}
	for(register int i=1;i<=n;++i)
	write(d[i]),printf(" ");
	return 0;
}
