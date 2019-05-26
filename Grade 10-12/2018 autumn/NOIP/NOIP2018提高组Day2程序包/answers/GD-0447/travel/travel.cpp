#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

const int N=5005;
int n,m;
int det[N];
struct node{
	int to,next;
}edge[2*N];
int head[N],cot;
queue<int> ans;
priority_queue<int> q[N];

void work(int k);
void add(int u,int v);
inline int read();

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	n=read(); m=read();
	for (int i=1,u,v;i<=m;i++) {
		u=read(); v=read();
		q[u].push(v);
		q[v].push(u);
		//add(u,v); add(v,u);
	}
	for (int i=1;i<=n;i++) {
		while(!q[i].empty()) {
			add(i,q[i].top());
			q[i].pop();
		}
	}
	/*for (int i=1;i<=n;i++) {
		cout<<i<<":";
		for (int j=head[i];j;j=edge[j].next) {
			cout<<edge[j].to<<' ';
		}
		cout<<endl;
	}*/
	work(1);
	while(!ans.empty()) {
		cout<<ans.front()<<' ';
		ans.pop();
	}
	cout<<endl;
	fclose(stdin); fclose(stdout);
	return 0;
}

void work(int k)
{
	//cout<<k<<endl;
	ans.push(k);
	det[k]=1;
	for (int i=head[k];i;i=edge[i].next) {
		if (!det[edge[i].to]) work(edge[i].to);
	}
}

void add(int u,int v)
{
	cot++;
	edge[cot].to=v;
	edge[cot].next=head[u];
	head[u]=cot;
}

inline int read()
{
	int ret=0,neg=0; char ch=getchar();
	while((ch<'0' || ch>'9') && ch!='-') ch=getchar();
	if (ch=='-') {neg=1;ch=getchar();}
	while(ch>='0' && ch<='9') {
		ret=ret*10+ch-'0';
		ch=getchar();
	}
	if (neg) return -ret;
	return ret;
}
