#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<string>
using namespace std;
int n,m,tre,sad;
string sd;
vector<int> lt[1007];
int f[1007][2],w[1007];
bool s[1007], xz[1007];
bool bx[1007];
void bl(int u)
{
	//cout<<"u "<<u<<endl;
	s[u]=true;
	if(lt[u].size()<=1&&u!=1)
	{
		if(xz[u])
			f[u][1]=11451419;
		else
			f[u][1]=w[u];
		if(bx[u])
			f[u][0]=11451419;
		return;	 
	}
	int v,bxz=0;
	for(int i=0;i<lt[u].size();i++)
	{
		v=lt[u][i];
		//cout<<"V "<<v<<endl;
		if(!s[v])
		{
			bl(v);	
			bxz+=f[v][1];
			f[u][1]+=min(f[v][1],f[v][0]);
		}	
	}
	//cout<<"sfdsf "<<u<<endl;
	if(bx[u])f[u][0]=11451419;
	else	 f[u][0]=bxz;
	if(xz[u])f[u][1]=11451419;
	else 	 f[u][1]+=w[u];
	return;
}
int aa,bb,cc,dd;
bool sha;
void clr()
{
	bx[aa]=false;
	xz[bb]=false;
	bx[cc]=false;
	bx[dd]=false;
	memset(f,0,sizeof(f));
	memset(s,false,sizeof(s));
	
	scanf("%d%d%d%d",&aa,&bb,&cc,&dd);
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	cin>>n>>m>>sd;
	int u,v;
	for(int i=1;i<=n;i++)
		scanf("%d",&w[i]);
	//cout<<"asda1"<<endl;
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&u,&v);
		lt[u].push_back(v);
		lt[v].push_back(u);
	}
	
	
	for(int i=1;i<=m;i++)
	{
		sha=false;
		clr();
		if(bb)	bx[aa]=true;
			else	xz[aa]=true;
		if(dd)	bx[cc]=true;
			else	xz[cc]=true;
		if(bb==0&&dd==0)
		{
			for(int i=0;i<lt[aa].size();i++)
			{
				v=lt[aa][i];
			//cout<<"V "<<v<<endl;
				if(v==bb)
				{
					cout<<"-1"<<endl;
					sha=true;
				}
			}
		}
		if(!sha)
		{
		bl(1);
		//if(min(f[1][1],f[1][0])>=1919810)	cout<<-1<<endl;
		cout<<min(f[1][1],f[1][0])<<endl;
		}	
	}
}

