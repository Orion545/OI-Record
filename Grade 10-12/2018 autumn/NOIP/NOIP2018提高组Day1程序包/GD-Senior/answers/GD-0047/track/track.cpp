#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>
#include<set>
using namespace std;
struct pic{int tonl,w;}treee[50005];
int n,m;
vector<pic> q[50005];
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	cin>>n>>m;int maxx=-1;
	for (int i=1;i<n;i++)
	{
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		q[a].push_back((pic){b,c});
		maxx=max(maxx,c);
	}
	cout<<maxx<<endl;
	return 0;
}
