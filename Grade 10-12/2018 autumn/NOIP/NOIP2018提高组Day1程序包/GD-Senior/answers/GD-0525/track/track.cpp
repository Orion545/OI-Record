#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
FILE *iin,*outt;
int n,m,x,y,z,a,b;
struct Edge
{
	int to,w;
};
struct Dian
{
	vector<Edge> edge;
}dian[50003];
int bj[50003],bj_dfs[50003];
int maxx(int a,int b){return a>b?a:b;}
int minn(int a,int b){return a<b?a:b;}
int DFS(int di)
{
	Dian qwq=dian[di];
	int ans=0;bool ok=0;
	for(int i=0;i<qwq.edge.size();i++)
	{
		int tto=qwq.edge[i].to;
		int ww=qwq.edge[i].w;
		if(bj_dfs[tto]!=233)
		{
			ok=1;
			bj_dfs[tto]=233;
			ans=maxx(ans,DFS(tto)+ww);
			bj_dfs[tto]=0;
		}
	}
	if(ok==0)
	{
		return 0;
	}
	return ans;
}
int IOI()
{
	memset(bj,0,sizeof(bj));
	int aan=0;
	for(int i=1;i<=n;i++)
	{
		Dian qwq=dian[i];
		if(qwq.edge.size()==1&&bj[i]!=1)
		{
			bj[i]=1;
			aan=maxx(aan,DFS(i));
		}
	}
	fprintf(outt,"%d",aan);
}
int fsol[50003];
int I_AK()
{
	int yy=dian[1].edge.size();
	for(int i=0;i<dian[1].edge.size();i++)
	{
		fsol[i+1]=dian[1].edge[i].w;
	}
	sort(fsol+1,fsol+1+n);
	for(int i=n-m;i>=1;i--)
	{
		fsol[n-m+1]+=fsol[i];
		sort(fsol+n-m+1,fsol+n+1);
	}
	fprintf(outt,"%d",fsol[n-m+1]);
}
bool ai1=1;
int main()
{
	iin=fopen("track.in","rb");
	outt=fopen("track.out","wb");
	fscanf(iin,"%d%d",&n,&m);int uu=0;
	for(int i=1;i<=n-1;i++)
	{
		fscanf(iin,"%d%d%d",&x,&y,&z);
		if(x!=1)ai1=0;
		dian[x].edge.push_back((Edge){y,z});
		dian[y].edge.push_back((Edge){x,z});
		uu=dian[1].edge.size();
	}
	//AK奥义--分情况讨论 m=1
	if(ai1)
		I_AK();
	else if(m==1)
		IOI();
	else
		IOI();
}
//I AK IOI
