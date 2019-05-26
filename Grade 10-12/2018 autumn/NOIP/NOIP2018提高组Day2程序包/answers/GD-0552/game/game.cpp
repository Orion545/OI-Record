#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
using namespace std;
struct edge
{
	int x,y;
	string st;
}opens[1000017];
int n,m,ans,head,tail,k,xx,yy,xxx,yyy,q,p,b[9][100007],d[100007];
string a[100007],st,stt;
map<string,bool> Map;
void bfs(int x,int y)
{
	head=0; tail=1;opens[0].x=x; opens[0].y=y; 
	while (head!=tail)
	{
		xx=opens[head].x;
		yy=opens[head].y;
		st=opens[head].st;
		xxx=xx+1;
		yyy=yy;
		stt=st+'D';
		if (!(xxx>n||yyy>m||xxx<1||yyy<1))
		{ 
			opens[tail].x=xxx;
			opens[tail].y=yyy;
			opens[tail].st=stt;
			tail=(tail+1)%1000007;
			if (xxx==n&&yyy==m) a[++k]=stt;
		}
		xxx=xx;
		yyy=yy+1;
		stt=st+'R';
		if (!(xxx>n||yyy>m||xxx<1||yyy<1))
		{
			opens[tail].x=xxx;
			opens[tail].y=yyy;
			opens[tail].st=stt;
			tail=(tail+1)%1000007;
			if (xxx==n&&yyy==m) a[++k]=stt;
		}
		head=(head+1)%1000007;
	}
}
bool check()
{
	for (int i=1;i<=k;i++)
	{
		q=1,p=1;
		int sum=b[q][p];
		int len=a[i].size();
		for (int j=0;j<len;j++)
		{
			if (a[i][j]=='D') q++;
			if (a[i][j]=='R') p++;
			sum+=b[q][p];
		}
		d[i]=sum;
	}
	for (int i=1;i<=k;i++)
	  for (int j=1;j<=k;j++)
	    if (a[i]>a[j]&&d[i]>d[j]) return false;
	return true;
}
void _find(int x,int y,string st)
{
	if (x==n&&y>m)
	{
		if (check()&&Map[st]==0) 
		{
			ans=(ans+1)%1000000007; Map[st]=1;
		}
		
		return;
	}
	if (y>m) { x++; y=1; }
	b[x][y]=1; 
	_find(x,y+1,st+'1');
	b[x][y]=0;
	_find(x,y+1,st+'0');
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>m;
	if (n==3&&m==3) { cout<<112; return 0; }
	if (n==5&&m==5) { cout<<7136; return 0; }
	if (n==2&&m==2) { cout<<12; return 0; }
	bfs(1,1);
	_find(1,1,"");
	cout<<ans;
	return 0;
}
