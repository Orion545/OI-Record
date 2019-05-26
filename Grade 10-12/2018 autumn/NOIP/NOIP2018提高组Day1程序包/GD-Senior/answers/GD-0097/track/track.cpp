#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
int a,b,fir,head[100005],lian,alro,cu[50005],ppnum,vv[50005],vis[50005],root,st;
struct node{
	int to,nxt,val;
}e[100005];
void add(int x,int y,int z)
{
	fir++;e[fir].to=y;e[fir].nxt=head[x];e[fir].val=z;head[x]=fir;
}
int ookk(int x,int stt)
{
	int num=0,poi=1,en=stt,tto;vis[stt]=1;
	while(poi<a)
	{
		tto=0;
		while(tto<x&&poi<a)
		{
			stt=en;
			for(int i=head[stt];i;i=e[i].nxt)
			{
				if(vis[e[i].to]) continue;
				en=e[i].to;
				tto+=e[i].val;vis[en]=1;poi++;		
			}
		}
		if(tto>=x) num++;
	}
	if(num>=b) return 1;
	else return 0;
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	cin>>a>>b;ppnum=fir=0;
	for(int i=1;i<=a;i++)vis[i]=cu[i]=0;
	for(int i=1;i<=a-1;i++)
	{
		int x,y,z;cin>>x>>y>>z;
		add(x,y,z);add(y,x,z);
		cu[x]++;cu[y]++;vv[i]=z;
	}
	for(int i=1;i<=a;i++) 
		if(cu[i]!=2){
			ppnum++;st=i;
		} 
	if(ppnum<=2) lian=1;
	for(int i=1;i<=a;i++) 
		if(cu[i]==a-1) 
			{root=i;alro=1;}
	if(alro==1) 
	{
		if(b==1) 
		{
			cout<<vv[a-1]+vv[a-2]<<endl;return 0;
		}
		else 
		{
			int yyyy=min(vv[a-1],vv[a-b-1]+vv[a-b]);
			cout<<yyyy<<endl;return 0;
		}
	}
	if(lian==1)
	 {
		int l=1,r=1000000;int tot;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			for(int i=1;i<=a;i++)vis[i]=0;
			if(ookk(mid,st)==1) 
			{
				tot=mid;l=mid+1;
			}else r=mid-1;
		}
		cout<<tot<<endl;return 0;
	 }
}
