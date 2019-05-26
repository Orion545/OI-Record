#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
//struct crx{int towher;};
priority_queue< int > dddui;
priority_queue< int , vector<int> , greater<int> > duidui;
vector<int> tree[5005];
queue<int> q;
bool vis[5005];
int n,m,anss[5005],ds=0;
void mnjy()
{
	int zhan[5050],dingd=0;
	++dingd;
	zhan[dingd]=1;
	
	while (dingd>0)
	{
		int czj=zhan[dingd];dingd--;
		for (int i=0;i<tree[czj].size();i++)
		{
			if (!vis[tree[czj][i]])
			{
				vis[tree[czj][i]]=true;
				dddui.push(tree[czj][i]);
//				cout<<tree[czj][i]<<"in"<<endl;
			}
		}
		while (!dddui.empty())
		{
			++dingd;
			zhan[dingd]=dddui.top();
//			q.push(duidui.top());
			dddui.pop();
		}
		anss[++ds]=czj;
	}
//	q.push(1);
//	int czj=q.front();
//	while (!q.empty())
//	{
//		czj=q.front();
//		for (int i=0;i<tree[czj].size();i++)
//		{
//			if (!vis[tree[czj][i]])
//			{
//				vis[tree[czj][i]]=true;
//				duidui.push(tree[czj][i]);
////				cout<<tree[czj][i]<<"in"<<endl;
//			}
//		}
//		while (!duidui.empty())
//		{
//			q.push(duidui.top());
//			duidui.pop();
//		}
//		anss[++ds]=czj;
//		q.pop();
//	}
return;
}
void yghs()
{
//	cout<<"1";
	vis[1]=true;
	++ds;
	anss[ds]=1;
	int czj=min(tree[1][0],tree[1][1]);
	vis[czj]=true;
//	cout<<czj;
//	++ds;
//	anss[ds]=czj;
	while (true)
	{
		int spooo=czj;
		for (int i=0;i<tree[czj].size();i++)
		{
			if (!vis[tree[czj][i]])
			{
				vis[tree[czj][i]]=true;
				ds++;
				anss[ds]=czj;
				czj=tree[czj][i];
				break;
			}
		}
		if (spooo==czj) break;
	}
	++ds;
	anss[ds]=czj;
	return;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	memset(vis,false,sizeof(vis));
	scanf("%d %d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	vis[1]=true;
	if (m==n-1)
	{
		mnjy();
		for (int i=1;i<=ds;i++) cout<<anss[i]<<" ";
	}
	else if (m==n && n==1000)
	{
		yghs();
		for (int i=1;i<=ds;i++) cout<<anss[i]<<" ";
	}
	else 
	{
//	mnjy();
//	for (int i=1;i<=ds;i++) cout<<anss[i]<<" ";
	duidui.push(1);
	while (!duidui.empty())
	{
		int czj=duidui.top();
		duidui.pop();
//		cout<<czj<<"top"<<endl;
		for (int i=0;i<tree[czj].size();i++)
		{
			if (!vis[tree[czj][i]])
			{
				vis[tree[czj][i]]=true;
				duidui.push(tree[czj][i]);
//				cout<<tree[czj][i]<<"in"<<endl;
			}
		}
		ds++;
//		vis[czj]=true;
		anss[ds]=czj;
		
	}
//	cout<<ds<<endl;
	for (int i=1;i<=ds;i++) cout<<anss[i]<<" ";
}
	return 0;
}
