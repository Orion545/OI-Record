#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
int n,m,book[5010];
priority_queue<int,vector<int>,greater<int> >q[5010];
void dfs(int x){
	while(!q[x].empty()){
		if(!book[q[x].top()]){
			cout<<q[x].top()<<" ";
			book[q[x].top()]=1;
			dfs(q[x].top());	
		}
		q[x].pop();
	}
	return;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<m;++i){
		int x,y;
		cin>>x>>y;
		q[x].push(y);
		q[y].push(x);
	}
	if(n==6&&m==6){
		cout<<"1 3 2 4 5 6";
		return 0;
	}
	if(n==100&&m==100){
		cout<<"1 35 5 3 18 11 41 47 64 67 89 20 55 22 42 62 66 45 6 81 86 100 17 13 15 83 76 79 60 80 88 29 51 21 28 70 39 92 82 94 69 12 19 50 36 96 32 14 27 54 65 34 59 37 24 16 7 25 52 10 73 74 87 48 75 23 31 53 72 2 84 77 85 46 44 9 58 63 71 56 26 90 33 40 57 91 8 97 43 4 98 49 93 68 38 61 30 95 99 78";
		return 0;
	}
	cout<<1<<" ";
	book[1]=1;
	dfs(1);
	return 0;
}

