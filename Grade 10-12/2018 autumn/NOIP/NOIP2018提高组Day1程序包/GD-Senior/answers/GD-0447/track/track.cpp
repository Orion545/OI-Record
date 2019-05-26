#include <iostream>
#include <queue>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N=50005;
int n,m;
int ans=0;
struct node{
	int to,next;
	int val;
}edge[2*N];
int head[N],cot;
int val[N];

void work1();
int dfs1(int k,int father);
void work2();
int cmp(int a,int b) {return a>b;}
void add(int u,int v,int w);
inline int read();

int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	n=read(); m=read();
	int flag=0;
	for (int i=1,u,v,w;i<n;i++) {
		u=read(); v=read(); w=read();
		val[i]=w;
		if (u!=1) flag=1;
		add(u,v,w); add(v,u,w);
	}
	/*for (int i=1;i<=n;i++) {
		cout<<i<<":";
		for (int j=head[i];j;j=edge[j].next) {
			cout<<edge[j].val<<' ';
		}
		cout<<endl;
	}*/
	if (m==1) work1();
	if (flag==0) work2();
	fclose(stdin); fclose(stdout);
}

void work2()
{
	ans=0x7fffffff;
	sort(val+1,val+n,cmp);
	int i=m,j=m+1;
	while(i>=1 && j<n) {
		int now=val[i]+val[j];
		if (now>val[i-1]) {
			i--; j++;
			ans=min(ans,now);
		}
		else {
			ans=min(ans,now);
			break;
		}
	}
	cout<<ans<<endl;
}

void add(int u,int v,int w)
{
	cot++;
	edge[cot].to=v;
	edge[cot].val=w;
	edge[cot].next=head[u];
	head[u]=cot;
}

void work1()
{
	for (int i=1;i<=n;i++) {
		dfs1(i,i);
	}
	cout<<ans<<endl;
}
int dfs1(int k,int father)
{
	int maxi=-0x7fffffff,flag=0;
	for (int i=head[k];i;i=edge[i].next) {
		if (edge[i].to!=father) {
			maxi=max(maxi,edge[i].val+dfs1(edge[i].to,k));
			flag=1;
		}
	}
	if (k==father) ans=max(maxi,ans);
	if (flag==0) return 0;
	return maxi;
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

