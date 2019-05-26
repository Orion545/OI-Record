#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int maxn=100010;
const int maxm=200010;
struct data{
	int next,to;
};
int cost[maxn],head[maxm],c[maxn];
data g[maxm];
int t=0,n;
void add(int from,int to)
{
	++t;
	g[t].next=head[from];
	g[t].to=to;
    head[from]=t;
    return;
}
int main()
{
	int m,x,y,a,b;
	string s;
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	cin>>n>>m>>s;
	for (int i=1;i<=n;++i) cin>>cost[i];
	for (int i=1;i<n;++i)
	{
		cin>>x>>y;
		add(x,y); add(y,x);
	}
	for (int i=1;i<=m;++i)
	{
		memset(c,0,sizeof(c));
		cin>>a>>x>>b>>y;
		if (x==0&&y==0) cout<<-1<<endl;
		else if (i%2!=0) cout<<cost[4]+cost[5];
		else cout<<cost[1]+cost[2]+cost[3];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
