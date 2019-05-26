#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
#define ll long long
struct data{
	ll from,to,val;
}e[100010];
data ea[100010];
ll tor1,tor2,tor3,bcnt;
ll n,m,ecnt,des,head[100010],dis[100010],cou,tmp,flag;
void adde(int u,int v,int c)
{
	e[++ecnt].to=v;
	e[ecnt].from=head[u];
	e[ecnt].val=c;
	head[u]=ecnt;
}
bool my_cmp(const data&a,const data&b)
{
	return a.val>b.val;
}
void bfs(ll noww,ll fa)
{
	for(int i=head[noww];i!=0;i=e[i].from)
	{
		des=e[i].to;
		if(des!=fa)
		{
			dis[des]=dis[noww]+e[i].val;
			if(dis[des]>cou)
			{
				cou=dis[des];tmp=des;
			}
			bfs(des,noww);
		}
	}
}
int jud(ll x)
{
	ll i;
	for(i=1;i<=n-1;i++) if(x>ea[i].val) break;
	ll res=n-i;
	if(res>bcnt*2) return 0;
	ll hd=i,tl=n-1;
	tl-=bcnt*2-res;
	ll temp=0;
	for(int i=hd;i<=hd+(tl-hd+1)/2-1;i++) 
	{
		temp++;
		if(ea[i].val+ea[tl-temp+1].val<x) return 0;
	}
	return 1;
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<n;i++)
	{
		scanf("%lld%lld%lld",&ea[i].from,&ea[i].to,&ea[i].val);
		if(ea[i].from!=1) flag=1;
		adde(ea[i].from,ea[i].to,ea[i].val);adde(ea[i].to,ea[i].from,ea[i].val);
	}
	if(m==1)
	{
		tmp=1;bfs(1,0);
		cou=0;memset(dis,0,sizeof(dis));
		bfs(tmp,0);
		printf("%lld\n",cou);
	}
	else
	{
		if(flag==0)
		{
			sort(ea+1,ea+n,my_cmp);
			ll minn=0x7fffffff;
			if(m*2>n-1)
			{
				bcnt=(n-1-m)*2;ll mid;
				ll tou=ea[n-1].val,wei=ea[1].val+ea[2].val;
				ll prt;
				while(tou<=wei)
				{
					mid=(tou+wei)>>1;
					if(jud(mid)) 
					{
						prt=mid;
						tou=mid+1;
					}
					else wei=mid-1;
				}
				cout<<prt<<endl;
			}
			else
			{
				for(int i=1;i<=m;i++) minn=min(ea[i].val+ea[m*2-i+1].val,minn);
				printf("%lld\n",minn);
			}
		}
	/*	else
		{
			
		}*/
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
/*
9 3
1 2 6
2 3 3
3 4 5
4 5 10
6 2 4
7 2 9
8 4 7
9 4 4
*/
