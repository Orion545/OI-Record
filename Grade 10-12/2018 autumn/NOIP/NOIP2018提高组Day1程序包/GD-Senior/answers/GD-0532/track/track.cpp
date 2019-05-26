#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
using namespace std;
struct _point
{
	int ar,rst;
};
struct _side
{
	int f,t,v;	
};
	_point point[50111];
	int n,m,lm,vst[50111],tmp[50111],use[501111],tm=0;
	vector<_side> wy[50111];
void vhgggg(int &a,int &b)
{
	int t=a;a=b;b=t;
}
int cm(int a,int b)
{
	return a<b;
}
_point mkp(int sz,int har)
{
	++tm;
	_point t;
	if(sz==1) 
		{
			t.ar=har+((tmp[0]/lm)!=0);
			t.rst=(tmp[0]<lm)?tmp[0]:0;
			return t;
		}
	sort(tmp,tmp+sz,cm);
	int i,j;
		for(i=0;i<sz-1;++i)
			if(tmp[i]+tmp[i+1]>=lm) 
				{
					use[i]=tm;
					use[i+1]=tm;
					i+=1;
					har+=1;
				}
			int ttt=0;
		for(i=sz-1;i>=0;--i)
			if(use[i]!=tm)
				{
					ttt=tmp[i];
					break;
				}
		t.ar=har;
		t.rst=ttt;
	return t;
		
}
void dfs(int add,int fa)
{
	vst[add]=1;
	vector<int>rt;
	int sz=wy[add].size(),i,ar=0;
		for(i=0;i<sz;++i)
			{
				int t=wy[add][i].t,v=wy[add][i].v;
					if(t==fa) continue;
						dfs(t,add);
					rt.push_back(point[t].rst+v);
					ar+=point[t].ar;
			}
		sz=rt.size();
		for(i=0;i<sz;++i)
			tmp[i]=rt[i];
		point[add]=mkp(sz,ar);
}
int judge(const int &mid)
{
	memset(vst,0,sizeof(vst));
	lm=mid;
	dfs(1,0);
	return point[1].ar>=m; 
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	int i,j,l=0,r=0;
	scanf("%d%d",&n,&m);
		for(i=1;i<n;++i)
			{
				_side sd;
					scanf("%d%d%d",&sd.f,&sd.t,&sd.v);
						r+=sd.v;
						wy[sd.f].push_back(sd);
					vhgggg(sd.f,sd.t);
				wy[sd.f].push_back(sd);
			}
		int mid;
		while(l<r)
			{
				mid=(l+r+1)/2;
				if(judge(mid)) l=mid;
						else r=mid-1;
			}
		printf("%d\n",l);
	return 0;
}

