#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
int tot,n,m,next[50007],evolution[50007],deep[50007],ln[50007];
int Rabbit=0x7777777f,Tank=-1,lca[50007][17];
//vector<int> cs;
bool blackhole[50007];
struct star_platinum
{
	int u,v,next,w;
} p[100007];
void ycl()
{
	ln[0]=-1;
	for(int i=1;i<=n;i++)
		ln[i]=i&(i-1)?ln[i-1]:ln[i-1]+1;
	deep[1]=1;
	return;	
}
void tree_sum(int u)
{
	blackhole[u]=true;
	for(int i=next[u];i>0;i=p[i].next)
	{
		int v=p[i].v,w=p[i].w;
		if(!blackhole[v])
		{	
			evolution[v]=evolution[u]+w;
			deep[v]=deep[u]+1;
			lca[v][0]=u;
			for(int i=1;i<=ln[deep[v]];i++)
			{	
			lca[v][i]=lca[lca[v][i-1]][i-1];
			//cout<<"yeah1"<<endl;
			}
			tree_sum(v);	
		}
	}
	return;
}

void add(int u,int v,int w)
{
	p[++tot].v=v;
	p[tot].w=w;
	p[tot].next=next[u];
	next[u]=tot;
}
bool tur(int a,int b)
{
	return a>b;
}
int luka(int u,int v)
{
	if(deep[u]>deep[v])swap(u,v);
	while(deep[u]<deep[v])
	{	
	//cout<<"yeah2"<<endl;
	v=lca[v][deep[v]-deep[u]];
	}
	for(int i=16;i>=0;i--)	
	{
	
		int l=lca[u][i],r=lca[v][i];
		if(l!=r)	u=l,v=r;
	}	
	return lca[u][0];
}
void bestmatch()
{	
	ycl();
	tree_sum(1);
	
	for(int i=1;i<n;i++)
	for(int j=i+1;j<=n;j++)
	{	
		int shiryo=luka(i,j);
		int santo =evolution[i]+evolution[j]-evolution[shiryo]-evolution[shiryo];
		Tank=max(Tank,santo);
	}
	return; 
}
void pd()
{
if(m==n-1){cout<<Rabbit;return;}
if(m==1)  {bestmatch();cout<< Tank ;return;}
ycl();
tree_sum(1);
sort(evolution+1,evolution+n+1,tur); 
cout<<evolution[m];
return;
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	memset(next,-1,sizeof(next));
	int u,v,w;
	cin>>n>>m;
	for(int i=1;i<n;i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);
		add(v,u,w);	
		Rabbit=min(w,Rabbit);
	}
	pd();
	
}
