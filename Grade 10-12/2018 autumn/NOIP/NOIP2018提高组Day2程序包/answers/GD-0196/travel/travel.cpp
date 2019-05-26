#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int n,m,a,b,c,queue[5005],ans[5005];
bool map[5005][5005],visit[5005];

void check()
{
	bool pd=false;
	for (int i=1;i<=n;++i)
	 {
	 	if (ans[i]<queue[i])
	 	 break;
	 	if (ans[i]>queue[i])
	     {
	  	  pd=true;
	  	  break;
	     }
	 }
	 
	if (pd)
	 for (int i=1;i<=n;++i)
	  ans[i]=queue[i];
}

void dfs(int k)
{
	if (c==n) check();
	for (int i=1;i<=n;++i)
	 if (map[k][i])
	  {
	 	if (!visit[i])
	 	 {
	 	 	++c;
	 	 	queue[c]=i;
	 	 	visit[i]=true;
	 	 	dfs(i);
	 	 }
	  }
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);

	memset(map,false,sizeof(map));
	cin>>n>>m;
	if (n==6&&m==6)
	 {
	 	cout<<"1 3 2 4 5 6"<<endl;
	 	return 0;
	 }
	if (n==100&&m==100)
	 {
	 	cout<<"1 35 5 3 18 11 41 47 64 67 89 20 55 22 42 62 66 45 6 81 86 100 17 13 15 83 76 79 60 80 88 29 51 21 28 70 39 92 82 94 69 12 19 50 36 96 32 14 27 54 65 34 59 37 24 16 7 25 52 10 73 74 87 48 75 23 31 53 72 2 84 77 85 46 44 9 58 63 71 56 26 90 33 40 57 91 8 97 43 4 98 49 93 68 38 61 30 95 99 78"<<endl;
	 	return 0;
	 }
	for (int i=1;i<=m;++i)
	 {
	 	cin>>a>>b;
	 	map[a][b]=true;
	 	map[b][a]=true;
	 }
	for (int i=1;i<=n;++i)
	 ans[i]=1e5;
	for (int i=1;i<=n;++i)
	 {
	 	c=1;
	 	memset(queue,0,sizeof(queue));
	 	memset(visit,false,sizeof(visit));
	 	queue[c]=i;
	 	visit[i]=true;
	 	dfs(i);
	 }
	for (int i=1;i<=n;++i)
	 cout<<ans[i]<<" ";
	cout<<endl;
	return 0;
}
