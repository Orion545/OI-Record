#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <utility>
#include <stdlib.h>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;

namespace Solution_zzc
{
template <typename tp>
void read(tp &x)
{
	x=0;char ch=getchar();bool f=0;
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	if(f)x=-x;
}

vector<pair<int,long long> >graph[50001];
//int height[50001];
//int parent[50001];
int vis[50001];
int times=1;
int n,m;
long long length[50001];
int dp[50001];
long long Mid;

pair<int,long long> bfs(int start)
{
	times++;
	queue <pair<int,long long> >q;
	q.push(make_pair(start,0));
	int p=start;
	long long maxn=0;
	vis[start]=times;
	while(!q.empty())
	{
		pair<int,long long> now=q.front();
		q.pop();
//		cout<<now.first<<endl;
		if(now.second>maxn)
		{
			maxn=now.second;
			p=now.first;
		}
		for(vector<pair<int,long long> >::iterator i=graph[now.first].begin();i!=graph[now.first].end();i++)
		{
			if(vis[i->first]!=times)
			{
				vis[i->first]=times;
				q.push(make_pair(i->first,now.second+i->second));
			}
		}
	}
	return make_pair(p,maxn);
}

multiset<long long> unable;

void dfs(int now)
{
	vis[now]=times;
	vector<long long>tmp;
	tmp.clear();
	for(vector<pair<int,long long> >::iterator i=graph[now].begin();i!=graph[now].end();i++)
	{
		if(vis[i->first]!=times)
		{
			dfs(i->first);
			tmp.push_back(length[i->first]+i->second);
			dp[now]+=dp[i->first];
		}
	}
	sort(tmp.begin(),tmp.end());
	int s=tmp.size();
	for(int i=0;i<s;i++)
	{
		if(tmp[i]>=Mid)
		{
			dp[now]++;
			continue;
		}
		multiset<long long>::iterator p=unable.lower_bound(Mid-tmp[i]);
		if(p!=unable.end())
		{
			dp[now]++;
			unable.erase(p);
		}
		else
		{
			unable.insert(tmp[i]);
		}
	}
	if(unable.size())
	{
		length[now]=(*(--unable.end()));
		unable.clear();
	}
}

bool check1(long long mid)
{
	int cnt=0;
	unable.clear();
//	printf("check1(%lld)\n",mid);
	for(int j=0;j<n-1;j++)
	{
//		cout<<j<<" "<<length[j]<<endl;
		if(length[j]>=mid)
		{
//			cout<<"ok"<<endl;
			cnt++;
			continue;
		}
		multiset<long long>::iterator i=unable.lower_bound(mid-length[j]);
		if(i!=unable.end())
		{
			cnt++;
			unable.erase(i);
		}
		else
		{
			unable.insert(length[j]);
		}
	}
	return cnt>=m;
}

bool check2(long long mid)
{
	int cnt=0;
	long long lennow=0;
	for(int i=1;i<n;i++)
	{
		lennow+=length[i];
		if(lennow>=mid)
		{
			cnt++;
			lennow=0;
		}
	}
	return cnt>=m;
}

bool check3(long long mid)
{
	memset(dp,0,sizeof(dp));
	memset(length,0,sizeof(length));
	times++;
	Mid=mid;
	dfs(1);
	return dp[1]>=m;
}

//m=1
void Subtask1()
{
	cout<<bfs(bfs(1).first).second<<endl;
}

//a_i=1
void Subtask2()
{
	for(int i=0;i<n-1;i++)
	{
		length[i]=graph[1][i].second;
	}
	sort(length,length+n-1);
//	for(int i=0;i<n-1;i++)
//	{
//		cout<<length[i]<<" ";
//	}
//	cout<<endl;
	long long l=0,r=500000001;
	while(r-l>1)
	{
		long long mid=l+r>>1;
		if(check1(mid))l=mid;
		else r=mid;
	}
	if(check1(r))cout<<r<<endl;
	else cout<<l<<endl;
}

//b_i=a_i+1
void Subtask3()
{
	for(int i=1;i<n;i++)
	{
		length[i]=graph[i][0].first==i+1?graph[i][0].second:graph[i][1].second;
	}
//	for(int i=1;i<n;i++)
//	{
//		cout<<length[i]<<" ";
//	}
//	cout<<endl;
	long long l=0,r=500000001;
	while(r-l>1)
	{
		long long mid=l+r>>1;
		if(check2(mid))l=mid;
		else r=mid;
	}
	if(check2(r))cout<<r<<endl;
	else cout<<l<<endl;
}

void Subtask4()
{
	long long l=0,r=500000001;
	while(r-l>1)
	{
		long long mid=l+r>>1;
		if(check3(mid))l=mid;
		else r=mid;
	}
	if(check3(r))cout<<r<<endl;
	else cout<<l<<endl;
}

int main()
{
	read(n);read(m);
	//flag1:a_i==1? flag2:b_i==a_i+1?
//	bool flag1=true,flag2=true;
	for(int i=1;i<n;i++)
	{
		int u,v;
		long long w;
		read(u);read(v);read(w);
//		if(u!=1)flag1=false;
//		if(v!=u+1)flag2=false;
		graph[u].push_back(make_pair(v,w));
		graph[v].push_back(make_pair(u,w));
	}
//	if(m==1)
//	{
//		Subtask1();
//		return 0;
//	}
//	if(flag1)
//	{
//		Subtask2();
//		return 0;
//	}
//	if(flag2)
//	{
//		Subtask3();
//		return 0;
//	}
	Subtask4();
	return 0;
}

}

int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	return Solution_zzc::main();
}

/*
Sub2:
5 2
1 2 3
1 3 7
1 4 8
1 5 2

Sub3:
5 2
1 2 7
4 5 6
3 4 1
2 3 2
*/
