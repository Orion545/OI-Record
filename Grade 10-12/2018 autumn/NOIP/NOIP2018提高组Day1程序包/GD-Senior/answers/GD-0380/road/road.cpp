#include<cstdio>
#include<iostream>
#include<queue>
using namespace std;
int read()
{
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')
	{
		s=s*10+ch-48;
		ch=getchar();
	}
	return s*w;
}
struct node
{
	int num;
	int w;
	friend bool operator < (node a,node b)
	{
		return a.w>b.w;
	}
}st[100001];
int n,cnt;
int l[100005];
int tag[100005];
int v[100005];
int fir0,las0;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	priority_queue <node> q;
	for(int i=1;i<=n;i++)	
	{
		l[i]=st[i].w=read();
		st[i].num=i;		
		q.push(st[i]);
	}
	node now;
	now=q.top();
	q.pop();
	cnt+=now.w;
	tag[1]=(-1)*now.w;
	v[now.num]=1;
	while(!q.empty())
	{
		now=q.top();
		int temp=0;
		for(int j=now.num;j>=1;j--)
			temp+=tag[j];
		temp+=now.w;
		if(temp==0) 
		{
			q.pop();
			v[now.num]=1;	
			continue;
		}		
		q.pop();
		cnt+=temp;
		las0=fir0=now.num;
		while(!v[fir0]&&fir0>=1) fir0--;
		while(!v[las0]&&las0<=n) las0++;
		fir0++;
		tag[fir0]-=temp;
		tag[las0]+=temp;
		v[now.num]=1;	
	}
	cout<<cnt;
	return 0;
}
